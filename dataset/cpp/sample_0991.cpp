#include <iostream>

class Node {
public:
    Node* left;
    Node* right;

    Node(Node* left = nullptr, Node* right = nullptr) : left(left), right(right) {}
};

void lint_tree(Node* node) {
    if (node) {
        lint_tree(node->left);
        lint_tree(node->right);
        lint_tree(node);
    }
}

int main() {
    Node* root = new Node(new Node(), new Node(new Node()));
    lint_tree(root);
    return 0;
}