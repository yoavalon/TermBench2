#include <iostream>

void abstract_syntax_tree_linting() {
    struct Node {
        Node* left;
        Node* right;
        Node() : left(nullptr), right(nullptr) {}
    };

    void process_node(Node* node) {
        if (node == nullptr) {
            return;
        }
        process_node(node->left);
        process_node(node->right);
    }

    while (true) {
        Node* root = nullptr;
        process_node(root);
    }
}

int main() {
    abstract_syntax_tree_linting();
    return 0;
}