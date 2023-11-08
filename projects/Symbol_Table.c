#include "Symbol_Table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SYMBOL_TABLE_SIZE 100
#define PREDEFINED_SYMBOL_NUM 23
#define ROM_NUM 16

/*
 * @constructor function
 * Predefined symbols:
 * R0, R1, ..., R15 stand for 0, 1, 2, ..., 15
 * SP,LCL,ARG,THIS,THAT stand for 0, 1, 2, 3, 4
 * SCREEN and KBD stand for 16384 and 24576
 * The values of these symbol are interpreted as addresses in Hack RAM
 */

symbol_table *Init_symbol_table() {
    symbol_table *new_table = (symbol_table *) malloc(sizeof(symbol_table));
    new_table->varNum = 0;
    new_table->capacity = 40;
    new_table->loadThres = 0.75;
    new_table->extendRadio = 2;
    symbol_entry *new_symbol = (symbol_entry *) malloc(sizeof(symbol_entry) * new_table->capacity);
    // create predefined symbols
    for (int i = 0; i < ROM_NUM; i++) {
        sprintf(new_symbol[i].name, "R%d", i);
        new_symbol[i].value = i;
    }
    strcpy(new_symbol[16].name, "SP");
    new_symbol[16].value = 0;
    strcpy(new_symbol[17].name, "LCL");
    new_symbol[17].value = 1;
    strcpy(new_symbol[18].name, "ARG");
    new_symbol[18].value = 2;
    strcpy(new_symbol[19].name, "THIS");
    new_symbol[19].value = 3;
    strcpy(new_symbol[20].name, "THAT");
    new_symbol[20].value = 4;
    strcpy(new_symbol[21].name, "SCREEN");
    new_symbol[21].value = 16384;
    strcpy(new_symbol[22].name, "KBD");
    new_symbol[22].value = 24576;
    for (int i = PREDEFINED_SYMBOL_NUM; i < new_table->capacity; i++) {
        strcpy(new_symbol[i].name, "");
        new_symbol[i].value = 0;
    }
    new_table->size = 22;
    new_table->symbol = new_symbol;
    return new_table;
}

void delete_symbol_table(symbol_table *Table) {
    for (int i = 0; i < Table->capacity; i++) {
        free(Table->symbol[i].name);
        free(Table->symbol);
    }
    free(Table->symbol);
    free(Table);
}

double load_factor(symbol_table *Table) {
    return (double) Table->size / (double) Table->capacity;
}

// search symbol, return line number,if not, add it to the symbol table
// the next line is the value of the symbol which is added
int Search_Symbol(symbol_table *Table, char *name) {
    for (int i = 0; i < Table->capacity; i++) {
        if (strcmp(Table->symbol[i].name, name) == 0) {
            return Table->symbol[i].value;
        }
    }
    return -1;
}

int Insert_Symbol(symbol_table *Table, char *newname, int NEXTline) {
    // check load factor > loadThres , extend the table
    if (load_factor(Table) > Table->loadThres) {
        Extend_Table(Table);
    }

    for (int i = Table->size; i < Table->capacity; i++) {
        if (strcmp(Table->symbol[i].name, "") == 0) {
            strcpy(Table->symbol[i].name, newname);
            Table->symbol[i].value = NEXTline;
            Table->size++;
            return Table->symbol[i].value;
        }
    }
}

// extend the table
void Extend_Table(symbol_table *Table) {
    int oldSize = Table->size;
    int oldCapacity = Table->capacity;
    symbol_entry *oldSymbol = Table->symbol;

    Table->capacity *= Table->extendRadio;
    Table->symbol = (symbol_entry *) malloc(sizeof(symbol_entry) * Table->capacity);
    for (int i = 0; i < Table->capacity; i++) {
        strcpy(Table->symbol[i].name, "");
        Table->symbol[i].value = 0;
    }
    Table->size = 0;
    for (int i = 0; i <= oldSize; i++) {
        symbol_entry *tmp = oldSymbol + i;
        Insert_Symbol(Table, tmp->name, tmp->value);
    }
    free(oldSymbol);
}

// print the symbol table
void Print_Table(symbol_table *Table) {
    for (int i = 0; i < Table->capacity; i++) {
        printf("%s %d\n", Table->symbol[i].name, Table->symbol[i].value);
    }
}