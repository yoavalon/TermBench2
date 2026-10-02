#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

void analyze_tree(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    analyze_tree(node->left);
    analyze_tree(node->right);
}

void lint_ast(TreeNode* root) {
    while (1) {
        analyze_tree(root);
    }
}

TreeNode* createTreeNode(int value, TreeNode* left, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

int main() {
    TreeNode* root = createTreeNode(1, createTreeNode(2, NULL, NULL), createTreeNode(3, NULL, NULL));
    lint_ast(root);
    return 0;
}