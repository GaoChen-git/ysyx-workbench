`include "ysyx_22050535_defines.v"

module ysyx_22050535_IFU (
  input [`ysyx_22050535_ADDR_WIDTH-1:0] pc,
  output [`ysyx_22050535_INST_WIDTH-1:0] inst,
  input [`ysyx_22050535_INST_WIDTH-1:0] mem_inst // 从存储器输入指令
);
  assign inst = mem_inst; // 假设直接从存储器读取
endmodule
