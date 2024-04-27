#include "agenda.h"
#include <stdio.h>



int main() {
   

    Agenda agenda[TOTAL];
    int pos;
    ERROS erro = carregar(agenda, &pos); 
    if (erro != OK)
        pos = 0;

    int opcao;
    do {
        printf("\nMenu principal\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Listar contatos\n");
        printf("3 - Deletar contato\n");
        printf("4 - Salvar contato\n");
        printf("5 - Carregar contato\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);


      switch (opcao) {

          case 1:

              adicionar(agenda, &pos);

              break;

          case 2:

              listar(agenda, &pos);

              break;

          case 3:

              deletar(agenda, &pos);

              break;

          case 4:

              salvar(agenda, &pos);

              break;

          case 5:

              carregar(agenda, &pos);

              break;

          case 0:

              printf("Saindo...\n");

              break;

          default:

              printf("Escolha inválida.\n");

      }

    } while (opcao != 0);

    return 0;
}
