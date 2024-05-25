#include "agenda.h"
#include <stdio.h>
#include <string.h>

#define TAM_TELEFONE 16
#define FILENAME_PESSOAL "agenda_pessoal.bin"
#define FILENAME_TRABALHO "agenda_trabalho.bin"

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

    // Loop para garantir que o número de telefone seja único
    do {
        printf("Digite o telefone: ");
        scanf("%15s", agenda[*pos].Telefone);
        clearBuffer();

        // Verifica se o número de telefone já existe em algum contato existente
        int telefoneExistente = 0;
        for (int i = 0; i < *pos; i++) {
            if (strcmp(agenda[i].Telefone, agenda[*pos].Telefone) == 0) {
                printf("Erro: Este número de telefone já está associado a outro contato.\n");
                telefoneExistente = 1;
                break;
            }
        }

        // Se o número de telefone não existir em nenhum contato, sai do loop
        if (!telefoneExistente) {
            break;
        }

    } while (1);

    (*pos)++;
    printf("Contato salvo com sucesso!!\n");
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
    FILE *arquivo = fopen(FILENAME_PESSOAL, "wb");
    if (arquivo == NULL) {
        return NAO_ENCONTRADO;
    }

    fwrite(agenda, sizeof(Agenda), *pos, arquivo);
    fclose(arquivo);
    printf("Agenda pessoal salva com sucesso!!\n");

    arquivo = fopen(FILENAME_TRABALHO, "wb");
    if (arquivo == NULL) {
        return NAO_ENCONTRADO;
    }

    fwrite(agenda, sizeof(Agenda), *pos, arquivo);
    fclose(arquivo);
    printf("Agenda de trabalho salva com sucesso!!\n");

    return OK;
}

ERROS carregar(Agenda agenda[], int *pos) {
    FILE *arquivo = fopen(FILENAME_PESSOAL, "rb");
    if (arquivo == NULL) {
        return NAO_ENCONTRADO;
    }

    *pos = fread(agenda, sizeof(Agenda), TOTAL, arquivo);
    fclose(arquivo);
    printf("Agenda pessoal carregada com sucesso!!\n");

    arquivo = fopen(FILENAME_TRABALHO, "rb");
    if (arquivo == NULL) {
        return NAO_ENCONTRADO;
    }

    *pos = fread(agenda, sizeof(Agenda), TOTAL, arquivo);
    fclose(arquivo);
    printf("Agenda de trabalho carregada com sucesso!!\n");

    return OK;
}

ERROS alterar(Agenda agenda[], int *pos) {
    if (*pos == 0) {
        return SEM_CONTATOS;
    }

    char telefone[TAM_TELEFONE];
    printf("Digite o número de telefone do contato que deseja alterar: ");
    scanf("%15s", telefone);
    clearBuffer();

    for (int i = 0; i < *pos; i++) {
        if (strcmp(agenda[i].Telefone, telefone) == 0) {
            printf("Contato encontrado. Digite os novos dados.\n");

            // Armazenar os dados antigos
            char antigoNome[TAM_NOME], antigoSobrenome[TAM_SOBRENOME], antigoEmail[TAM_EMAIL], antigoTelefone[TAM_TEL];
            strcpy(antigoNome, agenda[i].Nome);
            strcpy(antigoSobrenome, agenda[i].Sobrenome);
            strcpy(antigoEmail, agenda[i].Email);
            strcpy(antigoTelefone, agenda[i].Telefone);

            // Novos dados
            char novoNome[TAM_NOME], novoSobrenome[TAM_SOBRENOME], novoEmail[TAM_EMAIL], novoTelefone[TAM_TEL];

            printf("Digite o novo nome (atual: %s): ", agenda[i].Nome);
            scanf("%299s", novoNome);
            clearBuffer();

            printf("Digite o novo sobrenome (atual: %s): ", agenda[i].Sobrenome);
            scanf("%299s", novoSobrenome);
            clearBuffer();

            do {
                printf("Digite o novo email (atual: %s): ", agenda[i].Email);
                scanf("%299s", novoEmail);
                clearBuffer();

                int pos_arroba = strcspn(novoEmail, "@");
                int pos_ponto = strcspn(novoEmail, ".");

                if (pos_arroba != strlen(novoEmail) && pos_ponto != strlen(novoEmail) && pos_arroba < pos_ponto) {
                    break;
                } else {
                    printf("Formato de e-mail inválido. Por favor, insira um e-mail válido.\n");
                }
            } while (1);

            printf("Digite o novo telefone (atual: %s): ", agenda[i].Telefone);
            scanf("%15s", novoTelefone);
            clearBuffer();

            // Atualizar os dados
            strcpy(agenda[i].Nome, novoNome);
            strcpy(agenda[i].Sobrenome, novoSobrenome);
            strcpy(agenda[i].Email, novoEmail);
            strcpy(agenda[i].Telefone, novoTelefone);

            // Imprimir informações alteradas
            printf("Contato alterado com sucesso!\n");
            printf("Alterações feitas:\n");
            printf("Nome: %s -> %s\n", antigoNome, novoNome);
            printf("Sobrenome: %s -> %s\n", antigoSobrenome, novoSobrenome);
            printf("Email: %s -> %s\n", antigoEmail, novoEmail);
            printf("Telefone: %s -> %s\n", antigoTelefone, novoTelefone);

            return OK;
        }
    }

    return NAO_ENCONTRADO;
}

