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

int insere_Fila_Circ(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));

    if(no == NULL)
        return 0;

    no->dados = al;

    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
        no->prox = fi->inicio;

    fi->final = no;
    fi->qtd++;
    return 1;
}

int remove_Fila_Circ(Fila* fi){
    if(fi == NULL)
        return 0;

    if(fi->inicio == NULL)//fila vazia
        return 0;

    Elem *no = fi->inicio;

    fi->inicio = fi->inicio->prox;

    if (fi->inicio != fi->final) { // corrigir o apontamento circular
        fi->final->prox = fi->inicio;
    }
    else {
        fi->final = NULL;
    }

    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;

    free(no);
    fi->qtd--;

    return 1;
}

void imprime_Fila_Circ(Fila* fi){
    if(fi == NULL)
        return;

    Elem* no = fi->inicio;

    do {
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }

    while(no != fi->inicio); // Quando a fila for circulada e voltar a apontar ao início, o loop é encerrado.
}

void libera_Fila_Circ(Fila* fi){
    if(fi != NULL){
        
        Elem* no;

        do {
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);

            free(fi);

        } while(no != fi->inicio); 
    }

}

int fura_Fila_Circ(Fila* fi, struct aluno al) {
    if (fi == NULL) {
        return 0;
    }

    Elem *no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL) {
        return 0;
    }

    no->dados = al;
    no->prox = fi->inicio;

    fi->inicio = no;

    if (fi->final == NULL) { // Fila vazia
        fi->final = no;
    }
    else {
        fi->final->prox = no;
    }

    fi->qtd++;

    return 1;
}
