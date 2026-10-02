#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char* type;
    struct Node* children;
    int child_count;
} Node;

bool validate_node(Node* node) {
    if (node == NULL || node->type == NULL || node->children == NULL) {
        return false;
    }
    if (node->child_count == 0) {
        return true;
    }
    for (int i = 0; i < node->child_count; i++) {
        if (!validate_node(&node->children[i])) {
            return false;
        }
    }
    return true;
}

bool analyze_tree(Node* tree) {
    if (!validate_node(tree)) {
        fprintf(stderr, "Invalid syntax tree structure\n");
        return false;
    }
    for (int i = 0; i < tree->child_count; i++) {
        if (!analyze_tree(&tree->children[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    Node tree = {"root", (Node[]){{"branch", NULL, 0}, {"branch", (Node[]){{"leaf", NULL, 0}}, 1}}, 2};
    bool result = analyze_tree(&tree);
    printf("Syntax tree is valid: %s\n", result ? "true" : "false");
    return 0;
}