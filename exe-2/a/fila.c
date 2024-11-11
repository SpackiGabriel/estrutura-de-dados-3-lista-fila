#include <stdio.h>
#include <stdlib.h>

#include "fila.h"


Fila* criar_fila() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->quantidade = 0;
    return fila;
}

int enfileirar(Fila* fila, int valor) {
    ElementoFila* novo = (ElementoFila*) malloc(sizeof(ElementoFila));
    novo->valor = valor;

    if (fila->ultimo == NULL) {
        fila->primeiro = novo;
    }
    else {
        fila->ultimo->proximo = novo;
    }

    fila->ultimo = novo;
    fila->quantidade++;

    return 1;
}

int desenfileirar(Fila* fila) {
    if (fila->primeiro == NULL) {
        return 0;
    }

    ElementoFila* primeiro = fila->primeiro;
    fila->primeiro = primeiro->proximo;

    int valor = primeiro->valor;
    free(primeiro);

    fila->quantidade--;

    return valor;
}

void imprimir_fila(Fila* fila) {
    ElementoFila* atual = fila->primeiro;

    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }

}

void liberar_fila(Fila* fila) {
    ElementoFila* atual = fila->primeiro;

    while (atual != NULL) {
        ElementoFila* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}
