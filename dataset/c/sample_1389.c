#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

bool validate(Node* node, int min_val, int max_val) {
    if (!node) {
        return true;
    }
    if (node->value <= min_val || node->value >= max_val) {
        return false;
    }
    return validate(node->left, min_val, node->value) && validate(node->right, node->value, max_val);
}

int main() {
    Node* tree = (Node*)malloc(sizeof(Node));
    tree->value = 10;
    tree->left = (Node*)malloc(sizeof(Node));
    tree->left->value = 5;
    tree->left->left = NULL;
    tree->left->right = NULL;
    tree->right = (Node*)malloc(sizeof(Node));
    tree->right->value = 15;
    tree->right->left = (Node*)malloc(sizeof(Node));
    tree->right->left->value = 12;
    tree->right->left->left = NULL;
    tree->right->left->right = NULL;
    tree->right->right = (Node*)malloc(sizeof(Node));
    tree->right->right->value = 20;
    tree->right->right->left = NULL;
    tree->right->right->right = NULL;

    printf("%d\n", validate(tree, INT_MIN, INT_MAX));

    // Free allocated memory
    free(tree->right->right);
    free(tree->right->left);
    free(tree->right);
    free(tree->left);
    free(tree);

    return 0;
}