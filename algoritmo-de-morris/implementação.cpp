#include <iostream>
using namespace std;

struct ArvoreNo {
    int valor;
    ArvoreNo *esq;
    ArvoreNo *dir;

    ArvoreNo(int val) : valor(val), esq(nullptr), dir(nullptr) {}
};

void visit(ArvoreNo* node) {
    cout << node->valor << " ";
}

void MorrisInorder(ArvoreNo* root) {
    ArvoreNo* p = root;

    while(p != nullptr) {
        if(p->esq == nullptr) {
            visit(p);
            p = p->dir;
        }
        else {
            ArvoreNo* tmp = p->esq;
            while(tmp->dir != nullptr && tmp->dir != p) {
                tmp = tmp->dir;
            }
            if(tmp->dir == nullptr) {
                tmp->dir = p;
                p = p->esq;
            }
            else {
                visit(p);
                tmp->dir = nullptr;
                p = p->dir;
            }
        }
    }
}

void MorrisPreorder(ArvoreNo* root) {
    ArvoreNo* p = root;

    while(p != nullptr) {
        if(p->esq == nullptr) {
            visit(p);
            p = p->dir;
        }   
        else {
            ArvoreNo* tmp = p->esq;
            while(tmp->dir != nullptr && tmp->dir != p)
                tmp = tmp->dir;
            if (tmp->dir == nullptr) {
                visit(p);
                tmp->dir = p;
                p = p->esq;
            }
            else {
                tmp->dir = nullptr;
                p = p->dir;
            }
        }
    }
}

ArvoreNo* addNode(ArvoreNo* node, int value) {
    ArvoreNo* newNode = new ArvoreNo(value);
    if(node != nullptr) {
        if(node->esq == nullptr) {
            node->esq = newNode;
        }
        else {
            node->dir = newNode;
        }
    }
    return newNode;
}

int main() {
    ArvoreNo* root = addNode(nullptr, 1);
    ArvoreNo* node2 = addNode(root, 2);
    ArvoreNo* node3 = addNode(root, 3);
    ArvoreNo* node4 = addNode(node2, 4);
    ArvoreNo* node5 = addNode(node2, 5);
    ArvoreNo* node6 = addNode(node3, 6);


    cout << "Percurso pré-ordem: ";
    MorrisPreorder(root);
    cout << endl;

    cout << "Percurso in-ordem: ";
    MorrisInorder(root);
    cout << endl;
}
