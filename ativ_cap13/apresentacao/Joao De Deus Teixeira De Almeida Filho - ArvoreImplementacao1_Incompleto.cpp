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

void imprime(Arv *n) {
	if (n != NULL) {

		cout << "<" << n->info;
		imprime(n->esq);
		imprime(n->dir);
		cout << ">";
	} else
		cout << "<>";
}

int calculaQuantNos(Arv *no) {
	 if(no == NULL) return 0;
    else 
        return 1 + calculaQuantNos(no->esq) + calculaQuantNos(no->dir);
}

int calculaQuantNosFolha(Arv *no) {
	if (no == NULL)
		return 0;
	else if (no->esq == NULL && no->dir == NULL)
		return 1;
	else
		return calculaQuantNosFolha(no->esq) + calculaQuantNosFolha(no->dir);
}

int alturaArvore(Arv *no) {
	if (no == NULL)
		return 0;
	else if (no->esq == NULL && no->dir == NULL)
		return 1;
	else
		return calculaQuantNosFolha(no->esq) + calculaQuantNosFolha(no->dir);
}

Arv* procura(Arv *no, char valor) {
	 while(no) {
        if(valor < no->info)
            no = no->esq;
        else if(valor > no->info)
            no = no->dir;
        else 
            return no;
    }
    return NULL;
}

void desalocaNo(Arv *no) {
	if(no == NULL) {
		return;
	}

	desalocaNo(no->esq);
	desalocaNo(no->dir);

	free(no);
	no = NULL;
}

// remove o n� procurado. Se o n� tiver filhos, remova tamb�m os filhos
int removeSubArvore(Arv **no, char valor) {
		 if (*no == NULL) return 0;

    if ((*no)->info == valor) {
        desalocaNo(*no);
        *no = NULL;
        return 1;
    }

    int removido = removeSubArvore(&(*no)->esq, valor);

    if (removido) return removido;	

    removido = removeSubArvore(&(*no)->dir, valor);

    if (removido) return removido;

    return 0;
}

main() {
	Arv *raiz = arvore('3', arvore('5',  arvore('2', NULL, NULL), arvore('7', NULL, NULL)), arvore('1', NULL, NULL));

	imprime(raiz);
	removeSubArvore(&raiz, '1');
	cout << endl;
	imprime(raiz);
}

/*
<3<5<2<><>><7<><>>><1<><>>>
<3<5<2<><>><7<><>>><>>
*/