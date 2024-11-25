/* 
Implemente uma função que retorne o n-ésimo termo da série de Fibonacci. A série
de Fibonacci é dada por: 1 1 2 3 5 8 13 21..., isto é, os dois primeiros termos
são iguais a 1 e cada termo seguinte é a soma dos dois termos anteriores.
Essa função deve obedecer ao protótipo:

int fibonacci (int n);
*/

#include <stdio.h>

int fibonacci (int n);

int main() {

    int n;

    printf("Informe o termo da sequencia de fibonacci desejado: ");
    scanf("%d", &n);

    while (n < 1) {
        printf("Informe uma entrada inteira maior que zero: ");
        scanf("%d", &n);
    }

    printf("\nTermo: %d\n", fibonacci(n));

    return 0;
}

int fibonacci (int n) {
    int n1 = 1, n2 = 1, n3;

    if (n == 1) {
        return n1;
    } else if (n == 2) {
        return n2;
    }

    for (int i = 2; i < n; i++) {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3; 
    }

    return n3;
}
