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

/*concatenar listas*/
void concatenar_listas(struct no **, struct no **);

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

    struct no *l1, *l2;
    criar_lista(&l1);
    criar_lista(&l2);

    do {
        printf("\n===Menu===\n");
        printf("1.Inserir elemento no inicio (lista 1)\n");
        printf("2.Inserir elemento no fim (lista 1)\n");
        printf("3.Inserir elemento no inicio (lista 2)\n");
        printf("4.Inserir elemento no fim (lista 2)\n");
        printf("5.Mostrar lista 1\n");
        printf("6.Mostrar lista 2\n");
        printf("7.Concatenar listas\n");
        printf("8.Mostrar lista concatenada\n");
        printf("9.Sair\n");
        printf("Digite uma opcao valida: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                printf("\nInforme o elemento: ");
                scanf("%d", &elemento);
                inserir_inicio(&l1, elemento);
                printf("\nElemento inserido com sucesso!");
                break;
            case 2:
                printf("\nInforme o elemento: ");
                scanf("%d", &elemento);
                inserir_fim(&l1, elemento);
                printf("\nElemento inserido com sucesso!");
                break;
            case 3:
                printf("\nInforme o elemento: ");
                scanf("%d", &elemento);
                inserir_inicio(&l2, elemento);
                printf("\nElemento inserido com sucesso!");
                break;
            case 4:
                printf("\nInforme o elemento: ");
                scanf("%d", &elemento);
                inserir_fim(&l2, elemento);
                printf("\nElemento inserido com sucesso!");
                break;
            case 5:
                printf("\nLista 1: ");
                mostrar_lista(l1);
                break;
            case 6:
                printf("\nLista 2: ");
                mostrar_lista(l2);
                break;
            case 7:
                concatenar_listas(&l1, &l2);
                printf("\nListas concatenadas com sucesso!\n");
                break;
            case 8:
                printf("\nLista concatenada: ");
                mostrar_lista(l1);
                break;
            case 9:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    } while (opcao != 9);

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

void concatenar_listas(struct no **l1, struct no **l2) {

    if(esta_vazia(*l1)) {
        *l1 = *l2; // Se a primeira lista estiver vazia, basta fazer l1 apontar para l2
        return;
    }

    struct no *aux = *l1;

    while(aux->prox) {
        aux = aux->prox;
    }

    aux->prox = *l2;
    (*l2)->ant = aux;

    //Faz o último nó de l1 apontar para o primeiro nó de l2

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
