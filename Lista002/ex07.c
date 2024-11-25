/*
Implemente uma função que calcule a área da superfície e o volume de uma
esfera de raio r. Essa função deve obeder ao protótipo:

void calc_esfera (float r, float *area, float *volume);

A área da superfície e o volume são dados, respectivamente, por 4r² e 4r³/3.
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14F

void calc_esfera(float r, float *area, float *volume);

int main() {

    float r, area, volume;

    printf("Informe o raio da esfera: ");
    scanf("%f", &r);

    calc_esfera(r, &area, &volume);

    printf("\nArea da esfera: %.2fu.a | Volume da esfera: %.2fu.a\n", area, volume);


    return 0;
}

void calc_esfera(float r, float *area, float *volume) {

    *area = 4 * PI * pow(r, 2);
    *volume = (4.0/3.0) * PI * pow(r, 3);

}
