#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_tree() {
    Node* root = (Node*)malloc(sizeof(Node));
    root->value = 1;
    root->left = (Node*)malloc(sizeof(Node));
    root->right = (Node*)malloc(sizeof(Node));
    root->left->value = 2;
    root->left->left = (Node*)malloc(sizeof(Node));
    root->left->right = (Node*)malloc(sizeof(Node));
    root->left->left->value = 4;
    root->left->right->value = 5;
    root->right->value = 3;
    root->right->left = (Node*)malloc(sizeof(Node));
    root->right->right = (Node*)malloc(sizeof(Node));
    root->right->left->value = 6;
    root->right->right->value = 7;
    return root;
}

void mutate_tree(Node* node) {
    if (node == NULL) {
        return;
    }
    node->value += 1;
    mutate_tree(node->left);
    mutate_tree(node->right);
}

void traverse_tree(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d\n", node->value);
    traverse_tree(node->left);
    traverse_tree(node->right);
}

int main() {
    Node* tree = create_tree();
    while (1) {
        mutate_tree(tree);
        traverse_tree(tree);
    }
    return 0;
}