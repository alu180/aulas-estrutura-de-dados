#include <stdio.h>

void selectionSort(int lista[], int n, int *comparacoes, int *trocas) {
    int i, j, minimo, temp;
    *comparacoes = 0;
    *trocas = 0;

    for (i = 0; i < n - 1; i++) {
        minimo = i;
        for (j = i + 1; j < n; j++) {
            (*comparacoes)++;
            if (lista[j] < lista[minimo]) {
                minimo = j;
            }
        }
        if (minimo != i) {
            temp = lista[i];
            lista[i] = lista[minimo];
            lista[minimo] = temp;
            (*trocas)++;
        }
    }
}

int main() {
    int lista[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(lista) / sizeof(lista[0]);
    int comparacoes, trocas;

    selectionSort(lista, n, &comparacoes, &trocas);

    printf("lista ordenada: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\nComparacoes realizadas: %d\n", comparacoes);
    printf("Trocas realizadas: %d\n", trocas);

    return 0;
}