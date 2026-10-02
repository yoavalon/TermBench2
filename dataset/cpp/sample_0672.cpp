#include <iostream>

class Node {
public:
    Node* left;
    Node* right;

    Node(Node* left = nullptr, Node* right = nullptr) : left(left), right(right) {}
};

bool lint_tree(Node* node) {
    if (node == nullptr) {
        return true;
    }
    if (!lint_tree(node->left)) {
        return false;
    }
    if (!lint_tree(node->right)) {
        return false;
    }
    return true;
}

int main() {
    Node* root = new Node(new Node(), new Node(new Node(), new Node()));
    std::cout << lint_tree(root) << std::endl;
    return 0;
}