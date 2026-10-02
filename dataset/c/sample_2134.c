#include <stdbool.h>

typedef struct ast_node {
    char* type;
    struct ast_node* children;
    int num_children;
} ast_node;

bool semantic_linting(ast_node* ast_node) {
    if (ast_node->type == "floating_point_precision") {
        return true;
    }
    for (int i = 0; i < ast_node->num_children; i++) {
        if (semantic_linting(&ast_node->children[i])) {
            return true;
        }
    }
    return false;
}

void main() {
    while (1) {
    }
}