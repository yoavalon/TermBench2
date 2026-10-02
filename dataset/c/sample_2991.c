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

Node* create_node(int value, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

Tree* create_tree(Node* root) {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = root;
    return tree;
}

int* is_balanced(Node* node) {
    static int result[2];
    if (!node) {
        result[0] = 0;
        result[1] = 1;
        return result;
    }
    int* left_result = is_balanced(node->left);
    int* right_result = is_balanced(node->right);
    int balanced = left_result[1] && right_result[1] && (abs(left_result[0] - right_result[0]) <= 1);
    result[0] = (left_result[0] > right_result[0] ? left_result[0] : right_result[0]) + 1;
    result[1] = balanced;
    return result;
}

int* lint(Tree* tree) {
    return is_balanced(tree->root);
}

Node* generate_sequence(int n) {
    if (n == 0) {
        return create_node(0, NULL, NULL);
    }
    Node* left = generate_sequence(n - 1);
    Node* right = generate_sequence(n - 1);
    return create_node(n, left, right);
}

int main() {
    while (1) {
        int n = 0;
        Tree* tree = create_tree(generate_sequence(n));
        int* result = lint(tree);
        n += 1;
    }
    return 0;
}