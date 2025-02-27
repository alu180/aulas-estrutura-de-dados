#include <stdio.h>
#include <stdlib.h>
#include "calculadora_h_.h"

int main() {
    float num1, num2;
    char operacao;

    printf("Digite a operacao (+, -, *, /): ");
    scanf(" %c", &operacao);
    printf("Digite dois numeros: ");
    scanf("%f %f", &num1, &num2);

    Calculadora* calc = cria_calculadora(num1, num2, operacao);
    if (calc == NULL) {
        printf("Erro ao criar a calculadora!\n");
        return 1;
    }

    float resultado = calcula(calc);
    if (operacao == '/' && num2 == 0) {
        printf("Erro: divisao por zero!\n");
    } else {
		
        printf("Resultado: %.2f\n", resultado);
    }

    destroi_calculadora(calc);
    return 0;
}