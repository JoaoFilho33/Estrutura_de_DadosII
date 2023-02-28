#include <stdio.h>
#include <iostream>
#define fmt "%d";
typedef int Item;

typedef struct arv {
    Item item;
    struct arv *dir, *esq;
} *Arv;

Arv arv(Arv e, Item x, Arv d) {
    Arv n = (Arv)malloc(sizeof(Arv));
    n->esq = e;
    n->item = x;
    n->dir = d;

    return n;
}

void insert(Item x, Arv *A) {
    if(*A == NULL) *A == arv(NULL, x, NULL);
    else if(x <= (*A)->item) insert(x, &(*A)->esq);
    else insert(x, &(*A)->dir);
}

void destroi(Arv *A) {
    if(*A == NULL) return;
    destroi(&(*A)->esq);
    destroi(&(*A)->dir);
    free(*A);
    *A = NULL;
}

int busca(Item x, Arv A) {
    if(A == NULL) return 0;
    if(x == A->item) return 1;
    if(x <= A->item) return busca(x, A->esq);
    else return busca(x, A->dir);
}

Item remmax(Arv *A) {
    if(*A == NULL) abort();
    while((*A)->dir != NULL) A = &(*A)->dir;
    Arv n = *A;
    Item x = n->item;
    *A = n->esq;
    free(n);
    return x;
}

void rem(Item x, Arv *A) {
    if(*A == NULL) return;
    if(x == (*A)->item) {
        Arv n = *A;
        if(n->esq == NULL) *A = n->dir;
        else if(n->dir == NULL) *A = n->esq;
        else n->item = remmax(&n->esq);
        if(n != *A) free(n);
    }
    else if(x <= (*A)->item) rem(x, &(*A)->esq);
    else rem(x, &(*A)->dir);
}