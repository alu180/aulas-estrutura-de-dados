#include <stdio.h>
#include "pilha.h"

int main() {

 Pilha *p = criarPilha(5);

  // espaço para testes das operações criadas pelo aluno
  push(p, 5);
  push(p, 9);
  push(p, 6);
  listarlength(p);
  top(p);
  listarlength(p);
  pop(p);
  listarlength(p);
  top(p);
  listarlength(p);
  push(p, 7);
  listarlength(p);
  push(p, 8);
  listarlength(p);
  push(p, 15);
  listarlength(p);
  push(p, 14);
  push(p, 17);
  push(p, 19);
 
 

 liberarPilha(p);
  return 0;
}