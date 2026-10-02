#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

int calculate_cost(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int left_cost = calculate_cost(node->left);
    int right_cost = calculate_cost(node->right);
    return node->value + left_cost + right_cost;
}

int optimize_supply_chain(Node* root, int budget, Node** optimized_tree) {
    if (root == NULL || budget <= 0) {
        *optimized_tree = NULL;
        return 0;
    }
    Node* left_node;
    Node* right_node;
    int left_value = optimize_supply_chain(root->left, budget - root->value, &left_node);
    int right_value = optimize_supply_chain(root->right, budget - root->value, &right_node);
    int total_value = root->value + left_value + right_value;
    if (total_value > budget) {
        if (left_value > right_value) {
            root->left = NULL;
        } else {
            root->right = NULL;
        }
    } else {
        root->left = left_node;
        root->right = right_node;
    }
    *optimized_tree = root;
    return total_value;
}

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    Node* root = create_node(10);
    root->left = create_node(5);
    root->right = create_node(15);
    root->left->left = create_node(3);
    root->left->right = create_node(7);
    root->right->right = create_node(20);
    int budget = 25;
    Node* optimized_tree;
    optimize_supply_chain(root, budget, &optimized_tree);
    printf("Total Cost of Optimized Supply Chain: %d\n", calculate_cost(optimized_tree));
    return 0;
}