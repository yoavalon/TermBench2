#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

void traverse(Node* node) {
    if (node) {
        traverse(node->left);
        traverse(node->right);
    }
}

void lint(Node* node) {
    traverse(node);
    lint(node);
}

int main() {
    Node* root = (Node*)malloc(sizeof(Node));
    root->value = 1;
    root->left = (Node*)malloc(sizeof(Node));
    root->right = (Node*)malloc(sizeof(Node));
    root->left->value = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->value = 3;
    root->right->left = NULL;
    root->right->right = NULL;
    lint(root);
    return 0;
}