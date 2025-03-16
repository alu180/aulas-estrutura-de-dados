#include <stdio.h>

void selection_sort_mod(int arr[], int n) {
    int i, j, minimo, maximo, temp;
    for (i = 0; i < n / 2; i++) {
        minimo = i;
        maximo = i;
        int comeco = i;
        int fim = n - i - 1;

        for (j = comeco; j <= fim; j++) {
            if (arr[j] < arr[minimo]) {
                minimo = j;
            }
            if (arr[j] > arr[maximo]) {
                maximo = j;
            }
        }

        temp = arr[comeco];
        arr[comeco] = arr[minimo];
        arr[minimo] = temp;

        if (maximo == comeco) {
            maximo = minimo;
        }

        temp = arr[fim];
        arr[fim] = arr[maximo];
        arr[maximo] = temp;
    }
}

void print(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("lista original:\n");
    print(arr, n);
    selection_sort_mod(arr, n);
    printf("lista ordenada:\n");
    print(arr, n);
    return 0;
}