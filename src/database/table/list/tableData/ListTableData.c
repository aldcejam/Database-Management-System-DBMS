#include "ListTableData.h"
#include "../../../DatabaseStructures.c"

void printSeparator(int *columnWidths, int numColumns) {
    for (int i = 0; i < numColumns; i++) {
        for (int j = 0; j < columnWidths[i] + 2; j++) {
            printf("-");
        }
        if (i < numColumns - 1) {
            printf("  ");
        }
    }
    printf("\n");
}

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
        int columnWidths[table->numColumns];

        for (int i = 0; i < table->numColumns; i++) {
            columnWidths[i] = strlen(table->columns[i].name);
            for (int j = 0; j < table->numTuples; j++) {
                int len = strlen(table->tuples[j].data[i]);
                if (len > columnWidths[i]) {
                    columnWidths[i] = len;
                }
            }
        }

        for (int i = 0; i < table->numColumns; i++) {
            printf("%-*s", columnWidths[i], table->columns[i].name);
            if (i < table->numColumns - 1) {
                printf("  ");
            }
        }
        printf("\n");
 
        printSeparator(columnWidths, table->numColumns);
 
        for (int i = 0; i < table->numTuples; i++) {
            for (int j = 0; j < table->numColumns; j++) {
                printf("%-*s", columnWidths[j], table->tuples[i].data[j]);
                if (j < table->numColumns - 1) {
                    printf("  ");
                }
            }
            printf("\n");
        }
    } else {
        printf("Tabela %s não encontrada.\n", tableName);
    }
}
