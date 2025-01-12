`include "ysyx_22050535_defines.v"

module ysyx_22050535_IDU (
  input [`ysyx_22050535_INST_WIDTH-1:0] inst,  // 32位指令输入
  output [3:0] rs1,                           // 源寄存器1地址 (4位，16个寄存器)
  output [3:0] rs2,                           // 源寄存器2地址 (4位，16个寄存器)
  output [3:0] rd,                            // 目标寄存器地址 (4位，16个寄存器)
  output [`ysyx_22050535_DATA_WIDTH-1:0] imm, // 立即数输出
  output [6:0] opcode,                        // 指令的操作码
  output [2:0] func3,                         // 指令的 func3 字段
  output [6:0] func7                          // 指令的 func7 字段
);
  // 截断到 4 位，确保与寄存器数量匹配
  assign rs1   = inst[19:15] & 4'hF;  // 提取 rs1，并截断到 4 位
  assign rs2   = inst[24:20] & 4'hF;  // 提取 rs2，并截断到 4 位
  assign rd    = inst[11:7]  & 4'hF;  // 提取 rd，并截断到 4 位

  // 立即数根据指令类型解析
  assign imm   = (inst[6:0] == 7'b1101111) ? {{11{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0} : // J型立即数
                 (inst[6:0] == 7'b1100011) ? {{19{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0} :  // B型立即数
                 (inst[6:0] == 7'b0010011 || inst[6:0] == 7'b0000011 || inst[6:0] == 7'b1100111) ?
                 {{20{inst[31]}}, inst[31:20]} : // I型立即数
                 32'b0; // 默认

  // 提取指令字段
  assign opcode = inst[6:0];     // 操作码
  assign func3  = inst[14:12];   // func3 字段
  assign func7  = inst[31:25];   // func7 字段
endmodule
