#include <stdio.h>
#include "calculadora.h"
/*

integrantes do grupo:

Aluisio Veloso Silva Carvalho
2412130165

Alan Vitor Costa Pereira
2322130033

*/
int main() {
    Calculadora *calc = calculadora_criar();
    calculadora_exibir(calc);
    
    calculadora_somar(calc, 10);
    calculadora_exibir(calc);
    
    calculadora_subtrair(calc, 5);
    calculadora_exibir(calc);
    
    calculadora_multiplicar(calc, 3);
    calculadora_exibir(calc);
    
    calculadora_dividir(calc, 2);
    calculadora_exibir(calc);
    
    calculadora_zerar(calc);
    calculadora_exibir(calc);
    
    calculadora_destruir(calc);
    return 0;
}