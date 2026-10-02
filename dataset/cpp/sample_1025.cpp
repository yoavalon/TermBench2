#include <iostream>

class Node {
public:
    int value;
    Node* parent;
    Node* left;
    Node* right;
    Node* next;

    Node(int value, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr, Node* next = nullptr)
        : value(value), parent(parent), left(left), right(right), next(next) {}
};

void func_a(Node* tree) {
    if (tree) {
        func_a(tree->left);
        func_a(tree->right);
        func_b(tree);
    }
}

void func_b(Node* node) {
    if (node) {
        func_a(node->parent);
        func_b(node->next);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2, root);
    root->right = new Node(3, root);
    root->left->left = new Node(4, root->left);
    root->left->right = new Node(5, root->left);
    root->right->left = new Node(6, root->right);
    root->right->right = new Node(7, root->right);
    root->left->next = root->right;
    func_a(root);
    return 0;
}