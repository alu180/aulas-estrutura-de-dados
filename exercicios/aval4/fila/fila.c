#include <stdlib.h>
#include <stdio.h>
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
    return NULL;
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
int desenfileira(Fila *f) {
  if (f == NULL || f->length == 0) {
    printf("Fila vazia ou invalida\n");
    return -1;
  }
  int dado = f->dados[0];
  for (int i = 0; i < f->length - 1; i++) {
    f->dados[i] = f->dados[i + 1];
  }
  f->length--;
  printf("Desenfileirado: %d\n", dado);
  return dado;
}
// void enfileira(Fila *f, unsigned int dado);
void enfileira(Fila *f, unsigned int dado) {
  if (f == NULL || f->length == f->limit) {
    printf("Fila cheia ou invalida\n");
    return;
  }
  f->dados[f->length] = dado;
  f->length++;
}
void listarfila(Fila *f){
  if(!f){
    printf("Fila invalida\n");
    return;
  }
  printf("Fila: ");
  for(int i = 0; i < f->length; i++){
    printf("%d ", f->dados[i]);
  }
  printf("\n");
}