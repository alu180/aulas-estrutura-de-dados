#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de busca binária
int buscaBinaria(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x) return m;

        if (arr[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1; // Elemento não encontrado
}

int main() {
    int sizes[] = {100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    int key = -1; // Elemento a ser procurado (não presente no array)

    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int *arr = (int*) malloc(size * sizeof(int));

        // Preenchendo o array com números ordenados
        for (int j = 0; j < size; j++) {
            arr[j] = j; // Isso garante que o array esteja ordenado
        }

        clock_t start, end;
        double cpu_time_used;

        start = clock();
        buscaBinaria(arr, 0, size - 1, key);
        end = clock();

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("Busca Binária - Array Tamanho %d: %f segundos\n", size, cpu_time_used);
        free(arr); // Liberando a memória alocada
    }
    return 0;
}