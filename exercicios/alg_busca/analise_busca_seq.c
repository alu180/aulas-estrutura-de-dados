#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de busca sequencial
int buscaSequencial(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1; // Elemento não encontrado
}

int main() {
    // Tamanhos dos arrays para teste
    int sizes[] = {100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    int key = -1; // Elemento a ser procurado (não presente no array)

    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int *arr = calloc(size, sizeof(int)); // Alocando memória para o array
        clock_t start, end;
        double cpu_time_used;

        start = clock();
        buscaSequencial(arr, size, key);
        end = clock();

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("Busca Sequencial - Array Tamanho %d: %f segundos\n", size, cpu_time_used);
        free(arr); // Liberando a memória alocada
    }
    return 0;
}