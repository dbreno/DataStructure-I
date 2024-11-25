#include <stdio.h>
#include <stdlib.h> // Função Malloc, free e exit

struct no {
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
        printf("\nNao foi possivel buscar elemento, pois a lista esta vazia!\n");
        return;
    }

    int contador = 0;

    struct no *aux;

    aux = l;

    do {

        if(aux->info == elemento) {
            printf("\nElemento encontrado na posicao %d\n", contador);
            return; 
        }

        aux = aux->prox;
        contador++;

    } while(aux != l);
        
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

    if (esta_vazia(*l)) {
        printf("\nA lista já está vazia!\n");
        return;
    }

    struct no *aux, *sai; 
    aux = *l; 
    sai = NULL; 

    do {
        sai = aux; 
        aux = aux->prox;
        free(sai);
    } while (aux != *l);
    
    *l = NULL; 

    printf("\nLista esvaziada com sucesso!\n");
    
}

/*Insere elemento no final da lista*/
void inserir_fim(struct no **l, int elemento) {

    struct no *novo = (struct no *) malloc(sizeof(struct no)); 

    
    if(!novo) {
        printf("\nErro ao alocar memoria!\n");
        return; 
    }

    novo->info = elemento; 

    struct no *aux; 

    aux = *l; 

    if (!aux) {

        novo->prox = novo;
        *l = novo;

        return; 
    }

    do {

        aux = aux->prox;

    } while(aux->prox != *l);
    
    aux->prox = novo;
    novo->prox = *l;

}

/*Insere elemento no início da lista*/
void inserir_inicio(struct no **l, int elemento) {

    struct no *novo = (struct no *) malloc(sizeof(struct no));

    if(!novo) {
        printf("\nErro ao alocar memoria!\n");
        return;
    }

    novo->info = elemento;

    if(esta_vazia(*l)) {
        *l = novo; 
        novo->prox = *l; 
    } else {
        struct no *aux = *l;
        do {

            aux = aux->prox;

        } while(aux->prox != *l);

        aux->prox = novo;
        novo->prox = *l;
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

    if(esta_vazia(*l)) {

        *l = novo;
        novo->prox = novo;
        return;

    }

    struct no *aux; // Percorrer a lista
    aux = *l; // Aponta para inicio da lista

    // Caso especial: inserir no início da lista
    if(aux->info >= elemento) {

        while(aux->prox != *l) {

            aux = aux->prox;

        }

        novo->prox = *l;
        aux->prox = novo;
        *l = novo;

    }

    // Percorrer a lista para encontrar a posição correta
    while (aux->prox != *l && aux->prox->info < elemento) {

        aux = aux->prox;

    }

    novo->prox = aux->prox;
    aux->prox = novo;

}

/*Ordena os elementos da lista em ordem crescente*/
void ordenar_lista(struct no **l) {
    if (esta_vazia(*l)) {
        printf("\nNao foi possivel ordenar a lista, pois ela esta vazia!\n");
        return;
    }

    struct no *aux;
    int temp;
    int trocou;

    do {
        trocou = 0;
        aux = *l;

        while (aux->prox != *l) {
            if (aux->info > aux->prox->info) {
                temp = aux->info;
                aux->info = aux->prox->info;
                aux->prox->info = temp;
                trocou = 1;
            }
            aux = aux->prox;
        }

        // Verifica a última troca
        if (aux->info > (*l)->info) {
            temp = aux->info;
            aux->info = (*l)->info;
            (*l)->info = temp;
            trocou = 1;
        }

    } while (trocou);

    printf("\nLista ordenada com sucesso!\n");
}

/*Percorre e exibe todos os elementos da lista*/
void mostrar_lista(struct no *l) {

    if(esta_vazia(l)) {
        printf("\nNao foi possivel mostrar a lista, pois ela esta vazia!\n");
        return;
    }

    struct no *aux = l;

    printf("\n[");

    
    do {

        printf("%d", aux->info);

        if(aux->prox != l) {
            printf(", ");
        }

        aux = aux->prox;

    } while (aux != l);
    
    printf("]\n");

}

/*Remover elemento da lista*/
void remove_elemento(struct no **l, int elemento) {

    if(esta_vazia(*l)) {
        printf("\nNao foi possivel remover elemento, pois a lista esta vazia!\n");
        return;
    }

    struct no *aux = *l, *ant = NULL;

    while(aux->prox != *l && aux->info != elemento) {

        ant = aux;
        aux = aux->prox;

    }

    if(aux->prox == *l && aux->info != elemento) {
        printf("\nElemento nao encontrado!\n");
        return;
    }

    // Só tem um elemento
    if(!ant && aux->prox == *l) {
        
        free(aux);
        *l = NULL;

    } else {

        // Só tem dois elementos e a remoção é no início
        if(!ant && aux->prox->prox == *l) {

            aux->prox->prox = aux->prox;
            *l = aux->prox;
            free(aux);

        } else {

            // Só tem dois elementos e a remoção é no fim
            if(aux->prox == *l) {

                ant->prox = *l;
                free(aux);

            // Tem mais de dois elementos
            } else {

                // Remoção no inicio
                if(!ant) {
                    struct no *aux2 = *l;
                    while(aux2->prox != *l) {
                        aux2 = aux2->prox;
                    }
                    aux2->prox = aux->prox;
                    *l = aux->prox;
                    free(aux);

                  // Remoção no fim  
                } else {

                    if(aux->prox == *l) {

                        ant->prox = aux->prox;
                        free(aux);

                    // Remoção no meio
                    } else {

                        ant->prox = aux->prox;
                        free(aux);

                    }

                }

            }

        }



    }

    printf("\nElemento removido com sucesso!\n");

}