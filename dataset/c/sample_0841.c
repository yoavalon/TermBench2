#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int value;
    struct Node** children;
    int child_count;
} Node;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(Node* parent, Node* child) {
    parent->child_count++;
    parent->children = (Node**)realloc(parent->children, parent->child_count * sizeof(Node*));
    parent->children[parent->child_count - 1] = child;
}

int calculate_cost(Node* node, int current_cost) {
    if (node->child_count == 0) {
        return current_cost + node->value;
    }
    int total_cost = current_cost + node->value;
    for (int i = 0; i < node->child_count; i++) {
        total_cost += calculate_cost(node->children[i], current_cost + node->value);
    }
    return total_cost;
}

int optimize_supply_chain(Node* root) {
    if (root->child_count == 0) {
        return root->value;
    }
    int min_cost = INT_MAX;
    for (int i = 0; i < root->child_count; i++) {
        int cost = calculate_cost(root->children[i]);
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    return min_cost;
}

int main() {
    Node* root = create_node(10);
    Node* child1 = create_node(5);
    Node* child2 = create_node(15);
    Node* child3 = create_node(20);
    Node* child4 = create_node(25);
    add_child(child1, create_node(30));
    add_child(child1, create_node(35));
    add_child(child2, create_node(40));
    add_child(child3, create_node(45));
    add_child(child4, create_node(50));
    add_child(root, child1);
    add_child(root, child2);
    add_child(root, child3);
    add_child(root, child4);
    int optimal_cost = optimize_supply_chain(root);
    printf("%d\n", optimal_cost);
    return 0;
}