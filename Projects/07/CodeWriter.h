/*
 * =====================================================================================
 *
 *       Filename:  CodeWriter.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/23 17:05:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef  codewriter_INC
#define  CodeWriter_INC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parser.h"

#define DEBUG 1          /* show vm command to debug */
#define DISPLAY_SCR 0    /* print information on screen */

// Enum for arithmetic command types
enum ArithmrticCommand {
    C_ADD, /* integer addition */
    C_SUB, /* integer subtraction */
    C_NEG, /* arithmetic ngation */
    C_EQ, /* equality */
    C_GT, /* greater than */
    C_LT, /* less than */
    C_AND, /* bite-wise And */
    C_OR, /* bite-wise Or */
    C_NOT, /* bite-wise Not */
    C_UNKNOWN // Default for unsupported commands
};


enum ArithmrticCommand getArithmeticCommandType(const char* command);
void _add(outfile);
void _sub(outfile);
void _neg(outfile);
void _eq(outfile);
void _gt(outfile);
void _lt(outfile);
void _and(outfile);
void _or(outfile);
void _not(outfile);
void writeArithmetic(const char *command, FILE *outfile);
void writePushPop(int commandType, const char *segment, int index, FILE* outfile);
void close(outfile);

#endif   /* ----- #ifndef CodeWriter_INC  ----- */
