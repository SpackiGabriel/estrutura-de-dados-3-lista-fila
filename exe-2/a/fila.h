typedef struct ElementoFila {
    int valor;
    struct ElementoFila* proximo;
} ElementoFila;

typedef struct Fila {
    ElementoFila* primeiro;
    ElementoFila* ultimo;
    int quantidade;
} Fila;


Fila* criar_fila();
int enfileirar(Fila* fila, int valor);
int desenfileirar(Fila* fila);
void imprimir_fila(Fila* fila);
void liberar_fila(Fila* fila);
