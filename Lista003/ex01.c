/*
Fazer uma função que conte todas as vogais de um vetor
de caracteres local à "main"
*/

#include <stdio.h>
#include <ctype.h>

int contaVogais(char *v);

int main() {

    char vetor[50], c;
    int i = 0;

    printf("Digite uma palavra/frase: ");

    while (i < 49) {
        scanf("%c", &c);
        if (c == '\n') {
            break;
        }
        vetor[i] = c;
        i++;
    }

    vetor[i] = '\0';

    printf("\nQuantidade de vogais: %d\n", contaVogais(vetor));

    return 0;
}

int contaVogais(char *v) {
    int qtde = 0, i = 0;

    while(v[i] != '\0') {
        if (toupper(v[i]) == 'A' || toupper(v[i]) == 'E' || toupper(v[i]) == 'I' || toupper(v[i]) == 'O' || toupper(v[i]) == 'U') {
            qtde++;
        }
        i++;
    }

    return qtde;
}