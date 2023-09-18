#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função de comparação para o quicksort com base no comprimento da string
int compare(const void *a, const void *b) {
    return strlen(*(const char **)a) - strlen(*(const char **)b);
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limão", "manga", "abacate", "kiwi",
        "cereja", "morango", "pêssego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    // Contadores para trocas e comparações
    int swaps = 0, comparisons = 0;

    // Ordena o vetor usando quicksort com base no comprimento da string
    qsort(arr, 20, sizeof(char *), compare);

    // Mostra o vetor ordenado
    printf("Vetor ordenado por tamanho das palavras:\n");
    for (int i = 0; i < 20; i++) {
        printf("%s\n", arr[i]);
    }

    // Calcula a mediana (elemento do meio)
    char *mediana = arr[9]; // No vetor ordenado, a mediana é o elemento de índice 9.

    // Mostra a mediana
    printf("\nMediana: %s\n", mediana);

    // Mostra o número de trocas e comparações
    printf("\nNúmero de trocas: %d\n", swaps);
    printf("Número de comparações: %d\n", comparisons);

    // Gera um arquivo de texto de saída
    FILE *outputFile = fopen("saida.txt", "w");
    if (outputFile == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    // Escreve o vetor ordenado no arquivo
    for (int i = 0; i < 20; i++) {
        fprintf(outputFile, "%s\n", arr[i]);
    }

    // Fecha o arquivo
    fclose(outputFile);

    return 0;
}
  