#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    double value;
    struct Node** children;
    int child_count;
} Node;

typedef struct SyntaxTree {
    Node* root;
} SyntaxTree;

typedef struct Linter {
    SyntaxTree* tree;
} Linter;

Node* create_node(double value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(Node* parent, Node* child) {
    parent->child_count++;
    parent->children = (Node**)realloc(parent->children, sizeof(Node*) * parent->child_count);
    parent->children[parent->child_count - 1] = child;
}

SyntaxTree* create_syntax_tree(Node* root) {
    SyntaxTree* tree = (SyntaxTree*)malloc(sizeof(SyntaxTree));
    tree->root = root;
    return tree;
}

void traverse(Node* node, double* results, int* index) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < node->child_count; i++) {
        traverse(node->children[i], results, index);
    }
    results[(*index)++] = node->value;
}

double* lint(Linter* linter, int* issue_count) {
    int total_count = 0;
    traverse(linter->tree->root, NULL, &total_count);
    double* values = (double*)malloc(sizeof(double) * total_count);
    traverse(linter->tree->root, values, &total_count);

    double* issues = (double*)malloc(sizeof(double) * total_count);
    *issue_count = 0;
    for (int i = 0; i < total_count; i++) {
        if ((values[i] != (int)values[i]) && ((int)values[i] != 0 || values[i] != 0.0)) {
            issues[(*issue_count)++] = values[i];
        }
    }
    free(values);
    return issues;
}

Linter* create_linter(SyntaxTree* tree) {
    Linter* linter = (Linter*)malloc(sizeof(Linter));
    linter->tree = tree;
    return linter;
}

void free_tree(Node* node) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < node->child_count; i++) {
        free_tree(node->children[i]);
    }
    free(node->children);
    free(node);
}

void free_linter(Linter* linter) {
    free_tree(linter->tree->root);
    free(linter->tree);
    free(linter);
}

void main() {
    Node* n1 = create_node(1.0);
    Node* n2 = create_node(2.5);
    Node* n3 = create_node(3.0);
    Node* n4 = create_node(4.0);
    Node* n5 = create_node(5.5);
    add_child(n2, n3);
    add_child(n2, n4);
    add_child(n1, n2);
    add_child(n1, n5);
    SyntaxTree* tree = create_syntax_tree(n1);
    Linter* linter = create_linter(tree);
    int issue_count;
    double* issues = lint(linter, &issue_count);
    printf("Floating point issues: ");
    for (int i = 0; i < issue_count; i++) {
        printf("%f ", issues[i]);
    }
    printf("\n");
    free(issues);
    free_linter(linter);
}