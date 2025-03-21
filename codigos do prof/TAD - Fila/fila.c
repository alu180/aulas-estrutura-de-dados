#include <stdlib.h>

#include "fila.h"

struct fila {
  unsigned int *dados;
  int length;
  int limit;
};

Fila *criarFila(int limit) {
  Fila *f = malloc(sizeof(Fila));
  if(f == NULL) return NULL;
  f->dados = malloc(sizeof(unsigned int) * limit);
  if(f->dados == NULL) { // Erro na inicialização da fila
    free(f);
    return;
  }
  f->length = 0;
  f->limit = limit;
  return f;
}

void liberarFila(Fila *f) {
  free(f->dados);
  free(f);
}

// a ser imflementado felo aluno
// int desenfileira(Fila *f);
// void enfileira(Fila *f, unsigned int dado);