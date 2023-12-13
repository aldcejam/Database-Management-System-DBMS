#include "ListTableData.h"
#include "../../../DatabaseStructures.c"


void ListTableData(Database *db) {
    char tableName[MAX_STRING_SIZE];
    printf("Informe o nome da tabela para listar os dados: ");
    scanf("%s", tableName);

    Table *table = NULL;
    for (int i = 0; i < db->numTables; i++) {
        if (strcmp(db->tables[i].name, tableName) == 0) {
            table = &(db->tables[i]);
            break;
        }
    }

    if (table != NULL) {
        printf("Dados da tabela %s:\n", tableName);
        for (int i = 0; i < table->numTuples; i++) {
            printf("Tuple %d (Primary Key: %u):\n", i + 1, table->tuples[i].primaryKey);
            for (int j = 0; j < table->numColumns; j++) {
                printf("  %s: %s\n", table->columns[j].name, table->tuples[i].data[j]);
            }
        }
    } else {
        printf("Tabela %s não encontrada.\n", tableName);
    }
}