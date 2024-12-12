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

#include "local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>

#define R(i) gpr(i)
#define Mr vaddr_read
#define Mw vaddr_write

enum {
  TYPE_I, TYPE_U, TYPE_S, TYPE_J,
  TYPE_N, // none
};

#define src1R() do { *src1 = R(rs1); } while (0)
#define src2R() do { *src2 = R(rs2); } while (0)
#define immI() do { *imm = SEXT(BITS(i, 31, 20), 12); } while(0)
#define immU() do { *imm = SEXT(BITS(i, 31, 12), 20) << 12; } while(0)
#define immS() do { *imm = (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); } while(0)
// J-type
#define immJ() do {                                         \
  *imm = SEXT(((BITS(i, 31, 31) << 19) |  /* offset[20] */   \
              (BITS(i, 19, 12) << 11) |  /* offset[19:12] */\
              (BITS(i, 20, 20) << 10) |  /* offset[11] */   \
              (BITS(i, 30, 21))) << 1,         /* offset[10:1] */ \
              21); /* 符号扩展到21位 */                      \
} while (0)

static void decode_operand(Decode *s, int *rd, word_t *src1, word_t *src2, word_t *imm, int type) {
  uint32_t i = s->isa.inst.val;
  int rs1 = BITS(i, 19, 15);
  int rs2 = BITS(i, 24, 20);
  *rd     = BITS(i, 11, 7);
  switch (type) {
    case TYPE_I: src1R();          immI(); break;
    case TYPE_U:                   immU(); break;
    case TYPE_S: src1R(); src2R(); immS(); break;
    case TYPE_J:                   immJ(); break;
  }
}

static int decode_exec(Decode *s) { //s->snpc已经指向了+4后的下一条静态指令，s->pc指向的当前指令，我们需要维护s->dnpc动态指令
    int rd = 0;
    word_t src1 = 0, src2 = 0, imm = 0;
    s->dnpc = s->snpc;

#define INSTPAT_INST(s) ((s)->isa.inst.val)
#define INSTPAT_MATCH(s, name, type, ... /* execute body */ ) { \
    decode_operand(s, &rd, &src1, &src2, &imm, concat(TYPE_, type)); \
    __VA_ARGS__ ; \
}

    INSTPAT_START();
    INSTPAT("??????? ????? ????? ??? ????? 01101 11", lui    , U, R(rd) = imm);
    INSTPAT("??????? ????? ????? 010 ????? 00000 11", lw     , I, R(rd) = Mr(src1 + imm, 4));
    INSTPAT("??????? ????? ????? 010 ????? 01000 11", sw     , S, Mw(src1 + imm, 4, src2));

    // Standard instructions
    INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc, U, R(rd) = s->pc + imm);
    INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi , I, R(rd) = src1 + imm);
    INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal  , J,{R(rd) = s->snpc; s->dnpc = s->pc + imm;}); // 把下一条指令的地址(pc+4)，然后把 pc 设置为当前值加上符号位扩展的offset[20|10:1|11|19:12]
    INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr , I,{
                                                                R(rd) = s->snpc;                // 保存下一条指令地址
                                                                s->dnpc = (src1 + imm) & ~1;    // 计算跳转目标地址
                                                                });
    INSTPAT("??????? ????? ????? 000 ????? 01000 11", sb     , S, Mw(src1 + imm, 1, (src2 & 0xFF)));

    // Pseudo instructions
    INSTPAT("??????? ????? 00000 000 ????? 00100 11", li   , I, R(rd) = imm);
    INSTPAT("0000000 00000 ????? 000 ????? 00100 11", mv   , I, R(rd) = src1); // addi rd, rs1, 0
    INSTPAT("??????? ????? ????? ??? 00000 11011 11", j    , J,{R(0) = s->snpc; s->dnpc = s->pc + imm;}); // jal x0,offset
    INSTPAT("0000000 00000 00001 000 ????? 11001 11", ret  , I, {
                                                                R(0) = s->snpc;     // 保存下一条指令地址
                                                                s->dnpc = R(1);     // 计算跳转目标地址
                                                                });                 // jalr x0, 0(x1)

    INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
    INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv    , N, INV(s->pc));
    INSTPAT_END();

    R(0) = 0; // reset $zero to 0

    return 0;
}

int isa_exec_once(Decode *s) {
    s->isa.inst.val = inst_fetch(&s->snpc, 4);
    return decode_exec(s);
}
