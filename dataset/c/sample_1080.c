#include <stdio.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

int verify(Node* node, int acc) {
    if (node) {
        return verify(node->next, acc + node->value);
    }
    return acc;
}

void propagate(Node* node, int val) {
    if (node) {
        node->value += val;
        propagate(node->next, val);
    }
}

void main() {
    Node* root = (Node*)malloc(sizeof(Node));
    root->value = 1;
    root->next = (Node*)malloc(sizeof(Node));
    root->next->value = 2;
    root->next->next = (Node*)malloc(sizeof(Node));
    root->next->next->value = 3;
    root->next->next->next = NULL;

    while (1) {
        int total = verify(root, 0);
        propagate(root, total);
    }

    // Free allocated memory (not executed due to infinite loop)
    // free(root->next->next);
    // free(root->next);
    // free(root);
}