typedef struct ElementoPilha {
    int valor;
    struct ElementoPilha* proximo;
} ElementoPilha;

typedef struct Pilha {
    ElementoPilha* topo;
} Pilha;


Pilha* criar_pilha();
int empilhar(Pilha* pilha, int valor);
int desempilhar(Pilha* pilha);
void imprimir_pilha(Pilha* pilha);
void liberar_pilha(Pilha* pilha);
