#ifndef __SYMBOL_TABLE_H__
#define __SYMBOL_TABLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SYMBOL_TABLE_SIZE 100
#define PREDEFINED_SYMBOL_NUM 23
#define ROM_NUM 16

typedef struct Pair {
    char name[MAX_SYMBOL_TABLE_SIZE];
    int value;
} symbol_entry;

// symbol table is created to store the names of the variables and their values
typedef struct symbol_table {
    int size;
    int varNum;
    int capacity;
    double loadThres;
    int extendRadio;
    symbol_entry *symbol;
} symbol_table;

symbol_table *Init_symbol_table();

void delete_symbol_table(symbol_table *Table);

double load_factor(symbol_table *Table);

int Search_Symbol(symbol_table *Table, char *name);

int Insert_Symbol(symbol_table *Table, char *name, int NEXTline);

void Extend_Table(symbol_table *Table);

void Print_Table(symbol_table *Table);

#endif