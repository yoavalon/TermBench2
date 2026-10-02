#include <iostream>
#include <limits>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left = nullptr, Node* right = nullptr) : value(value), left(left), right(right) {}
};

bool validate(Node* node, int min_val = std::numeric_limits<int>::min(), int max_val = std::numeric_limits<int>::max()) {
    if (!node) {
        return true;
    }
    if (node->value <= min_val || node->value >= max_val) {
        return false;
    }
    return validate(node->left, min_val, node->value) && validate(node->right, node->value, max_val);
}

void main() {
    Node* tree = new Node(10, new Node(5), new Node(15, new Node(12), new Node(20)));
    std::cout << validate(tree) << std::endl;
}