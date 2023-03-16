#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct arv {
	char info;
	struct arv *esq;
	struct arv *dir;
} Arv;

Arv *arvore(char x,Arv *e,Arv *d){
	Arv *novo=(Arv *)malloc(sizeof(Arv));
	novo->esq=e;
	novo->dir=d;
	novo->info=x;
	return novo;	
}

bool ehArvoreBinariaCheia(Arv *no) {
    if (no == NULL) {
        // Árvore vazia é considerada CHEIA
        return true;
    }

    if (no->esq == NULL && no->dir == NULL) {
        // Folha é considerada CHEIA
        return true;
    }

    if (no->esq != NULL && no->dir != NULL) {
        // Nó com dois filhos: continue a verificação recursiva
        return ehArvoreBinariaCheia(no->esq) && ehArvoreBinariaCheia(no->dir);
    }

    // Qualquer outra configuração de filhos é considerada NÃO CHEIA
   return false;
}

main() {
	Arv *raiz = arvore('3', arvore('5',  arvore('2', NULL, NULL), arvore('7', NULL, NULL)), arvore('1', NULL, NULL));

    if(ehArvoreBinariaCheia(raiz)) {
        cout << "Arvore Cheia!";
    }
    else {
        cout << "A árvore não é cheia!";
    }
}