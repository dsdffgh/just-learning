/*
 * =====================================================================================
 *
 *       Filename:  Parser.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/04/23 21:20:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonessssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef  parser_INC
#define  Parser_INC

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define C_ARITHMETIC 255
#define C_PUSH 254
#define C_POP 253
#define C_LABEL 252
#define C_GOTO 252
#define C_IF 252
#define C_FUNCTION 251
#define C_RETURN 250
#define C_CALL 249
#define commandMaxSize 20 /* the max length of command */
#define lineMaxSize 256   /* the max length of the lines of **.vm  */


FILE* InputInitializer( const char* filename );
bool hasMoreLines(FILE *file);
bool isArithmeticLogicalCommand(char *command);
int commandType(char *command);
void advance(FILE *file, char *currentCommand);
char *arg1(char *command, int Type);
int arg2(char *command, int Type);

#endif   /* ----- #ifndef Parser_INC  ----- */
