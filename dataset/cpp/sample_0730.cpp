#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left = nullptr, Node* right = nullptr) : value(value), left(left), right(right) {}
};

bool lint(Node* node) {
    if (node == nullptr) {
        return true;
    }
    if (node->left != nullptr && !(dynamic_cast<Node*>(node->left))) {
        return false;
    }
    if (node->right != nullptr && !(dynamic_cast<Node*>(node->right))) {
        return false;
    }
    return lint(node->left) && lint(node->right);
}

int main() {
    Node* tree = new Node(1, new Node(2), new Node(3, new Node(4), new Node(5)));
    bool result = lint(tree);
    std::cout << "Tree is valid: " << (result ? "true" : "false") << std::endl;
    delete tree->left->left;
    delete tree->left->right;
    delete tree->left;
    delete tree->right->left;
    delete tree->right->right;
    delete tree->right;
    delete tree;
    return 0;
}