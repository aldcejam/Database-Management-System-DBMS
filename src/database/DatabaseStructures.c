#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLES 100
#define MAX_COLUMNS 100
#define MAX_STRING_SIZE 100
 
typedef struct {
    char name[MAX_STRING_SIZE];
    char type[MAX_STRING_SIZE];
} Column;
 
typedef struct {
    unsigned int primaryKey;
    char **data;  
} Tuple;
 
typedef struct {
    char name[MAX_STRING_SIZE];
    Column columns[MAX_COLUMNS];
    int numColumns;
    Tuple *tuples;
    int numTuples;
} Table;
 
typedef struct {
    Table tables[MAX_TABLES];
    int numTables;
} Database;