#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define fmt "%d";
typedef int Item;

typedef struct arv {
    Item item;
    struct arv *dir, *esq;
} Arv;

Arv* insert(Arv *raiz, int num) {
    if(raiz == NULL) {
        Arv *aux = (Arv *)malloc(sizeof(Arv));
        aux->item = num;
        aux->esq = NULL;
        aux->dir = NULL;

        return aux;
    }
    else {
        if(num < raiz->item)
            raiz->esq = insert(raiz->esq, num);
        else
            raiz->dir = insert(raiz->dir, num);
        return raiz;
    }
}

//Q 13.2
int qtd_nos(Arv *raiz) {
    if(raiz == NULL) return 0;
    else 
        return 1 + qtd_nos(raiz->esq) + qtd_nos(raiz->dir);
    
}

//Q 13.3
int qtd_folhas(Arv *raiz) {
    if(raiz == NULL) return 0;
    else if(raiz->esq == NULL && raiz->dir == NULL) return 1;
    else 
        return qtd_folhas(raiz->esq) + qtd_folhas(raiz->dir);
}

//Q 13.4
int altura(Arv *raiz) {
    if(raiz == NULL) return -1;
    else {
        int e = altura(raiz->esq);
        int d = altura(raiz->dir);
        if(e> d)
            return e + 1;
        else 
            return d + 1;
    }
}

//Q 13.5
Arv* tem(Arv *raiz, int valor) {
    while(raiz) {
        if(valor < raiz->item)
            raiz = raiz->esq;
        else if(valor > raiz->item)
            raiz = raiz->dir;
        else 
            return raiz;
    }
    return NULL;
}

void imprimir(Arv *raiz) {
    if(raiz) {
        cout << "<";
        imprimir(raiz->esq);
        cout << raiz->item;
        imprimir(raiz->dir);
        cout << ">";
    }

}

int main() {
    Arv *raiz = NULL;   
    Arv *busca;

    raiz = insert(raiz, 1), insert(raiz, 14), insert(raiz, 3);

    imprimir(raiz);

    busca = tem(raiz, 14);
    if(busca)
        printf("\nValor encontrado: %d\n", busca->item);
    else
        printf("\nValor não encontrado\n!");

    cout << "Altura: " << altura(raiz) << endl;
    cout << "Quantidade de nos: " << qtd_nos(raiz) << endl;
    cout << "Quantidade de folhas: " << qtd_folhas(raiz) << endl;
}

/*
Saída:
<1<<3>14>>
Valor encontrado: 14
Altura: 2
Quantidade de nos: 3
Quantidade de folhas: 1

*/