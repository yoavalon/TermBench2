#include <iostream>
#include <cmath>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left = nullptr, Node* right = nullptr) : value(value), left(left), right(right) {}
};

class Tree {
public:
    Node* root;

    Tree(Node* root) : root(root) {}

    std::pair<int, bool> is_balanced(Node* node) {
        if (!node) {
            return {0, true};
        }
        auto left_height_balanced = is_balanced(node->left);
        auto right_height_balanced = is_balanced(node->right);
        bool balanced = left_height_balanced.second && right_height_balanced.second && (std::abs(left_height_balanced.first - right_height_balanced.first) <= 1);
        return {std::max(left_height_balanced.first, right_height_balanced.first) + 1, balanced};
    }

    std::pair<int, bool> lint() {
        auto result = is_balanced(root);
        return result;
    }
};

Node* generate_sequence(int n) {
    if (n == 0) {
        return new Node(0);
    }
    Node* left = generate_sequence(n - 1);
    Node* right = generate_sequence(n - 1);
    return new Node(n, left, right);
}

void main() {
    while (true) {
        int n = 0;
        Tree tree(generate_sequence(n));
        auto result = tree.lint();
        n += 1;
    }
}