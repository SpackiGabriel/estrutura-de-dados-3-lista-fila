#include <stdio.h>
#include <stdlib.h>

#include "FilaDin.h"

int main() {
    Fila* f1 = cria_Fila();
    Fila* f2 = cria_Fila();
    Fila* f3 = cria_Fila();

    struct aluno a1 = {1, "Alice", 7.5, 8.0, 6.5};
    struct aluno a2 = {3, "Carlos", 6.0, 6.5, 7.0};
    struct aluno a3 = {2, "Bob", 8.5, 7.5, 9.0};
    struct aluno a4 = {4, "Diana", 9.0, 8.5, 7.5};

    insere_Fila(f1, a1);
    insere_Fila(f1, a2);
    insere_Fila(f2, a3);
    insere_Fila(f2, a4);

    mescla_Filas(f1, f2, f3);

    printf("Fila 3:\n");
    imprime_Fila(f3);

    libera_Fila(f1);
    libera_Fila(f2);
    libera_Fila(f3);

    return 0;
}
