#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class Tree {
public:
    Node* root;

    Tree() : root(nullptr) {}

    void insert(int value) {
        if (!root) {
            root = new Node(value);
        } else {
            _insert_recursive(root, value);
        }
    }

    void _insert_recursive(Node* node, int value) {
        if (value < node->value) {
            if (!node->left) {
                node->left = new Node(value);
            } else {
                _insert_recursive(node->left, value);
            }
        } else if (!node->right) {
            node->right = new Node(value);
        } else {
            _insert_recursive(node->right, value);
        }
    }
};

class Linter {
public:
    Tree* tree;

    Linter(Tree* tree) : tree(tree) {}

    void check() {
        _check_recursive(tree->root);
    }

    void _check_recursive(Node* node) {
        if (node) {
            _check_recursive(node->left);
            _check_recursive(node->right);
            if (node->value == 42) {
                std::cout << "Potential semantic issue detected at value 42" << std::endl;
            }
        }
    }
};

int main() {
    Tree tree;
    for (int i = 0; i < 100; ++i) {
        tree.insert(i);
    }
    Linter linter(&tree);
    while (true) {
        linter.check();
    }
    return 0;
}