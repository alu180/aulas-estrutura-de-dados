#include <stdio.h>

void bubbleSort(int lista[], int n, int *comparacoes, int *trocas) {
    int i, j, temp;
    int troca;
    *comparacoes = 0;
    *trocas = 0;
    
    for (i = 0; i < n - 1; i++) {
        troca = 0;
        for (j = 0; j < n - i - 1; j++) {
            (*comparacoes)++;
            if (lista[j] > lista[j + 1]) {
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
                (*trocas)++;
                troca = 1;
            }
        }
        if (!troca) {
            break;
        }
    }
}

int main() {
    int lista[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int n = sizeof(lista) / sizeof(lista[0]);
    int comparacoes, trocas;
    
    bubbleSort(lista, n, &comparacoes, &trocas);
    
    printf("lista ordenada: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\nComparacoes realizadas: %d\n", comparacoes);
    printf("Trocas realizadas: %d\n", trocas);
    
    return 0;
}