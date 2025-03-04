int buscaSequencial(int tamanho, int vetor[], int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            return i;
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
