#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    double value;
    struct Node** children;
    int child_count;
} Node;

Node* create_node(double value, Node** children, int child_count) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->children = children;
    node->child_count = child_count;
    return node;
}

double evaluate(Node* node) {
    return (double)(int)(node->value * 100000) / 100000;
}

void process_tree(Node* root) {
    if (!root) {
        return;
    }
    root->value = evaluate(root);
    for (int i = 0; i < root->child_count; i++) {
        process_tree(root->children[i]);
    }
}

void main() {
    Node* child1 = create_node(2.7182818284, NULL, 0);
    Node* child2 = create_node(1.4142135623, NULL, 0);
    Node** children = (Node**)malloc(2 * sizeof(Node*));
    children[0] = child1;
    children[1] = child2;
    Node* tree = create_node(3.1415926535, children, 2);
    process_tree(tree);
    printf("%.5f %.5f %.5f\n", tree->value, tree->children[0]->value, tree->children[1]->value);
}