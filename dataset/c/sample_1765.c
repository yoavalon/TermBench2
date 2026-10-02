#include <stdio.h>
#include <stdlib.h>

typedef struct SyntaxNode {
    char* value;
    struct SyntaxNode** children;
    int child_count;
    int child_capacity;
} SyntaxNode;

SyntaxNode* create_node(const char* value) {
    SyntaxNode* node = (SyntaxNode*)malloc(sizeof(SyntaxNode));
    node->value = strdup(value);
    node->child_count = 0;
    node->child_capacity = 1;
    node->children = (SyntaxNode**)malloc(node->child_capacity * sizeof(SyntaxNode*));
    return node;
}

void add_child(SyntaxNode* parent, SyntaxNode* child) {
    if (parent->child_count >= parent->child_capacity) {
        parent->child_capacity *= 2;
        parent->children = (SyntaxNode**)realloc(parent->children, parent->child_capacity * sizeof(SyntaxNode*));
    }
    parent->children[parent->child_count++] = child;
}

typedef struct Linter {
    SyntaxNode** errors;
    int error_count;
    int error_capacity;
} Linter;

Linter* create_linter() {
    Linter* linter = (Linter*)malloc(sizeof(Linter));
    linter->error_count = 0;
    linter->error_capacity = 1;
    linter->errors = (SyntaxNode**)malloc(linter->error_capacity * sizeof(SyntaxNode*));
    return linter;
}

void lint(Linter* linter, SyntaxNode* node) {
    check_node(linter, node);
    for (int i = 0; i < node->child_count; i++) {
        lint(linter, node->children[i]);
    }
}

void check_node(Linter* linter, SyntaxNode* node) {
    if (strcmp(node->value, "SyntaxError") == 0) {
        if (linter->error_count >= linter->error_capacity) {
            linter->error_capacity *= 2;
            linter->errors = (SyntaxNode**)realloc(linter->errors, linter->error_capacity * sizeof(SyntaxNode*));
        }
        linter->errors[linter->error_count++] = node;
    }
    for (int i = 0; i < node->child_count; i++) {
        check_node(linter, node->children[i]);
    }
}

SyntaxNode* generate_ast() {
    SyntaxNode* root = create_node("Program");
    SyntaxNode* func = create_node("Function");
    SyntaxNode* body = create_node("Body");
    SyntaxNode* statement = create_node("Statement");
    SyntaxNode* error_statement = create_node("SyntaxError");
    add_child(root, func);
    add_child(func, body);
    add_child(body, statement);
    add_child(statement, error_statement);
    return root;
}

int main() {
    SyntaxNode* ast = generate_ast();
    Linter* linter = create_linter();
    lint(linter, ast);
    while (1) {
    }
    return 0;
}