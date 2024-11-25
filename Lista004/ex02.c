/*
Faça uma lista ordenada!
*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa uma lista ordenada
struct ListaOrdenada {
    int *dados; // Ponteiro para os dados da lista
    int controle; // Índice do último elemento inserido
    int tamanhoMaximo; // Tamanho máximo da lista
};

// Declaração das funções que manipulam a lista ordenada
struct ListaOrdenada *criar(int);
int estaCheia(struct ListaOrdenada);
int estaVazia(struct ListaOrdenada);
void esvaziar(struct ListaOrdenada *);
void inserirElemento(struct ListaOrdenada *, int);
void liberaMemoriaLista(struct ListaOrdenada *);
void mostrar(struct ListaOrdenada);
void removerFim(struct ListaOrdenada *);
void removePorIndice(struct ListaOrdenada *, int);
void removePorValor(struct ListaOrdenada *, int);

int main() {
    int opcao, elemento, indice;
    struct ListaOrdenada *l;
    l = criar(5); // Cria uma lista ordenada com tamanho máximo 5

    do {
        // Menu de opções
        printf("\nMenu:\n");
        printf("1.Esta Cheia\n");
        printf("2.Esta Vazia\n");
        printf("3.Esvaziar\n");
        printf("4.Inserir Elemento\n");
        printf("5.Mostrar\n");
        printf("6.Remover fim\n");
        printf("7.Remover por indice\n");
        printf("8.Remover por valor\n");
        printf("9.Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao);
        system("cls"); // Limpa a tela

        switch(opcao) {
            case 1:
                // Verifica se a lista está cheia
                if(estaCheia(*l)) {
                    printf("\nA lista esta cheia!\n");
                } else {
                    printf("\nA lista NAO esta cheia!\n");
                }
                break;
            
            case 2:
                // Verifica se a lista está vazia
                if(estaVazia(*l)) {
                    printf("\nA lista esta vazia!\n");
                } else {
                    printf("\nA lista NAO esta vazia!\n");
                }
                break;

            case 3:
                // Esvazia a lista
                esvaziar(l);
                printf("\nLista esvaziada com sucesso!\n");
                break;

            case 4:
                // Insere um elemento na lista
                if(estaCheia(*l)) {
                    printf("\nNao eh possivel adicionar elemento, pois a lista esta cheia!\n");
                } else {
                    printf("\nInforme o elemento: ");
                    scanf("%d", &elemento);
                    inserirElemento(l, elemento);
                    printf("\nElemento inserido com sucesso!\n");
                }
                break;

            case 5:
                // Mostra os elementos da lista
                if(estaVazia(*l)) {
                    printf("\nNao eh possivel mostrar a lista, pois ela esta vazia!\n");
                } else {
                    mostrar(*l);
                }
                break;
                
            case 6:
                // Remove o último elemento da lista
                if(estaVazia(*l)) {
                    printf("\nNao eh possivel remover elemento, pois a lista esta vazia!\n");
                } else {
                    removerFim(l);
                    printf("\nElemento removido com sucesso!\n");
                }
                break;

            case 7:
                // Remove um elemento pelo índice
                if(estaVazia(*l)) {
                    printf("\nNao eh possivel remover elemento, pois a lista esta vazia!\n");
                } else {
                    do {
                        printf("\nDigite o indice do elemento a ser removido [0 - %d]: ", l->controle);
                        scanf("%d", &indice);
                    } while (indice < 0 || indice > l->controle);
                    
                    removePorIndice(l, indice);
                    printf("\nElemento removido com sucesso!\n");
                }
                break;

            case 8:
                // Remove um elemento pelo valor
                if(estaVazia(*l)) {
                    printf("\nNao eh possivel remover elemento, pois a lista esta vazia!\n");
                } else {
                    printf("\nInforme o elemento: ");
                    scanf("%d", &elemento);
                    removePorValor(l, elemento);
                    printf("\nElemento removido com sucesso!\n");
                }
                break;

            case 9:
                // Sai do programa
                printf("\nSaindo...\n");
                break;

            default:
                // Opção inválida
                printf("\nOpcao invalida!\n");
                break;
        }
    } while (opcao != 9);

    // Libera a memória alocada para a lista
    liberaMemoriaLista(l);

    return 0;
}

// Função para criar uma lista ordenada
struct ListaOrdenada *criar(int tamanho) {
    struct ListaOrdenada *l = (struct ListaOrdenada *) malloc(sizeof(struct ListaOrdenada));
    l->dados = (int *) malloc(tamanho * sizeof(int));

    if (l == NULL || l->dados == NULL) {
        printf("\nErro de alocacao de memoria!\n");
        return NULL;
    }

    l->controle = -1; // Inicializa a lista como vazia
    l->tamanhoMaximo = tamanho - 1; // Define o tamanho máximo da lista

    return l;
}

// Função para verificar se a lista está cheia
int estaCheia(struct ListaOrdenada l) {
    if (l.controle == l.tamanhoMaximo) {
        return 1;
    } else {
        return 0;
    }
}

// Função para verificar se a lista está vazia
int estaVazia(struct ListaOrdenada l) {
    if (l.controle == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Função para esvaziar a lista
void esvaziar(struct ListaOrdenada *l) {
    l->controle = -1;
}

// Função para inserir um elemento na lista de forma ordenada
void inserirElemento(struct ListaOrdenada *l, int elemento) {
    int i;
    
    // Encontra a posição correta para inserir o elemento
    for(i = 0; i <= l->controle; i++) {
        if (elemento <= l->dados[i]) {
            break;
        }
    }

    // Desloca os elementos para abrir espaço para o novo elemento
    for(int j = l->controle; j >= i; j--) {
        l->dados[j + 1] = l->dados[j];
    }

    l->dados[i] = elemento; // Insere o elemento na posição correta
    l->controle++; // Atualiza o índice do último elemento
}

// Função para liberar a memória alocada para a lista
void liberaMemoriaLista(struct ListaOrdenada *l) {
    free(l->dados);
    free(l);
}

// Função para mostrar os elementos da lista
void mostrar(struct ListaOrdenada l) {
    printf("\n[");

    for(int i = 0; i <= l.controle; i++) {
        printf("%d", l.dados[i]);
        if (l.controle > i) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Função para remover o último elemento da lista
void removerFim(struct ListaOrdenada *l) {
    l->controle = l->controle - 1;
}

// Função para remover um elemento pelo índice
void removePorIndice(struct ListaOrdenada *l, int indice) {
    for(int i = indice; i < l->controle; i++) {
        l->dados[i] = l->dados[i + 1];
    }
    l->controle = l->controle - 1;
}

// Função para remover um elemento pelo valor
void removePorValor(struct ListaOrdenada *l, int elemento) {
    for(int i = 0; i <= l->controle; i++) {
        if(l->dados[i] == elemento) {
            for (int j = i; j < l->controle; j++) {
                l->dados[j] = l->dados[j + 1];
            }
            l->controle = l->controle - 1;
            return;
        }
    }
    printf("\nElemento nao encontrado!\n");
}