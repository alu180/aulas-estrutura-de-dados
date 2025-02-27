#include <stdio.h>
#include "caixa.h"


int main() {
    Caixa *cx = caixa_criar(10, 5, 2);
    exibir_caixa(cx);
    
    area_caixa(cx);
    volume_caixa(cx);
    
    liberar_caixa(cx);
    return 0;
}