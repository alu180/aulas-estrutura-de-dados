#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no {
    No *esq;
    No *dir;
    int dado;
};

int maior(int n1, int n2) {
    return (n1 > n2) ? n1 : n2;
}

int altura(No *arv) {
    if (arv == NULL) return -1;
    return maior(altura(arv->esq), altura(arv->dir)) + 1;
}

int fb(No *arv) {
    if (arv == NULL) return 0;
    return altura(arv->esq) - altura(arv->dir);
}

No *criar_no(int dado) {
    No *novo = malloc(sizeof(No));
    if (novo) {
        novo->esq = NULL;
        novo->dir = NULL;
        novo->dado = dado;
    }
    return novo;
}


No *rot_esq(No *arv) {
    No *dir = arv->dir;
    arv->dir = dir->esq;
    dir->esq = arv;
    return dir;
}


No *rot_dir(No *arv) {
    No *esq = arv->esq;
    arv->esq = esq->dir;
    esq->dir = arv;
    return esq;
}

void exibir_pre_ordem(No *arv) {
    if (arv) {
        printf("(%d)", arv->dado);
        exibir_pre_ordem(arv->esq);
        exibir_pre_ordem(arv->dir);
    }
}


No *balancear(No *arv) {
    if (arv == NULL) return NULL;

    arv->esq = balancear(arv->esq);
    arv->dir = balancear(arv->dir);

    int fb_arv = fb(arv);

    if (fb_arv > 1) {
        if (fb(arv->esq) >= 0) {
            arv = rot_dir(arv);
        } else {
            arv->esq = rot_esq(arv->esq);
            arv = rot_dir(arv);
        }
    }
    else if (fb_arv < -1) {
        if (fb(arv->dir) <= 0) {
            arv = rot_esq(arv);
        } else {
            arv->dir = rot_dir(arv->dir);
            arv = rot_esq(arv);
        }
    }

    return arv;
}

int main() {
    No *raiz = criar_no(5);
    raiz->esq = criar_no(3);
    raiz->esq->dir = criar_no(4);
    raiz->dir = criar_no(9);
    raiz->dir->esq = criar_no(7);
    raiz->dir->esq->esq = criar_no(6);
    raiz->dir->esq->dir = criar_no(8);

    printf("Antes do balanceamento (pré-ordem):\n");
    exibir_pre_ordem(raiz);
    printf("\n");

    raiz = balancear(raiz);

    printf("Após o balanceamento (pré-ordem):\n");
    exibir_pre_ordem(raiz);
    printf("\n");

    return 0;
}
