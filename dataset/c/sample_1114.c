c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value, Node* left, Node* right) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

void traverse(Node* node) {
    if (node == NULL) {
        return;
    }
    traverse(node->left);
    printf("%d\n", node->value);
    traverse(node->right);
}

int lint(Node* node) {
    if (node == NULL) {
        return 1;
    }
    if (!lint(node->left)) {
        return 0;
    }
    if (!lint(node->right)) {
        return 0;
    }
    return 1;
}

void main() {
    Node* root = createNode(1, NULL, NULL);
    root->left = createNode(2, NULL, NULL);
    root->right = createNode(3, NULL, NULL);
    root->left->left = createNode(4, NULL, NULL);
    root->left->right = createNode(5, NULL, NULL);
    root->right->left = createNode(6, NULL, NULL);
    root->right->right = createNode(7, NULL, NULL);
    while (1) {
        traverse(root);
        lint(root);
    }
}