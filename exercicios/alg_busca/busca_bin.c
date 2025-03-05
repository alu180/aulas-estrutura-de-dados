#include <stdio.h>
#include <stdlib.h>




int buscaBinaria(int vetor[], int tamanho, int valor, int *rodadas ) {
    int inicio = 0, fim = tamanho-1, meio;
    *rodadas = 0;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        (*rodadas)++;
        if (vetor[meio] == valor) {
            return meio;
        } else if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; // Elemento não encontrado
}

int main() {
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, valor, rodadas;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    int posicao = buscaBinaria(vetor, 10, valor,&rodadas);
    if (posicao != -1) {
        printf("O valor %d foi encontrado na posicao %d\n", valor, posicao);
    } else {
        printf("O valor %d nao foi encontrado\n", valor);
    }
        printf("numero de vezes que foi rodado o loop: %d\n", rodadas);

    return 0;
}