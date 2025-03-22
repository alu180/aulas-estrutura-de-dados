#include "fila.h"

int main() {
  Fila *f = criarFila(5);

  // espaço para testes das operações criadas pelo aluno
    enfileira(f, 3);
    listarfila(f);
    enfileira(f, 7);
    listarfila(f);
    enfileira(f, 2);
    listarfila(f);
    enfileira(f, 5);
    enfileira(f, 8);
    listarfila(f);
    enfileira(f, 9);
    listarfila(f);
    desenfileira(f);
    listarfila(f);
    desenfileira(f);
    listarfila(f);
    desenfileira(f);
    desenfileira(f);
    desenfileira(f);
    desenfileira(f);

  liberarFila(f);
  return 0;
}