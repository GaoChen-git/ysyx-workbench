`include "ysyx_22050535_defines.v"

module ysyx_22050535_PC (
  input clk,
  input rst,
  output reg [`ysyx_22050535_ADDR_WIDTH-1:0] pc
);
  always @(posedge clk) begin
    if (rst)
    //   pc <= `ysyx_22050535_RESET_VAL;
      pc <= 32'h80000000;
    else
      pc <= pc + 4; // 每次递增4字节
  end
endmodule
