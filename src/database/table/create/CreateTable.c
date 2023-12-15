#include "CreateTable.h"
#include "../../DatabaseStructures.c"
#include <stdio.h>
#include <stdlib.h>  // Adicionado para a função atoi

void CreateTable(Database *db) {
    if (db->numTables < MAX_TABLES) {
        Table *table = &(db->tables[db->numTables]);
        printf("Informe o nome da tabela: ");
        scanf("%s", table->name);

        table->numColumns = 0;

        printf("Informe o nome da coluna primarykey: ");
        scanf("%s", table->columns[table->numColumns].name);

        char type[MAX_STRING_SIZE];
        do {
            printf("Informe o tipo da coluna primarykey (int): ");
            scanf("%s", type);
        } while (strcmp(type, "int") != 0);

        strcpy(table->columns[table->numColumns].type, type);
        table->numColumns++;
 
        int numAdditionalColumns;

        // Verificar se a entrada é um número inteiro válido
        while (1) {
            printf("Informe o número de colunas adicionais (int): ");
            if (scanf("%d", &numAdditionalColumns) == 1 && numAdditionalColumns >= 0) {
                break;
            } else {
                printf("Por favor, insira um número inteiro válido para o número de colunas adicionais.\n");
                while (getchar() != '\n');  // Limpar o buffer de entrada
            }
        }

        for (int i = 0; i < numAdditionalColumns; i++) {
            printf("Informe o nome da coluna %d: ", i + 2);
            scanf("%s", table->columns[table->numColumns].name);

            do {
                printf("Informe o tipo da coluna %d (char, int, float, double, string): ", i + 2);
                scanf("%s", type);
            } while (strcmp(type, "char") != 0 && strcmp(type, "int") != 0 && strcmp(type, "float") != 0 &&
                     strcmp(type, "double") != 0 && strcmp(type, "string") != 0);

            strcpy(table->columns[table->numColumns].type, type);
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
