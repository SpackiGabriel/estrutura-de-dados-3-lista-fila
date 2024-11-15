#include <stdio.h>
#include <stdlib.h>

#include "FilaDin.h"

int main() {
    SuperFila *sf = cria_SuperFila();

    Fila *f1 = cria_Fila();

    struct aluno a1 = {1, "Alice", 7.5, 8.0, 9.0};
    struct aluno a2 = {2, "Bob", 6.5, 7.0, 8.5};

    insere_Fila(f1, a1);
    insere_Fila(f1, a2);

    Fila *f2 = cria_Fila();

    struct aluno a3 = {3, "Charlie", 9.0, 8.5, 9.5};
    struct aluno a4 = {4, "Diana", 8.0, 7.5, 7.0};

    insere_Fila(f2, a3);
    insere_Fila(f2, a4);

    insere_SuperFila(sf, f1);
    insere_SuperFila(sf, f2);

    printf("Conteúdo da SuperFila:\n");
    imprimir_SuperFila(sf);

    printf("\nRemovendo a primeira fila da SuperFila...\n");
    remover_SuperFila(sf);

    printf("Conteúdo da SuperFila após remoção:\n");
    imprimir_SuperFila(sf);

    remover_SuperFila(sf);
    free(sf);

    return 0;
}
