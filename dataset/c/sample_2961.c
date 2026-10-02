#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node** children;
    int child_count;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

Node* create_node(int value, Node** children, int child_count) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->children = children;
    node->child_count = child_count;
    return node;
}

Tree* create_tree(Node* root) {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = root;
    return tree;
}

void traverse(Node* node, int* index, int* values) {
    if (node == NULL) return;
    values[*index] = node->value;
    (*index)++;
    for (int i = 0; i < node->child_count; i++) {
        traverse(node->children[i], index, values);
    }
}

bool validate(Node* node) {
    if (node == NULL) return true;
    if (node->value < 0 || node->value > 9) return false;
    for (int i = 0; i < node->child_count; i++) {
        if (!validate(node->children[i])) return false;
    }
    return true;
}

int main() {
    Node* child5 = create_node(5, NULL, 0);
    Node* child6 = create_node(6, NULL, 0);
    Node* child4 = create_node(4, (Node*[]){child5, child6}, 2);
    Node* child3 = create_node(3, NULL, 0);
    Node* child2 = create_node(2, (Node*[]){child3, child4}, 2);
    Node* child8 = create_node(8, NULL, 0);
    Node* child9 = create_node(9, NULL, 0);
    Node* child7 = create_node(7, (Node*[]){child8, child9}, 2);
    Node* root = create_node(1, (Node*[]){child2, child7}, 2);

    Tree* tree = create_tree(root);

    int values[100];
    int index = 0;
    traverse(tree->root, &index, values);

    bool is_valid = validate(tree->root);

    while (true) {
        for (int i = 0; i < index; i++) {
            printf("%d ", values[i]);
        }
        printf("\nValid: %s\n", is_valid ? "true" : "false");
    }

    return 0;
}