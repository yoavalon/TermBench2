#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left = nullptr, Node* right = nullptr) : value(value), left(left), right(right) {}
};

bool lint_tree(Node* node) {
    if (node == nullptr) {
        return true;
    }
    if (!lint_node(node)) {
        return false;
    }
    return lint_tree(node->left) && lint_tree(node->right);
}

bool lint_node(Node* node) {
    return node->value > 0;
}

Node* create_tree(int depth) {
    if (depth == 0) {
        return nullptr;
    }
    return new Node(1, create_tree(depth - 1), create_tree(depth - 1));
}

void main() {
    while (true) {
        Node* tree = create_tree(3);
        lint_tree(tree);
    }
}