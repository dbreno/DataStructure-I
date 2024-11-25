/*
Implemente uma função para testar se um número inteiro é primo ou não.
Essa função deve obedecer ao protótipo a seguir e ter como valor de 
retorno 1 se n for primo e 0 caso contrário.

int primo(int n);
*/

#include <stdio.h>
#include <math.h>

int primo (int n);

int main() {

    int n;

    printf("Informe um numero: ");
    scanf("%d", &n);

    if (primo(n)) {
        printf("\n%d eh primo!\n", n);
    } else {
        printf("\n%d nao eh primo!\n", n);
    }

    return 0;
}

int primo (int n) {

    if (n <= 1) {  // Se n for menor ou igual a 1, não é primo!
        return 0;
    } else if (n == 2 || n == 3) { // Se n for igual a 2 ou 3, é primo!
        return 1;
    } else if ((n % 2 == 0) || (n % 3 == 0)) { // Se n tiver 2 ou 3 como divisores, não é primo!
        return 0;
    }

    /* 
    Lógica do loop abaixo: é preciso verificar se n possui algum dos números primos como divisores,
    uma tratativa parecida como fazer um M.M.C (Mínimo Múltiplo Comum). O número que vem após o 3,
    já verificado em momento pretérito pelo "else if (n == 2 || n == 3)", é o 5. Dessa forma, o 
    inteiro i é inicializado como sendo igual a 5, depois é testado se n é divisível por 5 e depois
    por 5 + 2, que é igual a 7, o sucessor primo de 5. O sucessor primo de 7 é 11, que é igual a 5 + 6. 
    Então, i sempre será acrescido de 6, pois há um padrão matemático dos primos, a partir de 5, 
    serem da forma: 6k ± 1, i.e, {5; 5 + 2 (7); 5 + 6 (11); 11 + 2 (13); 13 + 6 (19); ...}.
    Todos os primos, após o 3, são dessa forma, mas é errado dizer que se um número
    inteiro qualquer pode ser escrito dessa forma, ele é primo, tipo o 25, por exemplo, 
    que pode ser escrito como 6.4 + 1. Então é uma forma de identificar potenciais primos.
    O motivo de usar sqrt(n) como delimitador do loop na verificação de números primos está 
    na propriedade matemática de que, se um número n não é primo, ele pode ser fatorado em 
    dois fatores a e b, de tal forma que a * b = n. Se ambos a e b fossem maiores que a raiz 
    quadrada de n (sqrt(n)), então o produto a * b seria maior que n. Da mesma forma, se ambos 
    fossem menores que sqrt(n), o produto seria menor que n. Portanto, se n tem um divisor além 
    de 1 e ele mesmo, esse divisor deve ser menor ou igual a sqrt(n).

    */

    for(int i = 5; i <= sqrt(n); i += 6) {
        if ((n % i == 0) || (n % (i + 2) == 0)) {
            return 0;
        }
    }

    return 1;

}
