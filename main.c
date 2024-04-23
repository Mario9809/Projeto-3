#include "agenda.h"
#include <stdio.h>

#define TAM_NOME 300
#define TAM_SOBRENOME 300
#define TAM_EMAIL 300

int main() {

  funcao fs[] = {criar, listar, deletar, salvar, carregar};

  Agenda agenda[TOTAL];
  int pos;
  ERROS erro = fs[4](agenda, &pos);
  if (erro != OK)
    pos = 0;



  int opcao;
  do {
    printf("\nMenu principal\n");
    printf("1 - Adicionar contato\n");
    printf("2 - Listar contatos\n");
    printf("3 - Deletar contato\n");
    printf("4 - Salvar contato\n");
    printf("5 - Carregar contato");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");


    scanf("%d", &opcao);
    opcao--;

    } while (opcao != 0);

}