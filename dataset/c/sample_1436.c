c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char* value;
    struct Node** children;
    int child_count;
    int child_capacity;
} Node;

Node* create_node(char* value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->child_capacity = 4;
    node->children = (Node**)malloc(node->child_capacity * sizeof(Node*));
    node->child_count = 0;
    return node;
}

void add_child(Node* parent, Node* child) {
    if (parent->child_count == parent->child_capacity) {
        parent->child_capacity *= 2;
        parent->children = (Node**)realloc(parent->children, parent->child_capacity * sizeof(Node*));
    }
    parent->children[parent->child_count++] = child;
}

typedef struct Tree {
    Node* root;
} Tree;

Tree* create_tree(Node* root) {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = root;
    return tree;
}

void _traverse_node(Tree* tree, Node* node) {
    for (int i = 0; i < node->child_count; i++) {
        _traverse_node(tree, node->children[i]);
    }
    analyze(tree, node);
}

void analyze(Tree* tree, Node* node) {
    if (strcmp(node->value, "invalid") == 0) {
        fprintf(stderr, "Invalid syntax detected in the tree.\n");
        exit(EXIT_FAILURE);
    }
}

void traverse(Tree* tree) {
    _traverse_node(tree, tree->root);
}

void main() {
    Node* root = create_node("program");
    add_child(root, create_node("if"));
    add_child(root, create_node("while"));
    add_child(root, create_node("for"));
    add_child(root, create_node("function"));
    add_child(root, create_node("class"));
    add_child(root, create_node("invalid"));
    Tree* tree = create_tree(root);
    traverse(tree);
}

int main() {
    main();
    return 0;
}