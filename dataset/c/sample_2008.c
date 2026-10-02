#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    double value;
    struct Node** children;
    int child_count;
    int child_capacity;
} Node;

Node* create_node(double value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->child_count = 0;
    node->child_capacity = 2;
    node->children = (Node**)malloc(node->child_capacity * sizeof(Node*));
    return node;
}

void add_child(Node* parent, Node* child) {
    if (parent->child_count >= parent->child_capacity) {
        parent->child_capacity *= 2;
        parent->children = (Node**)realloc(parent->children, parent->child_capacity * sizeof(Node*));
    }
    parent->children[parent->child_count++] = child;
}

void traverse(Node* node, int precision) {
    node->value = (double)((int)(node->value * pow(10, precision) + 0.5)) / pow(10, precision);
    for (int i = 0; i < node->child_count; i++) {
        traverse(node->children[i], precision);
    }
}

typedef struct Tree {
    Node* root;
} Tree;

Tree* create_tree(double root_value) {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = create_node(root_value);
    return tree;
}

Node* find_node(Node* node, double value) {
    if (node->value == value) {
        return node;
    }
    for (int i = 0; i < node->child_count; i++) {
        Node* result = find_node(node->children[i], value);
        if (result) {
            return result;
        }
    }
    return NULL;
}

void add_branch(Tree* tree, double parent_value, double child_value) {
    Node* parent_node = find_node(tree->root, parent_value);
    if (parent_node) {
        Node* child_node = create_node(child_value);
        add_child(parent_node, child_node);
    }
}

void apply_precision(Tree* tree, int precision) {
    traverse(tree->root, precision);
}

void free_tree(Node* node) {
    for (int i = 0; i < node->child_count; i++) {
        free_tree(node->children[i]);
    }
    free(node->children);
    free(node);
}

int main() {
    Tree* tree = create_tree(3.14159);
    add_branch(tree, 3.14159, 2.71828);
    add_branch(tree, 2.71828, 1.41421);
    add_branch(tree, 3.14159, 0.57721);
    apply_precision(tree, 3);
    printf("%.3f\n", tree->root->value);
    printf("%.3f\n", tree->root->children[0]->value);
    printf("%.3f\n", tree->root->children[1]->value);
    printf("%.3f\n", tree->root->children[0]->children[0]->value);
    free_tree(tree->root);
    free(tree);
    return 0;
}