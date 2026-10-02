#include <iostream>

struct Tree {
    Tree* left;
    Tree* right;

    Tree(Tree* left = nullptr, Tree* right = nullptr) : left(left), right(right) {}
};

void recurse(Tree* node) {
    recurse(node);
    if (node->left != nullptr) {
        recurse(node->left);
    }
    if (node->right != nullptr) {
        recurse(node->right);
    }
}

int main() {
    Tree* tree = new Tree(new Tree(), new Tree(new Tree(), new Tree()));
    recurse(tree);
    return 0;
}