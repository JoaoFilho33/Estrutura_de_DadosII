#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    vector<Node*>filho; // vetor de ponteiros para o filho do nó
    
    Node(int val) : value(val) {} // constructor que inicializa um nó com um valor
};

void addNode(Node* parente, int value) {
    Node* newNode = new Node(value);
    parente->filho.push_back(newNode);
}

void inorder(Node* node) {
    if (node == nullptr) return;

    for (Node* filho : node->filho) {   // Percorre os filhos do nó atual
        inorder(filho);
    }

    cout << node->value << " ";
}

void preorder(Node* node) {
    if (node == nullptr) return;

    cout << node->value << " "; // imprime o nó atual

    for (Node* filho : node->filho) {
        preorder(filho);
    }
}

int main() {
    Node* root = new Node(1); // raiz
    addNode(root, 2); //filho esq
    addNode(root, 3); //filho dir
    addNode(root->filho[0], 4); //addNode 4 como filho do filho[0]
    addNode(root->filho[0], 5);
    addNode(root->filho[1], 6); //addNode 4 como filho do filho[1]

    cout << "Percurso in-order: ";
    inorder(root);
    cout << endl;

    cout << "Percurso pre-order: ";
    preorder(root);
    cout << endl;

}