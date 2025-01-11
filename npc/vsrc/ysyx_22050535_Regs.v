`include "ysyx_22050535_defines.v"

module ysyx_22050535_Regs (
  input clk,
  input [`ysyx_22050535_DATA_WIDTH-1:0] wdata,
  input [`ysyx_22050535_ADDR_WIDTH-1:0] waddr,
  input [`ysyx_22050535_ADDR_WIDTH-1:0] raddr1,
  input [`ysyx_22050535_ADDR_WIDTH-1:0] raddr2,
  input wen,
  output [`ysyx_22050535_DATA_WIDTH-1:0] rdata1,
  output [`ysyx_22050535_DATA_WIDTH-1:0] rdata2
);
  reg [`ysyx_22050535_DATA_WIDTH-1:0] rf [`ysyx_22050535_REG_NUM-1:0];

  // 写操作
  always @(posedge clk) begin
    if (wen && waddr != 0) // 确保0号寄存器恒为0
      rf[waddr] <= wdata;
  end

  // 读操作
  assign rdata1 = (raddr1 == 0) ? {`ysyx_22050535_DATA_WIDTH{1'b0}} : rf[raddr1];
  assign rdata2 = (raddr2 == 0) ? {`ysyx_22050535_DATA_WIDTH{1'b0}} : rf[raddr2];
endmodule
