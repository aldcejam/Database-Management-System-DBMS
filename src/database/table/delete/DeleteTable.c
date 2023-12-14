#include "DeleteTable.h"
#include "../../DatabaseStructures.c"

void DeleteTable(Database *db) {
    char tableName[MAX_STRING_SIZE];
    printf("Informe o nome da tabela para apagar: ");
    scanf("%s", tableName);

    int tableIndex = -1;

 
    for (int i = 0; i < db->numTables; i++) {
        if (strcmp(db->tables[i].name, tableName) == 0) {
            tableIndex = i;
            break;
        }
    }

    if (tableIndex != -1) { 
        for (int i = 0; i < db->tables[tableIndex].numTuples; i++) {
            for (int j = 0; j < db->tables[tableIndex].numColumns; j++) {
                free(db->tables[tableIndex].tuples[i].data[j]);
            }
            free(db->tables[tableIndex].tuples[i].data);
        }
        free(db->tables[tableIndex].tuples);

        for (int i = tableIndex; i < db->numTables - 1; i++) {
            db->tables[i] = db->tables[i + 1];
        }

        db->numTables--;
        printf("Tabela %s apagada com sucesso.\n", tableName);
    } else {
        printf("Tabela %s não encontrada.\n", tableName);
    }
}
