/*
exercício de ED: ordenar uma lista

funções

criar
mostrar
inserir_fim
remover_fim
esta_vazia
esta_cheia
esvaziar / limpar

e fazer um menu

deixar lista com definição de tamanho N 

cuidados:

Ao inserir, verificar se está cheia. Na remoção, verificar se está vazia.
Não esquecer a função de criar.

Coisas a lembrar: colocar elemento -> modifica a lista. Modifica a lista -> exclui/desaparece com o elemento
*/

#include <stdio.h>
#include <stdlib.h>

#define N 5

struct Lista {
    int dados[N];
    int controle;
};

void criar(struct Lista *);
int esta_cheia(struct Lista);
int esta_vazia(struct Lista);
void esvaziar(struct Lista *);
void inserir_fim(struct Lista *, int);
void inserir_inicio(struct Lista *, int);
void inserir_meio(struct Lista *, int, int);
void ordenar(struct Lista *);
void mostrar(struct Lista);
void remover_fim(struct Lista *);
void remover_inicio(struct Lista *);
void remover_meio(struct Lista *, int);
void inserir_ordenado(struct Lista *, int);  


int main() {

    struct Lista l;
    criar(&l);
    int opcao, elemento, posicao;

    do {
        printf("\nMenu:\n");
        printf("1.Esta cheia\n");
        printf("2.Esta vazia\n");
        printf("3.Esvaziar\n");
        printf("4.Inserir fim\n");
        printf("5.Inserir inicio\n");
        printf("6.Inserir meio\n");
        printf("7.Ordenar\n");
        printf("8.Mostrar\n");
        printf("9.Remover fim\n");
        printf("10.Remover inicio\n");
        printf("11.Remover meio\n");
        printf("12.Inserir ordenado\n");
        printf("13.Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        system("clear");

        switch(opcao) {
            case 1:

                if(esta_cheia(l)) {
                    printf("\nA lista esta cheia!\n");
                } else {
                    printf("\nA lista NAO esta cheia!\n");
                }
                break;

            case 2:

                if(esta_vazia(l)) {
                    printf("\nA lista esta vazia!\n");
                } else {
                    printf("\nA lista NAO esta vazia!\n");
                }
                break;

            case 3:

                esvaziar(&l);
                break;

            case 4:

                printf("\nInforme o elemento: ");
                scanf("%d", &elemento);
                inserir_fim(&l, elemento);
                break;

            case 5:

                printf("\nInforme o elemento: ");
                scanf("%d", &elemento);
                inserir_inicio(&l, elemento);    

                break;

            case 6:

                printf("\nInforme a posicao: ");
                scanf("%d", &posicao);
                printf("\nInforme o elemento: ");
                scanf("%d", &elemento);
                inserir_meio(&l, elemento, posicao);
                break;

            case 7:

                ordenar(&l);
                break;

            case 8:

                mostrar(l);
                break;

            case 9:

                remover_fim(&l);
                break;

            case 10:

                remover_inicio(&l);
                break;

            case 11:


                printf("\nInforme a posicao: ");
                scanf("%d", &posicao);
                remover_meio(&l, posicao);
                break;

            case 12:

                printf("\nInforme o elemento: ");
                scanf("%d", &elemento);
                inserir_ordenado(&l, elemento);  
                break;

            case 13:

                printf("\nSaindo...\n");
                break;

            default:

                printf("\nOpcao invalida!\n");
                break;

        }


    } while (opcao != 13);

}

void criar(struct Lista *l) {

    l->controle = -1;


}

int esta_cheia(struct Lista l) {

    return(l.controle == N - 1);

}

int esta_vazia(struct Lista l) {

    return(l.controle == -1);

}

void esvaziar(struct Lista *l) {

    l->controle = -1;

    printf("\nLista esvaziada com sucesso!\n");

}

void inserir_fim(struct Lista *l, int elemento) {

    if(esta_cheia(*l)) {
        printf("\nNao foi possivel adicionar elemento, pois a lista esta cheia!\n");
        return;
    }

    l->controle++;
    l->dados[l->controle] = elemento;

    printf("\nElemento inserido com sucesso!\n");

}

void inserir_inicio(struct Lista *l, int elemento) {

    if(esta_cheia(*l)) {
        printf("\nNao foi possivel adicionar elemento, pois a lista esta cheia!\n");
        return;
    }

    for(int i = l->controle; i >= 0; i--) {
        l->dados[i + 1] = l->dados[i];
    }

    l->dados[0] = elemento;
    l->controle++;


    printf("\nElemento inserido com sucesso!\n");

}

void inserir_meio(struct Lista *l, int elemento, int posicao) {

    if(esta_cheia(*l)) {
        printf("\nNao foi possivel adicionar elemento, pois a lista esta cheia!\n");
        return;
    }

    if(posicao < 0 || posicao > l->controle) {

        printf("\nPosicao invalida!\n");
        return;

    }

    for(int i = l->controle; i >= posicao; i--) {
        l->dados[i + 1] = l->dados[i];
    }

    l->dados[posicao] = elemento;
    l->controle++;

    printf("\nElemento inserido com sucesso!\n");

}

void ordenar(struct Lista *l) {

    if(esta_vazia(*l)) {
        printf("\nNao foi possivel ordenar lista, pois ela esta vazia!\n");
        return;
    }

    int temp;

    for(int i = 0; i < l->controle; i++) {
        for(int j = 0; j < l->controle - i; j++) {
            if(l->dados[j] > l->dados[j + 1]) {
                temp = l->dados[j + 1];
                l->dados[j + 1] = l->dados[j];
                l->dados[j] = temp;
            }
        }
    }

    printf("\nLista ordenada com sucesso!\n");

}

void mostrar(struct Lista l) {

    if(esta_vazia(l)) {
        printf("\nNao eh possivel mostrar a lista, pois ela esta vazia!\n");
        return;
    }

    printf("\n[");

    for(int i = 0; i <= l.controle; i++) {
        printf("%d", l.dados[i]);
        if(l.controle > i) {
            printf(", ");
        }
    }

    printf("]\n");

}


void remover_fim(struct Lista *l) {

    if(esta_vazia(*l)) {
        printf("\nNao foi possivel remover elemento, pois a lista esta vazia!\n");
        return;
    }

    l->controle--;

    printf("\nElemento removido com sucesso!\n");

}
void remover_inicio(struct Lista *l) {

    if(esta_vazia(*l)) {
        printf("\nNao foi possivel remover elemento, pois a lista esta vazia!\n");
        return;
    }

    for(int i = 0; i < l->controle; i++) {
        l->dados[i] = l->dados[i + 1];
    }

    l->controle--;

    printf("\nElemento removido com sucesso!\n");

}

void remover_meio(struct Lista *l, int posicao) {

    if(esta_vazia(*l)) {
        printf("\nNao foi possivel remover elemento, pois a lista esta vazia!\n");
        return;
    }    

    int i = posicao;

    for(; i < l->controle; i++) {
        l->dados[i] = l->dados[i + 1];
    }

    l->controle--;

    printf("\nElemento removido com sucesso!\n");

}

void inserir_ordenado(struct Lista *l, int elemento) {

    if(esta_cheia(*l)) {
        printf("\nNao foi possivel inserir elemento, pois a lista esta cheia!\n");
        return;
    }

    if(esta_vazia(*l)) {
        l->controle++;
        l->dados[l->controle] = elemento;
    } else {
        int i;

        for(i = 0; i <= l->controle && l->dados[i] < elemento; i++);

        for(int j = l->controle; j >= i; j--) {
            l->dados[j + 1] = l->dados[j];
        }

        l->dados[i] = elemento;
        l->controle++;
        printf("\nElemento inserido com sucesso!\n");

    }

}