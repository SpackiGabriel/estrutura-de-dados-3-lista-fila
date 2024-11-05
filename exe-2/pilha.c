#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"



Pilha* criar_pilha() {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}


int empilhar(Pilha* pilha, int valor) {
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    novo->valor = valor;

    novo->proximo = pilha->topo;
    pilha->topo = novo;

    return 1;
}

int desempilhar(Pilha* pilha) {
    Elemento* aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;

    int valor = aux->valor;
    free(aux);
    return valor;
}

void imprimir_pilha(Pilha* pilha) {
    Elemento* aux = pilha->topo;

    while(aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->proximo;
    }
}


void liberar_pilha(Pilha* pilha) {
    Elemento* atual = pilha->topo;

    while (atual != NULL) {
        Elemento* aux = atual;
        atual = atual->proximo;
        free(aux);
    }

    free(pilha);
}

