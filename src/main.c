#include <stdio.h> 
#include "database/DatabaseStructures.c"
#include "database/table/create/CreateTable.h"
#include "database/table/list/ListTable.h"
#include "database/table/insert/InsertTuple.h"

int main() {
    printf("Olá do arquivo main.c!\n");
  
    Database myDatabase; 
    myDatabase.numTables = 0;

    CreateTable(&myDatabase);
    ListTable(&myDatabase);
    InsertTuple(&myDatabase);

    return 0;
}