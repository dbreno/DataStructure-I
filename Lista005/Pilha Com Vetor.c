#include <stdio.h>
#include <stdlib.h>

#define N 50

struct pilha {

    int topo;
    float vet[N];

};

void criar_pilha(struct pilha **);
void push(struct pilha **, float);
float pop(struct pilha **);
int pilha_vazia(struct pilha *);
void pilha_libera(struct pilha **);


int main() {

    struct pilha *stack;
    criar_pilha(&stack);

    int opcao;
    float elemento;

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

    *stack = (struct pilha *) malloc(sizeof(struct pilha)); // Alocação dinâmica da pilha

    if(!(*stack)) {
        printf("\nErro ao alocar memoria!\n");
        return;
    }

    (*stack)->topo = -1;

}

void push(struct pilha **stack, float elemento) {

    if((*stack)->topo == N - 1) { /*Capacidade esgotada*/

        printf("\nCapacidade da pilha estourou!\n");
        return;

    }

    (*stack)->topo++;
    (*stack)->vet[(*stack)->topo] = elemento;
    

    printf("\nElemento inserido no topo da pilha com sucesso!\n");

}

float pop(struct pilha **stack) {

    if(pilha_vazia(*stack)) {
        printf("\nPilha vazia!\n");
        exit(1);
    }

    /*retira elemento do topo*/

    float elemento;

    elemento = (*stack)->vet[(*stack)->topo];
    (*stack)->topo--;

    printf("\nTopo da pilha removido com sucesso!\n");

    return elemento;

}

int pilha_vazia(struct pilha *stack) {

    return(stack->topo == -1);

}

void pilha_libera(struct pilha **stack) {
    free(*stack);
    printf("\nPilha esvaziada com sucesso!\n");
}




