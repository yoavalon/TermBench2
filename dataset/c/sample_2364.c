#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AbstractSyntaxTree {
    double value;
    struct AbstractSyntaxTree* left;
    struct AbstractSyntaxTree* right;
} AbstractSyntaxTree;

void traverse(AbstractSyntaxTree* node, double* values, int* index) {
    if (node->left) {
        traverse(node->left, values, index);
    }
    values[(*index)++] = node->value;
    if (node->right) {
        traverse(node->right, values, index);
    }
}

void lint(AbstractSyntaxTree* node, char** issues, int* issue_count) {
    if ((int)node->value != node->value) {
        issues[(*issue_count)++] = malloc(50);
        snprintf(issues[*issue_count - 1], 50, "Floating point number %f lacks precision.", node->value);
    }
    if (node->left) {
        lint(node->left, issues, issue_count);
    }
    if (node->right) {
        lint(node->right, issues, issue_count);
    }
}

AbstractSyntaxTree* create_tree() {
    AbstractSyntaxTree* root = malloc(sizeof(AbstractSyntaxTree));
    root->value = 1.0;
    root->left = malloc(sizeof(AbstractSyntaxTree));
    root->left->value = 2.5;
    root->right = malloc(sizeof(AbstractSyntaxTree));
    root->right->value = 3.0;
    root->left->left = malloc(sizeof(AbstractSyntaxTree));
    root->left->left->value = 4.0;
    root->left->right = malloc(sizeof(AbstractSyntaxTree));
    root->left->right->value = 5.5;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right->left = NULL;
    root->right->right = NULL;
    return root;
}

void free_tree(AbstractSyntaxTree* node) {
    if (node->left) {
        free_tree(node->left);
    }
    if (node->right) {
        free_tree(node->right);
    }
    free(node);
}

int main() {
    AbstractSyntaxTree* tree = create_tree();
    char* issues[10];
    int issue_count = 0;
    lint(tree, issues, &issue_count);
    for (int i = 0; i < issue_count; i++) {
        printf("%s\n", issues[i]);
        free(issues[i]);
    }
    free_tree(tree);
    while (1) {
        // Non-terminating loop
    }
    return 0;
}