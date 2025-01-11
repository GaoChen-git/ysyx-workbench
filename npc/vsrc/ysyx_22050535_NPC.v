`include "ysyx_22050535_defines.v"

module ysyx_22050535_NPC (
  input clk,
  input rst,
  input [`ysyx_22050535_INST_WIDTH-1:0] mem_inst, // 从存储器读取指令
  output [`ysyx_22050535_ADDR_WIDTH-1:0] pc
);
  wire [`ysyx_22050535_INST_WIDTH-1:0] inst;
  wire [`ysyx_22050535_DATA_WIDTH-1:0] src1, result;
  wire [4:0] rs1, rd;
  wire [`ysyx_22050535_DATA_WIDTH-1:0] imm;

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
    .raddr2(5'b0),
    .rdata1(src1),
    .rdata2()
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
    .rd(rd),
    .imm(imm)
  );

  // EXU执行模块
  ysyx_22050535_EXU exu_inst (
    .src1(src1),
    .imm(imm),
    .result(result)
  );

  // EBREAK模块
  ysyx_22050535_EBREAK ebreak_inst (
    .inst(inst)
  );

endmodule
