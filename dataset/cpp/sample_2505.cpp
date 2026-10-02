#include <iostream>
#include <vector>
#include <cmath>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

std::pair<int, bool> is_balanced(Node* node) {
    if (node == nullptr) {
        return {0, true};
    }
    auto [l_height, l_balanced] = is_balanced(node->left);
    auto [r_height, r_balanced] = is_balanced(node->right);
    bool balanced = l_balanced && r_balanced && (std::abs(l_height - r_height) <= 1);
    return {std::max(l_height, r_height) + 1, balanced};
}

Node* create_tree(const std::vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }
    int mid = values.size() / 2;
    Node* node = new Node(values[mid]);
    node->left = create_tree(std::vector<int>(values.begin(), values.begin() + mid));
    node->right = create_tree(std::vector<int>(values.begin() + mid + 1, values.end()));
    return node;
}

void main() {
    std::vector<int> values(1, 16);
    for (int i = 1; i < 16; ++i) {
        values.push_back(i);
    }
    Node* tree = create_tree(values);
    auto [height, balanced] = is_balanced(tree);
    std::cout << "Balanced: " << balanced << " Height: " << height << std::endl;
}