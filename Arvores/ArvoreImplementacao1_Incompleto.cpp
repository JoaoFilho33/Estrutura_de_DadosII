#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct arv {
	int data;
    struct arv *esq;
	struct arv *dir;
}Arv;

Arv *arvore(int x,Arv *d,Arv *e){
	Arv *novo=(Arv *)malloc(sizeof(Arv));
	if(novo == NULL) exit(1);
	novo->esq=e;
	novo->dir=d;
	
	return novo;
}

Arv *insert(Arv *root, int data) {
	Arv *tempNode = (Arv*)malloc(sizeof(Arv));
	Arv *current;
	Arv *parent;

	tempNode->data = data;
	tempNode->esq = NULL;
	tempNode->dir = NULL;

	if(root == NULL) {
		root = tempNode;
	}
	else {
		current = root;
		parent = NULL;

		while(1) {
			parent = current;

			//esquerda da árvore
			if(data < parent->data) {
				current = current->esq;

				if(current == NULL) {
					parent->esq = tempNode;
					return root;
				}
			}
			else {
				current = current->dir;

				//inserir a direita
				if(current == NULL) {
					parent->dir = tempNode;
					return root;
				}
			}
		}
	}
}

void treePrint(Arv *root) {
	if(root != NULL) {
		cout << "<" << root->data;
		treePrint(root->esq);
		treePrint(root->dir);
		cout << ">";
	}
}


int main(){
	Arv *root = NULL;
    root = insert(root, 5), insert(root, 4), insert(root, 19), insert(root, 1), insert(root, 3);

    treePrint(root);
    printf ("\n");	
}
