module ysyx_22050535_Adder (
  input [`ysyx_22050535_DATA_WIDTH-1:0] op1,
  input [`ysyx_22050535_DATA_WIDTH-1:0] op2,
  output [`ysyx_22050535_DATA_WIDTH-1:0] result
);
  assign result = op1 + op2;
endmodule
