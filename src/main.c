#include <stdio.h> 
#include "database/table/create/CreateTable.h"
#include "database/table/list/ListTable.h"
#include "database/DatabaseStructures.c"

int main() {
    printf("Olá do arquivo main.c!\n");
  
    Database myDatabase; 
    myDatabase.numTables = 0;

    CreateTable(&myDatabase);
    ListTable(&myDatabase);

    return 0;
}