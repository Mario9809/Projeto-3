#include "agenda.h"
#include <stdio.h>
#include <string.h>

#define TAM_TELEFONE 16
#define FILENAME "agenda.bin"

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

ERROS adicionar(Agenda agenda[], int *pos) {
    if (*pos >= TOTAL) {
        return MAX_CONTATOS;
    }

    printf("Digite o nome: ");
    scanf("%299s", agenda[*pos].Nome);
    clearBuffer();

    printf("Digite o sobrenome: ");
    scanf("%299s", agenda[*pos].Sobrenome);
    clearBuffer();

    printf("Digite o email: ");
    scanf("%299s", agenda[*pos].Email);
    clearBuffer();

    printf("Digite o telefone: ");
    scanf("%15s", agenda[*pos].Telefone);
    clearBuffer();

    (*pos)++;
    printf("contato salvo com sucesso!!\n");
    return OK;
}



