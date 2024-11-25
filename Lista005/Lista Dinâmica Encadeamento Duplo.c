#include <stdio.h>
#include <stdlib.h> // Função Malloc, free e exit

struct no {
    struct no *ant;
    int info;
    struct no *prox;
};

/*Busca elemento na lista*/
void busca_elemento(struct no *, int);

/*Função de criação: lista vazia*/
void criar_lista(struct no **);

/*Verifica se a lista está vazia*/
int esta_vazia(struct no *);

/*Esvaziar lista*/
void esvaziar_lista(struct no **);

/*Insere elemento no final da lista*/
void inserir_fim(struct no **, int);

/*Insere elemento no início da lista*/
void inserir_inicio(struct no **, int);

/*Insere elemento de forma ordenada na lista*/
void insere_ordenado(struct no **, int);

/*Ordena os elementos da lista em ordem crescente*/
void ordenar_lista(struct no **);

/*Percorre e exibe todos os elementos da lista*/
void mostrar_lista(struct no *);

/*Remover elemento da lista*/
void remove_elemento(struct no **, int);

int main() {
    
    int opcao, elemento;

    struct no *l;
    criar_lista(&l);

    do {

        printf("\n===Menu===\n");
        printf("1.Inserir elemento no inicio\n");
        printf("2.Inserir elemento no fim\n");
        printf("3.Mostrar lista\n");
        printf("4.Verificar se esta vazia\n");
        printf("5.Esvaziar lista\n");
        printf("6.Buscar elemento\n");
        printf("7.Remover elemento\n");
        printf("8.Inserir ordenado\n");
        printf("9.Ordenar lista\n");
        printf("10.Sair\n");
        printf("Digite uma opcao valida: ");
        scanf("%d", &opcao);

        system("cls");

        switch(opcao) {
            
            case 1:
                printf("\nInforme o elemento: ");
                scanf("%d", &elemento);
                inserir_inicio(&l, elemento);
                printf("\nElemento inerido com sucesso!\n");
                break;

            case 2:
                printf("\nInforme o elemento: ");
                scanf("%d", &elemento);
                inserir_fim(&l, elemento);
                printf("\nElemento inserido com sucesso!\n");
                break;

            case 3:
                mostrar_lista(l);
                break;

            case 4:
                if(esta_vazia(l)) {
                    printf("\nEsta vazia!\n");
                } else {
                    printf("\nNao esta vazia!\n");
                }
                break;

            case 5:
                esvaziar_lista(&l);
                break;

            case 6:
                printf("\nInforme o elemento: ");
                scanf("%d", &elemento);
                busca_elemento(l, elemento);
                break;

            case 7:
                printf("\nInforme o elemento: ");
                scanf("%d", &elemento);
                remove_elemento(&l, elemento);
                break;

            case 8:
                printf("\nInforme o elemento: ");
                scanf("%d", &elemento);
                insere_ordenado(&l, elemento);
                printf("\nElemento inserido com sucesso!\n");
                break;

            case 9:
                ordenar_lista(&l);
                break;

            case 10:
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    } while (opcao != 10);

    return 0;

}

/*Busca elemento na lista*/
void busca_elemento(struct no *l, int elemento) {

    if(esta_vazia(l)) {
        printf("\nNao foi possivel buscar o elemento, pois a lista esta vazia!\n");
        return;
    }
    
    struct no *aux;
    aux = l;

    int posicao = 0;

    for(; aux; aux = aux->prox, posicao++) {

        if(aux->info == elemento) {
            printf("\nElemento encontrado na posicao %d\n", posicao);
            return;
        }

    }

    printf("\nElemento nao encontrado!\n");

}

/*Função de criação: lista vazia*/
void criar_lista(struct no **l) {

    *l = NULL;

}

/*Verifica se a lista está vazia*/
int esta_vazia(struct no *l) {

    return(!l);

}

/*Esvaziar lista*/
void esvaziar_lista(struct no **l) {
    
    if(!(*l)) {
        printf("\nLista esvaziada com sucesso!\n");
        return;
    }

    struct no *aux = *l;

    for(; aux->prox; aux = aux->prox) {

        if (aux->ant) {
            free(aux->ant);
        }

    }

    free(aux);

    *l = NULL;

    printf("\nLista esvaziada com sucesso!\n");

}

/*Insere elemento no final da lista*/
void inserir_fim(struct no **l, int elemento) {

    struct no *novo;
    novo = (struct no *) malloc(sizeof(struct no));

    if(!novo) {

        printf("\nErro ao alocar memoria!\n");
        return;

    }

    novo->info = elemento;

    // Verifica se a lista está vazia, caso esteja, inserção no inicio

    if(!(*l)) {
        novo->prox = *l;
        novo->ant = NULL;
        *l = novo;
    } else {

        struct no *aux = *l;

        // Chegar ao último elemento para inserir no fim
        for(; aux->prox; aux = aux->prox);

        novo->prox = aux->prox;
        novo->ant = aux;
        aux->prox = novo;
        
    }


}

/*Insere elemento no início da lista*/
void inserir_inicio(struct no **l, int elemento) {

    struct no *novo;
    novo = (struct no *) malloc(sizeof(struct no));

    if(!novo) {

        printf("\nErro ao alocar memoria!\n");
        return;

    }

    novo->info = elemento;

    novo->prox = *l;

    // Verifica se a lista está vazia!
    if(!(*l)) {
        
        novo->ant = NULL;
        *l = novo;

    } else {

        novo->ant = novo->prox->ant;
        (*l)->ant = novo;
        *l = novo;

    }

}

/*Insere elemento de forma ordenada na lista*/
void insere_ordenado(struct no **l, int elemento) {

    struct no *novo = (struct no *) malloc(sizeof(struct no));

    if(!novo) {
    
        printf("\nErro ao alocar memoria!\n");
        return;

    }

    novo->info = elemento;

    struct no *aux = *l;

    if(!(*l)) {

        // Verifica se está vazia

        novo->prox = *l;
        novo->ant = NULL;
        *l = novo;
        return;

    } 

    for(; aux->prox && aux->info < elemento; aux = aux->prox);

    
    if (aux == *l && aux->info >= elemento) {

        // Verifica se a inserção vai ser no início
        novo->prox = aux;
        novo->ant = novo->prox->ant;
        aux->ant = novo;
        *l = novo;

    } else if (!aux->prox && aux->info <= elemento) {

        // Verifica se a inserção vai ser no fim

        novo->prox = aux->prox;
        novo->ant = aux;
        aux->prox = novo;

    } else {

        // Verifica se a inserção vai ser no meio

        novo->prox = aux;
        novo->ant = aux->ant;
        aux->ant->prox = novo;
        aux->ant = novo;

    }




}

/*Ordena os elementos da lista em ordem crescente*/
void ordenar_lista(struct no **l) {
    
    if(esta_vazia(*l)) {
        printf("\nNao foi possivel ordenar a lista, pois ela esta vazia!\n");
        return;
    }

    struct no *aux;
    aux = *l;
    int lslen = 0;
    int temp;

    for(; aux; aux = aux->prox, lslen++);

    for(int i = 0; i < lslen - 1; i++) {

        aux = *l;

        for(int j = 0; j < lslen - i - 1; j++) {

            if(aux->info > aux->prox->info) {

                temp = aux->prox->info;
                aux->prox->info = aux->info;
                aux->info = temp;

            }

            aux = aux->prox;

        }

    }

    printf("\nLista ordenada com sucesso!\n");

}

/*Percorre e exibe todos os elementos da lista*/
void mostrar_lista(struct no *l) {

    if(esta_vazia(l)) {
        printf("\nNao eh possivel mostrar a lista, pois ela esta vazia!\n");
        return;
    }

    struct no *aux = l;

    printf("\n[");

    for(; aux; aux = aux->prox) {
        
        printf("%d", aux->info);

        if(aux->prox) {
            printf(", ");
        }

    }

    printf("]\n");

}

/*Remover elemento da lista*/
void remove_elemento(struct no **l, int elemento) {
    
    if(esta_vazia(*l)) {
        printf("\nNao foi possivel remover elemento, pois a lista esta vazia!\n");
        return;
    }

    struct no *aux;
    aux = *l;

    for(; aux && aux->info != elemento; aux = aux->prox);

    if(!aux) { 
        printf("\nElemento nao encontrado!\n");
        return;
    }

    if(!aux->ant && !aux->prox) {
       free(aux);
       *l = NULL; 
    } else if(!aux->ant) {
        aux->prox->ant = NULL;
        *l = aux->prox;
        free(aux);
    } else if(!aux->prox) {
        aux->ant->prox = aux->prox;
        free(aux);
    } else {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        free(aux);
    }

    printf("\nElemento removido com sucesso!\n");

    

}
