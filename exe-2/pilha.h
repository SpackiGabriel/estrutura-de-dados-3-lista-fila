typedef struct Elemento {
    int valor;
    struct Elemento* proximo;
} Elemento;

typedef struct Pilha {
    Elemento* topo;
} Pilha;


Pilha* criar_pilha();
int empilhar(Pilha* pilha, int valor);
int desempilhar(Pilha* pilha);
void imprimir_pilha(Pilha* pilha);
void liberar_pilha(Pilha* pilha);
