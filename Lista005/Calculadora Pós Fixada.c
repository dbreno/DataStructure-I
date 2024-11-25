#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista {

    float info;
    struct lista *prox;

};

struct pilha {

    struct lista *prim;

};


struct calc {

    char f[21]; /*Formato para impressão*/
    struct pilha *stack; /*Pilha de operandos*/

};

void pilha_cria(struct pilha **);
void push(struct pilha **, float);
float pop(struct pilha **);
int pilha_vazia(struct pilha *);
void pilha_libera(struct pilha **);

//===================================================//
struct calc *calc_cria(char *);
void calc_operando(struct calc *, float);
void calc_operador(struct calc *, char);
void calc_libera(struct calc *);

//===================================================//

int main() {

    char c;
    float elemento;
    struct calc *calc;

    /*cria calculadora com formato de duas casas decimais*/
    calc = calc_cria("%.2f\n");

    do {
        /*lê o próximo caractere não branco*/
        scanf(" %c", &c);
        /*verifica se o operador é válido*/
        if(c == '+' || c == '-' || c == '*' || c == '/') {
            calc_operador(calc, c);
        } /*devolve o caractere lido e tenta ler número*/else {
            ungetc(c, stdin);
            if(scanf("%f", &elemento) == 1) {
                calc_operando(calc, elemento);
            }
        }

    } while(c != 'q');

    calc_libera(calc);

    return 0;
}



struct calc *calc_cria(char *formato) {

    struct calc *c = (struct calc*) malloc(sizeof(struct calc));
    if(!c) {
        printf("\nErro ao alocar memoria!\n");
        return NULL;
    }
    strcpy(c->f, formato);
    pilha_cria(&(c->stack)); /*cria pilha vazia*/
    return c;

}

void calc_operando(struct calc *c, float elemento) {

    /*empilha operando*/
    push(&(c->stack), elemento);

    /*imprime topo da pilha*/

    printf(c->f, elemento);

}

void calc_operador(struct calc *c, char op) {

    float elemento1, elemento2, elemento;

    /*desempilha operandos*/

    if(pilha_vazia(c->stack)) {
        elemento2 = 0.0;
    } else {
        elemento2 = pop(&(c->stack));
    }

    if(pilha_vazia(c->stack)) {
        elemento1 = 0.0;
    } else {
        elemento1 = pop(&(c->stack));
    }

    /*faz operação*/

    switch(op) {

        case '+': 
            elemento = elemento1 + elemento2;
            break;

        case '-':
            elemento = elemento1 - elemento2;
            break;

        case '*':
            elemento = elemento1 * elemento2;
            break;

        case '/':
            if(elemento2 != 0) {
                elemento = elemento1 / elemento2;
            } else {
                printf("\nErro: Divisao por zero!\n");
                return;
            }
            break;

    }

    /*empilha resultado*/
    push(&(c->stack), elemento);

    /*imprime topo da pilha*/
    printf(c->f, elemento);

}

void calc_libera(struct calc *c) {
    pilha_libera(&(c->stack));
    free(c);
}

//===================================================//

void pilha_cria(struct pilha **stack) {

    *stack = (struct pilha *) malloc(sizeof(struct pilha));  // Aloca memória para a pilha
    if (!(*stack)) {
        printf("\nErro ao alocar memoria!\n");
        exit(1);  // Sai do programa caso a alocação falhe
    }
    (*stack)->prim = NULL;  // Inicializa o campo `prim` da pilha como NULL

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


}

float pop(struct pilha **stack) {

    if(pilha_vazia(*stack)) { 
        printf("\nPilha vazia!\n");
        return -1; // Retorna um valor de erro
    }

    struct lista *aux = (*stack)->prim; // Auxiliar aponta para o topo
    float elemento = aux->info;         // Guarda o valor do topo

    (*stack)->prim = aux->prox; // Atualiza o topo da pilha
    free(aux); // Libera a memória do nó removido

    return elemento;
}

int pilha_vazia(struct pilha *stack) {

    return(!stack->prim);

}

void pilha_libera(struct pilha **stack) {

    struct lista *aux = (*stack)->prim;
    struct lista *sai = NULL;

    while(aux) {
        sai = aux;
        aux = aux->prox;
        free(sai);
    }

    (*stack)->prim = NULL;

    printf("\nPilha esvaziada com sucesso!\n");
    
}