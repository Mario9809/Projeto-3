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

    char email[300];

    printf("Digite o nome: ");
    scanf("%299s", agenda[*pos].Nome);
    clearBuffer();

    printf("Digite o sobrenome: ");
    scanf("%299s", agenda[*pos].Sobrenome);
    clearBuffer();

    do {
        printf("Digite o email: ");
        scanf("%299s", email); // Use a variável 'email' aqui
        clearBuffer();

        int pos_arroba = strcspn(email, "@");
        int pos_ponto = strcspn(email, ".");

        if (pos_arroba != strlen(email) && pos_ponto != strlen(email) && pos_arroba < pos_ponto) {
            break;
        } else {
            printf("Formato de e-mail inválido. Por favor, insira um e-mail válido.\n");
        }
    } while (1);

    strcpy(agenda[*pos].Email, email);

    printf("Digite o telefone: ");
    scanf("%15s", agenda[*pos].Telefone);
    clearBuffer();

    
    for (int i = 0; i < *pos; i++) {
        if (strcmp(agenda[i].Telefone, agenda[*pos].Telefone) == 0) {
            printf("Erro: Este número de telefone já está associado a outro contato.\n");
            return NUMERO_EXISTENTE;
        }
    }

    (*pos)++;
    printf("Contato salvo com sucesso!!\n");
    return OK;
}


ERROS deletar(Agenda agenda[], int *pos) {
    if (*pos == 0) {
        return SEM_CONTATOS;
    }

    char telefone[TAM_TELEFONE];
    printf("Digite o número de telefone do contato que deseja deletar: ");
    scanf("%15s", telefone);
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
     printf("contato deletado com sucesso!!\n");
    return encontrado ? OK : NAO_ENCONTRADO;
}

ERROS salvar(Agenda agenda[], int *pos) {
    FILE *arquivo = fopen(FILENAME, "wb");
    if (arquivo == NULL) {
        return NAO_ENCONTRADO;
    }

    fwrite(agenda, sizeof(Agenda), *pos, arquivo);
    fclose(arquivo);
    printf("Agenda salva com sucesso!!\n");
    return OK;
}

ERROS carregar(Agenda agenda[], int *pos) {
    FILE *arquivo = fopen(FILENAME, "rb");
    if (arquivo == NULL) {
        return NAO_ENCONTRADO;
    }

    *pos = fread(agenda, sizeof(Agenda), TOTAL, arquivo);
    fclose(arquivo);
    printf("Agenda carregada com sucesso!!\n");
    return OK;
}
