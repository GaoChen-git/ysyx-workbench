`include "ysyx_22050535_defines.v"

import "DPI-C" function void sim_end();

module ysyx_22050535_EBREAK (
  input [`ysyx_22050535_INST_WIDTH-1:0] inst
);
  always @(*) begin
    if (inst == 32'h00100073) // ebreak 指令编码
      sim_end();
  end
endmodule
