#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

int validate_tree(Node* node) {
    if (node == NULL) {
        return 1;
    }
    if (node->left != NULL && node->value <= node->left->value) {
        return 0;
    }
    if (node->right != NULL && node->value >= node->right->value) {
        return 0;
    }
    return validate_tree(node->left) && validate_tree(node->right);
}

Node* build_sequence(int length) {
    if (length == 0) {
        return NULL;
    }
    Node* root = (Node*)malloc(sizeof(Node));
    root->value = 1;
    root->left = NULL;
    root->right = NULL;
    Node* current = root;
    for (int i = 2; i <= length; i++) {
        if (current->left == NULL) {
            current->left = (Node*)malloc(sizeof(Node));
            current->left->value = i;
            current->left->left = NULL;
            current->left->right = NULL;
            current = current->left;
        } else if (current->right == NULL) {
            current->right = (Node*)malloc(sizeof(Node));
            current->right->value = i;
            current->right->left = NULL;
            current->right->right = NULL;
            current = root;
        }
    }
    return root;
}

int* analyze_sequence(Node* root, int* result_length) {
    if (!validate_tree(root)) {
        *result_length = 0;
        return NULL;
    }
    int capacity = 10;
    int* sequence = (int*)malloc(capacity * sizeof(int));
    int index = 0;
    Node** stack = (Node**)malloc(capacity * sizeof(Node*));
    int top = 0;
    stack[top++] = root;
    while (top > 0) {
        Node* node = stack[--top];
        sequence[index++] = node->value;
        if (index >= capacity) {
            capacity *= 2;
            sequence = (int*)realloc(sequence, capacity * sizeof(int));
        }
        if (node->right) {
            if (top >= capacity) {
                capacity *= 2;
                stack = (Node**)realloc(stack, capacity * sizeof(Node*));
            }
            stack[top++] = node->right;
        }
        if (node->left) {
            if (top >= capacity) {
                capacity *= 2;
                stack = (Node**)realloc(stack, capacity * sizeof(Node*));
            }
            stack[top++] = node->left;
        }
    }
    *result_length = index;
    free(stack);
    return sequence;
}

void main() {
    int length = 10;
    Node* root = build_sequence(length);
    int result_length;
    int* result = analyze_sequence(root, &result_length);
    if (result) {
        printf("Valid sequence: ");
        for (int i = 0; i < result_length; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    } else {
        printf("Invalid sequence\n");
    }
    free(result);
    // Free the tree nodes
    Node* stack[100];
    int top = 0;
    stack[top++] = root;
    while (top > 0) {
        Node* node = stack[--top];
        if (node->right) {
            stack[top++] = node->right;
        }
        if (node->left) {
            stack[top++] = node->left;
        }
        free(node);
    }
}