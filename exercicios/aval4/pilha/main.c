#include <stdio.h>
#include "pilha.h"

int main() {
 // executarTestes();

 Pilha *p = criarPilha(5);

  // espaço para testes das operações criadas pelo aluno
  listarlength(p);
  push(p, 5);
  listarlength(p);
  push(p, 9);
  listarlength(p);
  push(p, 6);
  listarlength(p);
  top(p);
  listarlength(p);
  pop(p);
  listarlength(p);
  top(p);
  listarlength(p);
  push(p, 7);
  push(p, 8);
  push(p, 15);
  listarlength(p);
  push(p, 14);
  push(p, 17);
  push(p, 19);
 
 

 liberarPilha(p);
  return 0;
}