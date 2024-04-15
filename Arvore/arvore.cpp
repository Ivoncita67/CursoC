#include <iostream>

using namespace std;

// Definição da estrutura do nó da árvore
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Função para criar um novo nó da árvore
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // A altura inicial é 1, pois o nó é uma folha
    return node;
}

// Função para obter a altura de um nó
int height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Função para obter o fator de balanceamento de um nó
int balanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

// Função para atualizar a altura de um nó
void updateHeight(Node* node) {
    node->height = 1 + max(height(node->left), height(node->right));
}

// Função para rotacionar à direita em torno de um determinado nó
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Realiza a rotação
    x->right = y;
    y->left = T2;

    // Atualiza as alturas
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Função para rotacionar à esquerda em torno de um determinado nó
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Realiza a rotação
    y->left = x;
    x->right = T2;

    // Atualiza as alturas
    updateHeight(x);
    updateHeight(y);

    return y;
}

// Função para inserir um novo nó na árvore AVL
Node* insert(Node* node, int key) {
    // Realiza a inserção normal de um nó de busca binária
    if (node == nullptr)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Chaves iguais não são permitidas na árvore AVL
        return node;

    // Atualiza a altura do nó atual
    updateHeight(node);

    // Verifica se o nó se tornou desbalanceado
    int balance = balanceFactor(node);

    // Caso 1: Desbalanceamento na subárvore esquerda do nó
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Caso 2: Desbalanceamento na subárvore direita do nó
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Caso 3: Desbalanceamento na subárvore esquerda-direita do nó
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso 4: Desbalanceamento na subárvore direita-esquerda do nó
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Retorna o ponteiro para o nó
    return node;
}

// Função para percorrer a árvore em ordem
void inOrder(Node* root) {
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

int main() {
    Node* root = nullptr;

    // Insere os nós na árvore AVL
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Árvore AVL em ordem: ";
    inOrder(root);
    cout << endl;

    return 0;
}
