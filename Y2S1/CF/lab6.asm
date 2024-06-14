// @R0
// D=M

// @POSITIVE
// D;JGT

// @NEGATIVE
// D;JLT

// @R1
// M=0
// @END
// 0;JMP

// (POSITIVE)
// @R1
// M=1
// @END
// 0;JMP

// (NEGATIVE)
// @R1
// M=-1

// (END)
// @END
// 0;JMP


//



// @I
// M=1
// @SUM
// M=0

// (LOOP)
// @I
// D=M
// @0
// D=D-M
// @RETURN
// D;JGT

// @I
// D=M
// @SUM
// M=D+M
// @I
// M=M+1
// @LOOP
// 0;JMP

// (RETURN)
// @SUM
// D=M
// @1
// M=D
// (END)
// @END
// 0;JMP

//



// @PRODUCT
// M=0

// (LOOP)
// @1
// D=M
// @PRODUCT
// M=M+D
// @0
// M=M-1
// D=M
// @RETURN
// D;JEQ
// @LOOP
// 0;JMP

// (RETURN)
// @PRODUCT
// D=M
// @2
// M=D
// (END)
// @END
// 0;JMP


//


// @I
// M=1
// @J
// M=1
// @SUM
// M=0

// (LOOP)
// @SUM
// D=M
// @J
// M=D //J=SUM(OLD)
// @I
// D=M
// @SUM
// M=M+D//SUM=SUM+I
// @J
// D=M
// @I
// M=D//I=SUM(OLD)
// @SUM
// D=M
// @0
// D=M-D//RAM(0)-SUM
// @RETURN
// D;JLT
// @LOOP
// 0;JMP


// (RETURN)
// @SUM
// D=M
// @1
// M=D
// (END)
// @END
// 0;JMP


//



@2
M=0

(LOOP)
@1
D=M
@0
D=D-M  //D= Y-X
@RETURN
D;JGT //BRAKE WHEN Y>X

@1
D=M
@0
M=M-D

@2
M=M+1
@LOOP
0;JMP

(RETURN)
(END)
@END
0;JMP