#include <stdbool.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

bool check_tree(Node* node) {
    if (node == NULL) {
        return true;
    }
    if (node->value < 0) {
        return false;
    }
    return check_tree(node->left) && check_tree(node->right);
}

bool validate_syntax(Tree* tree) {
    if (tree->root == NULL) {
        return true;
    }
    return check_tree(tree->root);
}

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

int main() {
    Node* node4 = create_node(-4, NULL, NULL);
    Node* node3 = create_node(3, node4, NULL);
    Node* node2 = create_node(2, NULL, NULL);
    Node* root = create_node(1, node2, node3);

    Tree* tree = create_tree(root);
    printf("%d\n", validate_syntax(tree));

    return 0;
}