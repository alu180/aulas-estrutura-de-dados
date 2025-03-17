#include <stdio.h>
#include <stdlib.h>


int main(){

    typedef struct vetor{
        int *dados;
        int length;
        int limit;        
    }vetor;

    
    vetor *criar_vetor(int limit){
        //exceçoes
        if(limit < 1) return NULL;
        //codigo valido
        vetor *v = malloc(sizeof(vetor));
        if(v){
        v->length = 0;
        v->limit = limit;
        v->dados = calloc(limit, sizeof(int));
        if(!v->dados) { free(v); }
        }
        return v;
    }

    void liberar_vetor(vetor *v) {
        free(v->dados);
        free(v);
    }

    void lista_vetor(vetor *v) {
        if(!v){printf("vetor invalido\n");
        return;
    }
    if (v->length == 0) {
        printf("vetor vazio\n");
        return;
    }
        for(int i = 0; i < v->length; i++) {
        printf("[%d]", v->dados[i]);
    }
}
void zerar_vetor(vetor *v){
    if(!v) { // if (v == NULL)
        printf("vetor invalido!\n");
        return;
    }
    v->length = 0;
}

    return 0;
}