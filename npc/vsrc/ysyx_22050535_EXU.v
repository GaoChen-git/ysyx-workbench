module EXU (
    input [31:0] src1,
    input [31:0] imm,
    output [31:0] result
);
    assign result = src1 + imm;
endmodule
