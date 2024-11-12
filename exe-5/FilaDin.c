#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h" //inclui os Prot�tipos
//Defini��o do tipo Fila
struct elemento {
    struct aviao dados;
    struct elemento *prox;
};
typedef struct elemento Elem;
//Defini��o do N� Descritor da Fila
struct fila {
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Fila* cria_Fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->final = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_Fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}


int adiciona_Aviao(Fila* fi, struct aviao av){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = av;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int autoriza_Decolagem(Fila* fi){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    fi->qtd--;
    return 1;
}

void lista_Primeiro_Aviao(Fila* fi) {
    if (fi == NULL || fi->inicio == NULL) {
        printf("A fila está vazia.\n");
        return;
    }
    Elem *no = fi->inicio;
    printf("Primeiro avião da fila - ID=%d, Modelo=%s, Prioridade=%d\n", 
            no->dados.id, no->dados.modelo, no->dados.prioridade);
}

int lista_Numero_Avioes(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

void lista_Todos_Avioes(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
    while(no != NULL){
        printf("ID=%d, Modelo=%s, Prioridade=%d\n", no->dados.id, no->dados.modelo, no->dados.prioridade);
        no = no->prox;
    }
}