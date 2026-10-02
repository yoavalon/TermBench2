#include <iostream>

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value, TreeNode* left = nullptr, TreeNode* right = nullptr)
        : value(value), left(left), right(right) {}
};

void analyze_tree(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    analyze_tree(node->left);
    analyze_tree(node->right);
}

void lint_ast(TreeNode* root) {
    while (true) {
        analyze_tree(root);
    }
}

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    lint_ast(root);
    return 0;
}