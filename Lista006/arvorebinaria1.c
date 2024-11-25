/*
Funções:

cria_arvore
mostra_arvore
limpa_arvore
*/

#include <stdio.h>
#include <stdlib.h>

struct no {
    struct no *esq;
    int info;
    struct no *dir;
};

struct no *cria_arvore(int, struct no *, struct no *);
void mostra_arvore(struct no *);
struct no *limpa_arvore(struct no *);


int main() {

    struct no *arvore = NULL;

    arvore = cria_arvore(4, NULL, NULL);
    arvore->esq = cria_arvore(2, NULL, NULL);
    arvore->dir = cria_arvore(6, NULL, NULL);
    arvore->esq->esq = cria_arvore(1, NULL, NULL);
    arvore->esq->dir = cria_arvore(3, NULL, NULL);
    arvore->dir->esq = cria_arvore(5, NULL, NULL);
    arvore->dir->dir = cria_arvore(7, NULL, NULL);

    mostra_arvore(arvore);

    arvore = limpa_arvore(arvore);

    if(!arvore) {
        printf("\nArvore esvaziada com sucesso!\n");
    }

    return 0;
}

struct no *cria_arvore(int valor, struct no *fesq, struct no *fdir) {

    struct no *novo = (struct no *) malloc(sizeof(struct no));

    if(!novo) {

        printf("\nErro ao alocar memoria!\n");

        return NULL;

    }

    novo->info = valor;
    novo->esq = fesq;
    novo->dir = fdir;

    return novo;

}

void mostra_arvore(struct no *raiz) {
    if(raiz) {
        printf("%d ", raiz->info);
        mostra_arvore(raiz->esq);
        mostra_arvore(raiz->dir);
    } else {
        return;
    }
    
}

struct no *limpa_arvore(struct no *raiz) {

    if(raiz) {

        raiz->esq = limpa_arvore(raiz->esq);
        raiz->dir = limpa_arvore(raiz->dir);
        free(raiz);
        return NULL;

    } else {

        return NULL;

    }

}
