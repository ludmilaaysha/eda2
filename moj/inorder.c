#include <stdio.h>
#define MAXV 500

typedef struct no {
    int dado;
    struct no *esq, *dir;
 } no;

no v[MAXV];
int i = -1, c = -1;
int s[MAXV];

void verifica_esq (no *raiz){
    while (raiz->esq != NULL){
        v[++i] = *raiz;
        raiz = raiz->esq;
    }
}

void verifica_dir (no *raiz){
    if (raiz->dir != NULL){
        * raiz = v[i+1];
        verifica_esq(raiz);
    }
}

void processa_raiz (no *raiz){
    s[++c] = raiz->dado;
    // s[c] =  v[i--]->dado;
}

void em_ordem (no *raiz){
    verifica_esq(raiz);
    processa_raiz(raiz);
    verifica_dir(raiz);

    for (int i=0; i<c; i++){
        printf("%d ", s[i]);
    }
    printf("\n");


}
