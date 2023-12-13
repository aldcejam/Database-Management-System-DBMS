#include "CreateTable.h"
#include "../../DatabaseStructures.c"
#include <stdio.h>

void CreateTable(Database *db) {
    if (db->numTables < MAX_TABLES) {
        Table *table = &(db->tables[db->numTables]);
        printf("Informe o nome da tabela: ");
        scanf("%s", table->name);

        printf("Informe o número de colunas: ");
        scanf("%d", &(table->numColumns));
 
        for (int i = 0; i < table->numColumns; i++) {
            printf("Informe o nome da coluna %d: ", i + 1);
            scanf("%s", table->columns[i].name);

            printf("Informe o tipo da coluna %d (char, int, float, double, string): ", i + 1);
            scanf("%s", table->columns[i].type);
        }
 
        printf("Informe o nome da coluna para ser a chave primária: ");
        char primaryKeyColumn[MAX_STRING_SIZE];
        scanf("%s", primaryKeyColumn);

        for (int i = 0; i < table->numColumns; i++) {
            if (strcmp(table->columns[i].name, primaryKeyColumn) == 0 &&
                strcmp(table->columns[i].type, "int") == 0) {
                printf("Chave primária definida como: %s\n", primaryKeyColumn);
                break;
            } else if (i == table->numColumns - 1) {
                printf("Coluna especificada não é válida para chave primária ou não é do tipo inteiro sem sinal.\n");
                exit(EXIT_FAILURE);
            }
        }
 
        table->numTuples = 0;
        db->numTables++;
        printf("Tabela criada com sucesso.\n");
    } else {
        printf("Número máximo de tabelas atingido.\n");
    }
}