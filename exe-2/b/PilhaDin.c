#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h" //inclui os Prot�tipos

//Defini��o do tipo Pilha
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

struct super_fila {
    struct Pilha *inicio;
    struct Pilha *final;
    int qtd;
};


Pilha* cria_Pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_Pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int consulta_topo_Pilha(Pilha* pi, struct aluno *al){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    *al = (*pi)->dados;
    return 1;
}

int insere_Pilha(Pilha* pi, struct aluno al){
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remove_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int tamanho_Pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int Pilha_cheia(Pilha* pi){
    return 0;
}

int Pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return 1;
    if(*pi == NULL)
        return 1;
    return 0;
}

void imprime_Pilha(Pilha* pi){
    if(pi == NULL)
        return;
    Elem* no = *pi;
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

int insere_SuperFila(SuperFila* sf, Pilha* pi) {
    if (sf == NULL || pi == NULL) return 0;

    pi->prox = NULL;

    if (sf->inicio == NULL) {
        sf->inicio = pi;
    } else {
        sf->final->prox = pi;
    }

    sf->final = pi;
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
