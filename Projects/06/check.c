//
// Created by name on 2023/11/7.
//

#include "check.h"
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 20

int check(char *file_check_dest, char *file_check_sourse, FILE *checkout)
{
    FILE *file1 = fopen(file_check_dest, "r");
    if (file1 == NULL)
    {
        printf("Error opening target file : ***.cmp!\n");
        return 1;
    }

    FILE *file2 = fopen(file_check_sourse, "r");
    if (file2 == NULL)
    {
        printf("Error opening source file : **.hack!\n");
        fclose(file1); // If file2 fails to open, close the already opened file1
        return 1;
    }

    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];
    int line_num = 1;
    char wrong = 0;
    while (fgets(line1, sizeof(line1), file1) != NULL && fgets(line2, sizeof(line2), file2) != NULL)
    {
        line1[16] = line2[16] = '\0';
        if (strcmp(line1, line2) != 0)
        {
            if (checkout)
            {
                fprintf(checkout, "Difference found at line %d:\n", line_num);
                fprintf(checkout, "target file : ***.cmp: %s\n", line1);
                fprintf(checkout, "source file : **.hack: %s\n", line2);
            }
            else if(0)
            {
                printf("Difference found at line %d:\n", line_num);
                printf("target file : ***.cmp: %s\n", line1);
                printf("source file : **.hack: %s\n", line2);
            }
            wrong = 1;
        }
        line_num++;
    }

    fclose(file1);
    fclose(file2);

    if (wrong)
    {
        printf("=========================================\n");
        printf("*************lists your errors***********\n");
        printf("=========================================\n");
    }
    else
    {
        printf("=========================================\n");
        printf("********Congratulations, no errors!******\n");
        printf("=========================================\n");
    }

    return 0;
}
