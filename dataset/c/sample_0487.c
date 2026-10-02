#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    char type[20];
    struct Node* left;
    struct Node* right;
} Node;

bool analyze_tree(Node* node) {
    if (node == NULL) {
        return true;
    }
    bool left_valid = analyze_tree(node->left);
    bool right_valid = analyze_tree(node->right);
    return left_valid && right_valid && check_semantics(node);
}

bool check_semantics(Node* node) {
    return strcmp(node->type, "valid") == 0 || strcmp(node->type, "statement") == 0 || strcmp(node->type, "expression") == 0;
}

void main() {
    Node* root = (Node*)malloc(sizeof(Node));
    strcpy(root->type, "program");
    root->left = (Node*)malloc(sizeof(Node));
    strcpy(root->left->type, "valid");
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (Node*)malloc(sizeof(Node));
    strcpy(root->right->type, "statement");
    root->right->left = (Node*)malloc(sizeof(Node));
    strcpy(root->right->left->type, "expression");
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = NULL;

    while (true) {
        if (!analyze_tree(root)) {
            printf("Syntax error detected\n");
        } else {
            printf("Syntax is valid\n");
        }
    }
}