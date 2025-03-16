#include <stdio.h>

void insertionSort(int lista[], int n, int *comparacoes, int *trocas) {
    int i, j, aux;
    *comparacoes = 0;
    *trocas = 0;

    for (i = 1; i < n; i++) {
        aux = lista[i];
        j = i - 1;

        while (j >= 0) {
            (*comparacoes)++;
            if (lista[j] <= aux) {
                break;
            }
            lista[j + 1] = lista[j];
            (*trocas)++;
            j--;
        }
        lista[j + 1] = aux;
    }
}

int main() {
    int lista[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(lista) / sizeof(lista[0]);
    int comparacoes, trocas;

    insertionSort(lista, n, &comparacoes, &trocas);

    printf("lista ordenada: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\nComparacoes realizadas: %d\n", comparacoes);
    printf("Trocas realizadas: %d\n", trocas);

    return 0;
}