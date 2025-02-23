
#ifndef CALCULADORA_H
#define CALCULADORA_H

typedef struct {
    float num1;
    float num2;
    char operacao;
} Calculadora;

Calculadora* cria_calculadora(float num1, float num2, char operacao);
void destroi_calculadora(Calculadora* calc);

float calcula(Calculadora* calc);

#endif