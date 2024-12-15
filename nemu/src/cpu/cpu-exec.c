/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10

CPU_state cpu = {};
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

void device_update();

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));

#ifdef CONFIG_WATCHPOINT
  check_watchpoints();  // 检查所有监视点的值是否发生变化
#endif
}

// ***********************************************************
// *** iringbuf code begin ***
#ifdef CONFIG_ITRACE
#define IRINGBUF_SIZE 16  // 可以根据需要调整大小

typedef struct {
  vaddr_t pc;           // 指令的PC地址
  char instr[128];      // 指令的反汇编字符串
  uint8_t bytes[8];     // 指令的机器码原始字节（长度可根据ISA决定，一般4-8字节）
  int ilen;             // 指令长度（字节数）
} IringbufEntry;

static IringbufEntry iringbuf[IRINGBUF_SIZE];
static int iringbuf_pos = 0;    // 当前写入位置
static bool iringbuf_full = false; // 是否已经写满过一次

static void save_instruction_to_iringbuf(Decode *s) {
  iringbuf[iringbuf_pos].pc = s->pc;

  snprintf(iringbuf[iringbuf_pos].instr, sizeof(iringbuf[iringbuf_pos].instr), "%s", s->logbuf);

  int ilen = s->snpc - s->pc; // 指令长度
  iringbuf[iringbuf_pos].ilen = ilen;
  memcpy(iringbuf[iringbuf_pos].bytes, &s->isa.inst.val, ilen);

  iringbuf_pos = (iringbuf_pos + 1) % IRINGBUF_SIZE;
  if (iringbuf_pos == 0) {
    iringbuf_full = true;
  }
}

static void print_iringbuf() {
  printf("Recent executed instructions:\n");
  int start = iringbuf_full ? iringbuf_pos : 0;
  int count = iringbuf_full ? IRINGBUF_SIZE : iringbuf_pos;

  // 最后一条记录的指令一般是出错前执行的那条，可以用`-->`标记
  for (int i = 0; i < count; i++) {
    int idx = (start + i) % IRINGBUF_SIZE;
    const char *marker = (i == count - 1) ? "-->" : "   ";
    printf("%s 0x%08" PRIxPTR ": %s\n", marker, (uintptr_t)iringbuf[idx].pc, iringbuf[idx].instr);
    // 如有需要，可以在这里打印机器码
    // for(int j = 0; j < iringbuf[idx].ilen; j++) {
    //   printf("%02x ", iringbuf[idx].bytes[j]);
    // }
    // printf("\n");
  }
}
#endif
// *** iringbuf code end   ***
// ***********************************************************

static void exec_once(Decode *s, vaddr_t pc) {
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);
  cpu.pc = s->dnpc;
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
  int ilen = s->snpc - s->pc;
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst.val;
  for (i = ilen - 1; i >= 0; i --) {
    p += snprintf(p, 4, " %02x", inst[i]);
  }
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

#ifndef CONFIG_ISA_loongarch32r
  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);
#else
  p[0] = '\0'; // the upstream llvm does not support loongarch32r
#endif
    // iringbuf存储指令
    save_instruction_to_iringbuf(s);
#endif
}

static void execute(uint64_t n) {
  Decode s;
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);
    g_nr_guest_inst ++;
    trace_and_difftest(&s, cpu.pc);
    if (nemu_state.state != NEMU_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  isa_reg_display();
  print_iringbuf(); // 在这里调用打印iringbuf
  statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

    case NEMU_END: case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          nemu_state.halt_pc);
      // fall through
    case NEMU_QUIT: statistic();
  }
}
