#include "agenda.h"
#include <stdio.h>
#include <string.h>

#define TAM_TELEFONE 15
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
    scanf("%14s", agenda[*pos].Telefone);
    clearBuffer();

    (*pos)++;
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

ERROS deletar(Agenda agenda[], int *pos) {
    if (*pos == 0) {
        return SEM_CONTATOS;
    }

    char telefone[TAM_TELEFONE];
    printf("Digite o número de telefone do contato que deseja deletar: ");
    scanf("%14s", telefone);
    clearBuffer();

    int encontrado = 0;
    for (int i = 0; i < *pos; i++) {
        if (strcmp(agenda[i].Telefone, telefone) == 0) {
            encontrado = 1;
            for (int j = i; j < *pos - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            (*pos)--;
            break;
        }
    }

    return encontrado ? OK : NAO_ENCONTRADO;
}

ERROS salvar(Agenda agenda[], int *pos) {
    FILE *arquivo = fopen(FILENAME, "wb");
    if (arquivo == NULL) {
        return ERRO_ARQUIVO;
    }

    fwrite(agenda, sizeof(Agenda), *pos, arquivo);
    fclose(arquivo);

    return OK;
}

ERROS carregar(Agenda agenda[], int *pos) {
    FILE *arquivo = fopen(FILENAME, "rb");
    if (arquivo == NULL) {
        return ERRO_ARQUIVO;
    }

    *pos = fread(agenda, sizeof(Agenda), TOTAL, arquivo);
    fclose(arquivo);

    return OK;
}