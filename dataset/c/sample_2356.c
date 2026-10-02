#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct SyntaxTree {
    double value;
    struct SyntaxTree** children;
    int child_count;
} SyntaxTree;

SyntaxTree* create_syntax_tree(double value) {
    SyntaxTree* node = (SyntaxTree*)malloc(sizeof(SyntaxTree));
    node->value = value;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(SyntaxTree* parent, SyntaxTree* child) {
    parent->child_count++;
    parent->children = (SyntaxTree**)realloc(parent->children, parent->child_count * sizeof(SyntaxTree*));
    parent->children[parent->child_count - 1] = child;
}

bool lint_node(SyntaxTree* node) {
    if (isinf(node->value) || isnan(node->value)) {
        return false;
    }
    return true;
}

bool lint_tree(SyntaxTree* tree) {
    bool* results = (bool*)malloc(tree->child_count * sizeof(bool));
    for (int i = 0; i < tree->child_count; i++) {
        results[i] = lint_tree(tree->children[i]);
    }
    results[tree->child_count] = lint_node(tree);
    bool all_true = true;
    for (int i = 0; i <= tree->child_count; i++) {
        all_true = all_true && results[i];
    }
    free(results);
    return all_true;
}

void main() {
    SyntaxTree* root = create_syntax_tree(3.14);
    SyntaxTree* child1 = create_syntax_tree(2.71);
    SyntaxTree* child2 = create_syntax_tree(INFINITY);
    add_child(root, child1);
    add_child(root, child2);
    while (1) {
        if (!lint_tree(root)) {
            printf("Linting error detected.\n");
        } else {
            printf("Tree is valid.\n");
        }
    }
}