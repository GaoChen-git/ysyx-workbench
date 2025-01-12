`include "ysyx_22050535_defines.v"

module ysyx_22050535_NPC (
  input clk,
  input rst,
  input [`ysyx_22050535_INST_WIDTH-1:0] mem_inst,   // 从存储器读取指令
  output [`ysyx_22050535_ADDR_WIDTH-1:0] pc
);
  wire [`ysyx_22050535_INST_WIDTH-1:0] inst;
  wire [`ysyx_22050535_DATA_WIDTH-1:0] src1, src2, result;
  wire [`ysyx_22050535_DATA_WIDTH-1:0] imm;
  wire [4:0] rs1, rs2, rd;
  wire branch_taken;
  wire [6:0] opcode;
  wire [2:0] func3;
  wire [6:0] func7;

  // PC模块
  ysyx_22050535_PC pc_inst (
    .clk(clk),
    .rst(rst),
    .pc(pc)
  );

  // 寄存器文件模块
  ysyx_22050535_Regs regs_inst (
    .clk(clk),
    .wdata(result),
    .waddr(rd),
    .wen(1'b1),
    .raddr1(rs1),
    .raddr2(rs2),
    .rdata1(src1),
    .rdata2(src2)
  );

  // IFU取址模块
  ysyx_22050535_IFU ifu_inst (
    .pc(pc),
    .inst(inst),
    .mem_inst(mem_inst)
  );

  // IDU译码模块
  ysyx_22050535_IDU idu_inst (
    .inst(inst),
    .rs1(rs1),
    .rs2(rs2),
    .rd(rd),
    .imm(imm),
    .opcode(opcode),
    .func3(func3),
    .func7(func7)
  );

  // EXU执行模块
  ysyx_22050535_EXU exu_inst (
    .src1(src1),
    .src2(src2),
    .imm(imm),
    .opcode(opcode),
    .func3(func3),
    .func7(func7),
    .result(result),
    .branch_taken(branch_taken)
  );

endmodule
