#include <stdio.h>
#include "caixa.h"


int main() {
    Caixa *cx = caixa_criar(10.0f, 5.0f, 2.0f);


    if(!cx){
        printf("Erro ao criar a caixa. memoria nao alocada\n");
        return 1;
    }
    exibir_caixa(cx);
    
    area_caixa(cx);
    volume_caixa(cx);
    
    liberar_caixa(cx);
    return 0;
}