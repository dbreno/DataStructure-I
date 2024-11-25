///////////////// EXERCÍCIO DE ESTRUTURA DE DADOS /////////////////////////////
/////////////////////////// LISTA CIRCULAR ////////////////////////////////////
// Profªa Liliane Machado
// Discente: Herick José de Freitas

#include <stdio.h>
#include <stdlib.h>

// Definicao de constantes
#define MAX 5

// Definicao das structs
typedef struct {
    int dado[MAX];
    int i, f;
} l;

// Protótipo das funcoes
void addElement(l*);            // insere elemento no fim
void addElementInStart(l*);     // insere elemento no início
void createList(l*);            // inicializa i e f com valor -1
int isFull(l);                  // retorna 1 se cheia, 0 se não
int isEmpty(l);                 // retorna 1 se vazia, 0 se não
void removeFirstElement(l*);    // remove o primeiro elemento
void removeLastElement(l*);     // remove o último elemento
void showList(l);               // mostra a lista
void sortList(l*);              // ordena a lista

int menu(l*);                   // gerencia o acesso a lista

//////////////// MAIN ////////////////////
int main(){
    l list;
    createList(&list);
    int n = menu(&list);
    while(n){
        n = menu(&list);
    }
    return 0;
}

////////////////// Implementacao das funcoes /////////////////////////
//////////////////////////////////////////////////////////////////////

int menu(l* list){
    int op;
    printf("\nMENU:\n\t"
            "(1) Show list;\n\t"
            "(2) Add element;\n\t"
            "(3) Add element in the start;\n\t"
            "(4) Remove last element;\n\t"
            "(5) Remove first element;\n\t"
            "(6) Sort list;\n\t"
            "(7) Is list empty?\n\t"
            "(8) Is list full?\n\t"
            "(9) Clear list\n\t"
            "(0) Exit.\n"
            "Choose one option: ");
    scanf("%d", &op);

    system("cls");

    switch (op){
        case 1:
            showList(*list);
            return op;
        case 2:
            addElement(list);
            return op;
        case 3:
            addElementInStart(list);
            return op;
        case 4:
            removeLastElement(list);
            return op;
        case 5:
            removeFirstElement(list);
            return op;
        case 6:
            sortList(list);
            return op;
        case 7:
            if(isEmpty(*list)){
                printf("List is empty!\n\n");
            }else{
                printf("List is not empty!\n\n");
            }
            return op;
        case 8:
            if(isFull(*list)){
                printf("List is full!\n\n");
            }else{
                printf("List is not full!\n\n");
            }
            return op;
        case 9:
            createList(list);
            printf("List cleaned!\n\n");
            return op;
        default:
            return op;
    }
}

/////////////////////////////////////////
void addElement(l* list){
    if(!isFull(*list)){         // se a lista não estiver cheia
        int n;
        printf("Enter a value: ");
        scanf("%d", &n);        // recebe a entrada do user
        if(isEmpty(*list)){     // se estiver vazia incrementa os dois indices
            list->dado[list->i+1] = n;
            list->i += 1;
            list->f += 1;
        }else{                  // se não estiver vazia, insere normalmente no final
            if(list->f != MAX-1){
                list->dado[list->f+1] = n;
                list->f += 1;
            }else{
                list->dado[0] = n;
                list->f = 0;
            }
        }
        printf("Value added to the list!\n\n");
    }else{
        printf("List is full!\n\n");
    }
}

//////////////////////////////////////////////
void addElementInStart(l* list){
    if(!isFull(*list)){
        //recebe o valor
        int n;
        printf("Enter a value (in the start): ");
        scanf("%d", &n);
        if(isEmpty(*list)){         // caso a lista esteja vazia, incrementa os indicadores de inicio e fim.
            list->dado[list->f+1] = n;
            list->i += 1;
            list->f += 1;
        }else{                      // caso a lista não esteja vazia
            if(list->i != 0){       // se não estiver no inicio do vetor ainda, insere normalmente.
                list->dado[list->i-1] = n;
                list->i -= 1;
            }else{                  // se já estiver no inicio (literalmente) do vetor, vai inserir no final (literalmente).
                list->dado[MAX-1] = n;
                list->i = MAX-1;
            }
        }
        printf("Value added to the start of the list!\n\n");
    }else{
        printf("List is full!\n\n");
    }
}

/////////////////////////////////////
void createList(l* list){
    list->i = list->f = -1;
}

/////////////////////////////////////////
int isFull(l list){
    if((list.i == list.f+1) || (list.f == MAX-1 && list.i == 0)){
        return 1;
    }else{
        return 0;
    }
}

////////////////////////////////////////
int isEmpty(l list){
    if((list.i == list.f) && (list.i == -1)){
        return 1;
    }else{
        return 0;
    }
}

////////////////////////////////////////////////
void removeLastElement(l* list){
    if(!isEmpty(*list)){    // se não estiver vazia
        if(list->f == 0)    // se o ultimo elemento for o primeiro do vetor, volta o final da lista para o final do vetor
            if(list->f != list->i)
                list->f = MAX-1;
            else{
                createList(list); // retorna os indices para -1
            }
        else if(list->i == list->f){ // se só houver um elemento na lista
            createList(list);
        }else{
            list->f -= 1;// se o ultimo elemento da lista não for o primeiro do vetor
        }
        printf("Last element removed!\n\n");
    }else{
        createList(list);
        printf("List is empty!\n\n");
    }
}

////////////////////////////////////////////////
void removeFirstElement(l* list){
    if(!isEmpty(*list)){    // se não estiver vazia
        if(list->i == 0)    // se o ultimo elemento for o primeiro do vetor, volta o final da lista para o final do vetor
            if(list->i != list->f)
                list->i += 1;
            else{
                createList(list); // retorna os indices para -1
            }
        else if(list->i == list->f){ // se só houver um elemento na lista
            createList(list);
        }else{
            if(list->i != MAX-1){
                list->i += 1;// se o ultimo elemento da lista não for o primeiro do vetor
            }else{
                list->i = 0;
            }
        }
        printf("First element removed!\n\n");
    }else{
        createList(list);
        printf("List is empty!\n\n");
    }
}

///////////////////////////////////////////
void showList(l list){
    if(!isEmpty(list)){
        printf("List: ");
        for(int i = list.i; ; i = (i+1)%MAX){
            printf("%d%s ", list.dado[i], i == list.f ? ".\n\n" : ",");
            if (i == list.f)
                break;
        }
    }else{
        printf("List is empty!\n\n");
    }
}

/////////////////////////////////////////
void sortList(l* list){
    if(!isEmpty(*list)){
        for(int i = list->i; ; i = (i+1)%MAX){
            for(int j = list->i; ; j = (j+1)%MAX){
                if(list->dado[i] < list->dado[j]){
                    int temp = list->dado[j];
                    list->dado[j] = list->dado[i];
                    list->dado[i] = temp;
                }
                if(j == list->f)
                    break;
            }
            if(i == list->f)
                break;
        }
        printf("List sorted!\n\n");
    }else{
        printf("List is empty!\n");
    }
}