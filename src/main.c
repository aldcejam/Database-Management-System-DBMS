#include <stdio.h> 
#include "database/DatabaseStructures.c"
#include "database/table/create/CreateTable.h"
#include "database/table/list/table/ListTable.h"
#include "database/table/list/tableData/ListTableData.h"
#include "database/table/delete/DeleteTable.h"
#include "database/table/tuple/insert/InsertTuple.h"
#include "database/table/tuple/search/SearchTuple.h"

int main() {
    printf("Olá do arquivo main.c!\n");
  
    Database myDatabase; 
    myDatabase.numTables = 0;

    CreateTable(&myDatabase); 
    InsertTuple(&myDatabase);
    SearchTuple(&myDatabase);  
/*     ListTableData(&myDatabase);
    DeleteTable(&myDatabase);
    ListTable(&myDatabase);
 */
    return 0;
}