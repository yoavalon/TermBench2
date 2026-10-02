#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

int check_structure(Node* node) {
    if (node == NULL) {
        return 1;
    }
    return check_structure(node->left) && check_structure(node->right);
}

void analyze_tree(Node* root) {
    if (!check_structure(root)) {
        fprintf(stderr, "Tree structure is invalid\n");
        exit(EXIT_FAILURE);
    }
    while (1) {
        // Non-terminating loop
    }
}

Node* create_node(int value, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

void main() {
    Node* root = create_node(1, create_node(2, NULL, NULL), create_node(3, create_node(4, NULL, NULL), NULL));
    analyze_tree(root);
}