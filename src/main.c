#include <stdio.h>
#include "database/DatabaseStructures.c"
#include "database/table/create/CreateTable.h"
#include "database/table/list/table/ListTable.h"
#include "database/table/list/tableData/ListTableData.h"
#include "database/table/delete/DeleteTable.h"
#include "database/table/tuple/insert/InsertTuple.h"
#include "database/table/tuple/search/SearchTuple.h"
#include "database/table/tuple/delete/DeleteTuple.h"
#include "database/table/save/SaveTable.h"

void displayMenu() {
    printf("\nEscolha uma opção:\n");
    printf("1. Criar tabela\n");
    printf("2. Inserir tupla\n");
    printf("3. Pesquisar tupla\n");
    printf("4. Listar dados da tabela\n");
    printf("5. Excluir tabela\n");
    printf("6. Listar tabelas\n");
    printf("7. Salvar tabela\n");
    printf("8. Sair\n");
}

int main() {
    printf("Olá do arquivo main.c!\n");

    Database myDatabase;
    myDatabase.numTables = 0;

    char choice;
    do {
        displayMenu();
        printf("Opção: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                CreateTable(&myDatabase);
                break;
            case '2':
                InsertTuple(&myDatabase);
                break;
            case '3':
                SearchTuple(&myDatabase);
                break;
            case '4':
                ListTableData(&myDatabase);
                break;
            case '5':
                DeleteTable(&myDatabase);
                break;
            case '6':
                ListTable(&myDatabase);
                break;
            case '7':
                SaveTable(&myDatabase);
                break;
            case '8':
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (choice != '8');

    return 0;
}
