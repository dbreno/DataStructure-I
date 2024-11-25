/*
Ler "primeiro nome" e "idade" de n pessoas
- Guardar dados em um arquivo de texto
- Mostrar o nome das pessoas maiores de 18 anos
- Ordenar os nomes (com idades respectivas) e Salvar em um novo arquivo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    int idade;
} Pessoa;

long estaVazio(FILE *arq);
void ordenarPessoas(Pessoa *pessoas, int n);
void salvarDados(Pessoa *pessoas, int n, char *caminhoArquivo);

int main() {

    FILE *arq;
    int n;
    
    printf("Quantidade de pessoas: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("\nNumero de pessoas invalido!\n");
        return 1;
    }
    getchar(); // Limpar o buffer do teclado
    /*
    Poderia usar fflush(stdin) também, mas, em alguns compiladores, não funciona.
    */

    Pessoa pessoas[n];

    for (int i = 0; i < n; i++) {

        int len = sizeof(pessoas[i].nome);

        printf("\nDigite o primeiro nome da pessoa %d: ", i + 1);
        fgets(pessoas[i].nome, len, stdin); // ou scanf("%19[^\n]s", nome);
        
        for (int j = 0; j < len; j++) { //Remove o 'enter' da string
            if (pessoas[i].nome[j] == '\n') {
                pessoas[i].nome[j] = '\0';
                break;
            } 
        }
        
        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &pessoas[i].idade);
        getchar();
        /*
        fprintf retorna um valor negativo caso a escrita não tenha sido bem sucedida
        */
    }   

    arq = fopen("C:\\Users\\deivi\\Documents\\UFPB\\Estrutura de Dados\\Lista 001\\arquivo.txt", "w"); //Abre e escreve no arquivo

    if (arq == NULL) {
        printf("\nNao foi possivel abrir arquivo.txt\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        
        if (fprintf(arq, "Nome: %s, Idade: %d\n", pessoas[i].nome, pessoas[i].idade) < 0) {
            printf("\nErro ao escrever no arquivo\n");
            fclose(arq);
            return 1;
        } else if (i >= n - 1) { // Verifica se é a última pessoa lida

            // Escreve as pessoas maiores de 18 anos

            fprintf(arq, "\nPessoas maiores de 18 anos:\n");
            for (int j = 0; j < n; j++) {
                if (pessoas[j].idade >= 18) {
                    fprintf(arq, "Nome: %s, Idade: %d\n", pessoas[j].nome, pessoas[j].idade);
                }
            }

        } 

    }

    fclose(arq);

    ordenarPessoas(pessoas, n);
    char caminhoArquivo[] = "C:\\Users\\deivi\\Documents\\UFPB\\Estrutura de Dados\\Lista 001\\arquivoOrdenado.txt";
    salvarDados(pessoas, n, caminhoArquivo); 

    // Verifica se o arquivo.txt tem conteúdo

    arq = fopen("C:\\Users\\deivi\\Documents\\UFPB\\Estrutura de Dados\\Lista 001\\arquivo.txt", "r");
    
    long tamanho = estaVazio(arq);

    if(tamanho > 0) {
        printf("\nDados de arquivo.txt gravados com sucesso!\n");
    } else {
        printf("\nErro ao gravar os dados de arquivo.txt!\n");
    }

    // Verifica se o arquivoOrdenado.txt tem conteúdo

    arq = fopen(caminhoArquivo, "r");

    tamanho = estaVazio(arq);

    if(tamanho > 0) {
        printf("\nDados de arquivoOrdenado.txt gravados com sucesso!\n");
    } else {
        printf("\nErro ao gravar os dados de arquivoOrdenado.txt!\n");
    }
    
    return 0;
}

long estaVazio(FILE *arq) {
    
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo para leitura.\n");
        return 1;
    }
    
    fseek(arq, 0, SEEK_END); // Move o indicador de posição para o final do arquivo
    long tamanho = ftell(arq); // Obtém a posição atual do indicador de posição (tamanho do arquivo)
    fclose(arq);

    return tamanho;
}

void ordenarPessoas(Pessoa *pessoas, int n) {
    
    Pessoa temporaria;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (strcmp(pessoas[j].nome, pessoas[j + 1].nome) > 0) {
                temporaria = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = temporaria;
            }
        }
    }
}

void salvarDados(Pessoa *pessoas, int n, char *caminhoArquivo) {

    FILE *arq = fopen(caminhoArquivo, "w");
    if (arq == NULL) {
        printf("\nNao foi posivvel abrir o segundo arquivo!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(arq, "Nome: %s, Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
    }
    fclose(arq);
}
