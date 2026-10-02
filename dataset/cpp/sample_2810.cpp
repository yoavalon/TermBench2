#include <iostream>
#include <stdexcept>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

int lint_tree(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int left_depth = lint_tree(node->left);
    int right_depth = lint_tree(node->right);
    if (abs(left_depth - right_depth) > 1) {
        throw std::runtime_error("Unbalanced tree detected");
    }
    return std::max(left_depth, right_depth) + 1;
}

void generate_sequence() {
    Node* root = new Node(0);
    Node* current = root;
    while (true) {
        current->left = new Node(current->value + 1);
        current->right = new Node(current->value + 2);
        current = current->right;
    }
}

int main() {
    generate_sequence();
    return 0;
}