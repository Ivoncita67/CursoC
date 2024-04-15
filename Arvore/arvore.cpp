#include <iostream>

using namespace std;

// Defini��o da estrutura do n� da �rvore
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Fun��o para criar um novo n� da �rvore
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // A altura inicial � 1, pois o n� � uma folha
    return node;
}

// Fun��o para obter a altura de um n�
int height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Fun��o para obter o fator de balanceamento de um n�
int balanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

// Fun��o para atualizar a altura de um n�
void updateHeight(Node* node) {
    node->height = 1 + max(height(node->left), height(node->right));
}

// Fun��o para rotacionar � direita em torno de um determinado n�
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Realiza a rota��o
    x->right = y;
    y->left = T2;

    // Atualiza as alturas
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Fun��o para rotacionar � esquerda em torno de um determinado n�
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Realiza a rota��o
    y->left = x;
    x->right = T2;

    // Atualiza as alturas
    updateHeight(x);
    updateHeight(y);

    return y;
}

// Fun��o para inserir um novo n� na �rvore AVL
Node* insert(Node* node, int key) {
    // Realiza a inser��o normal de um n� de busca bin�ria
    if (node == nullptr)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Chaves iguais n�o s�o permitidas na �rvore AVL
        return node;

    // Atualiza a altura do n� atual
    updateHeight(node);

    // Verifica se o n� se tornou desbalanceado
    int balance = balanceFactor(node);

    // Caso 1: Desbalanceamento na sub�rvore esquerda do n�
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Caso 2: Desbalanceamento na sub�rvore direita do n�
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Caso 3: Desbalanceamento na sub�rvore esquerda-direita do n�
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso 4: Desbalanceamento na sub�rvore direita-esquerda do n�
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Retorna o ponteiro para o n�
    return node;
}

// Fun��o para percorrer a �rvore em ordem
void inOrder(Node* root) {
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

int main() {
    Node* root = nullptr;

    // Insere os n�s na �rvore AVL
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "�rvore AVL em ordem: ";
    inOrder(root);
    cout << endl;

    return 0;
}
