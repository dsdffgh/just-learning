// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.
	@1
	D =	M
	@STR1
	M = D	// STR1 = R1
	

	@1
	D = M
	@SKIP1
	D;JNE
	@2
	M = 0
	@END
	0;JMP
	
(SKIP1)
	@0
	D = M
	@SKIP0
	D;JNE
	@2
	M = 0
	@END
	0;JMP
	
(SKIP0)	
	
	@2
	M = 0
(add_loop)
	@STR1
	D = M
	@END
	D;JLE
	
	@0
	D = M
	@2
	M = D + M
	@STR1
	//D = M
	M = M - 1
	@add_loop
	D;JGE
	
//(XCH)
//	@0
//	D = M
//	@2
//	M = D	// R2 = R0
//	
//	@SUM
//	D = M
//	@0
//	M = D	// R0 = SUMs
	
//(R1_EQU_0)
//	@1
//	D = M
//	@2
//	M = D
//	
//(R0_EQU_0)
//	@0
//	D = M
//	@2
//	M = D

(END)
	@END
	0;JMP