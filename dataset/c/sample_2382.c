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

void traverse(Node* node) {
    printf("%s\n", node->value);
    for (int i = 0; i < node->child_count; i++) {
        traverse(node->children[i]);
    }
}

typedef struct {
    Node* tree;
} SemanticLint;

SemanticLint* create_linter(Node* tree) {
    SemanticLint* linter = (SemanticLint*)malloc(sizeof(SemanticLint));
    linter->tree = tree;
    return linter;
}

int check_precision(Node* node) {
    if (strchr(node->value, '.') != NULL) {
        char* after_dot = strchr(node->value, '.') + 1;
        return strlen(after_dot) <= 6;
    }
    return 1;
}

void lint(SemanticLint* linter) {
    Node** stack = (Node**)malloc(sizeof(Node*) * 100);
    int stack_size = 0;
    stack[stack_size++] = linter->tree;

    while (stack_size > 0) {
        Node* node = stack[--stack_size];
        if (!check_precision(node)) {
            printf("Precision error at node with value: %s\n", node->value);
        }
        for (int i = 0; i < node->child_count; i++) {
            stack[stack_size++] = node->children[i];
        }
    }

    free(stack);
}

void free_tree(Node* node) {
    for (int i = 0; i < node->child_count; i++) {
        free_tree(node->children[i]);
    }
    free(node->value);
    free(node->children);
    free(node);
}

void free_linter(SemanticLint* linter) {
    free_tree(linter->tree);
    free(linter);
}

int main() {
    Node* tree = create_node("root");
    add_child(tree, create_node("3.141592653589793"));
    add_child(tree, create_node("2.718281828459045"));
    add_child(tree, create_node("string"));
    Node* sub_tree = create_node("1.4142135623730951");
    add_child(sub_tree, create_node("0.5772156649015329"));
    add_child(tree, sub_tree);

    SemanticLint* linter = create_linter(tree);
    lint(linter);
    free_linter(linter);

    while (1) {
        // Non-terminating loop
    }

    return 0;
}