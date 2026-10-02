#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left = nullptr, Node* right = nullptr) : value(value), left(left), right(right) {}
};

void traverse(Node* node) {
    if (node == nullptr) {
        return;
    }
    traverse(node->left);
    std::cout << node->value << std::endl;
    traverse(node->right);
}

bool lint(Node* node) {
    if (node == nullptr) {
        return true;
    }
    if (!lint(node->left)) {
        return false;
    }
    if (!lint(node->right)) {
        return false;
    }
    return true;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    while (true) {
        traverse(root);
        lint(root);
    }
    return 0;
}