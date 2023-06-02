#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

void insertNode(TreeNode*& root, int value) {
    if (root == NULL) {
        root = new TreeNode(value);
        return;
    }

    if (value < root->value)
        insertNode(root->left, value);
    else
        insertNode(root->right, value);
}

int calculateHeight(TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == NULL)
        return;

    inorderTraversal(root->left, result);
    result.push_back(root->value);
    inorderTraversal(root->right, result);
}

TreeNode* balanceTree(vector<int>& sortedArray, int first, int last) {
    if (first > last)
        return NULL;

    int mid = (first + last) / 2;
    TreeNode* root = new TreeNode(sortedArray[mid]);

    root->left = balanceTree(sortedArray, first, mid - 1);
    root->right = balanceTree(sortedArray, mid + 1, last);

    return root;
}

bool isTreeBalanced(TreeNode* root) {
    if (root == NULL)
        return true;

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);
    bool isBalanced = abs(leftHeight - rightHeight) <= 1;

    return isBalanced;
}

bool areTreesEqual(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->value != root2->value)
        return false;

    return areTreesEqual(root1->left, root2->left) && areTreesEqual(root1->right, root2->right);
}

int main() {
    // Vetor de valores a serem inseridos na árvore
    int valuesArray[] = {7, 6, 22, 14, 40, 63};
    vector<int> values(valuesArray, valuesArray + sizeof(valuesArray) / sizeof(valuesArray[0]));

    // 1) Construindo a árvore binária
    TreeNode* root = NULL;
    for (size_t i = 0; i < values.size(); ++i)
        insertNode(root, values[i]);

    // 1.1) Calculando a altura da árvore
    int height = calculateHeight(root);
    cout << "Altura da árvore: " << height << endl;

    // 1.2) Exibindo a árvore no percurso in-order
    cout << "Árvore resultante (in-order): ";
    vector<int> inorder;
    inorderTraversal(root, inorder);
    for (size_t i = 0; i < inorder.size(); ++i)
        cout << inorder[i] << " ";
    cout << endl;

    // 1.3) Verificando se a árvore está balanceada
    cout << "A árvore resultante está balanceada? " << (isTreeBalanced(root) ? "Sim" : "Não") << endl;

    // 1.4) No caso da árvore resultante NÃO ESTAR balanceada, aplicar o algoritmo de reordenação dos dados para balanceá-la
    if (!isTreeBalanced(root)) {
        vector<int> sortedValues = inorder;
        sort(sortedValues.begin(), sortedValues.end());
        TreeNode* balancedRoot = balanceTree(sortedValues, 0, sortedValues.size() - 1);
        cout << "Árvore balanceada (in-order): ";
        vector<int> inorderBalanced;
        inorderTraversal(balancedRoot, inorderBalanced);
        for (size_t i = 0; i < inorderBalanced.size(); ++i)
            cout << inorderBalanced[i] << " ";
        cout << endl;
        
        cout << "A árvore resultante está balanceada? " << (isTreeBalanced(balancedRoot) ? "Sim" : "Não") << endl;
        cout << "As árvores resultantes são iguais? " << (areTreesEqual(root, balancedRoot) ? "Sim" : "Não") << endl;
    }

   

    return 0;
}
