/*
Implemente uma função que retorne a soma dos n primeiros números naturais ímpares. 
Essa função deve obedecer ao protótipo:

int soma_impares (int n);
*/

#include <stdio.h>

int soma_impares(int n);

int main () {
    
    int n;

    printf("Quantos primeiros numeros naturais impares voce deseja somar? ");
    scanf("%d", &n);
    printf("Soma %d", soma_impares(n));

    return 0;
}

int soma_impares(int n) {

    int impar = 1, soma = 0;

    for (int i = 0; i < n; i++) {

        soma += impar;
        impar += 2;

    }

    return soma;

}