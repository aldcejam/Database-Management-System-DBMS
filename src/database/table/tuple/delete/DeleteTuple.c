#include "../../../DatabaseStructures.c"
#include "DeleteTuple.h" 

void DeleteTuple(Database *db) {
    char tableName[MAX_STRING_SIZE];
    printf("Informe o nome da tabela: ");
    scanf("%s", tableName);

    Table *table = NULL;

    for (int i = 0; i < db->numTables; i++) {
        if (strcmp(db->tables[i].name, tableName) == 0) {
            table = &(db->tables[i]);
            break;
        }
    }

    if (table != NULL) {
        unsigned int primaryKey;
        printf("Informe a chave primária da tupla a ser apagada: ");
        scanf("%u", &primaryKey);

        int tupleIndex = -1;
 
        for (int i = 0; i < table->numTuples; i++) {
            if (table->tuples[i].primaryKey == primaryKey) {
                tupleIndex = i;
                break;
            }
        }

        if (tupleIndex != -1) { 
            free(table->tuples[tupleIndex].data);
            for (int i = tupleIndex; i < table->numTuples - 1; i++) {
                table->tuples[i] = table->tuples[i + 1];
            }
            table->numTuples--;

            printf("Tupla apagada com sucesso.\n");
        } else {
            printf("Chave primária não encontrada.\n");
        }
    } else {
        printf("Tabela não encontrada.\n");
    }
}
