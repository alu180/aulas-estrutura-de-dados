#ifndef caixa_h
#define caixa_h 1

typedef struct caixa Caixa;

Caixa* caixa_criar(float comprimento, float altura, float largura);
void liberar_caixa(Caixa *c);
void exibir_caixa(Caixa *c);
void area_caixa(Caixa *c);
void volume_caixa(Caixa *c);


#endif