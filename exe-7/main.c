#include <stdio.h>
#include <stdlib.h>

#include "FilaDin.h"

int main(){
    Fila* fi = cria_Fila();

    struct aluno a1 = {1, "Alice", 7.5, 8.0, 6.5};
    struct aluno a2 = {2, "Bob", 8.5, 7.5, 9.0};
    struct aluno a3 = {3, "Carlos", 6.0, 6.5, 7.0};

    insere_Fila(fi, a1);
    insere_Fila(fi, a2);
    insere_Fila(fi, a3);

    printf("Fila original:\n");
    imprime_Fila(fi);

    reverso(fi);

    printf("\nFila invertida:\n");
    imprime_Fila(fi);

    libera_Fila(fi);

    return 0;
}


