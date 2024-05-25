#include "agenda.h"
#include <stdio.h>

  int main() {
    Agenda agendaPessoal[TOTAL];
    Agenda agendaTrabalho[TOTAL];
    int posPessoal = 0, posTrabalho = 0;

      int opcao;
      do {
          printf("\nMenu principal\n");
          printf("1 - Adicionar contato\n");
          printf("2 - Listar contatos\n");
          printf("3 - Deletar contato\n");
          printf("4 - Alterar contato\n");
          printf("5 - Salvar contatos\n");
          printf("6 - Carregar contatos\n");
          printf("0 - Sair\n");
          printf("Escolha uma opcao: ");
          scanf("%d", &opcao);

        TIPO_CONTATO tipo;
        if (opcao > 0 && opcao < 5) {
            printf("Escolha o tipo de contato sendo 1 para pessoal e 2 para trabalho: ");
        int tipoInt;
            scanf("%d", &tipoInt);
            tipo = tipoInt == 1 ? PESSOAL : TRABALHO;
        }

    switch (opcao) {
      case 1:
          if (tipo == PESSOAL)
              adicionar(agendaPessoal, &posPessoal);
          else
              adicionar(agendaTrabalho, &posTrabalho);
          break;
      case 2:
          if (tipo == PESSOAL)
              listar(agendaPessoal, &posPessoal);
          else
              listar(agendaTrabalho, &posTrabalho);
          break;
      case 3:
          if (tipo == PESSOAL)
              deletar(agendaPessoal, &posPessoal);
          else
              deletar(agendaTrabalho, &posTrabalho);
          break;
      case 4:
          if (tipo == PESSOAL)
              alterar(agendaPessoal, &posPessoal);
          else
              alterar(agendaTrabalho, &posTrabalho);
          break;
      case 5:
          salvar(agendaPessoal, &posPessoal);
          salvar(agendaTrabalho, &posTrabalho);
          break;
      case 6:
          carregar(agendaPessoal, &posPessoal);
          carregar(agendaTrabalho, &posTrabalho);
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