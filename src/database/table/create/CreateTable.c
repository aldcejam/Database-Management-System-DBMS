#include "CreateTable.h"
#include "../../DatabaseStructures.c"
#include <stdio.h>

void CreateTable(Database *db) {
    if (db->numTables < MAX_TABLES) {
        Table *table = &(db->tables[db->numTables]);
        printf("Informe o nome da tabela: ");
        scanf("%s", table->name);
 
        table->numColumns = 0;
 
        printf("Informe o nome da coluna 1/primarykey: ");
        scanf("%s", table->columns[table->numColumns].name);
        strcpy(table->columns[table->numColumns].type, "int");  
        table->numColumns++;
 
        printf("Informe o número de colunas adicionais: ");
        int numAdditionalColumns;
        scanf("%d", &numAdditionalColumns);

        for (int i = 0; i < numAdditionalColumns; i++) {
            printf("Informe o nome da coluna %d: ", i + 2);   
            scanf("%s", table->columns[table->numColumns].name);

            printf("Informe o tipo da coluna %d (char, int, float, double, string): ", i + 2);
            scanf("%s", table->columns[table->numColumns].type);

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
