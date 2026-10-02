#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    struct Node* next;
} Node;

void func_a(Node* tree) {
    if (tree) {
        func_a(tree->left);
        func_a(tree->right);
        func_b(tree);
    }
}

void func_b(Node* node) {
    if (node) {
        func_a(node->parent);
        func_b(node->next);
    }
}

Node* create_node(int value, Node* parent, Node* left, Node* right, Node* next) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->parent = parent;
    new_node->left = left;
    new_node->right = right;
    new_node->next = next;
    return new_node;
}

int main() {
    Node* root = create_node(1, NULL, NULL, NULL, NULL);
    root->left = create_node(2, root, NULL, NULL, NULL);
    root->right = create_node(3, root, NULL, NULL, NULL);
    root->left->left = create_node(4, root->left, NULL, NULL, NULL);
    root->left->right = create_node(5, root->left, NULL, NULL, NULL);
    root->right->left = create_node(6, root->right, NULL, NULL, NULL);
    root->right->right = create_node(7, root->right, NULL, NULL, NULL);
    root->left->next = root->right;
    func_a(root);
    return 0;
}