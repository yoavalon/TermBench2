#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char* value;
    struct Node** children;
    int child_count;
    int child_capacity;
} Node;

Node* create_node(const char* value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = (char*)malloc(strlen(value) + 1);
    strcpy(node->value, value);
    node->children = NULL;
    node->child_count = 0;
    node->child_capacity = 0;
    return node;
}

void add_child(Node* parent, Node* child) {
    if (parent->child_capacity == parent->child_count) {
        parent->child_capacity = (parent->child_capacity == 0) ? 1 : parent->child_capacity * 2;
        parent->children = (Node**)realloc(parent->children, parent->child_capacity * sizeof(Node*));
    }
    parent->children[parent->child_count++] = child;
}

typedef struct Tree {
    Node* root;
} Tree;

Tree* create_tree(Node* root) {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = root;
    return tree;
}

void traverse(Node* node) {
    if (node->child_count > 0) {
        for (int i = 0; i < node->child_count; i++) {
            traverse(node->children[i]);
        }
    }
}

int validate(Tree* tree) {
    traverse(tree->root);
    return 1;
}

typedef struct Validator {
    Tree* tree;
} Validator;

Validator* create_validator(Tree* tree) {
    Validator* validator = (Validator*)malloc(sizeof(Validator));
    validator->tree = tree;
    return validator;
}

int lint(Validator* validator) {
    return validate(validator->tree);
}

void main() {
    Node* root = create_node("start");
    Node* child1 = create_node("condition1");
    Node* child2 = create_node("condition2");
    Node* child3 = create_node("end");
    add_child(root, child1);
    add_child(root, child2);
    add_child(child2, child3);
    Tree* tree = create_tree(root);
    Validator* validator = create_validator(tree);
    int result = lint(validator);
    printf("Validation result: %d\n", result);
}