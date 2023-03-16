#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define fmt "%d";
typedef int Item;

typedef struct arv {
    //struct arv *esq;
    Item item;
    struct arv *esq;
    struct arv *dir;
} *Arv;

Arv criarArv(Arv e, Item item, Arv d){
	Arv novo = (Arv)malloc(sizeof(Arv));
	novo->esq = e;
	novo->item = item;
	novo->dir = d;
	return novo;	
}


int calcular(int valor_esq, int valor_dir, char sinal) {
    if(sinal == '+') {
        return valor_esq + valor_dir;
    }
    else if(sinal== '-') {
        return valor_esq - valor_dir;
    }
    else if(sinal == '*') {
        return valor_esq * valor_dir;
    }
    else if(sinal == '/') {
        return valor_esq / valor_dir;
    }
    else {
        cout << "Operador inválido";
    }
}

int valor(Arv raiz) {
    if (raiz == nullptr) {
        return 0;
    }
    else if (raiz->dir == raiz->esq) {
        return raiz->item;
    }
    else{
        int valor_esq = valor(raiz->esq);
        int valor_dir = valor(raiz->dir);
        return calcular(valor_esq, valor_dir, char(raiz->item));
    }

}

int main() {
    // ((5 + 3) / 4) * (6 - 1)
    Arv root = criarArv(criarArv(criarArv(criarArv(NULL, 5, NULL), '+', criarArv(NULL, 3, NULL)), 
    '/', criarArv(NULL, 4, NULL)), '*', criarArv(criarArv(NULL, 6, NULL), '-', criarArv(NULL, 1, NULL)));

    cout << valor(root) << endl; // 10

    return 0;
}
