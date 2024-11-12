//Arquivo FilaDin.h
struct aviao {
    int id;
    char modelo[50];
    int prioridade;
};

typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int autoriza_Decolagem(Fila* fi);
int adiciona_Aviao(Fila* fi, struct aviao av);
void lista_Primeiro_Aviao(Fila* fi);
int lista_Numero_Avioes(Fila* fi);
void lista_Todos_Avioes(Fila* fi);
