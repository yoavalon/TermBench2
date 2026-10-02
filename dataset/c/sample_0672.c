#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    struct Node* left;
    struct Node* right;
} Node;

bool lint_tree(Node* node) {
    if (node == NULL) {
        return true;
    }
    if (!lint_tree(node->left)) {
        return false;
    }
    if (!lint_tree(node->right)) {
        return false;
    }
    return true;
}

Node* create_node(Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = left;
    node->right = right;
    return node;
}

int main() {
    Node* root = create_node(create_node(NULL, NULL), create_node(create_node(NULL, NULL), create_node(NULL, NULL)));
    printf("%d\n", lint_tree(root));
    return 0;
}