//双控开关
module our_OnOff(
  input a,
  input b,
  output f
);
assign f = a ^ b;
endmodule
