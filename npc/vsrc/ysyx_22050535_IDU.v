// 译码

`include "ysyx_22050535_defines.v"

module ysyx_22050535_IDU (
  input [`ysyx_22050535_INST_WIDTH-1:0] inst,
  output [4:0] rs1,
  output [4:0] rd,
  output [`ysyx_22050535_DATA_WIDTH-1:0] imm
);
  assign rs1 = inst[19:15];
  assign rd = inst[11:7];
  assign imm = {{20{inst[31]}}, inst[31:20]}; // 符号扩展
endmodule
