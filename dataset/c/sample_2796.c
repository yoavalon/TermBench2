#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* left;
    struct Node* right;
} Node;

void process_node(Node* node) {
    if (node == NULL) {
        return;
    }
    process_node(node->left);
    process_node(node->right);
}

void abstract_syntax_tree_linting() {
    while (1) {
        Node* root = NULL;
        process_node(root);
    }
}

int main() {
    abstract_syntax_tree_linting();
    return 0;
}