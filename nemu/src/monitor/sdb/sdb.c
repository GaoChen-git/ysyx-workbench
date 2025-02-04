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

#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include <memory/paddr.h>
#include <memory/vaddr.h>

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
void print_watchpoints();
void delete_watchpoint(int no);

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  nemu_state.state = NEMU_QUIT;
  return -1;
}

static int cmd_help(char *args);

//单步执行
static int cmd_si(char *args) {
  int n = 1; // 默认单步执行 1 条指令
  if (args != NULL) {
    if (sscanf(args, "%d", &n) != 1 || n < 1) { // 检查参数合法性
      printf("Invalid argument. Usage: si [N], where N >= 1\n");
      return 0;
    }
  }
  cpu_exec(n); // 调用框架函数执行指令
  return 0;
}
//打印寄存器
static int cmd_info(char *args) {
  // 提取子命令（如 "r"）
  char *arg = strtok(NULL, " ");
  if (arg == NULL) {
    // 用户未提供子命令
    printf("Please provide a subcommand: r (registers)\n");
  } else if (strcmp(arg, "r") == 0) {
    // 调用 API 打印寄存器
    isa_reg_display();
  } else if (strcmp(arg, "w") == 0) { // 添加对 info w 的支持
    // 调用 API 打印监视点
    print_watchpoints();
  } else {
    // 未识别的子命令
    printf("Invalid subcommand. Supported: r\n");
  }
  return 0;
}

//扫描内存
static int cmd_x(char *args) {
    if (args == NULL) {
        printf("Usage: x N EXPR\n");
        return 0;
    }

    // 解析参数
    char *n_str = strtok(args, " ");
    char *expr_str = strtok(NULL, " ");

    if (n_str == NULL || expr_str == NULL) {
        printf("Usage: x N EXPR\n");
        return 0;
    }

    // 转换 N
    int n = 0;
    if (sscanf(n_str, "%d", &n) != 1 || n <= 0) {
        printf("Invalid N. N should be a positive integer.\n");
        return 0;
    }

    // 转换 EXPR 为地址
    paddr_t addr = 0;
    if (sscanf(expr_str, "%x", &addr) != 1) {
        printf("Invalid EXPR. EXPR should be a hexadecimal number.\n");
        return 0;
    }

    // 扫描内存并打印
    printf("Scanning memory from address 0x%x:\n", addr);
    for (int i = 0; i < n; i++) {
        paddr_t current_addr = addr + i * 4;
        word_t data = 0;
        data = vaddr_read(current_addr, 4);
        printf("0x%08x: 0x%08x\n", current_addr, data);
    }

    return 0;
}


static int cmd_p(char *args) {


  return 0;
}

static int cmd_info_w(char *args) {
  // 调用 print_watchpoints 打印监视点信息
  print_watchpoints();
  return 0;
}

static int cmd_delete_watchpoint(char *args) {
  if (args == NULL) {
    printf("Usage: d <no>\n"); // 提示用法
    return 0;
  }

  int no = 0;
  if (sscanf(args, "%d", &no) != 1) { // 解析监视点编号
    printf("Invalid argument. Usage: d <no>\n");
    return 0;
  }

  // 调用 delete_watchpoint 删除监视点
  delete_watchpoint(no);
  return 0;
}

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  /* TODO: Add more commands */
  { "si", "Single step program through N instructions", cmd_si },
  { "info", "Print program status", cmd_info },
  { "x", "Scan memory", cmd_x },
  { "p", "Evaluate the expression EXPR", cmd_p },
  { "info w", "Print watchpoints information", cmd_info_w },
  { "d", "Delete a watchpoint by its number", cmd_delete_watchpoint }
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
