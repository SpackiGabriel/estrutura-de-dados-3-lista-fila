#include <stdio.h>
#include <stdlib.h>
#include "FilaDin.h" //inclui os Prot�tipos
//Defini��o do tipo Fila
struct elemento {
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;
//Defini��o do N� Descritor da Fila
struct fila {
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
    struct fila *prox;
};

struct super_fila {
    struct fila *inicio;
    struct fila *final;
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

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL)
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    *al = fi->inicio->dados;
    return 1;
}

int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fila(Fila* fi){
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

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return 0;
    return fi->qtd;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}

int Fila_cheia(Fila* fi){
    return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    Elem* no = fi->inicio;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

SuperFila* cria_SuperFila() {
    SuperFila* sf = (SuperFila*) malloc(sizeof(SuperFila));
    if (sf != NULL) {
        sf->inicio = NULL;
        sf->final = NULL;
        sf->qtd = 0;
    }
    return sf;
}

int insere_SuperFila(SuperFila* sf, Fila* fi) {
    if (sf == NULL || fi == NULL) return 0;

    fi->prox = NULL;

    if (sf->inicio == NULL) {
        sf->inicio = fi;
    } else {
        sf->final->prox = fi;
    }

    sf->final = fi;
    sf->qtd++;

    return 1;
}

int remover_SuperFila(SuperFila *sf) {
    if (sf == NULL || sf->inicio == NULL) return 0;

    Fila* fi = sf->inicio;
    sf->inicio = sf->inicio->prox;

    if (sf->inicio == NULL) {
        sf->final = NULL;
    }

    free(fi);
    sf->qtd--;

    return 1;
}

void imprimir_SuperFila(SuperFila *sf) {
    if (sf == NULL || sf->inicio == NULL) {
        printf("SuperFila vazia.\n");
        return;
    }

    Fila* at = sf->inicio;
    int count = 1;

    while (at != NULL) {
        printf("Fila %d:\n", count);
        struct elemento *elem_atual = at->inicio;
        
        if (elem_atual == NULL) {
            printf("  [Fila vazia]\n");
        }

        while (elem_atual != NULL) {
            printf("  Matricula: %d, Nome: %s, Notas: %.2f, %.2f, %.2f\n",
                   elem_atual->dados.matricula,
                   elem_atual->dados.nome,
                   elem_atual->dados.n1,
                   elem_atual->dados.n2,
                   elem_atual->dados.n3);
            elem_atual = elem_atual->prox;
        }

        at = at->prox;
        count++;
    }
}
