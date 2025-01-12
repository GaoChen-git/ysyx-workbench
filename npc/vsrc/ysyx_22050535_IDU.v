`include "ysyx_22050535_defines.v"

module ysyx_22050535_IDU (
  input [`ysyx_22050535_INST_WIDTH-1:0] inst,
  output [3:0] rs1,
  output [3:0] rs2,
  output [3:0] rd,
  output [`ysyx_22050535_DATA_WIDTH-1:0] imm,
  output [6:0] opcode,
  output [2:0] func3,
  output [6:0] func7
);
  assign rs1   = inst[19:15];
  assign rs2   = inst[24:20];
  assign rd    = inst[11:7];
  assign imm   = (inst[6:0] == 7'b1101111) ? {{11{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0} : // J型立即数
                 (inst[6:0] == 7'b1100011) ? {{19{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0} :  // B型立即数
                 (inst[6:0] == 7'b0010011 || inst[6:0] == 7'b0000011 || inst[6:0] == 7'b1100111) ?
                 {{20{inst[31]}}, inst[31:20]} : // I型立即数
                 32'b0; // 默认
  assign opcode = inst[6:0];
  assign func3  = inst[14:12];
  assign func7  = inst[31:25];
endmodule
