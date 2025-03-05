#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int buscaBinariaMaisProximo(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1, meio;
    int maisProximo = vetor[0];

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        // Atualiza o mais próximo se o elemento atual for mais próximo do valor
        if (abs(vetor[meio] - valor) < abs(maisProximo - valor) ||
            (abs(vetor[meio] - valor) == abs(maisProximo - valor) && vetor[meio] < maisProximo)) {
            maisProximo = vetor[meio];
        }

        if (vetor[meio] == valor) {
            return vetor[meio];
        } else if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return maisProximo; // Retorna o elemento mais próximo encontrado
}

int main() {
    int vetor[7] = {2, 4, 6, 7, 8, 8, 9}, valor;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    int maisProximo = buscaBinariaMaisProximo(vetor, 7, valor);
    printf("O numero mais proximo de %d e %d\n", valor, maisProximo);

    return 0;
}