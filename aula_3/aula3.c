#include <stdio.h>
#include <stdlib.h>



    typedef struct vetor{
        int *dados;
        int length;
        int limit;        
    } vetor;


    vetor *criar_vetor(int limit){
        //exceçoes
        if(limit < 1) return NULL;
        //codigo valido
        vetor *v = malloc(sizeof(vetor));
        if(v){
        v->length = 0;
        v->limit = limit;
        v->dados = calloc(limit, sizeof(int));
        if(!v->dados) { free(v);v = NULL; }
        }
        return v;
    }


    void inserir_fim_vetor(vetor *v, int dado){
        if(!v) {// if(v == NULL)
            printf("vetor invalido\n");
        return;
        }
    if(v->length == v->limit) {
        printf("vetor cheio\n");
        return;
    }
    v->dados[v->length] = dado;
    v->length++;
}


    void liberar_vetor(vetor **v) {
        free((*v)->dados);
        free(*v); //endereço que aponta para um vetor valido
        *v = NULL;
    }

    //liberar_vetor(&v);

    vetor *liberar_vetor_v2(vetor *v) {
        free(v->dados);
        free(v); //endereço que aponta para um vetor valido
        return NULL;
    }

    //v = liberar_vetor_v2(v);

    void listar_vetor(vetor *v) {
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
    printf("\n");
}
void zerar_vetor(vetor *v){
    if(!v) { // if (v == NULL)
        printf("vetor invalido!\n");
        return;
    }
    v->length = 0;
}


void deletar_elemento(vetor*v, int dado){
    if(!v){
        printf("vetor invalido!\n");
        return;
    }
    for(int i = 0; i < v->length; i++){
        if(v->dados[i] == dado){
            //sobreposiçao (deslocamento a esquerda)
            for(int j = i; j < v->length-1;j++){
                v->dados[j] = v->dados[j+1];
            }
            v->length--;
            break;
            //break comentado deleta todos os elementos
        }
    }
}


int main(){

    vetor *v = criar_vetor(10);
    listar_vetor(v);
    inserir_fim_vetor(v, 10);
    inserir_fim_vetor(v, 5);
    inserir_fim_vetor(v, 3);
    inserir_fim_vetor(v, 7);
    inserir_fim_vetor(v, 9);
    inserir_fim_vetor(v, 7);
    inserir_fim_vetor(v, 5);
    deletar_elemento(v, 7);
    listar_vetor(v);




    //deixar assim para para testar o deletar elemento
    /*vetor *v = criar_vetor(4);
    listar_vetor(v);
    inserir_fim_vetor(v, 1);
    inserir_fim_vetor(v, 2);
    inserir_fim_vetor(v, 3);
    inserir_fim_vetor(v, 4);
    inserir_fim_vetor(v, 5);
    listar_vetor(v);
    zerar_vetor(v);
    listar_vetor(v);
    inserir_fim_vetor(v, 5);
    inserir_fim_vetor(v, 6);
    inserir_fim_vetor(v, 7);
    listar_vetor(v);
    liberar_vetor(&v);
    listar_vetor(v);*/


    return 0;
}