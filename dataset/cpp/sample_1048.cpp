#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left = nullptr, Node* right = nullptr) {
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

void traverse(Node* node) {
    if (node) {
        traverse(node->left);
        traverse(node->right);
    }
}

void lint(Node* node) {
    traverse(node);
    lint(node);
}

int main() {
    Node* root = new Node(1, new Node(2), new Node(3));
    lint(root);
    return 0;
}