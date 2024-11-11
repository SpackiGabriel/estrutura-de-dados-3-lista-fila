#include <stdio.h>
#include <stdlib.h>

#include "FilaDin.h"

int main(){
    struct aluno al, a[15] = {
        {2, "Andre", 9.5, 7.8, 8.5},
        {4, "Ricardo", 7.5, 8.7, 6.8},
        {1, "Bianca", 9.7, 6.7, 8.4},
        {3, "Ana", 5.7, 6.1, 7.4},
        {5, "Carlos", 8.5, 7.5, 9.0},
    };

    Fila* f1 = cria_Fila();

    for(int i = 0; i < 5; i++){
        insere_Fila_Circ(f1, a[i]);
    }

    fura_Fila_Circ(f1, a[2]);

    imprime_Fila_Circ(f1);

    libera_Fila_Circ(f1);


    return 0;
}


