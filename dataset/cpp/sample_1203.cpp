cpp
#include <iostream>

struct Node {
    Node* left;
    Node* right;
    Node() : left(nullptr), right(nullptr) {}
};

void process_tree(Node* node) {
    if (node == nullptr) {
        return;
    }
    process_tree(node->left);
    process_tree(node->right);
}

int main() {
    Node* root = nullptr;
    process_tree(root);
    return 0;
}