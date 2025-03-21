#include <stdlib.h>

#include "pilha.h"

struct pilha {
  unsigned int *dados;
  int length;
  int limit;
};

Pilha *criarPilha(int limit) {
  Pilha *p = malloc(sizeof(Pilha));
  if(p == NULL) return NULL;
  p->dados = malloc(sizeof(unsigned int) * limit);
  if(p->dados == NULL) { // Erro na inicialização da pilha
    free(p);
    return;
  }
  p->length = 0;
  p->limit = limit;
  return p;
}

void liberarPilha(Pilha *p) {
  free(p->dados);
  free(p);
}

// a ser implementado pelo aluno
// int top(Pilha *p);
// int pop(Pilha *p);
// void push(Pilha *p, unsigned int dado);