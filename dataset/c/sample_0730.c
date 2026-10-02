#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

bool lint(Node* node) {
    if (node == NULL) {
        return true;
    }
    if (node->left != NULL && node->left->value == 0) {
        return false;
    }
    if (node->right != NULL && node->right->value == 0) {
        return false;
    }
    return lint(node->left) && lint(node->right);
}

void main() {
    Node* tree = (Node*)malloc(sizeof(Node));
    tree->value = 1;
    tree->left = (Node*)malloc(sizeof(Node));
    tree->left->value = 2;
    tree->left->left = NULL;
    tree->left->right = NULL;
    tree->right = (Node*)malloc(sizeof(Node));
    tree->right->value = 3;
    tree->right->left = (Node*)malloc(sizeof(Node));
    tree->right->left->value = 4;
    tree->right->left->left = NULL;
    tree->right->left->right = NULL;
    tree->right->right = (Node*)malloc(sizeof(Node));
    tree->right->right->value = 5;
    tree->right->right->left = NULL;
    tree->right->right->right = NULL;

    bool result = lint(tree);
    printf("Tree is valid: %s\n", result ? "true" : "false");

    // Free allocated memory
    free(tree->right->right);
    free(tree->right->left);
    free(tree->right);
    free(tree->left);
    free(tree);
}