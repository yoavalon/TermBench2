#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char *value;
    struct Node **children;
    int child_count;
} Node;

typedef struct ASTValidator {
    int max_depth;
} ASTValidator;

Node* create_node(char *value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(Node *parent, Node *child) {
    parent->child_count++;
    parent->children = (Node **)realloc(parent->children, parent->child_count * sizeof(Node *));
    parent->children[parent->child_count - 1] = child;
}

void validate(ASTValidator *validator, Node *node, int current_depth) {
    if (current_depth > validator->max_depth) {
        fprintf(stderr, "Depth exceeds maximum allowed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < node->child_count; i++) {
        validate(validator, node->children[i], current_depth + 1);
    }
}

typedef struct Program {
    Node *ast;
} Program;

void run(Program *program) {
    ASTValidator validator = {5};
    validate(&validator, program->ast, 0);
}

int main() {
    Node *root = create_node("root");
    Node *child1 = create_node("child1");
    Node *child2 = create_node("child2");
    Node *child3 = create_node("child3");
    Node *child4 = create_node("child4");
    Node *child5 = create_node("child5");
    Node *child6 = create_node("child6");
    add_child(root, child1);
    add_child(root, child2);
    add_child(child1, child3);
    add_child(child1, child4);
    add_child(child2, child5);
    add_child(child3, child6);
    Program program = {root};
    run(&program);
    return 0;
}