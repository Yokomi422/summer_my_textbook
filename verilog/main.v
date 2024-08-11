module Decoder(
	clk,
	instruction,
	opcode,
	rd,
	funct3,
	funct7,
	rs1,
	rs2,
	imm,
	imm_type
);
	input clk;
	input [31:0] instruction;
	output reg [6:0] opcode;
	output reg [4:0] rd;
	output reg [2:0] funct3;
	output reg [6:0] funct7;
	output reg [4:0] rs1;
	output reg [4:0] rs2;
	output reg [31:0] imm;
	output reg [2:0] imm_type;

	always @(posedge clk) begin
		opcode <= instruction[6:0];
		rd <= instruction[11:7];
		funct3 <= instruction[14:12];
		funct7 <= instruction[31:25];
		rs1 <= instruction[19:15];
		rs2 <= instruction[24:20];
		imm <= { {20{instruction[31]}}, instruction[31:20] };
		case (opcode)
		// R-type
		7'b0110011: begin
			imm_type <= 3'b000;
		end
		// I-type
		7'b0010011,
		7'b0000011,
		7'b1100111: begin 
			imm_type <= 3'b001;
			// 符号拡張
			imm <= {{20{instruction[31]}}, instruction[31:20]};
		end
		// U-type
		7'b0110111: begin
			imm_type <= 3'b010;
			imm <= {instruction[31:12], 12'b0};
		end
		// J-type
		7'b1101111: begin
			imm_type <= 3'b011;
			imm <= {{11{instruction[31]}}, instruction[31], instruction[19:12], instruction[20], instruction[30:21], 1'b0};
		end
		// B-type
		7'b1100011: begin
			imm_type <= 3'b100;
			imm <= {{19{instruction[31]}}, instruction[31], instruction[7], instruction[30:25], instruction[11:8], 1'b0};
		end
		// S-type
		7'b0100011: begin
			imm_type <= 3'b101;
			imm <= {{20{instruction[31]}}, instruction[31:25], instruction[11:7]}; 
		end
		// 未定義
		default: begin
            imm_type <= 3'b111;
            imm <= 32'b0;
        end
		endcase
	end
endmodule;;

module testbench;

    reg clk;
    reg [31:0] instruction;
    wire [6:0] opcode;
    wire [4:0] rd;
    wire [2:0] funct3;
    wire [6:0] funct7;
    wire [4:0] rs1;
    wire [4:0] rs2;
    wire [31:0] imm;
    wire [2:0] imm_type;

    Decoder decoder1 (
        .clk(clk),
        .instruction(instruction),
        .opcode(opcode),
        .rd(rd),
        .funct3(funct3),
        .funct7(funct7),
        .rs1(rs1),
        .rs2(rs2),
        .imm(imm),
        .imm_type(imm_type)
    );

	always begin
		#5;
		clk = ~clk;
	end

	 initial begin
		clk = 0;
        $monitor("Time: %t | instruction: %h | opcode: %b | rd: %b | funct3: %b | funct7: %b | rs1: %b | rs2: %b | imm: %h | imm_type: %b",
                  $time, instruction, opcode, rd, funct3, funct7, rs1, rs2, imm, imm_type);
        
        instruction = 32'b0000000_00010_00001_000_00011_0110011; // ADD x3, x1, x2
        #10;

        instruction = 32'b000000000001_00000000_00000_1101111; // JAL x0, 0x1
        #10;

        instruction = 32'b000000_00010_00001_000_00001_1100011; // BEQ x1, x2, 0x1
        #10;

        instruction = 32'b0000000_00010_00001_010_00000_0100011; // SW x2, 0(x1)
        #10;

        $finish;
    end

endmodule