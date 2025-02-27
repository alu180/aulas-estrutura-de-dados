#include <stdlib.h>
#include <stdio.h>
#include "calculadora.h"
/*
integrantes do grupo:

Aluisio Veloso Silva Carvalho
2412130165

Alan Vitor Costa Pereira
2322130033
*/
struct calculadora {
    float memoria;
};

Calculadora* calculadora_criar() {
    Calculadora *c = malloc(sizeof(Calculadora));
    if (c) {
        c->memoria = 0;
    }
    return c;
}

void calculadora_destruir(Calculadora *c) {
    free(c);
}

void calculadora_exibir(Calculadora *c) {
    if (c)
        printf("Memória: %f\n", c->memoria);
}

void calculadora_zerar(Calculadora *c) {
    if (c)
        c->memoria = 0;
}

void calculadora_somar(Calculadora *c, float valor) {
    if (c)
        c->memoria += valor;
}

void calculadora_subtrair(Calculadora *c, float valor) {
    if (c)
        c->memoria -= valor;
}

void calculadora_multiplicar(Calculadora *c, float valor) {
    if (c)
        c->memoria *= valor;
}

void calculadora_dividir(Calculadora *c, float valor) {
    if (c && valor != 0)
        c->memoria /= valor;
}