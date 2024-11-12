#include <stdio.h>
#include "FilaDin.h"

#define MAX_FILAS 10

Fila* filas[MAX_FILAS];
int fila_count = 0;

void menu() {
    printf("1-Inicializa fila.\n");
    printf("2-Verifica se a fila é vazia.\n");
    printf("3-Verifica se a fila é cheia.\n");
    printf("4-Enfileira o elemento na fila.\n");
    printf("5-Desefileira elemento da fila.\n");
    printf("6-Le o número no início da fila.\n");
    printf("7-Testar qual fila possui mais elementos.\n");
    printf("8-Furar a fila.\n");
    printf("9-Sair.\n");
}

int main() {
    int opcao;
    struct aluno al;
    Fila* fi;
    int fila_index;

    while(1) {
        menu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                if (fila_count < MAX_FILAS) {
                    filas[fila_count] = cria_Fila();
                    printf("Fila %d inicializada.\n", fila_count + 1);
                    fila_count++;
                } 
                
                else {
                    printf("Limite de filas atingido.\n");
                }

                break;

            case 2:
                printf("Digite o número da fila (1 a %d): ", fila_count);

                scanf("%d", &fila_index);

                if (fila_index >= 1 && fila_index <= fila_count) {
                    fi = filas[fila_index - 1];

                    if (Fila_vazia(fi)) {
                        printf("Fila %d está vazia.\n", fila_index);
                    }

                    else {
                        printf("Fila %d não está vazia.\n", fila_index);
                    }

                } 
                
                else {
                    printf("Fila inválida.\n");
                }

                break;

            case 3:
                printf("Fila nunca estará cheia (fila dinâmica).\n");
                break;

            case 4:
                printf("Digite o número da fila (1 a %d): ", fila_count);
                scanf("%d", &fila_index);

                if (fila_index >= 1 && fila_index <= fila_count) {
                    printf("Digite a matrícula: ");
                    scanf("%d", &al.matricula);

                    printf("Digite o nome: ");
                    scanf(" %[^\n]s", al.nome);

                    printf("Digite as 3 notas: ");
                    scanf("%f %f %f", &al.n1, &al.n2, &al.n3);

                    fi = filas[fila_index - 1];

                    if (insere_Fila(fi, al)) {
                        printf("Aluno inserido na fila %d.\n", fila_index);
                    }

                    else {
                        printf("Erro ao inserir aluno na fila %d.\n", fila_index);
                    }

                } 
                
                else {
                    printf("Fila inválida.\n");
                }
                
                break;

            case 5:
                printf("Digite o número da fila (1 a %d): ", fila_count);
                scanf("%d", &fila_index);
                if (fila_index >= 1 && fila_index <= fila_count) {

                    fi = filas[fila_index - 1];

                    if (remove_Fila(fi)) {
                        printf("Elemento removido da fila %d.\n", fila_index);
                    }
                    
                    else {
                        printf("Erro ao remover elemento da fila %d.\n", fila_index);
                    }
                } 
                
                else {
                    printf("Fila inválida.\n");
                }

                break;

            case 6:
                printf("Digite o número da fila (1 a %d): ", fila_count);
                scanf("%d", &fila_index);

                if (fila_index >= 1 && fila_index <= fila_count) {
                    fi = filas[fila_index - 1];

                    if (consulta_Fila(fi, &al)) {
                        printf("Início da fila %d: %d, %s, %.2f %.2f %.2f\n", fila_index, al.matricula, al.nome, al.n1, al.n2, al.n3);
                    }
                    
                    else {
                        printf("Fila %d está vazia.\n", fila_index);
                    }

                } 
                
                else {
                    printf("Fila inválida.\n");
                }

                break;

            case 7:
                if (fila_count == 0) {
                    printf("Nenhuma fila criada.\n");
                } 
                
                else {
                    int max_tamanho = 0, max_index = 0;

                    for (int i = 0; i < fila_count; i++) {
                        fi = filas[i];

                        if (tamanho_Fila(fi) > max_tamanho) {
                            max_tamanho = tamanho_Fila(fi);
                            max_index = i;
                        }
                    }
                    
                    printf("A fila com mais elementos é a fila %d com %d elementos.\n", max_index + 1, max_tamanho);
                }

                break;

            case 8:
                printf("Digite o número da fila (1 a %d): ", fila_count);
                scanf("%d", &fila_index);

                if (fila_index >= 1 && fila_index <= fila_count) {
                    printf("Digite a matrícula: ");
                    scanf("%d", &al.matricula);

                    printf("Digite o nome: ");
                    scanf(" %[^\n]s", al.nome);

                    printf("Digite as 3 notas: ");
                    scanf("%f %f %f", &al.n1, &al.n2, &al.n3);

                    fi = filas[fila_index - 1];

                    if (furar_Fila(fi, al)) {
                        printf("Aluno furou a fila %d.\n", fila_index);
                    }
                    
                    else {
                        printf("Erro ao furar a fila %d.\n", fila_index);
                    }
                } 
                
                else {
                    printf("Fila inválida.\n");
                }

                break;

            case 9:
                printf("Saindo...\n");
                for (int i = 0; i < fila_count; i++) {
                    libera_Fila(filas[i]);
                }

                break;

            default:
                printf("Opção inválida.\n");
                break;
        }
    }

    return 0;
}
