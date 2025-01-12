`include "ysyx_22050535_defines.v"

module ysyx_22050535_EXU (
  input [`ysyx_22050535_DATA_WIDTH-1:0] src1,
  input [`ysyx_22050535_DATA_WIDTH-1:0] src2,
  input [`ysyx_22050535_DATA_WIDTH-1:0] imm,
  input [6:0] opcode,
  input [2:0] func3,
  input [6:0] func7,
  output reg [`ysyx_22050535_DATA_WIDTH-1:0] result,
  output reg branch_taken
);
  always @(*) begin
    branch_taken = 1'b0;
    case (opcode)
      7'b0010011: begin // I类型算术指令
        case (func3)
          3'b000: result = src1 + imm; // ADDI
          3'b010: result = ($signed(src1) < $signed(imm)) ? 1 : 0; // SLTI
          3'b011: result = (src1 < imm) ? 1 : 0; // SLTIU
          3'b100: result = src1 ^ imm; // XORI
          3'b110: result = src1 | imm; // ORI
          3'b111: result = src1 & imm; // ANDI
        endcase
      end
      7'b0110011: begin // R类型算术指令
        case (func3)
          3'b000: result = (func7[5]) ? src1 - src2 : src1 + src2; // ADD/SUB
          3'b001: result = src1 << src2[4:0]; // SLL
          3'b010: result = ($signed(src1) < $signed(src2)) ? 1 : 0; // SLT
          3'b011: result = (src1 < src2) ? 1 : 0; // SLTU
          3'b100: result = src1 ^ src2; // XOR
          3'b101: result = (func7[5]) ? ($signed(src1) >>> src2[4:0]) : (src1 >> src2[4:0]); // SRL/SRA
          3'b110: result = src1 | src2; // OR
          3'b111: result = src1 & src2; // AND
        endcase
      end
      7'b1100011: begin // 分支指令
        case (func3)
          3'b000: branch_taken = (src1 == src2); // BEQ
          3'b001: branch_taken = (src1 != src2); // BNE
          3'b100: branch_taken = ($signed(src1) < $signed(src2)); // BLT
          3'b101: branch_taken = ($signed(src1) >= $signed(src2)); // BGE
          3'b110: branch_taken = (src1 < src2); // BLTU
          3'b111: branch_taken = (src1 >= src2); // BGEU
        endcase
      end
      default: result = 32'b0;
    endcase
  end
endmodule
