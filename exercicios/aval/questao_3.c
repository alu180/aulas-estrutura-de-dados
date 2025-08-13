#include <stdlib.h>
#include <stdio.h>


typedef struct no No;

struct no {
int dado;
No *esq;
No *dir;
};

No *criar_no(int dado) {
    No *novo_no = malloc(sizeof(No));
    if(novo_no) {
        novo_no->esq = NULL;
        novo_no->dir = NULL;
        novo_no->dado = dado;
    }
    return novo_no;
}

void exibir(No *no) {
    if(no) { // no != NULL
        exibir(no->dir);
        printf("(%d)",no->dado); // em-ordem
        exibir(no->esq);
    }
}
//-------------------------------------------------
void inserir_ordenado(No *arvore, int dado) {
    if (dado == arvore->dado) {
        return;
    } else if (dado < arvore->dado) {
        if (arvore->esq == NULL) {
            arvore->esq = criar_no(dado);
        } else {
            inserir_ordenado(arvore->esq, dado);
        }
    } else {
        if (arvore->dir == NULL) {
            arvore->dir = criar_no(dado);
        } else {
            inserir_ordenado(arvore->dir, dado);
        }
    }
}
//-------------------------------------------------
int altura(No *arvore) {
    if (arvore == NULL) {
        return -1;
    } else {
        int altura_esq = altura(arvore->esq);
        int altura_dir = altura(arvore->dir);
        return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir);
    }
}
//-------------------------------------------------

int caminho_aux(No *arvore, int dado, int eh_raiz) {
    if (arvore == NULL) {
        return 0;
    }
    if (arvore->dado == dado) {
        if (!eh_raiz) printf("(%d)", arvore->dado);
        return 1;
    }
    int encontrado_esq = caminho_aux(arvore->esq, dado, 0); // Busca na esquerda
    if (encontrado_esq) {
        printf("(%d)", arvore->dado);
        return 1;
    }
    int encontrado_dir = caminho_aux(arvore->dir, dado, 0); // Busca na direita
    if (encontrado_dir) {
        printf("(%d)", arvore->dado);
        return 1;
    }
    return 0;
}

void caminho(No *arvore, int dado) {
    printf("caminho para %d: ", dado);
    int encontrado = caminho_aux(arvore, dado, 1);
    if (!encontrado) printf("Nao encontrado");
    printf("\n");
}
//-------------------------------------------------

int total_nos(No *arvore) {
    if (arvore == NULL) {
        return 0;
    } else {
        return 1 + total_nos(arvore->esq) + total_nos(arvore->dir);
    }
}
//-------------------------------------------------

int main() {
    No *raiz = criar_no(5);
    raiz->esq = criar_no(3);
        raiz->esq->esq = criar_no(0);
        raiz->esq->dir = criar_no(4);
    raiz->dir = criar_no(8);
        raiz->dir->dir = criar_no(9);


    printf("arvore original:\n");
    exibir(raiz);
    printf("\n\n");

    caminho(raiz, 0); // Saída: (0)(3)(5)
    caminho(raiz, 5); // Saída: (vazio)
    caminho(raiz, 9); // Saída: (9)(8)(5)
    printf("\n");

    // teste Inserir 6
    inserir_ordenado(raiz, 6);
    printf("apos inserir 6:\n");
    exibir(raiz);
    printf("\n\n");

    // teste Inserir 4 (ja existe nao insere)
    inserir_ordenado(raiz, 4);
    printf("apos tentar inserir 4:\n");
    exibir(raiz);
    printf("\n\n");

    printf("arvore atual:\n");
    exibir(raiz);
    printf("\nAltura da arvore: %d\n", altura(raiz));
    printf("Total de nos: %d\n", total_nos(raiz));

      raiz->esq->dir->dir = criar_no(7); //teste funcoes altura e total_nos
    printf("\narvore final:\n");
    exibir(raiz);
    printf("\nAltura da arvore: %d\n", altura(raiz));
    printf("Total de nos: %d\n", total_nos(raiz));
    



    return 0;
}
