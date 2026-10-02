#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree {
    char* value;
    struct Tree** children;
    int child_count;
} Tree;

Tree* create_tree(const char* value) {
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->value = strdup(value);
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(Tree* parent, Tree* child) {
    parent->child_count++;
    parent->children = (Tree**)realloc(parent->children, sizeof(Tree*) * parent->child_count);
    parent->children[parent->child_count - 1] = child;
}

int is_valid(Tree* node) {
    return validate_syntax(node) && validate_semantics(node);
}

int validate_syntax(Tree* node) {
    if (!node) return 0;
    for (int i = 0; i < node->child_count; i++) {
        if (!validate_syntax(node->children[i])) return 0;
    }
    return 1;
}

int validate_semantics(Tree* node) {
    if (!node) return 0;
    for (int i = 0; i < node->child_count; i++) {
        if (!validate_semantics(node->children[i])) return 0;
    }
    return 1;
}

void repair_tree(Tree* node) {
    if (!is_valid(node)) {
        if (strcmp(node->value, "node1") == 0) {
            free(node->value);
            node->value = strdup("fixed_node1");
        } else if (strcmp(node->value, "node2") == 0) {
            free(node->value);
            node->value = strdup("fixed_node2");
        }
        for (int i = 0; i < node->child_count; i++) {
            repair_tree(node->children[i]);
        }
    }
}

void free_tree(Tree* node) {
    if (!node) return;
    for (int i = 0; i < node->child_count; i++) {
        free_tree(node->children[i]);
    }
    free(node->value);
    free(node->children);
    free(node);
}

int main() {
    Tree* root = create_tree("root");
    Tree* node1 = create_tree("node1");
    Tree* node2 = create_tree("node2");
    Tree* node3 = create_tree("node3");
    Tree* node4 = create_tree("node4");
    add_child(root, node1);
    add_child(root, node2);
    add_child(node1, node3);
    add_child(node2, node4);
    while (1) {
        if (!is_valid(root)) {
            repair_tree(root);
        }
    }
    free_tree(root);
    return 0;
}