#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    struct No *esq;
    struct No *dir;
    int dado;
} No;


int maior(int n1, int n2) { 
    if (n1 > n2)
        return n1;
    else
        return n2;
}

int altura(No *arv) {
    if (arv == NULL)
        return -1;

    int alt_esq = altura(arv->esq);
    int alt_dir = altura(arv->dir);

    return maior(alt_esq, alt_dir) + 1;
}


int fb(No *arv) {
    if (arv == NULL)
        return -1;

    int alt_esq = altura(arv->esq);
    int alt_dir = altura(arv->dir);

    int fator = alt_esq - alt_dir;
    return fator;
}


No *criar_no(int dado) {
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no != NULL) {
        novo_no->dado = dado;
        novo_no->esq = NULL;
        novo_no->dir = NULL;
    }
    return novo_no;
}


No *rot_esq(No *arv) {
    No *temp = arv->dir;
    arv->dir = temp->esq;
    temp->esq = arv;
    return temp;
}


void exibir_pre_ordem(No *arv) {
    if (arv == NULL)
        return;

    printf("(%d)", arv->dado);

    if (arv->esq != NULL)
        exibir_pre_ordem(arv->esq);
    else
        ;

    if (arv->dir != NULL)
        exibir_pre_ordem(arv->dir);
    else
        ;
}

int main() {
    No *raiz = criar_no(1);
    raiz->dir = criar_no(2);
    raiz->dir->dir = criar_no(3);

    printf("fb(1): %d\n", fb(raiz));
    printf("fb(2): %d\n", fb(raiz->dir));
    printf("fb(3): %d\n", fb(raiz->dir->dir));

    exibir_pre_ordem(raiz);
    printf("\n");

    raiz = rot_esq(raiz);

    printf("fb(2): %d\n", fb(raiz));
    printf("fb(1): %d\n", fb(raiz->esq));
    printf("fb(3): %d\n", fb(raiz->dir));

    exibir_pre_ordem(raiz);
    printf("\n");

    return 0;
}
