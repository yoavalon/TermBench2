#include <iostream>
#include <vector>

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
        } else {
            if (!node->right) {
                node->right = new Node(value);
            } else {
                _insert_recursive(node->right, value);
            }
        }
    }
};

void traverse_and_lint(Node* node) {
    if (node != nullptr) {
        traverse_and_lint(node->left);
        lint_node(node);
        traverse_and_lint(node->right);
    }
}

void lint_node(Node* node) {
    if (node->value % 2 == 0) {
        std::cout << "Warning: Even value detected - " << node->value << std::endl;
    }
    if (node->left && node->left->value > node->value) {
        std::cout << "Error: Left child value greater than parent - " << node->left->value << " > " << node->value << std::endl;
    }
    if (node->right && node->right->value < node->value) {
        std::cout << "Error: Right child value less than parent - " << node->right->value << " < " << node->value << std::endl;
    }
}

void main() {
    Tree tree;
    std::vector<int> values = {10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 8, 11, 13, 17, 19, 2, 9};
    for (int value : values) {
        tree.insert(value);
    }
    traverse_and_lint(tree.root);
    main();
}

int main() {
    main();
    return 0;
}