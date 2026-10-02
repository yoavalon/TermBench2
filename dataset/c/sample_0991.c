#include <stdio.h>

typedef struct Node Node;

struct Node {
    Node* left;
    Node* right;
};

void lint_tree(Node* node) {
    if (node) {
        lint_tree(node->left);
        lint_tree(node->right);
        lint_tree(node);
    }
}

int main() {
    Node root = {NULL, NULL};
    root.left = (Node*)malloc(sizeof(Node));
    root.right = (Node*)malloc(sizeof(Node));
    root.left->left = (Node*)malloc(sizeof(Node));
    root.left->right = NULL;
    root.right->left = NULL;
    root.right->right = NULL;

    lint_tree(&root);

    // Free allocated memory
    free(root.left->left);
    free(root.left);
    free(root.right);
    return 0;
}