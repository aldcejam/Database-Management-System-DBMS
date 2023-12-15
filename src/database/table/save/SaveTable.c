#include "SaveTable.h"
#include "../../DatabaseStructures.c"

void printSeparatorToFile(FILE *file, int *columnWidths, int numColumns) {
    for (int i = 0; i < numColumns; i++) {
        for (int j = 0; j < columnWidths[i] + 2; j++) {
            fprintf(file, "-");
        } 
    }
    fprintf(file, "\n");
}

void SaveTable(Database *db) {
    char tableName[MAX_STRING_SIZE];
    printf("Informe o nome da tabela para salvar os dados: ");
    scanf("%s", tableName);

    Table *table = NULL;
    for (int i = 0; i < db->numTables; i++) {
        if (strcmp(db->tables[i].name, tableName) == 0) {
            table = &(db->tables[i]);
            break;
        }
    }

    if (table != NULL) {
        char fileName[100];
        strcpy(fileName, "src/tablesCreated/");
        strcpy(fileName, tableName);
        FILE *file = fopen(strcat(fileName, ".txt"), "w");

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
            fprintf(file, "%-*s", columnWidths[i], table->columns[i].name);
            if (i < table->numColumns - 1) {
                fprintf(file, "  ");
            }
        }
        fprintf(file, "\n");

        printSeparatorToFile(file, columnWidths, table->numColumns);

        for (int i = 0; i < table->numTuples; i++) {
            for (int j = 0; j < table->numColumns; j++) {
                fprintf(file, "%-*s", columnWidths[j], table->tuples[i].data[j]);
                if (j < table->numColumns - 1) {
                    fprintf(file, "  ");
                }
            }
            fprintf(file, "\n");
        }

        fclose(file);  
        printf("Dados salvos com sucesso.\n");
    } else {
        printf("Tabela %s não encontrada.\n", tableName);
    }
}
