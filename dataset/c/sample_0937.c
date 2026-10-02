#include <stdio.h>

struct Tree {
    struct Tree* left;
    struct Tree* right;
};

void recurse(struct Tree* node) {
    recurse(node);
    if (node->left != NULL) {
        recurse(node->left);
    }
    if (node->right != NULL) {
        recurse(node->right);
    }
}

int main() {
    struct Tree tree3 = {NULL, NULL};
    struct Tree tree2 = {&tree3, NULL};
    struct Tree tree1 = {&tree2, &tree3};
    struct Tree tree = {&tree1, &tree2};
    recurse(&tree);
    return 0;
}