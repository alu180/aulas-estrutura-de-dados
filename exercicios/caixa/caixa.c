#include <stdlib.h>
#include <stdio.h>
#include "caixa.h"



struct caixa {
    float comprimento,altura,largura;
};

Caixa* caixa_criar(float comprimento, float altura, float largura) {
    Caixa *c = malloc(sizeof(Caixa));
    if (c) {
        c->comprimento = 0;
        c->altura = 0;
        c->largura = 0;
    }
    return c;
}


void liberar_caixa(Caixa *c) {
    free(c);
}

void exibir_caixa(Caixa *c) {
    if (c)
        printf("Comprimento: %f\n", c->comprimento);
        printf("Altura: %f\n", c->altura);
        printf("Largura: %f\n", c->largura);
}

void area_caixa (Caixa *c) {
    if (c)
        printf("Area: %f\n", c->comprimento*c->altura*c->largura);
}

void volume_caixa (Caixa *c) {
    if (c)
        printf("Volume: %f\n", c->comprimento*c->altura*c->largura);
}