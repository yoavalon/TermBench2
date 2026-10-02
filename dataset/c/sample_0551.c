#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

void Tree_init(Tree* tree) {
    tree->root = NULL;
}

void Node_init(Node* node, int value) {
    node->value = value;
    node->left = NULL;
    node->right = NULL;
}

void Tree_insert(Tree* tree, int value) {
    if (!tree->root) {
        tree->root = (Node*)malloc(sizeof(Node));
        Node_init(tree->root, value);
    } else {
        Tree_insert_recursive(tree->root, value);
    }
}

void Tree_insert_recursive(Node* node, int value) {
    if (value < node->value) {
        if (!node->left) {
            node->left = (Node*)malloc(sizeof(Node));
            Node_init(node->left, value);
        } else {
            Tree_insert_recursive(node->left, value);
        }
    } else {
        if (!node->right) {
            node->right = (Node*)malloc(sizeof(Node));
            Node_init(node->right, value);
        } else {
            Tree_insert_recursive(node->right, value);
        }
    }
}

typedef struct Linter {
    Tree* tree;
} Linter;

void Linter_init(Linter* linter, Tree* tree) {
    linter->tree = tree;
}

void Linter_check(Linter* linter) {
    Linter_check_recursive(linter->tree->root);
}

void Linter_check_recursive(Node* node) {
    if (node) {
        Linter_check_recursive(node->left);
        Linter_check_recursive(node->right);
        if (node->value == 42) {
            printf("Potential semantic issue detected at value 42\n");
        }
    }
}

int main() {
    Tree tree;
    Tree_init(&tree);
    for (int i = 0; i < 100; i++) {
        Tree_insert(&tree, i);
    }
    Linter linter;
    Linter_init(&linter, &tree);
    while (1) {
        Linter_check(&linter);
    }
    return 0;
}