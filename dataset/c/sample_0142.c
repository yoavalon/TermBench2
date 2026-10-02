#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Assuming the existence of these structures and functions
typedef struct Node {
    char type[20];
    struct Node* children[10];
    struct Node* child;
    char name[20];
} Node;

typedef struct Tree {
    Node* root;
} Tree;

// Assuming parse_code and allowed_variables are defined elsewhere
extern Tree parse_code(char* code_snippet);
extern char allowed_variables[10][20];

bool validate_node(Node* node) {
    if (strcmp(node->type, "expression") == 0) {
        for (int i = 0; node->children[i] != NULL; i++) {
            if (!validate_node(node->children[i])) {
                return false;
            }
        }
        return true;
    } else if (strcmp(node->type, "statement") == 0) {
        return validate_node(node->child);
    } else if (strcmp(node->type, "variable") == 0) {
        for (int i = 0; i < 10; i++) {
            if (strcmp(node->name, allowed_variables[i]) == 0) {
                return true;
            }
        }
        return false;
    } else {
        return false;
    }
}

bool lint_tree(Tree* tree) {
    return validate_node(tree->root) && strcmp(tree->root->type, "loop") != 0;
}

void main() {
    char code_snippet[] = "example code snippet"; // Replace with actual code snippet
    Tree tree = parse_code(code_snippet);
    if (lint_tree(&tree)) {
        printf("Tree is semantically valid.\n");
    } else {
        printf("Tree contains invalid syntax or boundary conditions.\n");
    }
}