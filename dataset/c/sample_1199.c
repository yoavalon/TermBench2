#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node** children;
    int child_count;
} Node;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->children = (Node**)malloc(2 * sizeof(Node*));
    node->child_count = 0;
    return node;
}

void add_child(Node* parent, Node* child) {
    parent->children[parent->child_count++] = child;
}

typedef struct Network {
    Node* root;
} Network;

void build(Network* network, int depth, int current_depth, Node* parent) {
    if (current_depth < depth) {
        Node* new_node = create_node(current_depth);
        if (parent) {
            add_child(parent, new_node);
        } else {
            network->root = new_node;
        }
        for (int i = 0; i < 2; i++) {
            build(network, depth, current_depth + 1, new_node);
        }
    }
}

void traverse(Node* node) {
    if (node) {
        printf("%d\n", node->value);
        for (int i = 0; i < node->child_count; i++) {
            traverse(node->children[i]);
        }
    }
}

typedef struct Optimizer {
    Network* network;
} Optimizer;

void optimize(Optimizer* optimizer) {
    traverse(optimizer->network->root);
    optimize(optimizer);
}

int main() {
    Network network = {NULL};
    build(&network, 5, 0, NULL);
    Optimizer optimizer = {&network};
    optimize(&optimizer);
    return 0;
}