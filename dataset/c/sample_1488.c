#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* value;
    struct Node** children;
    int child_count;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

Node* create_node(const char* value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = strdup(value);
    node->children = (Node**)malloc(0);
    node->child_count = 0;
    return node;
}

void add_child(Node* parent, Node* child) {
    parent->children = (Node**)realloc(parent->children, (parent->child_count + 1) * sizeof(Node*));
    parent->children[parent->child_count++] = child;
}

void traverse(Node* node, void (*func)(Node*)) {
    func(node);
    for (int i = 0; i < node->child_count; i++) {
        traverse(node->children[i], func);
    }
}

void lint_node(Node* node) {
    if (!node->value) {
        fprintf(stderr, "Node value cannot be empty\n");
        exit(EXIT_FAILURE);
    }
    if (node->child_count > 5) {
        fprintf(stderr, "Node has too many children\n");
        exit(EXIT_FAILURE);
    }
}

void main() {
    Node* root = create_node("root");
    Node* child1 = create_node("child1");
    Node* child2 = create_node("child2");
    Node* child3 = create_node("child3");
    Node* child4 = create_node("child4");
    Node* child5 = create_node("child5");
    Node* child6 = create_node("child6");
    add_child(root, child1);
    add_child(root, child2);
    add_child(root, child3);
    add_child(root, child4);
    add_child(root, child5);
    add_child(root, child6);
    Tree tree;
    tree.root = root;
    traverse(tree.root, lint_node);
    // Free allocated memory
    for (int i = 0; i < root->child_count; i++) {
        free(root->children[i]->value);
        free(root->children[i]);
    }
    free(root->children);
    free(root->value);
    free(root);
}