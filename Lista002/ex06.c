/*
Implemente uma função que calcule as raízes de uma equação do segundo
grau, do tipo ax² + bx + c = 0. Essa função deve obedecer ao protótipo:

int raizes(float a, float b, float c, float *x1, float *x2);

Essa função deve ter como vvalor de retorno o número de raízes reais e
distintas da equação. Se existirem raízes reais, seus valores devem ser
armazenados nas variáveis apontadaspor x1 e x2.
*/

#include <stdio.h>
#include <math.h>

int raizes(float a, float b, float c, float *x1, float *x2);

int main() {

    float a, b, c, x1, x2;

    printf("Seja uma equacao do segundo grau, forneca os coeficientes a, b e c da equacao (respectivamente): ");
    scanf("%f %f %f", &a, &b, &c);

    int retorno = raizes(a, b, c, &x1, &x2);

    if (retorno == 2) {
        printf("\nDuas raizes reais e distintas: x1 = %.2f e x2 = %.2f\n", x1, x2);
    } else if (retorno == 1) {
        printf("\nDuas raizes reais iguais: x1 = x2 = %.2f", x1);
    } else {
        printf("\nSem raizes reais.\n");
    }

    return 0;
}

int raizes(float a, float b, float c, float *x1, float *x2) {

    float discriminante;

    discriminante = pow(b, 2) - 4 * a * c;

    if (discriminante > 0) {
        *x1 = (- b + sqrt(discriminante)) / (2 * a);
        *x2 = (- b - sqrt(discriminante)) / (2 * a);
        return 2;
    } else if (discriminante == 0) {
        *x1 = *x2 = - b / (2 * a);
        return 1;
    } else {
        return 0;
    }

}