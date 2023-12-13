#include "ListTable.h"
#include "../../../DatabaseStructures.c"

void ListTable(Database *db) {
    printf("Tabelas existentes:\n");
    for (int i = 0; i < db->numTables; i++) {
        printf("%s\n", db->tables[i].name);
    }
}