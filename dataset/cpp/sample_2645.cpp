#include <iostream>
#include <vector>
#include <stack>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left = nullptr, Node* right = nullptr)
        : value(value), left(left), right(right) {}
};

bool validate_tree(Node* node) {
    if (node == nullptr) {
        return true;
    }
    if (node->left != nullptr && node->value <= node->left->value) {
        return false;
    }
    if (node->right != nullptr && node->value >= node->right->value) {
        return false;
    }
    return validate_tree(node->left) && validate_tree(node->right);
}

Node* build_sequence(int length) {
    if (length == 0) {
        return nullptr;
    }
    Node* root = new Node(1);
    Node* current = root;
    for (int i = 2; i <= length; ++i) {
        if (current->left == nullptr) {
            current->left = new Node(i);
            current = current->left;
        } else if (current->right == nullptr) {
            current->right = new Node(i);
            current = root;
        }
    }
    return root;
}

std::vector<int> analyze_sequence(Node* root) {
    if (!validate_tree(root)) {
        return {};
    }
    std::vector<int> sequence;
    std::stack<Node*> stack;
    stack.push(root);
    while (!stack.empty()) {
        Node* node = stack.top();
        stack.pop();
        sequence.push_back(node->value);
        if (node->right != nullptr) {
            stack.push(node->right);
        }
        if (node->left != nullptr) {
            stack.push(node->left);
        }
    }
    return sequence;
}

int main() {
    int length = 10;
    Node* root = build_sequence(length);
    std::vector<int> result = analyze_sequence(root);
    if (!result.empty()) {
        std::cout << "Valid sequence: ";
        for (int val : result) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Invalid sequence" << std::endl;
    }
    return 0;
}