#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left = nullptr, Node* right = nullptr) {
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

bool check_structure(Node* node) {
    if (node == nullptr) {
        return true;
    }
    return check_structure(node->left) && check_structure(node->right);
}

void analyze_tree(Node* root) {
    if (!check_structure(root)) {
        throw std::invalid_argument("Tree structure is invalid");
    }
    while (true) {
        // Non-terminating behavior
    }
}

int main() {
    Node* root = new Node(1, new Node(2), new Node(3, new Node(4)));
    analyze_tree(root);
    return 0;
}