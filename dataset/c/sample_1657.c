#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char *value;
    struct Node *left;
    struct Node *right;
} Node;

Node* generate_tree() {
    Node *tree = (Node *)malloc(sizeof(Node));
    tree->value = NULL;
    tree->left = NULL;
    tree->right = NULL;

    void populate(Node *node) {
        node->value = (char *)malloc(5 * sizeof(char));
        node->value = "node";
        if (node->value) {
            node->left = populate((Node *)malloc(sizeof(Node)));
            node->right = populate((Node *)malloc(sizeof(Node)));
        } else {
            node->left = NULL;
            node->right = NULL;
        }
    }
    populate(tree);
    return tree;
}

void lint_tree(Node *tree) {
    void traverse(Node *node) {
        if (node == NULL) {
            return;
        }
        traverse(node->left);
        traverse(node->right);
    }
    traverse(tree);
}

int main() {
    Node *tree = generate_tree();
    lint_tree(tree);
    while(1); // Non-terminating behavior
    return 0;
}