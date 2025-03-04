#include <stdlib.h>
#include <stdio.h>
#include "caixa.h"



struct caixa {
    float comprimento,altura,largura;
};

Caixa* caixa_criar(float comprimento, float altura, float largura) {
    Caixa *c = malloc(sizeof(Caixa));
    if (c) {
        c->comprimento = comprimento;
        c->altura = altura;
        c->largura = largura;
    }
    return c;
}


void liberar_caixa(Caixa *c) {
    if(c) {
         free(c);
    }
}

void exibir_caixa(Caixa *c) {
    if (c) {
        printf("Comprimento: %f\n", c->comprimento);
        printf("Altura: %f\n", c->altura);
        printf("Largura: %f\n", c->largura);
    } else {
        printf("Caixa invalida.\n");
    }
}


void area_caixa (Caixa *c) {
    if (c) {
        float area = 2 * (c->comprimento * c->largura +
                          c->comprimento * c->altura +
                          c->largura * c->altura);
            printf("Area: %f\n", area);
        } else {
            printf("Caixa inválida.\n");
        }
    }

void volume_caixa (Caixa *c) {
    if (c){
         float volume = c->comprimento * c->altura * c->largura;
         printf("Volume: %f\n", volume);
    } else {
         printf("Caixa inválida.\n");
    }
}
 
   