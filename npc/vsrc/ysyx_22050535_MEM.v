`include "ysyx_22050535_defines.v"

module ysyx_22050535_MEM (
  input valid,
  input wen,
  input [`ysyx_22050535_ADDR_WIDTH-1:0] addr,
  input [`ysyx_22050535_DATA_WIDTH-1:0] wdata,
  input [3:0] wmask, // 写掩码，每位对应一个字节
  output reg [`ysyx_22050535_DATA_WIDTH-1:0] rdata
);
  import "DPI-C" function int pmem_read(input int raddr);
  import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);

  always @(*) begin
    if (valid) begin
      rdata = pmem_read(addr & ~32'h3); // 地址按4字节对齐
      if (wen) pmem_write(addr & ~32'h3, wdata, wmask);
    end else begin
      rdata = 32'b0;
    end
  end
endmodule
