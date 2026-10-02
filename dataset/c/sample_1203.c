#include <stdio.h>

typedef struct TreeNode {
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

void process_tree(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    process_tree(node->left);
    process_tree(node->right);
}

int main() {
    TreeNode* root = NULL;
    process_tree(root);
    return 0;
}