#include "../../DatabaseStructures.c"
#include "FindTableByName.h"

Table *FindTableByName(Database *db, const char *tableName) {
    for (int i = 0; i < db->numTables; i++) {
        if (strcmp(db->tables[i].name, tableName) == 0) {
            return &(db->tables[i]);
        }
    }
    return NULL;
}