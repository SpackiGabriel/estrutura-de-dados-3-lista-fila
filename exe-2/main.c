#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {

    Pilha* pilha = criar_pilha();

    empilhar(pilha, 1);
    empilhar(pilha, 2);
    empilhar(pilha, 3);

    imprimir_pilha(pilha);

    desempilhar(pilha);
    desempilhar(pilha);

    imprimir_pilha(pilha);

    liberar_pilha(pilha);

    return 0;
}
