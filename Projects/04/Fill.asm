// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.
	@8191
	D = A
	@0
	M = D
	
	@i
	M = 0
(LOOP)
	@KBD//6000H
	D = M
	@SetBlack
	D;JNE	// KBD is true
	@ClearScreen
	0;JMP
	
(SetBlack)
	@i
	D = M
	@0
	D = M - D	// 8192 - i <= 0 -- i >= 8192(2000H) , go out of loop
				// i > 8191		<=>		i >= 8192(2000H)
	@LOOP
	D;JLT
	
	@SCREEN
	D = A
	@i
	A = M + D	// SCREEN + i
	M = -1	// *(SCREEN + i) = black
	@i
	M = M + 1	// i + 1
	D = M
	@LOOP
	0;JMP
(ClearScreen)
	@i
	D = M
	@LOOP
	D;JLT	// i < 0 , go out of loop
	
	@SCREEN
	D = A
	@i
	A = M + D	// SCREEN + i
	M = 0	// *(SCREEN + i) = white
	@i
	M = M - 1	// i + 1
	D = M
	@LOOP
	0;JMP