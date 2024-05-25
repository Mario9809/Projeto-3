#define TOTAL 255
#define TAM_NOME 300
#define TAM_SOBRENOME 300
#define TAM_EMAIL 300
#define TAM_TEL 15

typedef struct {
    char Nome[TAM_NOME];
    char Sobrenome[TAM_SOBRENOME];
    char Email[TAM_EMAIL];
    char Telefone[TAM_TEL];
} Agenda;

typedef enum {OK, MAX_CONTATOS, SEM_CONTATOS, NAO_ENCONTRADO} ERROS;

typedef enum {PESSOAL, TRABALHO} TIPO_CONTATO;

typedef ERROS (funcao)(Agenda[], int);

ERROS adicionar(Agenda agenda[], int *pos);
ERROS listar(Agenda agenda[], int *pos);
ERROS deletar(Agenda agenda[], int *pos);
ERROS salvar(Agenda agenda[], int *pos);
ERROS carregar(Agenda agenda[], int *pos);
ERROS alterar(Agenda agenda[], int *pos);