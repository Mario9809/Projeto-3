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

typedef ERROS (*funcao)(Agenda[], int*);
