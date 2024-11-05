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
        {6, "Fernanda", 6.7, 8.0, 7.2},
        {7, "Gabriel", 7.4, 9.3, 8.1},
        {8, "Juliana", 9.2, 7.1, 8.7},
        {9, "Eduardo", 6.8, 7.9, 6.5},
        {10, "Patricia", 8.0, 7.7, 9.2},
        {11, "Thiago", 7.3, 6.8, 7.5},
        {12, "Camila", 8.9, 9.1, 7.8},
        {13, "Renato", 6.6, 7.2, 8.4},
        {14, "Mariana", 9.0, 8.3, 7.6},
        {15, "Lucas", 7.1, 6.9, 8.3}
    };

    Fila* f1 = cria_Fila();
    Fila* f2 = cria_Fila();

    for(int i = 0; i < 15; i++){
        insere_Fila(f1,a[i]);

        if (Fila_vazia(f1)) {
            printf("Erro!!!!!!\n");
        }
    }

    printf("FILA 1 ANTES DE SEPARAR:\n\n");
    imprime_Fila(f1);
    printf("Tamanho: %d\n\n", tamanho_Fila(f1));

    separa(f1, f2, 8);

    printf("FILA 1 DEPOIS DE SEPARAR:\n\n");
    imprime_Fila(f1);
    printf("Tamanho: %d\n\n", tamanho_Fila(f1));

    printf("FILA 2 DEPOIS DE SEPARAR:\n\n");
    imprime_Fila(f2);
    printf("Tamanho: %d\n\n", tamanho_Fila(f2));

    return 0;
}


