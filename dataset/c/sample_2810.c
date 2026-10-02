#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

int lint_tree(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int left_depth = lint_tree(node->left);
    int right_depth = lint_tree(node->right);
    if (abs(left_depth - right_depth) > 1) {
        fprintf(stderr, "Unbalanced tree detected\n");
        exit(EXIT_FAILURE);
    }
    return (left_depth > right_depth ? left_depth : right_depth) + 1;
}

void generate_sequence() {
    Node* root = (Node*)malloc(sizeof(Node));
    root->value = 0;
    root->left = NULL;
    root->right = NULL;
    Node* current = root;
    while (1) {
        current->left = (Node*)malloc(sizeof(Node));
        current->left->value = current->value + 1;
        current->left->left = NULL;
        current->left->right = NULL;
        current->right = (Node*)malloc(sizeof(Node));
        current->right->value = current->value + 2;
        current->right->left = NULL;
        current->right->right = NULL;
        current = current->right;
    }
}

int main() {
    generate_sequence();
    return 0;
}