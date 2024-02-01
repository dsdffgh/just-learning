/*
 * =====================================================================================
 *
 *       Filename:  CodeWriter.c
 *
 *    Description:  This module translates a parsed VM command into Hack
 *                  assembly code.
 *
 *        Version:  1.0
 *        Created:  11/29/23 16:02:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:
 *
 * =====================================================================================
 */

#include "Parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1       /* show vm command to debug */
#define DISPLAY_SCR 0 /* print information on screen */

// Enum for arithmetic command types
enum ArithmrticCommand {
  C_ADD,    /* integer addition */
  C_SUB,    /* integer subtraction */
  C_NEG,    /* arithmetic ngation */
  C_EQ,     /* equality */
  C_GT,     /* greater than */
  C_LT,     /* less than */
  C_AND,    /* bite-wise And */
  C_OR,     /* bite-wise Or */
  C_NOT,    /* bite-wise Not */
  C_UNKNOWN // Default for unsupported commands
};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  getArithmeticCommandType
 *  Description:  Returns the command type for the given arithmetic command.
 * =====================================================================================
 */
enum ArithmrticCommand getArithmeticCommandType(const char *command) {
  if (strcmp(command, "add") == 0) {
    return C_ADD;
  } else if (strcmp(command, "sub") == 0) {
    return C_SUB;
  } else if (strcmp(command, "neg") == 0) {
    return C_NEG;
  } else if (strcmp(command, "eq") == 0) {
    return C_EQ;
  } else if (strcmp(command, "gt") == 0) {
    return C_GT;
  } else if (strcmp(command, "lt") == 0) {
    return C_LT;
  } else if (strcmp(command, "and") == 0) {
    return C_AND;
  } else if (strcmp(command, "or") == 0) {
    return C_OR;
  } else if (strcmp(command, "not") == 0) {
    return C_NOT;
  }
  // Default case for unsupported commands
  return C_UNKNOWN;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _add
 *  Description:  
 * =====================================================================================
 */
void _add(outfile) {
  // sp--, because sp points above the top element of the stack.
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P1
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "D=M\n"); // D = M[A] = M[*SP] = **SP = *DATA

  // sp--
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P2
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "A=M\n"); // A = M[A] = M[*SP] = **SP = *DATA

  // perform operations on operands
  fprintf(outfile, "D=D+A\n");

  // push result
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n", );
  fprintf(outfile, "M=D\n", );
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M+1\n"); // *SP = *SP + 1
} /* -----  end of function _add  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _sub
 *  Description:  
 * =====================================================================================
 */
void _sub(outfile) {
  // sp--, because sp points above the top element of the stack.
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P1
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "D=M\n"); // D = M[A] = M[*SP] = **SP = *DATA

  // sp--
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P2
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "A=M\n"); // A = M[A] = M[*SP] = **SP = *DATA

  // perform operations on operands
  fprintf(outfile, "D=D-A\n");

  // push result
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n", );
  fprintf(outfile, "M=D\n", );
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M+1\n"); // *SP = *SP + 1
} /* -----  end of function _sub  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _neg
 *  Description:  
 * =====================================================================================
 */
void _neg(outfile) {
  // sp--, because sp points above the top element of the stack.
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P1
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "D=M\n"); // D = M[A] = M[*SP] = **SP = *DATA

  // perform operations on operands
  fprintf(outfile, "D=-D\n");

  // push result
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n", );
  fprintf(outfile, "M=D\n", );
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M+1\n"); // *SP = *SP + 1
} /* -----  end of function _neg  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _eq
 *  Description:  
 * =====================================================================================
 */
void _eq(outfile) {
  // sp--, because sp points above the top element of the stack.
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P1
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "D=M\n"); // D = M[A] = M[*SP] = **SP = *DATA

  // sp--
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P2
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "A=M\n"); // A = M[A] = M[*SP] = **SP = *DATA

  // perform operations on operands
  fprintf(outfile, "D=A-D\n");
  fprintf(outfile, "@EQ_label\n"); // if ( P2==P1 ), goto EQ_label
  fprintf(outfile, "D;JEQ\n", );
  fprintf(outfile, "@SP\n", );
  fprintf(outfile, "A=M\n", );
  fprintf(outfile, "M=0\n", );
  fprintf(outfile, "@PUSH_finished\n", );
  fprintf(outfile, "0;JMP\n", );
  fprintf(outfile, "(EQ_label)\n", );
  fprintf(outfile, "@SP\n", );
  fprintf(outfile, "A=M\n", );
  fprintf(outfile, "M=-1\n", ); // P1==P2, is true, push true(-1)

  // sp++
  fprintf(outfile, "(PUSH_finished)\n", );
  fprintf(outfile, "@SP\n", );
  fprintf(outfile, "M=M+1\n", );
} /* -----  end of function _eq  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _gt
 *  Description:  
 * =====================================================================================
 */
void _gt(outfile) {
  // sp--, because sp points above the top element of the stack.
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P1
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "D=M\n"); // D = M[A] = M[*SP] = **SP = *DATA

  // sp--
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P2
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "A=M\n"); // A = M[A] = M[*SP] = **SP = *DATA

  // perform operations on operands
  fprintf(outfile, "D=A-D\n");
  fprintf(outfile, "@Greater\n", );
  fprintf(outfile, "D;JGT\n", ); // if( P1-P2>0 ), goto Greater
  fprintf(outfile, "@SP\n", );
  fprintf(outfile, "A=M\n", );
  fprintf(outfile, "M=0\n", ); // P1<=P2, is false, push false
  fprintf(outfile, "@PUSH_finished\n", );
  fprintf(outfile, "0;JMP\n", );
  fprintf(outfile, "(Greater)\n", );
  fprintf(outfile, "@SP\n", );
  fprintf(outfile, "A=M\n", );
  fprintf(outfile, "M=-1\n", ); // P1>P2, is true, push true(-1)

  // sp++
  fprintf(outfile, "(PUSH_finished)\n", );
  fprintf(outfile, "@SP\n", );
  fprintf(outfile, "M=M+1\n", );
} /* -----  end of function _gt  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _lt
 *  Description:  
 * =====================================================================================
 */
void _lt(outfile) {
  // sp--, because sp points above the top element of the stack.
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P1
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "D=M\n"); // D = M[A] = M[*SP] = **SP = *DATA

  // sp--
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P2
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "A=M\n"); // A = M[A] = M[*SP] = **SP = *DATA

  // perform operations on operands
  fprintf(outfile, "D=A-D\n");
  fprintf(outfile, "@Less\n", );
  fprintf(outfile, "D;JLT\n", ); // if( P1-P2<0 ), goto Less
  fprintf(outfile, "@SP\n", );
  fprintf(outfile, "A=M\n", );
  fprintf(outfile, "M=0\n", ); // P1>=P2, is false, push false
  fprintf(outfile, "@PUSH_finished\n", );
  fprintf(outfile, "0;JMP\n", );
  fprintf(outfile, "(Less)\n", );
  fprintf(outfile, "@SP\n", );
  fprintf(outfile, "A=M\n", );
  fprintf(outfile, "M=-1\n", ); // P1<P2, is true, push true(-1)

  // sp++
  fprintf(outfile, "(PUSH_finished)\n", );
  fprintf(outfile, "@SP\n", );
  fprintf(outfile, "M=M+1\n", );

} /* -----  end of function _lt  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _and
 *  Description:  
 * =====================================================================================
 */
void _and(outfile) {
  // sp--, because sp points above the top element of the stack.
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P1
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "D=M\n"); // D = M[A] = M[*SP] = **SP = *DATA

  // sp--
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P2
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "A=M\n"); // A = M[A] = M[*SP] = **SP = *DATA

  // perform operations on operands
  fprintf(outfile, "D=D&A\n");

  // push result
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n", );
  fprintf(outfile, "M=D\n", );
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M+1\n"); // *SP = *SP + 1
} /* -----  end of function _and  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _or
 *  Description:  
 * =====================================================================================
 */
void _or(outfile) {
  // sp--, because sp points above the top element of the stack.
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P1
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "D=M\n"); // D = M[A] = M[*SP] = **SP = *DATA

  // sp--
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P2
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "A=M\n"); // A = M[A] = M[*SP] = **SP = *DATA

  // perform operations on operands
  fprintf(outfile, "D=D|A\n");

  // push result
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n", );
  fprintf(outfile, "M=D\n", );
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M+1\n"); // *SP = *SP + 1

} /* -----  end of function _or  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  _not
 *  Description:  
 * =====================================================================================
 */
void _not(outfile) {
  // sp--, because sp points above the top element of the stack.
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P1
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "D=M\n"); // D = M[A] = M[*SP] = **SP = *DATA

  // sp--
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M-1\n"); // *SP = *SP - 1
  // take out the first element, P2
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n"); // A = M[0] = *SP
  fprintf(outfile, "A=M\n"); // A = M[A] = M[*SP] = **SP = *DATA

  // perform operations on operands
  fprintf(outfile, "D=!D\n");

  // push result
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n", );
  fprintf(outfile, "M=D\n", );
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "M=M+1\n"); // *SP = *SP + 1
} /* -----  end of function _not  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  writeArithmetic
 *  Description:  Write to the output file the assembly code that
 *                implements the given arithmetic-logical command. 
 * =====================================================================================
 */
void writeArithmetic(const char *command, FILE *outfile) {
#if DISPLAY_SCR
  outfile = stdout;
#endif
  // Get the command type dynamically
  const enum ArithmrticCommand arithmeticcommandType =
      getArithmeticCommandType(command);

  // Use a switch statement to handle each arithmetic-logical command
  switch (arithmeticcommandType) {
  case C_ADD:
    // Generate code for 'add' operation
    // fprintf(outfile, "// Code for 'add' operation\n");
    _add(outfile);
    break;
  case C_SUB:
    _sub(outfile);
    break;
  case C_NEG:
    _neg(outfile);
    break;
  case C_EQ:
    _eq(outfile);
    break;
  case C_GT:
    _gt(outfile);
    break;
  case C_LT:
    _lt(outfile);
    break;
  case C_AND:
    _and(outfile);
    break;
  case C_OR:
    _or(outfile);
    break;
  case C_NOT:
    _not(outfile);
    break;
  default:
    // is not ari-cmd
  }
} /* -----  end of function writeArithmetic  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  writePushPop
 *  Description:  Write to the output file the assembly code that implements 
 *                the given push or pop command. 
 * =====================================================================================
 */
void writePushPop(int commandType, const char *segment, int index, FILE* outfile) {
#if DISPLAY_SCR
  outfile = stdout;
#endif
  fprintf(outfile, "VM vommand is: %d %s %d\n", commandType, segment, index);
  // store arg2
  fprintf(outfile, "@%d\n", index); // @index
  fprintf(outfile, "D=A\n");        // D=A
  // push or pop
  fprintf(outfile, "@SP\n");
  fprintf(outfile, "A=M\n");
  fprintf(outfile, "M=D\n");
  fprintf(outfile, "@SP\n");
  if (commandType == C_PUSH)
    fprintf(outfile, "M=M+1\n"); // push
  if (commandType == C_POP)
    fprintf(outfile, "M=M-1\n"); // pop
} /* -----  end of function writePushPop  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  close
 *  Description:  Close the output file/stream. 
 * =====================================================================================
 */
void close(outfile) {
  flose(outfile);
} /* -----  end of function close  ----- */
