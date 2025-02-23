#include "calculadora_h_.h"
#include <stdlib.h>
#include <stdio.h>

Calculadora* cria_calculadora(float num1, float num2, char operacao) {
    Calculadora* calc = (Calculadora*)malloc(sizeof(Calculadora));
    if (calc != NULL) {
        calc->num1 = num1;
        calc->num2 = num2;
        calc->operacao = operacao;
    }
    return calc;
}

void destroi_calculadora(Calculadora* calc) {
    free(calc);
}

void exibir (Calculadora* calc) {
    printf("num1: %.2f\n", calc->num1);
    printf("num2: %.2f\n", calc->num2);
    printf("operacao: %c\n", calc->operacao);
}

float calcula(Calculadora* calc) {
    switch (calc->operacao) {
        case '+':
            return calc->num1 + calc->num2;
        case '-':
            return calc->num1 - calc->num2;
        case '*':
            return calc->num1 * calc->num2;
        case '/':
            if (calc->num2 == 0) {
                return 0; // Erro: divisão por zero
            }
            return calc->num1 / calc->num2;
        default:
            return 0; // Operação inválida
    }
}