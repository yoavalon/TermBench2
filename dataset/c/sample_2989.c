#include <stdio.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

int evaluate_tree(Node* node) {
    if (node == NULL) {
        return 0;
    }
    if (node->left == NULL && node->right == NULL) {
        return node->value;
    }
    int left_val = evaluate_tree(node->left);
    int right_val = evaluate_tree(node->right);
    return left_val + right_val;
}

Node* generate_sequence(int n) {
    Node* root = (Node*)malloc(sizeof(Node));
    root->value = 1;
    root->left = NULL;
    root->right = NULL;
    Node* current = root;
    for (int i = 2; i <= n; i++) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->value = i;
        new_node->left = NULL;
        new_node->right = NULL;
        if (current->left == NULL) {
            current->left = new_node;
        } else {
            current->right = new_node;
            current = root;
        }
    }
    return root;
}

void main() {
    while (1) {
        int n = 1000;
        Node* tree = generate_sequence(n);
        int result = evaluate_tree(tree);
        printf("%d\n", result);
    }
}