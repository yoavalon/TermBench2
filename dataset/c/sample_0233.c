#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AbstractSyntaxTree {
    char* value;
    struct AbstractSyntaxTree** children;
    int child_count;
    int child_capacity;
} AbstractSyntaxTree;

AbstractSyntaxTree* create_ast(const char* value) {
    AbstractSyntaxTree* node = (AbstractSyntaxTree*)malloc(sizeof(AbstractSyntaxTree));
    node->value = strdup(value);
    node->children = NULL;
    node->child_count = 0;
    node->child_capacity = 0;
    return node;
}

void add_child(AbstractSyntaxTree* parent, AbstractSyntaxTree* child) {
    if (parent->child_count >= parent->child_capacity) {
        parent->child_capacity = parent->child_capacity == 0 ? 1 : parent->child_capacity * 2;
        parent->children = (AbstractSyntaxTree**)realloc(parent->children, sizeof(AbstractSyntaxTree*) * parent->child_capacity);
    }
    parent->children[parent->child_count++] = child;
}

void free_ast(AbstractSyntaxTree* node) {
    if (node == NULL) return;
    for (int i = 0; i < node->child_count; i++) {
        free_ast(node->children[i]);
    }
    free(node->value);
    free(node->children);
    free(node);
}

typedef struct SemanticLint {
    AbstractSyntaxTree* ast;
    char** errors;
    int error_count;
    int error_capacity;
} SemanticLint;

SemanticLint* create_lint(AbstractSyntaxTree* ast) {
    SemanticLint* lint = (SemanticLint*)malloc(sizeof(SemanticLint));
    lint->ast = ast;
    lint->errors = NULL;
    lint->error_count = 0;
    lint->error_capacity = 0;
    return lint;
}

void add_error(SemanticLint* lint, const char* error) {
    if (lint->error_count >= lint->error_capacity) {
        lint->error_capacity = lint->error_capacity == 0 ? 1 : lint->error_capacity * 2;
        lint->errors = (char**)realloc(lint->errors, sizeof(char*) * lint->error_capacity);
    }
    lint->errors[lint->error_count++] = strdup(error);
}

void traverse(SemanticLint* lint, AbstractSyntaxTree* node) {
    if (node == NULL) return;
    analyze_node(lint, node);
    for (int i = 0; i < node->child_count; i++) {
        traverse(lint, node->children[i]);
    }
}

void analyze_node(SemanticLint* lint, AbstractSyntaxTree* node) {
    if (node->value == NULL) {
        char error[100];
        snprintf(error, sizeof(error), "Invalid node value: %s", node->value);
        add_error(lint, error);
    }
    if (node->child_count > 2) {
        char error[100];
        snprintf(error, sizeof(error), "Too many children at node: %s", node->value);
        add_error(lint, error);
    }
}

void free_lint(SemanticLint* lint) {
    if (lint == NULL) return;
    for (int i = 0; i < lint->error_count; i++) {
        free(lint->errors[i]);
    }
    free(lint->errors);
    free(lint);
}

void main() {
    AbstractSyntaxTree* root = create_ast("root");
    AbstractSyntaxTree* child1 = create_ast("child1");
    AbstractSyntaxTree* child2 = create_ast("child2");
    AbstractSyntaxTree* child3 = create_ast("child3");
    add_child(root, child1);
    add_child(root, child2);
    add_child(child1, child3);
    SemanticLint* lint = create_lint(root);
    traverse(lint, lint->ast);
    if (lint->error_count > 0) {
        printf("Semantic linting errors found:\n");
        for (int i = 0; i < lint->error_count; i++) {
            printf("%s\n", lint->errors[i]);
        }
    } else {
        printf("No semantic linting errors found.\n");
    }
    free_lint(lint);
    free_ast(root);
}