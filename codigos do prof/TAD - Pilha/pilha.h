#ifndef PILHA_H
#define PILHA_H

// protótipo da estrutura
typedef struct pilha Pilha;

// protótipo das operações
Pilha *criarPilha(int limit);
void liberarPilha(Pilha *p);

// a ser implementado pelo aluno
int top(Pilha *p);
int pop(Pilha *p);
void push(Pilha *p, unsigned int dado);

#endif // PILHA_H