#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"



Pilha* criar_pilha() {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}


int empilhar(Pilha* pilha, int valor) {
    ElementoPilha* novo = (ElementoPilha*) malloc(sizeof(ElementoPilha));
    novo->valor = valor;

    novo->proximo = pilha->topo;
    pilha->topo = novo;

    return 1;
}

int desempilhar(Pilha* pilha) {
    ElementoPilha* aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;

    int valor = aux->valor;
    free(aux);
    return valor;
}

void imprimir_pilha(Pilha* pilha) {
    ElementoPilha* aux = pilha->topo;

    while(aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->proximo;
    }
}


void liberar_pilha(Pilha* pilha) {
    ElementoPilha* atual = pilha->topo;

    while (atual != NULL) {
        ElementoPilha* aux = atual;
        atual = atual->proximo;
        free(aux);
    }

    free(pilha);
}

