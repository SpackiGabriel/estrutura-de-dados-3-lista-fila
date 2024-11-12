#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FilaDin.h"

void exibir_menu() {
    printf("\nControle de Pista de Decolagem\n");
    printf("1. Listar número de aviões na fila de decolagem\n");
    printf("2. Autorizar decolagem do primeiro avião\n");
    printf("3. Adicionar avião à fila de espera\n");
    printf("4. Listar todos os aviões na fila de espera\n");
    printf("5. Listar características do primeiro avião da fila\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    Fila* fila_decolagem = cria_Fila();
    struct aviao aviao;
    int opcao;

    if (fila_decolagem == NULL) {
        printf("Erro ao criar a fila de decolagem.\n");
        return 1;
    }

    do {
        exibir_menu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Número de aviões aguardando na fila: %d\n", lista_Numero_Avioes(fila_decolagem));
                break;
            
            case 2:
                if (!autoriza_Decolagem(fila_decolagem)) {
                    printf("A fila está vazia. Nenhum avião para decolar.\n");
                };
                break;
            
            case 3:
                printf("Informe o ID do avião: ");
                scanf("%d", &aviao.id);

                printf("Informe o modelo do avião: ");
                scanf("%s", aviao.modelo);

                printf("Informe a prioridade de decolagem: ");
                scanf("%d", &aviao.prioridade);
                
                if (adiciona_Aviao(fila_decolagem, aviao)){
                    printf("Avião adicionado à fila de espera.\n");
                }
                else {
                    printf("Erro ao adicionar o avião à fila.\n");
                }
                break;
            
            case 4:
                printf("Aviões na fila de espera:\n");
                lista_Todos_Avioes(fila_decolagem);
                break;
            
            case 5:
                lista_Primeiro_Aviao(fila_decolagem);
                break;
            
            case 6:
                printf("Encerrando programa.\n");
                break;
            
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
        }
    } while(opcao != 6);

    libera_Fila(fila_decolagem);
    return 0;
}
