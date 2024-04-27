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

ERROS listar(Agenda agenda[], int *pos) {
    if (*pos == 0) {
        return SEM_CONTATOS;
    }

    printf("Lista de contatos:\n");
    for (int i = 0; i < *pos; i++) {
        printf("Nome: %s %s, Email: %s, Telefone: %s\n", agenda[i].Nome, agenda[i].Sobrenome, agenda[i].Email, agenda[i].Telefone);
    }

    return OK;
}





