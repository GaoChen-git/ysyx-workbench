`include "ysyx_22050535_defines.v"

module ysyx_22050535_EXU (
  input [`ysyx_22050535_DATA_WIDTH-1:0] src1,
  input [`ysyx_22050535_DATA_WIDTH-1:0] imm,
  output [`ysyx_22050535_DATA_WIDTH-1:0] result
);
  ysyx_22050535_Adder adder (
    .op1(src1),
    .op2(imm),
    .result(result)
  );
endmodule
