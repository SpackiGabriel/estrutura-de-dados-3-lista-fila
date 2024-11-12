#include <stdio.h>
#include "FilaDin.h"
#include "PilhaDin.h"

int main() {
    Fila* fila = cria_Fila();

    struct aluno a1 = {1, "Aluno 1", 7.5, 8.0, 6.5};
    struct aluno a2 = {2, "Aluno 2", 5.5, 7.0, 9.0};
    struct aluno a3 = {3, "Aluno 3", 6.0, 8.5, 7.5};
    
    insere_Fila(fila, a1);
    insere_Fila(fila, a2);
    insere_Fila(fila, a3);

    printf("Fila original:\n");
    imprime_Fila(fila);

    inverte_Fila(fila);

    printf("\nFila invertida:\n");
    imprime_Fila(fila);

    libera_Fila(fila);
    return 0;
}