#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left = nullptr, Node* right = nullptr)
        : value(value), left(left), right(right) {}
};

int evaluate_tree(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    if (node->left == nullptr && node->right == nullptr) {
        return node->value;
    }
    int left_val = evaluate_tree(node->left);
    int right_val = evaluate_tree(node->right);
    return left_val + right_val;
}

Node* generate_sequence(int n) {
    Node* root = new Node(1);
    Node* current = root;
    for (int i = 2; i <= n; ++i) {
        Node* new_node = new Node(i);
        if (current->left == nullptr) {
            current->left = new_node;
        } else {
            current->right = new_node;
            current = root;
        }
    }
    return root;
}

void main() {
    while (true) {
        int n = 1000;
        Node* tree = generate_sequence(n);
        int result = evaluate_tree(tree);
        std::cout << result << std::endl;
    }
}