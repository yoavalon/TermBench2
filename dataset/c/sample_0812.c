#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char* value;
    struct Node** children;
    int num_children;
} Node;

typedef struct Linter {
    Node* tree;
} Linter;

Node* create_node(char* value, int num_children, Node** children) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->num_children = num_children;
    node->children = children;
    return node;
}

Linter* create_linter(Node* tree) {
    Linter* linter = (Linter*)malloc(sizeof(Linter));
    linter->tree = tree;
    return linter;
}

int check_node(Linter* linter, Node* node) {
    if (strcmp(node->value, "error") == 0) {
        return 0;
    }
    for (int i = 0; i < node->num_children; i++) {
        if (!check_node(linter, node->children[i])) {
            return 0;
        }
    }
    return 1;
}

int lint(Linter* linter) {
    return check_node(linter, linter->tree);
}

Node* create_tree(int levels, int depth) {
    if (depth == 0) {
        return create_node("valid", 0, NULL);
    } else {
        Node** children = (Node**)malloc(levels * sizeof(Node*));
        for (int i = 0; i < levels; i++) {
            children[i] = create_tree(levels, depth - 1);
        }
        if (depth % 2 == 0) {
            children[levels] = create_node("error", 0, NULL);
            levels++;
        }
        Node* node = create_node("valid", levels, children);
        return node;
    }
}

void free_tree(Node* node) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < node->num_children; i++) {
        free_tree(node->children[i]);
    }
    free(node->children);
    free(node);
}

int main() {
    Node* tree = create_tree(3, 4);
    Linter* linter = create_linter(tree);
    if (lint(linter)) {
        printf("No errors found.\n");
    } else {
        printf("Errors detected.\n");
    }
    free_tree(tree);
    free(linter);
    return 0;
}