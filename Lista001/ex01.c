/*
Fazer o programa para calcular o n-ésimo termo da sequência de Fibonacci.

    - Use função para calcular o valor da sequência
    - Não use recursão
    - Main possuir apenas 3 variáveis locais
    - Utilize passagem de parâmetro por referência para a função
*/

#include <stdio.h>

void sequenciaFibo(int*); //Funcao que calcula a sequência de Fibonacci.

int main() {

    int qtde; //Variável que carrega a quantidade de termos desejada a ser exibida na sequência

    printf("Quantidade de termos da sequencia: ");
    scanf("%d", &qtde);
    printf("\nSequencia: ");
    sequenciaFibo(&qtde); //Chamada da função, por referência, que calcula e exibe a sequência de Fibonacci

    return 0;
}

void sequenciaFibo(int *quantidade) {
    long long int n1 = 1, n2 = 1, n; //Foi utilizado long long (64bits) para exibir mais termos da sequencia

    if (*quantidade == 0) {
        printf("{}");
    } else if (*quantidade == 1) {
        printf("{%lld...}", n1);
    } else if (*quantidade == 2) {
        printf("{%lld, %lld...}", n1, n2);
    } else {

        printf("{%lld, %lld", n1, n2);

        for (int i = 2; i < *quantidade; i++) {
            n = n1 + n2; //n diz respeito ao próximo termo que é calculado pela soma dos seus dois anteriores
            n1 = n2; //o termo que vem antes do termo que vem antes do próximo calculado recebe o termo que vem depois dele
            n2 = n; //o termo que vem antes do próximo calculado recebe o próprio termo calculado
            printf(", %lld", n);
        }

        printf("...}\n");

    }
}
