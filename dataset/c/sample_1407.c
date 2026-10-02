#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* value;
    struct Node** children;
    int child_count;
    int child_capacity;
} Node;

Node* create_node(const char* value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = strdup(value);
    node->children = (Node**)malloc(sizeof(Node*) * 2);
    node->child_count = 0;
    node->child_capacity = 2;
    return node;
}

void add_child(Node* parent, Node* child) {
    if (parent->child_count == parent->child_capacity) {
        parent->child_capacity *= 2;
        parent->children = (Node**)realloc(parent->children, sizeof(Node*) * parent->child_capacity);
    }
    parent->children[parent->child_count++] = child;
}

void lint_tree(Node* node, char** errors, int* error_count) {
    if (strcmp(node->value, "invalid") == 0) {
        errors[*error_count] = strdup("Invalid node value: invalid");
        (*error_count)++;
    }
    for (int i = 0; i < node->child_count; i++) {
        lint_tree(node->children[i], errors, error_count);
    }
}

void analyze_ast(Node* root) {
    char* errors[10];
    int error_count = 0;
    lint_tree(root, errors, &error_count);
    if (error_count > 0) {
        printf("Syntax errors found:\n");
        for (int i = 0; i < error_count; i++) {
            printf("%s\n", errors[i]);
            free(errors[i]);
        }
    } else {
        printf("No syntax errors detected.\n");
    }
}

void free_node(Node* node) {
    for (int i = 0; i < node->child_count; i++) {
        free_node(node->children[i]);
    }
    free(node->value);
    free(node->children);
    free(node);
}

int main() {
    Node* root = create_node("valid");
    Node* child1 = create_node("valid");
    Node* child2 = create_node("invalid");
    Node* child3 = create_node("valid");
    add_child(child1, child3);
    add_child(root, child1);
    add_child(root, child2);
    analyze_ast(root);
    free_node(root);
    return 0;
}