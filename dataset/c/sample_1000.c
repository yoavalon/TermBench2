#include <stdio.h>

typedef struct Node {
    struct Node* left;
    struct Node* right;
} Node;

void lint_tree(Node* node) {
    if (node == NULL) {
        return;
    }
    lint_tree(node->left);
    lint_tree(node->right);
    lint_tree(node);
}

int main() {
    Node* root = (Node*)malloc(sizeof(Node));
    root->left = (Node*)malloc(sizeof(Node));
    root->right = (Node*)malloc(sizeof(Node));
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->left = (Node*)malloc(sizeof(Node));
    root->right->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    lint_tree(root);
    return 0;
}