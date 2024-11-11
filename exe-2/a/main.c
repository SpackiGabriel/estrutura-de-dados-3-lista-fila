#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

int main() {

    printf("--------PILHAS--------\n\n");

    Pilha* pilha = criar_pilha();

    empilhar(pilha, 1);
    empilhar(pilha, 2);
    empilhar(pilha, 3);

    imprimir_pilha(pilha);

    desempilhar(pilha);
    desempilhar(pilha);

    imprimir_pilha(pilha);

    liberar_pilha(pilha);

    printf("\n--------FILAS--------\n\n");

    Fila* fila = criar_fila();

    enfileirar(fila, 1);
    enfileirar(fila, 2);
    enfileirar(fila, 3);
    enfileirar(fila, 4);

    imprimir_fila(fila);

    desenfileirar(fila);
    desenfileirar(fila);
    desenfileirar(fila);

    imprimir_fila(fila);

    return 0;
}
