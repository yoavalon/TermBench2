#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

int calculate_cost(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int left_cost = calculate_cost(node->left);
    int right_cost = calculate_cost(node->right);
    return node->value + left_cost + right_cost;
}

std::pair<int, Node*> optimize_supply_chain(Node* root, int budget) {
    if (root == nullptr || budget <= 0) {
        return {0, root};
    }
    auto [left_value, left_node] = optimize_supply_chain(root->left, budget - root->value);
    auto [right_value, right_node] = optimize_supply_chain(root->right, budget - root->value);
    int total_value = root->value + left_value + right_value;
    if (total_value > budget) {
        if (left_value > right_value) {
            root->left = nullptr;
        } else {
            root->right = nullptr;
        }
    }
    return {total_value, root};
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);
    int budget = 25;
    auto [_, optimized_tree] = optimize_supply_chain(root, budget);
    std::cout << "Total Cost of Optimized Supply Chain: " << calculate_cost(optimized_tree) << std::endl;
    return 0;
}