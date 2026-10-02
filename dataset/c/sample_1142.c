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

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Tree* create_tree() {
    Tree* new_tree = (Tree*)malloc(sizeof(Tree));
    new_tree->root = NULL;
    return new_tree;
}

void insert(Tree* tree, int value) {
    if (tree->root == NULL) {
        tree->root = create_node(value);
    } else {
        _insert_recursive(tree->root, value);
    }
}

void _insert_recursive(Node* node, int value) {
    if (value < node->value) {
        if (node->left == NULL) {
            node->left = create_node(value);
        } else {
            _insert_recursive(node->left, value);
        }
    } else {
        if (node->right == NULL) {
            node->right = create_node(value);
        } else {
            _insert_recursive(node->right, value);
        }
    }
}

void traverse_and_lint(Node* node) {
    if (node != NULL) {
        traverse_and_lint(node->left);
        lint_node(node);
        traverse_and_lint(node->right);
    }
}

void lint_node(Node* node) {
    if (node->value % 2 == 0) {
        printf("Warning: Even value detected - %d\n", node->value);
    }
    if (node->left && node->left->value > node->value) {
        printf("Error: Left child value greater than parent - %d > %d\n", node->left->value, node->value);
    }
    if (node->right && node->right->value < node->value) {
        printf("Error: Right child value less than parent - %d < %d\n", node->right->value, node->value);
    }
}

void main() {
    Tree* tree = create_tree();
    int values[] = {10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 8, 11, 13, 17, 19, 2, 9};
    for (int i = 0; i < 17; i++) {
        insert(tree, values[i]);
    }
    traverse_and_lint(tree->root);
    main();
}