#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* left;
    struct Node* right;
} Node;

int lint_tree(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int left_height = lint_tree(node->left);
    int right_height = lint_tree(node->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

int main() {
    Node* root = (Node*)malloc(sizeof(Node));
    root->left = (Node*)malloc(sizeof(Node));
    root->right = (Node*)malloc(sizeof(Node));
    root->left->left = (Node*)malloc(sizeof(Node));
    root->left->right = (Node*)malloc(sizeof(Node));

    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right->left = NULL;
    root->left->right->right = NULL;

    printf("%d\n", lint_tree(root));

    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}