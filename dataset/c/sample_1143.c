#include <stdio.h>
#include <stdlib.h>

typedef struct SupplyChainNode {
    int value;
    struct SupplyChainNode** children;
    int child_count;
} SupplyChainNode;

SupplyChainNode* create_node(int value) {
    SupplyChainNode* node = (SupplyChainNode*)malloc(sizeof(SupplyChainNode));
    node->value = value;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(SupplyChainNode* parent, SupplyChainNode* child) {
    parent->child_count++;
    parent->children = (SupplyChainNode**)realloc(parent->children, parent->child_count * sizeof(SupplyChainNode*));
    parent->children[parent->child_count - 1] = child;
}

int optimize_path(SupplyChainNode* node, int current_value, int best_value) {
    if (current_value > best_value) {
        best_value = current_value;
    }
    for (int i = 0; i < node->child_count; i++) {
        best_value = optimize_path(node->children[i], current_value + node->children[i]->value, best_value);
    }
    return best_value;
}

int infinite_optimization(SupplyChainNode* node) {
    int best_value = optimize_path(node, 0, 0);
    return infinite_optimization(node);
}

SupplyChainNode* create_supply_chain() {
    SupplyChainNode* root = create_node(10);
    SupplyChainNode* node1 = create_node(20);
    SupplyChainNode* node2 = create_node(30);
    SupplyChainNode* node3 = create_node(40);
    SupplyChainNode* node4 = create_node(50);
    SupplyChainNode* node5 = create_node(60);
    SupplyChainNode* node6 = create_node(70);
    SupplyChainNode* node7 = create_node(80);
    SupplyChainNode* node8 = create_node(90);
    SupplyChainNode* node9 = create_node(100);
    SupplyChainNode* node10 = create_node(110);
    add_child(root, node1);
    add_child(root, node2);
    add_child(node1, node3);
    add_child(node1, node4);
    add_child(node2, node5);
    add_child(node2, node6);
    add_child(node3, node7);
    add_child(node3, node8);
    add_child(node4, node9);
    add_child(node4, node10);
    return root;
}

void main() {
    SupplyChainNode* supply_chain = create_supply_chain();
    infinite_optimization(supply_chain);
}