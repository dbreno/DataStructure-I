#include <stdio.h>
#include <stdlib.h>

struct lista {
    float info;
    struct lista *prox;
};

struct pilha {
    struct lista *prim;
};

void criar_pilha(struct pilha **);
void push(struct pilha **, float);
float pop(struct pilha **);
int pilha_vazia(struct pilha *);
void pilha_libera(struct pilha **);

int main() {
    
    int opcao;
    float elemento;

    struct pilha *stack;
    criar_pilha(&stack);

    do {

        printf("\n===Menu===\n");
        printf("1.Inserir no topo da pilha\n");
        printf("2.Remover topo da pilha\n");
        printf("3.Esta vazia\n");
        printf("4.Esvaziar pilha\n");
        printf("5.Sair\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        system("cls");

        switch(opcao) {

            case 1:
                printf("\nInforme o elemento: ");
                scanf("%f", &elemento);
                push(&stack, elemento);
                break;

            case 2:
                if(!pilha_vazia(stack)) {
                    elemento = pop(&stack);
                    printf("\nElemento retornado: %.2f", elemento);
                }
                break;

            case 3:
                if(pilha_vazia(stack)) {
                    printf("\nPilha esta vazia!\n");
                } else {
                    printf("\nPilha NAO esta vazia!\n");
                }
                break;

            case 4:
                pilha_libera(&stack);
                break;

            case 5:
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;

        }

    } while(opcao != 5);

    
    
    return 0;
}

void criar_pilha(struct pilha **stack) {
    
    *stack = (struct pilha *) malloc(sizeof(struct pilha));

    if(!(*stack)) {
        printf("\nErro ao alocar memoria!\n");
        return;
    }
    
    (*stack)->prim = NULL;

}

void push(struct pilha **stack, float elemento) {

    struct lista *novo = (struct lista*) malloc(sizeof(struct lista));

    if(!novo) {
        printf("\nErro ao alocar memoria!\n");
        return;
    }

    novo->info = elemento;
    novo->prox = (*stack)->prim;
    (*stack)->prim = novo;

    printf("\nElemento inserido no topo da pilha com sucesso!\n");

}

float pop(struct pilha **stack) {

    if(pilha_vazia(*stack)) { 
        printf("\nPilha vazia!\n");
        exit(1); // Retorna um valor de erro
    }

    struct lista *aux = (*stack)->prim; // Auxiliar aponta para o topo
    float elemento = aux->info;         // Guarda o valor do topo

    (*stack)->prim = aux->prox; // Atualiza o topo da pilha
    free(aux); // Libera a memória do nó removido

    printf("\nElemento retirado do topo da pilha com sucesso!\n");

    return elemento;
}

int pilha_vazia(struct pilha *stack) {

    return(!stack->prim);

}

void pilha_libera(struct pilha **stack) {

    while(((*stack)->prim)) {

        pop(stack);
        
    }

    free(*stack);

    printf("\nPilha esvaziada com sucesso!\n");
    
}

