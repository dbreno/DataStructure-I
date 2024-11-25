#include <stdio.h>
#include <stdlib.h>

struct no {
    struct no *esq;
    int info;
    struct no *dir;
};

int altura(struct no *);
struct no *balancear(struct no *);
int conta_nos(struct no *);
struct no *cria_arvore();
int esta_vazia(struct no *);
int fator_balanceamento(struct no *);
struct no *insere_arvore(struct no *, int);
struct no *limpa_arvore(struct no *);
void mostra_arvore_infix(struct no *);
void mostra_arvore_posfix(struct no *);
void mostra_arvore_prefix(struct no *);
struct no *rotacao_direita(struct no *);
struct no *rotacao_esquerda(struct no *);


int main() {

    struct no *arvore;
    arvore = cria_arvore();

    int valor, opcao;

    do{
        printf("\n===Menu===\n");
        printf("1. Inserir elemento na arvore\n");
        printf("2.Mostrar arvore (prefix)\n");
        printf("3.Mostrar arvore (infix)\n");
        printf("4.Mostrar arvore (posfix)\n");
        printf("5.Contar nos\n");
        printf("6.Altura da arvore\n");
        printf("7.Limpar arvore\n");
        printf("8.Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        system("cls");

        switch(opcao) {

            case 1:
                printf("\nInforme o valor: ");
                scanf("%d", &valor);
                arvore = insere_arvore(arvore, valor);
                printf("\nElemento inserido com sucesso!\n");
                break;

            case 2:

                if(esta_vazia(arvore)) {
                    printf("\nNao foi possivel mostrar a arvore, pois ela esta vazia!\n");
                } else {
                    printf("\n");
                    mostra_arvore_prefix(arvore);
                    printf("\n");
                }

                break;

            case 3:

                if(esta_vazia(arvore)) {
                    printf("\nNao foi possivel mostrar a arvore, pois ela esta vazia!\n");
                } else {
                    printf("\n");
                    mostra_arvore_infix(arvore);
                    printf("\n");
                }

                break;

            case 4:

                if(esta_vazia(arvore)) {
                    printf("\nNao foi possivel mostrar a arvore, pois ela esta vazia!\n");
                } else {
                    printf("\n");
                    mostra_arvore_posfix(arvore);
                    printf("\n");
                }

                break;


            case 5:
                printf("\nQuantidade de nos: %d\n", conta_nos(arvore));
                break;

            case 6:
                printf("\nAltura da arvore: %d\n", altura(arvore));
                break;

            case 7:

                arvore = limpa_arvore(arvore);
                if(!arvore) {
                    printf("\nArvore esvaziada com sucesso!\n");
                }
                break;

            case 8:
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;

        }

    }while (opcao != 8);

    return 0;
}

int altura(struct no *raiz) {

    int esq, dir;

    if(raiz) {
        esq = altura(raiz->esq);
        dir = altura(raiz->dir);
        if(esq > dir) {
            return esq + 1;
        } else {
            return dir + 1;
        }
    } else {

        return 0;

    }

}

struct no* balancear(struct no* raiz) {
    int fb = fator_balanceamento(raiz);  // Calcula o fator de balanceamento (fb) para a raiz

    // Caso 1: Rotação à direita (desbalanceada à esquerda)
    if (fb > 1 && fator_balanceamento(raiz->esq) >= 0) {
        return rotacao_direita(raiz);
    }

    // Caso 2: Rotação à esquerda (desbalanceada à direita)
    if (fb < -1 && fator_balanceamento(raiz->dir) <= 0) {
        return rotacao_esquerda(raiz);
    }

    // Caso 3: Rotação dupla esquerda-direita (desbalanceada à esquerda com subárvore direita)
    if (fb > 1 && fator_balanceamento(raiz->esq) < 0) {
        raiz->esq = rotacao_esquerda(raiz->esq);  // Primeiro, rotaciona à esquerda a subárvore esquerda
        return rotacao_direita(raiz);  // Em seguida, rotaciona à direita a raiz
    }

    // Caso 4: Rotação dupla direita-esquerda (desbalanceada à direita com subárvore esquerda)
    if (fb < -1 && fator_balanceamento(raiz->dir) > 0) {
        raiz->dir = rotacao_direita(raiz->dir);  // Primeiro, rotaciona à direita a subárvore direita
        return rotacao_esquerda(raiz);  // Em seguida, rotaciona à esquerda a raiz
    }

    return raiz;  // Retorna a raiz (se nenhuma rotação for necessária)
}


int conta_nos(struct no *raiz) {

    int a, b;

    if(raiz) {

        a = conta_nos(raiz->esq);
        b = conta_nos(raiz->dir);
        return(a + b + 1);

    } else {

        return 0;

    }

}

struct no *cria_arvore() {

    return NULL;

}

int esta_vazia(struct no *raiz) {
    return(!raiz);
}

int fator_balanceamento(struct no *raiz) {

    int a, b;
    
    if(raiz) {
        a = altura(raiz->esq);
        b = altura(raiz->dir);
        return (a - b); // Calcula a diferença de altura entre a subárvore esquerda e a direita
    } else {
        return 0; // Se a raiz for nula, o fator de balanceamento é 0
    }
    
    
}

struct no *insere_arvore(struct no *raiz, int valor) {

    if(!raiz) {

        struct no *novo;
        novo = (struct no *) malloc(sizeof(struct no));

        if(!novo) {

            printf("\nErro ao alocar memoria!\n");
            return NULL;

        } else {

            novo->info = valor;
            novo->esq = NULL;
            novo->dir = NULL;
            return novo;

        }

    } else {

        if(valor < raiz->info) {
            raiz->esq = insere_arvore(raiz->esq, valor);
        } else {
            raiz->dir = insere_arvore(raiz->dir, valor);
        }
        
        // Após inserir, balancear a árvore
        return balancear(raiz);

    }

}

struct no *limpa_arvore(struct no *raiz) {

    if(raiz) {

        raiz->esq = limpa_arvore(raiz->esq);
        raiz->dir = limpa_arvore(raiz->dir);
        free(raiz);
        return NULL;

    } else {

        return NULL;

    }

}

void mostra_arvore_infix(struct no *raiz) {

    if(raiz) {
        mostra_arvore_infix(raiz->esq);
        printf("%d ", raiz->info);
        mostra_arvore_infix(raiz->dir);
    } else {
        return;
    }

}

void mostra_arvore_posfix(struct no *raiz) {

    if(raiz) {
        mostra_arvore_posfix(raiz->esq);
        mostra_arvore_posfix(raiz->dir);
        printf("%d ", raiz->info);
    } else {
        return;
    }

}

void mostra_arvore_prefix(struct no *raiz) {
    if(raiz) {
        printf("%d ", raiz->info);
        mostra_arvore_prefix(raiz->esq);
        mostra_arvore_prefix(raiz->dir);
    } else {
        return;
    }

}

struct no *rotacao_direita(struct no *raiz) {

    struct no *no = raiz->esq; // O nó à esquerda da raiz será a nova raiz após a rotação
    raiz->esq = no->dir; // A subárvore direita de "no" passa a ser o filho esquerdo da raiz original
    no->dir = raiz; // A raiz original passa a ser o filho direito do novo nó "no"
    raiz = no; // Raiz passa a ser igual a novo nó
    return raiz; // Retorna o novo nó que se tornou a raiz
    
}

struct no *rotacao_esquerda(struct no *raiz) {

    struct no *no = raiz->dir; // O nó à direita da raiz será a nova raiz após a rotação
    raiz->dir = no->esq; // A subárvore esquerda de "no" ássa a ser o novo filho direito da raiz original
    no->esq = raiz; // A raiz original passa a ser o filho esquerdo do novo nó "no"
    raiz = no; // Raiz passa a ser igual a novo nó
    return raiz; // Retorna o novo nó que se tornou a raiz

}






