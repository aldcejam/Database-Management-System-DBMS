#include "InsertTuple.h"
#include "../../../DatabaseStructures.c"

int isPrimaryKeyUnique(Table *table, unsigned int primaryKey) {
    // Verificar se a chave primária já existe na tabela
    for (int i = 0; i < table->numTuples; i++) {
        if (table->tuples[i].primaryKey == primaryKey) {
            return 0; // Chave primária não é única
        }
    }
    return 1; // Chave primária é única
}

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
 
            unsigned int primaryKey;
            char buffer[MAX_STRING_SIZE];
            int validInput = 0;

            while (!validInput) {
                printf("Informe o valor para a chave primária (int): ");
                if (scanf("%s", buffer) == 1) {
                    // Tenta converter a entrada para um número inteiro
                    if (sscanf(buffer, "%u", &primaryKey) == 1) {
                        if (isPrimaryKeyUnique(table, primaryKey)) {
                            validInput = 1;
                        } else {
                            printf("Chave primária já existe. Escolha outro valor.\n");
                        }
                    } else {
                        printf("Valor informado não é um número inteiro. Tente novamente.\n");
                    }
                } else {
                    printf("Entrada inválida. Tente novamente.\n");
                    while (getchar() != '\n');  // Limpar o buffer de entrada
                }
            }

            tuple->primaryKey = primaryKey;

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
