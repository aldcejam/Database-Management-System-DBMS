#include "../../../DatabaseStructures.c" 
#include "SearchTuple.h" 


void SearchTuple(Database *db)
{
    char tableName[MAX_STRING_SIZE];
    printf("Informe o nome da tabela para pesquisar: ");
    scanf("%s", tableName);

    Table *table = NULL;

    for (int i = 0; i < db->numTables; i++) {
        if (strcmp(db->tables[i].name, tableName) == 0) {
            table = &(db->tables[i]);
            break;
        }
    }

    if (table != NULL)
    {
        printf("Colunas disponíveis na tabela %s:\n", tableName);
        for (int i = 0; i < table->numColumns; i++)
        {
            printf("%d. %s\n", i + 1, table->columns[i].name);
        }

        int columnIndex;
        printf("Selecione uma coluna para pesquisar (número): ");
        scanf("%d", &columnIndex);
        columnIndex--;  

        if (columnIndex >= 0 && columnIndex < table->numColumns)
        {
            int option;
            printf("Escolha a opção de pesquisa:\n");
            if (strcmp(table->columns[columnIndex].type, "string") == 0)
            {
                printf("1. Valores igual ao valor informado\n");
                option = 1;  
            }
            else
            {
                printf("1. Valores maior que o valor informado\n");
                printf("2. Valores maior ou igual ao valor informado\n");
                printf("3. Valores igual ao valor informado\n");
                printf("4. Valores menor que o valor informado\n");
                printf("5. Valores menor ou igual ao valor informado\n");
                printf("6. Valores próximo ao valor informado\n");
                printf("Opção: ");
                scanf("%d", &option);
            }

            char searchValue[MAX_STRING_SIZE];
            printf("Informe o valor para pesquisa: ");
            scanf("%s", searchValue);

            printf("Resultados da pesquisa na tabela %s:\n", tableName);
            int found = 0;

            for (int i = 0; i < table->numTuples; i++)
            {
                int tupleIntValue;
                double tupleDoubleValue;
                if (strcmp(table->columns[columnIndex].type, "int") == 0)
                {
                    tupleIntValue = atoi(table->tuples[i].data[columnIndex]);
                }
                else if (strcmp(table->columns[columnIndex].type, "double") == 0)
                {
                    tupleDoubleValue = atof(table->tuples[i].data[columnIndex]);
                }

                switch (option)
                {
                case 1: 
                    if (strcmp(table->tuples[i].data[columnIndex], searchValue) == 0)
                    {
                        found = 1;
                        PrintTuple(table, i);
                    }
                    break;
                case 2:  
                    if (strcmp(table->columns[columnIndex].type, "int") == 0)
                    {
                        if (atoi(table->tuples[i].data[columnIndex]) >= atoi(searchValue))
                        {
                            found = 1;
                            PrintTuple(table, i);
                        }
                    }
                    else if (strcmp(table->columns[columnIndex].type, "double") == 0)
                    {
                        if (atof(table->tuples[i].data[columnIndex]) >= atof(searchValue))
                        {
                            found = 1;
                            PrintTuple(table, i);
                        }
                    }
                    break;
                case 3: 
                    if (strcmp(table->columns[columnIndex].type, "int") == 0)
                    {
                        if (atoi(table->tuples[i].data[columnIndex]) == atoi(searchValue))
                        {
                            found = 1;
                            PrintTuple(table, i);
                        }
                    }
                    else if (strcmp(table->columns[columnIndex].type, "double") == 0)
                    {
                        if (atof(table->tuples[i].data[columnIndex]) == atof(searchValue))
                        {
                            found = 1;
                            PrintTuple(table, i);
                        }
                    }
                    break;
                case 4:  
                    if (strcmp(table->columns[columnIndex].type, "int") == 0)
                    {
                        if (atoi(table->tuples[i].data[columnIndex]) < atoi(searchValue))
                        {
                            found = 1;
                            PrintTuple(table, i);
                        }
                    }
                    else if (strcmp(table->columns[columnIndex].type, "double") == 0)
                    {
                        if (atof(table->tuples[i].data[columnIndex]) < atof(searchValue))
                        {
                            found = 1;
                            PrintTuple(table, i);
                        }
                    }
                    break;
                case 5: 
                    if (strcmp(table->columns[columnIndex].type, "int") == 0)
                    {
                        if (atoi(table->tuples[i].data[columnIndex]) <= atoi(searchValue))
                        {
                            found = 1;
                            PrintTuple(table, i);
                        }
                    }
                    else if (strcmp(table->columns[columnIndex].type, "double") == 0)
                    {
                        if (atof(table->tuples[i].data[columnIndex]) <= atof(searchValue))
                        {
                            found = 1;
                            PrintTuple(table, i);
                        }
                    }
                    break;
                case 6: 
                    if (strcmp(table->columns[columnIndex].type, "int") == 0)
                    {
                        if (abs(atoi(table->tuples[i].data[columnIndex]) - atoi(searchValue)) <= 1)
                        {
                            found = 1;
                            PrintTuple(table, i);
                        }
                    }
                    else if (strcmp(table->columns[columnIndex].type, "double") == 0)
                    {
                        if (fabs(atof(table->tuples[i].data[columnIndex]) - atof(searchValue)) <= 1.0)
                        {
                            found = 1;
                            PrintTuple(table, i);
                        }
                    }
                    break;
                default:
                    printf("Opção inválida.\n");
                    break;
                }
            }

            if (!found)
            {
                printf("Valor não encontrado.\n");
            }
        }
        else
        {
            printf("Número de coluna inválido.\n");
        }
    }
    else
    {
        printf("Tabela %s não encontrada.\n", tableName);
    }
}

void PrintTuple(Table *table, int tupleIndex)
{
    printf("Tuple %d (Primary Key: %u):\n", tupleIndex + 1, table->tuples[tupleIndex].primaryKey);
    for (int i = 0; i < table->numColumns; i++)
    {
        printf("  %s: %s\n", table->columns[i].name, table->tuples[tupleIndex].data[i]);
    }
}