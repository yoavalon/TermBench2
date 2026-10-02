#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left = nullptr, Node* right = nullptr)
        : value(value), left(left), right(right) {}
};

class Tree {
public:
    Node* root;

    Tree(Node* root) : root(root) {}
};

bool check_tree(Node* node) {
    if (node == nullptr) {
        return true;
    }
    if (node->value < 0) {
        return false;
    }
    return check_tree(node->left) && check_tree(node->right);
}

bool validate_syntax(Tree* tree) {
    if (tree->root == nullptr) {
        return true;
    }
    return check_tree(tree->root);
}

int main() {
    Node* tree = new Tree(new Node(1, new Node(2), new Node(3, new Node(-4)))).root;
    std::cout << validate_syntax(new Tree(tree)) << std::endl;
    return 0;
}