/*
 * =====================================================================================
 *
 *       Filename:  Parser.c
 *
 *    Description:  This module handles the parsing of a single .vm file.
 *                  The parser provides services for reading a VM command,
 *                  unpacking the command into its various components,
 *                  and providing convenient access to these components.
 *                  In addition, the parser ignores all white space and
 *                  comments. For example, if the current command is push
 *                  local 2, then calling arg1() and arg2() would return,
 *                  respectively, "local" and 2. If the current command is
 *                  add, then calling arg1() would return "add", and
 *                  arg2() would not be called.
 *
 *        Version:  1.0
 *        Created:  11/21/23 10:29:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonesssssssss (), whyunotdo@qq.com
 *   Organization:
 *
 * =====================================================================================
 */

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

// Define an array of valid arithmetic-logical commands
const char *arithmeticCommands[] = {"add", "sub", "neg", "eq", "and",
                                    "or", "not", "gt", "lt"};

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  InputInitializer
 *  Description:  Opens the input file / stream,and fets ready to parse it.
 * =====================================================================================
 */
void *InputInitializer(FILE* openedfile, const char *filename)
{
  FILE *openedfile = fopen(filename ".vm", "r");
  if (openedfile == NULL)
  {
    printf("Error opening vm file : ***.vm!\n");
    return 1;
  }
} /* -----  end of function InputInitializer  ----- */

#if 0
/*
 * ===  FUNCTION  ======================================================================
 *         Name:  hasMoreLines
 *  Description:  Are there more lines in the inputs?
 *                read char
 * =====================================================================================
 */
    bool
hasMoreLines ( FILE *file )
{
    // save the current position of file
    long currentPostion = ftell(file);

    // read a char
    char ch = fgetc(file);

    // Restore to original position
    fseek(file, currentPostion, SEEK_SET);

    // If EOF is read, there are no more rows 
    if ( ch != EOF )    return true;
    else    return false;
}		/* -----  end of function hasMoreLines  ----- */
#else
/*
 * ===  FUNCTION  ======================================================================
 *           Name:  hasMoreLines
 *    Description:  Are there more lines in the inputs? read line
 * =====================================================================================
 */
bool hasMoreLines(FILE *file)
{
  // save the current position of file
  long currentPosition = ftell(file);

  // read a line
  char line[lineMaxSize];
  char *result = fgets(line, sizeof(line), file);

  // restore to original position
  fseek(file, currentPosition, SEEK_SET);

  // if result is NULL, there are no more lines
  return result != NULL;
} /* -----  end of function hasMoreLines  ----- */
#endif

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  isArithmeticLogicalCommand
 *  Description:  Checks if the given command is an
 *                arithmetic-logical command.
 * =====================================================================================
 */
bool isArithmeticLogicalCommand(char *command)
{
  for (int i = 0;
       i < sizeof(arithmeticCommands) / sizeof(arithmeticCommands[0]); ++i)
  {
    if (strcmp(command, arithmeticCommands[i]) == 0)
    {
      return true;
    }
  }
  return false;
}

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  commandType
 *  Description:  Returns a constant representing the type of the
 *                current command. If the current command is an
 *                arithmetic-logical command,returns C_ARITHMETIC.
 * =====================================================================================
 */
int commandType(char *command)
{
  // get command from lines
  char *commandType = strtok(command, " ");
  // if it is stack command : push or pop
  if (strstr(commandType, "push") != NULL)
  {
    return C_PUSH;
  }
  if (strstr(commandType, "pop") != NULL)
  {
    return C_POP;
  }
  // if it is arithmetic-logical command
  if (isArithmeticLogicalCommand(commandType))
  {
    return C_ARITHMETIC;
  }
  // others
  /***********************
   * undone
   ************************/
} /* -----  end of function commandType  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  advance
 *  Description:  Reads the next command from the input and makes it the
 *                current command. This routine should be called only if
 *                hasMoreLines is true.
 *                Initially there is no current command.
 * =====================================================================================
 */
void advance(FILE *file, char *currentCommand)
{
  if (hasMoreLines(file))
  {
    fgets(currentCommand, lineMaxSize, file);
  }
} /* -----  end of function advance  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  arg1
 *  Description:  returns the first argument of the current command. In the
 *                case of C_ARITHMETIC,the command itself (add,sub,etc)
 *                Should not be called if the current command is C_RETURN.
 * =====================================================================================
 */
char *arg1(char *command, int Type)
{
  if (Type == C_RETURN)
    return NULL; /* should not be called */
  else if (Type == C_ARITHMETIC)
    return command;
  else
  {
    char *token = strtok(command, " ");
    token = strtok(NULL, " ");
    return token;
  }
} /* -----  end of function arg1  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  arg2
 *  Description:  Returns the second argument of the current command. Should
 *                be called only if the current command is C_PUSH,C_POP,
 *                C_FUNCTION,or C_CALL.
 * =====================================================================================
 */
int arg2(char *command, int Type)
{
  if (Type == C_PUSH ||
      Type == C_POP ||
      Type == C_FUNCTION ||
      Type == C_CALL)
  {
    char *token = strtok(command, " ");
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    if (token != NULL)
      return token;
    else
      return -1; /* a error  */
  }
  else
    return -1; /* should not be called */
} /* -----  end of function arg2  ----- */
