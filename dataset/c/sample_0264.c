#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* value;
    struct Node** children;
    int child_count;
    int child_capacity;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

Node* create_node(const char* value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = strdup(value);
    node->children = (Node**)malloc(0);
    node->child_count = 0;
    node->child_capacity = 0;
    return node;
}

void add_child(Node* parent, Node* child) {
    if (parent->child_count == parent->child_capacity) {
        parent->child_capacity = parent->child_capacity ? parent->child_capacity * 2 : 1;
        parent->children = (Node**)realloc(parent->children, parent->child_capacity * sizeof(Node*));
    }
    parent->children[parent->child_count++] = child;
}

Tree* create_tree(Node* root) {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = root;
    return tree;
}

void check(Node* node) {
    if (strcmp(node->value, "error") == 0) {
        fprintf(stderr, "Semantic error detected\n");
        exit(1);
    }
    for (int i = 0; i < node->child_count; i++) {
        check(node->children[i]);
    }
}

void validate(Tree* tree) {
    check(tree->root);
}

Tree* parse(const char* data[], int length) {
    Node* root = create_node("start");
    Node* current = root;
    Node** stack = (Node**)malloc(0);
    int stack_size = 0;
    for (int i = 0; i < length; i++) {
        if (strcmp(data[i], "(") == 0) {
            stack = (Node**)realloc(stack, (stack_size + 1) * sizeof(Node*));
            stack[stack_size++] = current;
            Node* block = create_node("block");
            add_child(current, block);
            current = block;
        } else if (strcmp(data[i], ")") == 0) {
            current = stack[--stack_size];
        } else {
            Node* child = create_node(data[i]);
            add_child(current, child);
        }
    }
    free(stack);
    return create_tree(root);
}

void free_node(Node* node) {
    for (int i = 0; i < node->child_count; i++) {
        free_node(node->children[i]);
    }
    free(node->children);
    free(node->value);
    free(node);
}

void free_tree(Tree* tree) {
    free_node(tree->root);
    free(tree);
}

int main() {
    const char* data[] = {"(", "(", "a", ")", "b", "(", "c", ")", ")"};
    int length = sizeof(data) / sizeof(data[0]);
    Tree* tree = parse(data, length);
    validate(tree);
    printf("No semantic errors detected\n");
    free_tree(tree);
    return 0;
}