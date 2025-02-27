#ifndef CALCULADORA_H
#define CALCULADORA_H 1
/*
integrantes do grupo:

Aluisio Veloso Silva Carvalho
2412130165

Alan Vitor Costa Pereira
2322130033
*/
typedef struct calculadora Calculadora;

Calculadora* calculadora_criar();
void calculadora_destruir(Calculadora *c);
void calculadora_exibir(Calculadora *c);
void calculadora_zerar(Calculadora *c);
void calculadora_somar(Calculadora *c, float valor);
void calculadora_subtrair(Calculadora *c, float valor);
void calculadora_multiplicar(Calculadora *c, float valor);
void calculadora_dividir(Calculadora *c, float valor);

#endif