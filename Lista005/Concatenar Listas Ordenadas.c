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

/* Nova função: Concatenar listas ordenadas */
void concatenar_listas_ordenadas(struct no **l1, struct no **l2, struct no **resultado);

/*Verifica se a lista está vazia*/
int esta_vazia(struct no *);

/*Esvaziar lista*/
void esvaziar_lista(struct no **);

/*Insere elemento de forma ordenada na lista*/
void insere_ordenado(struct no **, int);

/*Percorre e exibe todos os elementos da lista*/
void mostrar_lista(struct no *);

/*Remover elemento da lista*/
void remove_elemento(struct no **, int);

int main() {
    int opcao, elemento;
    struct no *l1, *l2, *resultado;  // Listas 1, 2 e a lista resultante
    criar_lista(&l1);
    criar_lista(&l2);
    criar_lista(&resultado);

    do {
        printf("\n===Menu===\n");
        printf("1. Inserir elemento ordenado na Lista 1\n");
        printf("2. Inserir elemento ordenado na Lista 2\n");
        printf("3. Mostrar Lista 1\n");
        printf("4. Mostrar Lista 2\n");
        printf("5. Concatenar Listas Ordenadas\n");
        printf("6. Esvaziar Lista 1\n");
        printf("7. Esvaziar Lista 2\n");
        printf("8. Buscar elemento em Lista 1\n");
        printf("9. Buscar elemento em Lista 2\n");
        printf("10. Remover elemento de Lista 1\n");
        printf("11. Remover elemento de Lista 2\n");
        printf("12. Sair\n");
        printf("Digite uma opcao valida: ");
        scanf("%d", &opcao);

        system("cls");

        switch(opcao) {
            case 1:
                printf("\nInforme o elemento para Lista 1: ");
                scanf("%d", &elemento);
                insere_ordenado(&l1, elemento);
                printf("\nElemento inserido na Lista 1 com sucesso!\n");
                break;

            case 2:
                printf("\nInforme o elemento para Lista 2: ");
                scanf("%d", &elemento);
                insere_ordenado(&l2, elemento);
                printf("\nElemento inserido na Lista 2 com sucesso!\n");
                break;

            case 3:
                printf("\nLista 1: ");
                mostrar_lista(l1);
                break;

            case 4:
                printf("\nLista 2: ");
                mostrar_lista(l2);
                break;

            case 5:
                concatenar_listas_ordenadas(&l1, &l2, &resultado);
                printf("\nListas concatenadas e ordenadas: ");
                mostrar_lista(resultado);
                break;

            case 6:
                esvaziar_lista(&l1);
                printf("\nLista 1 esvaziada com sucesso!\n");
                break;

            case 7:
                esvaziar_lista(&l2);
                printf("\nLista 2 esvaziada com sucesso!\n");
                break;

            case 8:
                printf("\nInforme o elemento para buscar na Lista 1: ");
                scanf("%d", &elemento);
                busca_elemento(l1, elemento);
                break;

            case 9:
                printf("\nInforme o elemento para buscar na Lista 2: ");
                scanf("%d", &elemento);
                busca_elemento(l2, elemento);
                break;

            case 10:
                printf("\nInforme o elemento para remover da Lista 1: ");
                scanf("%d", &elemento);
                remove_elemento(&l1, elemento);
                break;

            case 11:
                printf("\nInforme o elemento para remover da Lista 2: ");
                scanf("%d", &elemento);
                remove_elemento(&l2, elemento);
                break;

            case 12:
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    } while (opcao != 12);

    return 0;
}

/*Busca elemento na lista*/
void busca_elemento(struct no *l, int elemento) {

    // Verifica se a lista está vazia, caso esteja, encerra a função
    
    if(esta_vazia(l)) {
        printf("\nNao foi possivel buscar elemento, pois a lista esta vazia!\n");
        return;
    }

    int contador = 0; // Posição atual ao percorrer a lista

    struct no *aux; // Ponteiro aux para percorrer a lista

    aux = l; // aux vai apontar para onde l aponta, ou seja, para o primeiro elemento da lista (se existir)

    /* Estrutura de repetição para percorrer todos os elementos da lista
    -> Primeiro parâmetro vazio, pois aux já foi inicializado acima
    -> Segundo parâmetro pode ser interpretado como: enquanto aux for diferente de NULL, i.e, aux != NULL
    -> A interpretação do segundo parâmetro é equivalente a pensar: enquanto aux apontar para algum elemento, 
    ou enquanto o fim da lista ainda não foi alcançado
    -> O terceiro parâmetro atualiza o valor de aux para apontar para o elemento posterior e de contador para
    informar qual posição do elemento atual (notação parecida com a de um vetor)*/

    for(; aux; aux = aux->prox, contador++) {
        if(aux->info == elemento) {
            printf("\nElemento encontrado na posicao %d\n", contador);
            return; // Função encerra aqui se o elemento for encontrado de fato
        }
    }

    printf("\nElemento nao encontrado!\n"); // Aqui só é executado se o elemento não for encontrado

}

/*Função de criação: lista vazia*/
void criar_lista(struct no **l) {

    *l = NULL; // Lista não aponta para nada, pois ainda não tem elementos, apenas foi criada!

    // OBS: essa função é importante, pois sem ela, o ponteiro l poderia apontar para lixo!

}

void concatenar_listas_ordenadas(struct no **l1, struct no **l2, struct no **resultado) {

    struct no *aux1 = *l1;
    struct no *aux2 = *l2;
    struct no *ultimo = NULL;
    
    //Enquanto as duas listas não forem vazias
    while(aux1 && aux2) {

        struct no *novo = (struct no *) malloc(sizeof(struct no));

        if(!novo) {
            printf("\nErro ao alocar memoria!\n");
            return;
        }

        
        if(aux1->info < aux2->info) {

            novo->info = aux1->info;
            aux1 = aux1->prox;

        } else {

            novo->info = aux2->info;
            aux2 = aux2->prox;

        }

        if(ultimo) {
            ultimo->prox = novo;
        } else {
            *resultado = novo;
        }

        ultimo = novo;
        ultimo->prox = NULL;


    }

    //elementos restantes da primeira lista

    while(aux1) {

        struct no *novo = (struct no *) malloc(sizeof(struct no));

        if(!novo) {
            printf("\nErro ao alocar memoria!\n");
            return;
        }

        novo->info = aux1->info;
        aux1 = aux1->prox;


        if(ultimo) {
            ultimo->prox = novo;
        } else {
            *resultado = novo;
        }

        ultimo = novo;
        ultimo->prox = NULL;


    }

    //elementos restantes da segunda lista

    while(aux2) {

        struct no *novo = (struct no *) malloc(sizeof(struct no));

        if(!novo) {
            printf("\nErro ao alocar memoria!\n");
            return;
        }

        novo->info = aux2->info;
        aux2 = aux2->prox;


        if(ultimo) {
            ultimo->prox = novo;
        } else {
            *resultado = novo;
        }

        ultimo = novo;
        ultimo->prox = NULL;

    }


}

/*Verifica se a lista está vazia*/
int esta_vazia(struct no *l) {
    
    return(!l);

    /*
    Essa notação é mais simplificada, porém um pouco menos intuitiva de ser compreendida.
    É equivalente a fazer:

    ```
        if (l == NULL) {
            return 1;
        } else {
            return 0;
        }

    ```

    Apenas verificar l significa verificar se l aponta para alguma coisa. Fazer !l significa
    verifificar se l está apontando para nada (NULL), sendo assim, a lista está vazia.

    Se a condição é verdadeira, uma função do tipo int, em C, sempre vai retornar 1.
    1 é como se fosse um TRUE, ou seja, a lista está vazia! Caso não esteja, retorna 0.
    0 é como se fosse um FALSE. 1 é como um: sucesso! é verdade! 0 é como um: falha! mentira!
    
    Implicitamente, return(!l) retorna algo diferente de zero se for verdadeiro e 0 se for falso.

    */
}

/*Esvaziar lista*/
void esvaziar_lista(struct no **l) {

    struct no *aux, *sai; // aux para percorrer a lista e sai para remover o elemento apontado

    aux = *l; // aux aponta para o primeiro elemento da lista
    sai = NULL; // sai aponta para nada inicialmente

    // while(aux) é equivalente a while(aux != NULL): enquanto final da lista nao for alcançado

    while(aux) {

        sai = aux; // sai aponta para o elemento apontado por aux
        aux = aux->prox; // aux aponta para o proximo elemento da lista
        free(sai); // desaloca regiao de memoria apontada por sai: remove elemento

    }

    *l = NULL; // atualiza valor da lista, aponta para nada, pois não tem mais elemento!

    printf("\nLista esvaziada com sucesso!\n");
    
}

/*Insere elemento de forma ordenada na lista*/
void insere_ordenado(struct no **l, int elemento) {

    struct no *novo = (struct no *) malloc(sizeof(struct no));

    if(!novo) {
        printf("\nErro ao alocar memoria!\n");
        return;
    }

    novo->info = elemento;

    struct no *aux; // Percorrer a lista
    aux = *l; // Aponta para inicio da lista

    struct no *ant; // Aponta para o elemento anterior a aux
    ant = NULL; // Aponta para nada inicialmente

    for(; aux && aux->info < elemento; aux = aux->prox) {

        ant = aux;

    }

    // if(!ant) tem a semântica: lista está vazia, ou só tem um elemento e ele é maior que o novo

    if(!ant) {

        novo->prox = *l;
        *l = novo;

    } else {

        novo->prox = aux;
        ant->prox = novo;

    }

}

/*Percorre e exibe todos os elementos da lista*/
void mostrar_lista(struct no *l) {

    if(esta_vazia(l)) {
        printf("\nNao foi possivel mostrar a lista, pois ela esta vazia!\n");
        return;
    }

    struct no *aux = l;

    printf("\n["); // Pretendo exibir a lista no formato: [e1, e2, e3, ..., en]

    for(; aux; aux = aux->prox) {

        printf("%d", aux->info);

        // Pode ser interpretado como: se tiver um próximo elemento, colocar vírgula
        if(aux->prox) {
            printf(", ");
        }

    }

    printf("]\n"); // Pretendo exibir a lista no formato: [e1, e2, e3, ..., en]

}

/*Remover elemento da lista*/
void remove_elemento(struct no **l, int elemento) {

    if(esta_vazia(*l)) {
        printf("\nNao foi possivel remover elemento, pois a lista esta vazia!\n");
        return;
    }

    struct no *aux = *l, *ant = NULL;

    while(aux && aux->info != elemento) {
        
        ant = aux; // Anterior aponta para o atual elemento
        aux = aux->prox; // Atual elemento passa a ser o próximo

    }

    if(!aux) {
        printf("\nElemento nao encontrado!\n");
        return;
    }

    // Se ant = NULL, lista só tem um elemento
    if(!ant) {
        *l = aux->prox; // Equivalente a *l = NULL;
        free(aux); // Remove elemento
    } else {
        ant->prox = aux->prox; // Elemento anterior aponta para o próximo depois do atual
        free(aux); // Remove elemento atual;
    }

    printf("\nElemento removido com sucesso!\n");

}