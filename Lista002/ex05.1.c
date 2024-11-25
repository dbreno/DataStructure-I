/*
Implemente uma função que retorne uma aproximação do valor de pi, de acordo
com a fórmula de Leibiniz:

pi ~= 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 ...)

Essa função deve obedecer ao seguinte protótipo, em que n indica o número
de termos que deve ser usado para avaliar o valor de pi:

double pi(int n);
*/

#include <stdio.h>

double pi (int n);

int main() {

    int n;

    printf("Quantidade de termos: ");
    scanf("%d", &n);
    printf("Valor de pi aproximado: %.2lf", pi(n));

    return 0;
}

double pi (int n) {
    
    double somatorio = 0.0;

    for (int i = 0; i < n; i++) {
        
        if (i % 2 == 0) {
            somatorio += (double) 1 / (2 * i + 1);
        } else {
            somatorio -= (double) 1 / (2 * i + 1);
        }
        
    }

    return 4 * somatorio;

}
