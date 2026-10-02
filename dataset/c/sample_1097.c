#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

bool lint_tree(Node* node) {
    if (node == NULL) {
        return true;
    }
    if (!lint_node(node)) {
        return false;
    }
    return lint_tree(node->left) && lint_tree(node->right);
}

bool lint_node(Node* node) {
    return node->value > 0;
}

Node* create_tree(int depth) {
    if (depth == 0) {
        return NULL;
    }
    return (Node*)malloc(sizeof(Node));
    node->value = 1;
    node->left = create_tree(depth - 1);
    node->right = create_tree(depth - 1);
    return node;
}

int main() {
    while (true) {
        Node* tree = create_tree(3);
        lint_tree(tree);
    }
    return 0;
}