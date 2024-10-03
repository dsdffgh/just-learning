#include "Symbol_Table.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "check.h"
// #include <regex.h>

#define FILE_PATH "Rect"
#define INPUT_FILE_PATH FILE_PATH ".asm"
char *checkOutFile = "check_" FILE_PATH ".txt";

struct InstructionMap
{
    char instruction[5];
    char binaryCode[8];
};

struct InstructionMap instructionMappings[] = {
    {"0", "101010"},
    {"1", "111111"},
    {"-1", "111010"},
    {"D", "001100"},
    {"A", "110000"},
    {"!D", "001101"},
    {"!A", "110001"},
    {"-D", "001111"},
    {"-A", "110011"},
    {"D+1", "011111"},
    {"A+1", "110111"},
    {"D-1", "001110"},
    {"A-1", "110010"},
    {"D+A", "000010"},
    {"D-A", "010011"},
    {"A-D", "000111"},
    {"D&A", "000000"},
    {"D|A", "010101"},
};

/*
 * First pass: The assembler goes through the entire assembly program, line
 * by line, keeping track of the line number. This number starts at 0 and is
 * incremented by 1 whenever an A-instruction or a C-instruction is
 * encountered, but does not change when a comment or a label declaration is
 * encountered. Each time a label declaration (xxx) is encountered, the
 * assembler adds a new entry to the symbol table, associating the symbol xxx
 * with the current line number plus 1 (this will be the ROM address of the
 * next instruction in the program).
 */

/*
 * A symbol can be any sequence of letters, digits, underscore (_),
 * dot (.), dollar sign ($), and colon (:) that does not begin with a digit.
 */
#if 1
int isSymbolValid(char *symbol)
{
    // check if the first character is a digit
    if (symbol[0] >= '0' && symbol[0] <= '9')
    {
        return false;
    }
    // check if the symbol contains invalid characters
    for (int i = 0; i < strlen(symbol); i++)
    {
        if (!((symbol[i] >= '0' && symbol[i] <= '9') ||
              (symbol[i] >= 'a' && symbol[i] <= 'z') ||
              (symbol[i] >= 'A' && symbol[i] <= 'Z') ||
              symbol[i] == '_' || symbol[i] == '.' ||
              symbol[i] == '$' || symbol[i] == ':'))
        {
            return false;
        }
    }
    return true;
}
#else
int isSymbolValid(char *symbol)
{
    regex_t regex;
    int reti = regcomp(&regex, "^[^0-9][a-zA-Z0-9_.$:]*$", 0);

    if (reti)
    {
        fprintf(stderr, "Could not compile regex\n");
        return 0;
    }

    reti = regexec(&regex, symbol, 0, NULL, 0);
    regfree(&regex);

    if (!reti)
    {
        return 1; // vaild
    }
    else
    {
        return 0; // invalid
    }
}
#endif

// (xxx) is a label declaration
bool isLabelSymbol(char *line)
{
    if (strstr(line, "(") != NULL && strstr(line, ")") != NULL)
    {
        return true;
    }
    else
        return false;
}

bool isVarSymbol(symbol_table *TABLE, char *var_begin)
{
    if (Search_Symbol(TABLE, var_begin) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isPredefinedSymbol()
{
}

bool is_A_ins(char *line)
{
    return strstr(line, "@") != NULL;
}

bool is_C_ins(char *line)
{
    return strstr(line, "=") != NULL || strstr(line, ";") != NULL;
}

void handleLabelSymbol(symbol_table *TABLE, char *line, int value)
{
    // ignore the '(' and ')'
    char *newLabel = strtok(line, "()");
    // check if the symbol is valid
    if (isSymbolValid(newLabel))
    {
        // add a new entry to the symbol table
        Insert_Symbol(TABLE, newLabel, value);
    }
    else
    {
        // throw an error
    }
}

// Comments may appear on a separate line or later in the code
bool handleComments(char *line)
{
    char *commentStart = strstr(line, "//");
    if (commentStart != NULL)
    {
        // truncate the comment part
        *commentStart = '\0';
    }
    if (*line == '\0')
        return true;
    else
        return false;
}

bool isWhiteLine(char *line)
{
    if (strspn(line, " \t\n\r") == strlen(line))
    {
        return true;
    }
    else
        return false;
}

void removeSpaces(char *str)
{
    int j = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ')
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

void firstPass(FILE *fp, symbol_table *TABLE)
{
    int lineNumber = -1;
    char *newLabel = NULL;

    // traversal the file by line
    // Allocate an array to store the line
    char line[100];

    // Read lines from the file
    while (fgets(line, 100, fp) != NULL)
    {
        // Remove trailing newline characters
        line[strcspn(line, "\n")] = '\0';
        // Ignore white line
        if (handleComments(line) || isWhiteLine(line))
        {
            continue;
        }
        // Remove spaces
        removeSpaces(line);

        // if it is a label declaration
        if (isLabelSymbol(line))
        {
            handleLabelSymbol(TABLE, line, lineNumber + 1);
        }
        // if it is a A-instruction or C-instruction
        else
        {
            if (is_A_ins(line) || is_C_ins(line))
            {
                lineNumber++;
            }
        }
        // Clear line after operate
        memset(line, 0, sizeof(line));
    }
    free(newLabel); // free the memory (if any) allocated by malloc
    newLabel = NULL;
}

/*
 * Second pass: The assembler goes again through the entire program and
 * parses each line as follows. Each time an A-instruction with a symbolic
 * reference is encountered, namely, @xxx, where xxx is a symbol and not a
 * number, the assembler looks up xxx in the symbol table. If the symbol is
 * found, the assembler replaces it with its numeric value and completes the
 * instruction’s translation. If the symbol is not found, then it must represent a
 * new variable. To handle it, the assembler (i) adds the entry <xxx, value> to
 * the symbol table, where value is the next available address in the RAM
 * space designated for variables, and (ii) completes the instruction’s
 * translation, using this address. In the Hack platform, the RAM space
 * designated for storing variables starts at 16 and is incremented by 1 after
 * each time a new variable is found in the code.
 */

void *to_binary(char *binary, int n, FILE *outFile, FILE *checkout)
{
    static int hack_line = 1;
    binary[16] = '\0';
    for (int i = 15; i >= 0; --i)
    {
        binary[i] = (n & 1) + '0'; // n - lowest bit
        n >>= 1;
    }
    if (checkout != NULL)
    {
        fprintf(checkout, "%d-----%s\n", hack_line, binary);
    }
    else
    {
        printf("%d-----%s\n", hack_line, binary);
    }
    fprintf(outFile, "%s\n", binary);
    hack_line++;
}

char *getBinaryCode(const char *instruction)
{
    for (int i = 0; i < sizeof(instructionMappings) / sizeof(instructionMappings[0]); ++i)
    {
        if (strcmp(instructionMappings[i].instruction, instruction) == 0)
        {
            return instructionMappings[i].binaryCode;
        }
    }
    return NULL; // none of the instructions matched
}

// A-ins like @xxx, such as @123, @string_label
// A-ins (binary) like 0xxxxxxxxxxxxxxx (15-bit is vaild)
void handle_A_ins(symbol_table *TABLE, char *line, FILE *outFile, FILE *checkout)
{
    char *ins_begin = strstr(line, "@") + 1;
    int value = 0;
    // if it is a constant (0-32767 is vaild) like @123, but not @0string
    if (strspn(ins_begin, "0123456789") == strlen(ins_begin))
    {
        // convert the string to int
        value = atoi(ins_begin);

        if (value < 0 || value > 32767)
        {
            // throw an error
        }
    }
    // if it is a symbol
    else
    {
        value = Search_Symbol(TABLE, ins_begin);
        // it is a new variable, add it to the symbol table
        if (value < 0)
        {
            value = Insert_Symbol(TABLE, ins_begin, TABLE->varNum + ROM_NUM);
            TABLE->varNum++;
        }
        // if found, it is a predefined symbol or Label
        else
        {
            // do nothing
        }
    }
    if (checkout != NULL)
    {
        fprintf(checkout, "A-ins\n");
    }
    else
    {
        printf("A-ins\n");
    }

    // convert the int to binary
    char *binary = (char *)malloc(sizeof(char) * 16);
    to_binary(binary, value, outFile, checkout);

    // print the binary
    free(binary);
}

void handle_C_jump(char *jump_begin, int *value)
{

    // jump is a sequence of JGT, JEQ, JGE, JLT, JNE, JLE, JMP
    if (strcmp(jump_begin, "JGT") == 0)
    {
        *value |= 1;
    }
    else if (strcmp(jump_begin, "JEQ") == 0)
    {
        *value |= 2;
    }
    else if (strcmp(jump_begin, "JGE") == 0)
    {
        *value |= 3;
    }
    else if (strcmp(jump_begin, "JLT") == 0)
    {
        *value |= 4;
    }
    else if (strcmp(jump_begin, "JNE") == 0)
    {
        *value |= 5;
    }
    else if (strcmp(jump_begin, "JLE") == 0)
    {
        *value |= 6;
    }
    else if (strcmp(jump_begin, "JMP") == 0)
    {
        *value |= 7;
    }
    else
    {
        // throw an error
    }
}
void handle_C_comp(char *comp_begin, int *value)
{
    if (strstr(comp_begin, "M") != NULL)
    {
        *value |= 1 << 12;
        char *MtoA = strstr(comp_begin, "M");
        *MtoA = 'A';
    }
    else
    {
        // 12-bit is 0, a = 0
        // do nothing
    }
    // set value_comp bit by getBinaryCode(comp_begin)
    char *binaryCode = getBinaryCode(comp_begin);
    if (binaryCode == NULL)
    {
        // throw an error
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            if (binaryCode[i] == '1')
            {
                *value |= 1 << (11 - i);
            }
        }
    }
}
void handle_C_dest(char *dest_begin, int *value)
{
    // dest is a sequence of A, D, M
    if (strstr(dest_begin, "A") != NULL)
    {
        *value |= 1 << 5;
    }
    if (strstr(dest_begin, "D") != NULL)
    {
        *value |= 1 << 4;
    }
    if (strstr(dest_begin, "M") != NULL)
    {
        *value |= 1 << 3;
    }
}

/*
 * C-ins like dest=comp;jump, such as D=M+1;JGT
 * dest is optional, comp is required, jump is optional
 * dest is a sequence of A, D, M, or null
 * comp is a sequence of 1-3 characters in the set {A, M, D, 0, 1, !, -, +, &, |}
 * jump is a sequence of JGT, JEQ, JGE, JLT, JNE, JLE, JMP, or null
 * dest=comp;jump
 * dest=comp
 * comp;jump
 * comp
 * C-ins (binary) like 111accccccdddjjj
 *
 * Ignore white space; d,c,j all have 1-3 bits
 */
void handle_C_ins(char *line, FILE *outFile, FILE *checkout)
{
    int value = 0;
    value |= 111 << 13;

    // Find the positions of = and ; respectively
    char *pos_equal = strstr(line, "=");
    char *pos_semicolon = strstr(line, ";");
    // If there is no ;, jump is null
    if (pos_semicolon == NULL)
    {
        value &= ~7;
    }
    else
    {
        handle_C_jump(pos_semicolon + 1, &value);
        *pos_semicolon = '\0';
    }
    // If there is no =, dest is null
    if (pos_equal == NULL)
    {
        value &= ~(7 << 3);
        handle_C_comp(line, &value);
    }
    else
    {
        handle_C_comp(pos_equal + 1, &value);
        *pos_equal = '\0';
        handle_C_dest(line, &value);
    }

    // convert the int to binary
    char *binary = (char *)malloc(sizeof(char) * 16);

    // print the binary
    if (checkout != NULL)
    {
        fprintf(checkout, "A-ins\n");
    }
    else
    {
        printf("A-ins\n");
    }
    to_binary(binary, value, outFile, checkout);
    free(binary);
}

void SecondPass(FILE *fp, symbol_table *TABLE, FILE *outFile, FILE *checkout)
{
    // traversal the file by line
    // Allocate an array to store the line
    char line[100];

    // Read lines from the file
    while (fgets(line, 100, fp) != NULL)
    {
        // Remove trailing newline characters
        line[strcspn(line, "\n")] = '\0';

        line[strcspn(line, "\r")] = '\0';
        // Ignore white line
        if (handleComments(line) || isWhiteLine(line))
        {
            continue;
        }
        // Remove spaces
        removeSpaces(line);

        if (is_A_ins(line))
        {
            handle_A_ins(TABLE, line, outFile, checkout);
        }
        else if (is_C_ins(line))
        {
            handle_C_ins(line, outFile, checkout);
        }
    }
}

void writeInstructionsToFile(const char *filePath)
{
    FILE *out = fopen(filePath, "w");
    if (out == NULL)
    {
        perror("Error opening file for writing");
        return; // Handle the error accordingly
    }

    //    for (int i = 0; i < instructionCount; ++i) {
    //        fprintf(out, "%s\n", binaryInstructions[i]);
    //    }

    fclose(out);
}

/*int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    const char *inputFileName = argv[1];
    // The assembler creates a symbol table and initializes it
    symbol_table *TABLE = Init_symbol_table();

    FILE *in = fopen(inputFileName, "r");
    if (in == NULL)
    {
        perror("Error opening file");
        return 1; // Exit with an error code
    }
    firstPass(in, TABLE);
    // test Symbol Table
    Print_Table(TABLE);
    fclose(in);
}*/

int main()
{
    char *checkFile1 = FILE_PATH ".hack";
    char *checkFile2 = FILE_PATH "1.hack";
    // The assembler creates a symbol table and initializes it
    symbol_table *TABLE = Init_symbol_table();
    // test Symbol Table
    // Print_Table(TABLE);

    FILE *out = fopen(checkFile1, "w");
    if (out == NULL)
    {
        perror("Error opening file for writing");
        return 1; // Handle the error accordingly
    }
    FILE *checkout = NULL; // fopen(checkOutFile, "w");
    if (checkout == NULL)
    {
        perror("Error opening file for writing");
        // return 1; // Handle the error accordingly
    }

    // test firstPass
    FILE *in = fopen(INPUT_FILE_PATH, "r");
    if (in == NULL)
    {
        perror("Error opening file");
        return 1; // Exit with an error code
    }
    firstPass(in, TABLE);
    // test Symbol Table
    // Print_Table(TABLE);
    fclose(in);
    // test secondPass
    FILE *in2 = fopen(INPUT_FILE_PATH, "r");
    if (in2 == NULL)
    {
        perror("Error opening file");
        return 1; // Exit with an error code
    }
    SecondPass(in2, TABLE, out, checkout);
    // test Symbol Table
    // Print_Table(TABLE);
    fclose(in2);

    fclose(out);

    // check(checkFile1, checkFile2, checkout);
}