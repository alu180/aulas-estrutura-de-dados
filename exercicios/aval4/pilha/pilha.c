#include <stdlib.h>
#include <stdio.h>
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
    return NULL;
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
int top(Pilha *p) {
  if (p == NULL || p->length == 0) {
    printf("Pilha vazia ou invalida\n");
      return -1;
  }
  printf("Top: %d\n", p->dados[p->length - 1]);
  return p->dados[p->length - 1];

}
// int pop(Pilha *p);
int pop(Pilha *p) {
  if (p == NULL || p->length == 0) {
      return -1;
  }
  p->length--;
  printf("Pop: %d\n", p->dados[p->length]);
  return p->dados[p->length];
}

// void push(Pilha *p, unsigned int dado);
void push(Pilha *p, unsigned int dado) {
  if (p == NULL || p->length == p->limit) {
    printf("Pilha cheia ou invalida\n");
      return;
  }
  p->dados[p->length] = dado;
  p->length++;
  printf("Push: %d\n", dado);
}
void listarlength(Pilha *p){
    printf("Length: %d\n", p->length);
}