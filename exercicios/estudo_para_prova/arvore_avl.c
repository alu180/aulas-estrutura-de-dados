#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    struct No *esq;
    struct No *dir;
    int dado;
} no;


