#include <stdio.h>
#include <stdlib.h>



int buscaSequencial(int vetor[], int tamanho, int valor) {
    for (int i = 0; i < tamanho / 2; i++) {
        if (vetor[i] == valor) {
            return i;
        }
        if (vetor[tamanho - 1 - i] == valor) {
            return tamanho - 1 - i;
        }
    }
    return -1; // Elemento não encontrado
}

int main() {
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, valor;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    int posicao = buscaSequencial(vetor, 10, valor);
    if (posicao != -1) {
        printf("O valor %d foi encontrado na posicao %d\n", valor, posicao);
    } else {
        printf("O valor %d nao foi encontrado\n", valor);
    }
    return 0;
}
