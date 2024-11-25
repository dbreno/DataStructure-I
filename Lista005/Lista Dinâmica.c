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

/*
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
*/

void esvaziar_lista(struct no **l) {
    if (*l == NULL) {
        return;
    }

    esvaziar_lista(&((*l)->prox));

    free(*l);

    *l = NULL;
}

/*Insere elemento no final da lista*/
void inserir_fim(struct no **l, int elemento) {

    struct no *novo = (struct no *) malloc(sizeof(struct no)); // Cria elemento

    // if(!novo) é equivalente a if(novo == NULL), i.e, aponta para nada: memoria nao alocada

    if(!novo) {
        printf("\nErro ao alocar memoria!\n");
        return; // Encerra a execução da função!
    }

    novo->info = elemento; // Novo elemento recebe dado fornecido pelo usuário

    struct no *aux; // Ponteiro para percorrer a lista

    aux = *l; // aux aponta para o inicio da lista: primeiro elemento

    /*
    if(!aux) é equivalente a if(aux == NULL), ou seja, se aux aponta para nada, e aux é igual
    a l, então a lista não tem nenhum elemento ainda, está vazia! Isso poderia ser
    verificado também com if(!(*l)) ou simplesmente chamar a função `esta_vazia()`.
    */

    if (!aux) {

        inserir_inicio(&(*l), elemento); 

        /*
        Se a lista está vazia, inserir elemento no fim ou inserir no início dá na mesma. 

        -> A notação &(*l) pode parecer carregada, mas vou explicar meu raciocínio!
        l é a variável do tipo `struct no *`, um ponteiro para uma struct no. O valor
        que ela carrega é o endereço de uma struct no. Quando passamos uma variável por 
        referência para uma função, é recebido um ponteiro do tipo daquela variável e é
        enviado o endereço daquela variável na chamada da função. Sendo assim, usar 
        simplesmente l dentro da variável é usar o endereço da variável l, mas não
        significa modificar o conteúdo dela, que é justamente a struct no que ela aponta!
        Por isso qualquer modificação da struct no é feita com *l, pois está sendo acessado
        o conteúdo de l que é o endereço da struct no, acessando a struct no de fato. 
        Como estou chamando a função inserir_inicio, que também usa passagem por referência, 
        estou recebendo, nessa função, um ponteiro. Então, é passado o endereço da variável
        Por isso, o `&`. Não bastando, eu preciso passar o endereço do conteúdo de l, que
        é justamente a struct no para ser jogado no ponteiro da função inserir_inicio.
        Se não for passsado na notação &(*l), mas sim, &(l), eu estaria passando o endereço
        do ponteiro l, então inserir_inicio teria um ponteiro que teria, como conteúdo,
        o endereço de l, mas não da struct no!
        */

        /*
        Caso não opte por usar inserir_inicio, uma opção seria replicar o código, assim seria:

            ```
                if(!aux) {
                
                    novo->prox = aux;
                    *l = novo;
                    return;

                }
        */

        return; // Encerra a execução!
    }

    /* while(aux->prox) é equivalente a while(aux->prox != NULL), ou seja, enquanto o elemento
    atual não aponta para nada, é o último */
    
    while(aux->prox) {

        aux = aux->prox; // aux passa a apontar para o elemento seguinte

    }

    novo->prox = aux->prox; // Novo elemento aponta para onde o último apontava (nada)
    // Seria equivalente fazer novo->prox = NULL também
    aux->prox = novo; // Último elemento aponta para o novo elemento que agora é o último elemento

}

/*Insere elemento no início da lista*/
void inserir_inicio(struct no **l, int elemento) {

    struct no *novo = (struct no *) malloc(sizeof(struct no));

    if(!novo) {
        printf("\nErro ao alocar memoria!\n");
        return;
    }

    novo->info = elemento;

    novo->prox = *l; // Novo elemento aponta para o antigo primeiro elemento da lista
    *l = novo; // Novo elemento passa a ser o primeiro elemento da lista


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

         

    } else {

        novo->prox = aux;
        ant->prox = novo;

    }

}

/*Ordena os elementos da lista em ordem crescente*/
void ordenar_lista(struct no **l) {

    if(esta_vazia(*l)) {
        printf("\nNao foi possivel ordenar a lista, pois ela esta vazia!\n");
        return;
    }

    struct no *aux; // Percorre a lista

    int lista_len = 0; // Tamanho da lista
    int temp; // Variável que faz backup do valor do elemento

    for(aux = *l; aux; aux = aux->prox, lista_len++); // Percorre a lista para saber seu tamanho

    // Algoritmo de Ordenação de Bolha para ordenar os elementos
    for(int i = 0; i < lista_len - 1; i++) {

        aux = *l; // Sempre aponta para o inicio da lista após ordenar os da leva atual

        for (int j = 0; j < lista_len - i - 1; j++) {

            // Se o elemento atual for maior que o próximo

            if(aux->info > aux->prox->info) {

                temp = aux->prox->info; // Backup do próximo elemento
                aux->prox->info = aux->info; // Próximo elemento recebe o atual que é maior
                aux->info = temp; // Elemento atual recebe o que era o próximo que é menor

            }

            aux = aux->prox; // Avança para o próximo elemento da lista

        }

    }

    printf("\nLista ordenada com sucesso!\n");

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
        
        // Atual elemento passa a ser o próximo

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