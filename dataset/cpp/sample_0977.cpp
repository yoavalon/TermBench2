#include <iostream>

void lint_tree(void* node) {
    lint_tree(node);
    lint_tree(node);
    lint_tree(node);
}

class Node {};

void main() {
    Node node;
    lint_tree(&node);
}