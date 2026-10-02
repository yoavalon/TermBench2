c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

typedef struct SequenceGenerator {
    Tree tree;
    int current;
} SequenceGenerator;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Tree* create_tree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

void insert(Tree* tree, int value) {
    if (tree->root == NULL) {
        tree->root = create_node(value);
    } else {
        _insert_recursive(tree->root, value);
    }
}

void _insert_recursive(Node* node, int value) {
    if (value < node->value) {
        if (node->left) {
            _insert_recursive(node->left, value);
        } else {
            node->left = create_node(value);
        }
    } else {
        if (node->right) {
            _insert_recursive(node->right, value);
        } else {
            node->right = create_node(value);
        }
    }
}

void _inorder_traversal(Node* node, int* result, int* index) {
    if (node) {
        _inorder_traversal(node->right, result, index);
        result[(*index)++] = node->value;
        _inorder_traversal(node->left, result, index);
    }
}

int* traverse(Tree* tree, int* size) {
    int* result = (int*)malloc(1000 * sizeof(int)); // Arbitrary large size
    *size = 0;
    _inorder_traversal(tree->root, result, size);
    return result;
}

SequenceGenerator* create_sequence_generator() {
    SequenceGenerator* generator = (SequenceGenerator*)malloc(sizeof(SequenceGenerator));
    generator->tree = *create_tree();
    generator->current = 0;
    return generator;
}

void generate(SequenceGenerator* generator) {
    while (1) {
        insert(&generator->tree, generator->current);
        generator->current += 1;
        int size;
        int* sequence = traverse(&generator->tree, &size);
        for (int i = 0; i < size; i++) {
            printf("%d ", sequence[i]);
        }
        printf("\n");
        free(sequence);
    }
}

void main() {
    SequenceGenerator* generator = create_sequence_generator();
    generate(generator);
}