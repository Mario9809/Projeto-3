#define TOTAL 255
#define TAM_NOME 300
#define TAM_SOBRENOME 300
#define TAM_EMAIL 300

typedef struct {
    char Nome[TAM_NOME] ;
    char Sobrenome[TAM_SOBRENOME];
    int Telefone;
    char Email[TAM_EMAIL];
} Agenda;


typedef enum {OK, MAX_CONTATOS, SEM_CONTATOS, NAO_ENCONTRADO} ERROS;

typedef ERROS (*funcao)(Tarefa[], int*);

ERROS adicionar(Agenda agenda[], int *pos);
ERROS listar(Agenda agenda[], int *pos);
ERROS deletar(Agenda agenda[], int *pos);
ERROS salvar(Agenda agenda[], int *pos);
ERROS carregar(Agenda agenda[], int *pos);

void clearBuffer();