#ifndef FILA_H
#define FILA_H

// protótipo da estrutura
typedef struct fila Fila;

// protótipo das operações
Fila *criarFila(int limit);
void liberarFila(Fila *p);

// a ser implementado pelo aluno
int desenfileira(Fila *p);
void enfileira(Fila *p, unsigned int dado);
void listarfila(Fila *p);

#endif // FILA_H