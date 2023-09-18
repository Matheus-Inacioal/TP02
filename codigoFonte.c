#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar(const void *a, const void *b) {
    return strlen(*(const char **)a) - strlen(*(const char **)b);
}

void trocar(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(char **arr, int esquerda, int direita, int *trocas, int *comparacoes) {
    if (esquerda < direita) {
        int i = esquerda, j = direita;
        char *pivot = arr[(i + j) / 2];

        while (i <= j) {
            while (strlen(arr[i]) < strlen(pivot)) {
                i++;
                (*comparacoes)++;
            }
            while (strlen(arr[j]) > strlen(pivot)) {
                j--;
                (*comparacoes)++;
            }
            if (i <= j) {
                trocar(&arr[i], &arr[j]);
                i++;
                j--;
                (*trocas)++;
            }
        }

        quicksort(arr, esquerda, j, trocas, comparacoes);
        quicksort(arr, i, direita, trocas, comparacoes);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
        "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int trocas = 0, comparacoes = 0;

    quicksort(arr, 0, 19, &trocas, &comparacoes);

    char *mediana = arr[9];

    FILE *arquivoCSV = fopen("saida.csv", "w");
    if (arquivoCSV == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    fprintf(arquivoCSV, "Palavra, Tamanho\n");

    for (int i = 0; i < 20; i++) {
        fprintf(arquivoCSV, "%s, %d\n", arr[i], (int)strlen(arr[i]));
    }

    fprintf(arquivoCSV, "Trocas: %d\n", trocas);
    fprintf(arquivoCSV, "Comparacoes: %d\n", comparacoes);
    fprintf(arquivoCSV, "Mediana: %s\n", mediana);

    fclose(arquivoCSV);

    printf("Vetor ordenado por tamanho das palavras foi salvo em 'saida.csv'.\n");
    printf("Número de trocas: %d\n", trocas);
    printf("Número de comparações: %d\n", comparacoes);
    printf("Mediana: %s\n", mediana);

    return 0;
}
