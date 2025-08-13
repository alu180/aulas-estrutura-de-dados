#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prototipo(int, int p2, char p3);

typedef struct {
    char nome[250];
    int idade;
} Pessoa;

typedef struct no {
    int chave;
    Pessoa valor;
    struct no *prox;
} NoChaveValor;


typedef struct lista {
  NoChaveValor *inicio;
  int size;
} ListaEnc;


int hash10(int idade) {
    return idade % 10;
}


typedef struct {
    ListaEnc *listas;          
    int (*h)(int valor);      
} HashTable;


NoChaveValor *criarNo(int chave, Pessoa valor) {
    NoChaveValor *novo = malloc(sizeof(NoChaveValor));
    if (novo) {
        novo->chave = chave;
        novo->valor = valor;
        novo->prox = NULL;
    }
    return novo;
}


HashTable *criarTabelaHash(int size, int (*h)(int)) {
    HashTable *ht = malloc(sizeof(HashTable));
    if (!ht) return NULL;
    ht->listas = calloc(size, sizeof(ListaEnc));
    if (!ht->listas) {
        free(ht);
        return NULL;
    }
    
    for (int i = 0; i < size; i++) {
        ht->listas[i].inicio = NULL;
        ht->listas[i].size = 0;
    }
    ht->h = h;
    return ht;
}


void inserir(Pessoa p, HashTable *ht) {
    if (!ht) return;
    int h = ht->h(p.idade);           
    ListaEnc *lista = &ht->listas[h];


    NoChaveValor *atual = lista->inicio;
    while (atual) {
        if (atual->chave == p.idade) {
            atual->valor = p;
            return;
        }
        atual = atual->prox;
    }

   
    NoChaveValor *novo = criarNo(p.idade, p);
    if (!novo) return;

   
    NoChaveValor *ant = NULL;
    atual = lista->inicio;
    while (atual && atual->chave < novo->chave) {
        ant = atual;
        atual = atual->prox;
    }
    if (ant == NULL) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
    } else {
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    lista->size++;
}


NoChaveValor *getValue(HashTable *ht, int key) {
    if (!ht) return NULL;
    int h = ht->h(key);
    ListaEnc *lista = &ht->listas[h];
    NoChaveValor *atual = lista->inicio;
    while (atual) {
        if (atual->chave == key) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}


void *delKey(HashTable *ht, int key) {
    if (!ht) return NULL;
    int h = ht->h(key);
    ListaEnc *lista = &ht->listas[h];

    NoChaveValor *atual = lista->inicio;
    NoChaveValor *ant = NULL;

    while (atual) {
        if (atual->chave == key) break;
        ant = atual;
        atual = atual->prox;
    }

    if (!atual) {
        return NULL;
    }


    Pessoa *retorno = malloc(sizeof(Pessoa));
    if (!retorno) return NULL; 
    *retorno = atual->valor;

    if (ant == NULL) {
        lista->inicio = atual->prox;
    } else {
        ant->prox = atual->prox;
    }
    free(atual);
    lista->size--;

    return (void *)retorno;
}

int main() {
     //teste da tabela hash
    HashTable *ht = criarTabelaHash(10, hash10);

    Pessoa p1;
    strcpy(p1.nome, "Alice");
    p1.idade = 25;

    Pessoa p2;
    strcpy(p2.nome, "Bruno");
    p2.idade = 35;

    Pessoa p3;
    strcpy(p3.nome, "Carla");
    p3.idade = 15;

    inserir(p1, ht);
    inserir(p2, ht);
    inserir(p3, ht);


    NoChaveValor *busca = getValue(ht, 35);
    if (busca) {
        printf("Encontrou: %s, idade %d\n", busca->valor.nome, busca->valor.idade);
    } else {
        printf("Chave 35 não encontrada.\n");
    }

    Pessoa *removido = (Pessoa *)delKey(ht, 25);
    if (removido) {
        printf("Removido: %s, idade %d\n", removido->nome, removido->idade);
        free(removido);
    } else {
        printf("Chave 25 não encontrada para remoção.\n");
    }

    if (getValue(ht, 25) == NULL) {
        printf("Chave 25 realmente não existe mais.\n");
    }


    return 0;
}
