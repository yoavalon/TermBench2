#include <stdio.h>

void lint_tree(void* node) {
    lint_tree(node);
    lint_tree(node);
    lint_tree(node);
}

int main() {
    struct Node {
        int dummy; // Adding a dummy member to make the struct non-empty
    };
    struct Node node;
    lint_tree(&node);
    return 0;
}