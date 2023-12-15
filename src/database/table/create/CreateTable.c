#include "CreateTable.h"
#include "../../DatabaseStructures.c"
#include <stdio.h>
#include <stdlib.h> 

void CreateTable(Database *db) {
    if (db->numTables < MAX_TABLES) {
        Table *table = &(db->tables[db->numTables]);
        printf("Informe o nome da tabela: ");
        scanf("%s", table->name);

        table->numColumns = 0;

        printf("Informe o nome da coluna primarykey: ");
        scanf("%s", table->columns[table->numColumns].name);

        // Define automaticamente o tipo da primeira coluna como "int"
        strcpy(table->columns[table->numColumns].type, "int");
        table->numColumns++;
 
        int numAdditionalColumns;

        while (1) {
            printf("Informe o número de colunas adicionais (int): ");
            if (scanf("%d", &numAdditionalColumns) == 1 && numAdditionalColumns >= 0) {
                break;
            } else {
                printf("Por favor, insira um número inteiro válido para o número de colunas adicionais.\n");
                while (getchar() != '\n');  
            }
        }

        for (int i = 0; i < numAdditionalColumns; i++) {
            printf("Informe o nome da coluna %d: ", i + 2);
            scanf("%s", table->columns[table->numColumns].name);

            do {
                printf("Informe o tipo da coluna %d (char, int, float, double, string): ", i + 2);
                scanf("%s", table->columns[table->numColumns].type);
            } while (strcmp(table->columns[table->numColumns].type, "char") != 0 &&
                     strcmp(table->columns[table->numColumns].type, "int") != 0 &&
                     strcmp(table->columns[table->numColumns].type, "float") != 0 &&
                     strcmp(table->columns[table->numColumns].type, "double") != 0 &&
                     strcmp(table->columns[table->numColumns].type, "string") != 0);

            table->numColumns++;
        }

        printf("Chave primária definida como: %s\n", table->columns[0].name);

        table->numTuples = 0;
        db->numTables++;
        printf("Tabela criada com sucesso.\n");
    } else {
        printf("Número máximo de tabelas atingido.\n");
    }
}
