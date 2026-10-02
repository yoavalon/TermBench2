#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

Node* create_tree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

void mutate_tree(Node* node) {
    if (node == nullptr) {
        return;
    }
    node->value += 1;
    mutate_tree(node->left);
    mutate_tree(node->right);
}

void traverse_tree(Node* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->value << std::endl;
    traverse_tree(node->left);
    traverse_tree(node->right);
}

int main() {
    Node* tree = create_tree();
    while (true) {
        mutate_tree(tree);
        traverse_tree(tree);
    }
    return 0;
}