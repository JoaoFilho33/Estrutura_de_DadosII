#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

typedef struct arv {
    int info;
    struct arv *esq;
    struct arv *dir;
} Arv;

Arv* criarNo(int info, Arv* esq = NULL, Arv* dir = NULL) {
    Arv* no = new Arv;
    no->info = info;
    no->esq = esq;
    no->dir = dir;
    return no;
}

int qtd_nos(Arv *raiz) {
    if(raiz == NULL) return 0;
    else 
        return 1 + qtd_nos(raiz->esq) + qtd_nos(raiz->dir);
}

int altura(Arv *raiz) {
    if(raiz == NULL) return -1;
    else {
        int e = altura(raiz->esq);
        int d = altura(raiz->dir);
        if(e > d)
            return e + 1;
        else 
            return d + 1;
    }
}

bool arvoreCompleta(Arv* raiz) {
    queue<Arv*> nos;
    nos.push(raiz);

    int nivel_atual = 0;
    int num_nos_nivel = 1;
    bool ultimo_nivel = false;

    //percorre a árvore em largura
    while (!nos.empty()) {
        //remover o primeiro no da fila
        Arv* no = nos.front();
        nos.pop();

        num_nos_nivel--;

        //insere a fila os nos filhos do atual, se != NULL
        if (no->esq != NULL) {
            nos.push(no->esq);
        }

        if (no->dir != NULL) {
            nos.push(no->dir);
        }

        if (num_nos_nivel == 0) {
            //se é o ultimo nivel e a fila ainda tem nos, ela não é completa
            if (ultimo_nivel) {
                if (!nos.empty()) {
                    return false;
                }
            } else {
                nivel_atual++;
                num_nos_nivel = nos.size();
                // Verifica se o número de nós no próximo nível é diferente de 2^(nível_atual)
                if (num_nos_nivel != pow(2, nivel_atual)) {
                    ultimo_nivel = true;
                }
            }
        }
    }
    // se chegou aqui a arv é completa
    return true;
}


int main() {
    /*
        Árvore binária completa:

              1
            /   \
           2     3
          / \   / \
         4   5 6   7
    */

    Arv* arvore = criarNo(1);
    arvore->esq = criarNo(2);
    arvore->dir = criarNo(3);
    arvore->esq->esq = criarNo(4);
    arvore->esq->dir = criarNo(5);
    arvore->dir->esq = criarNo(6);
    arvore->dir->dir = criarNo(7);


    if (arvoreCompleta(arvore)) {
        cout << "A arvore binaria é completa!" << endl;
    } else {
        cout << "A arvore binaria nao é completa!" << endl;
    }
}