#include "InsertTuple.h"
#include "../../../DatabaseStructures.c"

void InsertTuple(Database *db) {
    char tableName[MAX_STRING_SIZE];
    printf("Informe o nome da tabela para inserir a tupla: ");
    scanf("%s", tableName);

    Table *table = NULL;

    for (int i = 0; i < db->numTables; i++) {
        if (strcmp(db->tables[i].name, tableName) == 0) {
            table = &(db->tables[i]);
            break;
        }
    }

    if (table != NULL) {
        if (table->numTuples < MAX_TABLES) {
            table->tuples = (Tuple *)realloc(table->tuples, (table->numTuples + 1) * sizeof(Tuple));

            Tuple *tuple = &(table->tuples[table->numTuples]);
            tuple->data = (char **)malloc(table->numColumns * sizeof(char *));
 
            printf("Informe o valor para a chave primária (%s): ", table->columns[0].type);
            scanf("%u", &(tuple->primaryKey));
 
            for (int i = 0; i < table->numColumns; i++) {
                tuple->data[i] = (char *)malloc(MAX_STRING_SIZE);
                if (i == 0) { 
                    snprintf(tuple->data[i], MAX_STRING_SIZE, "%u", tuple->primaryKey);
                } else {
                    printf("Informe o valor para a coluna %s (%s): ", table->columns[i].name, table->columns[i].type);
                    scanf("%s", tuple->data[i]);
                }
            }

            table->numTuples++;
            printf("Tupla inserida com sucesso.\n");
        } else {
            printf("Número máximo de tuplas atingido para a tabela %s.\n", tableName);
        }
    } else {
        printf("Tabela %s não encontrada.\n", tableName);
    }
}
