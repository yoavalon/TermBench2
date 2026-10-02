#include <stdio.h>
#include <stdlib.h>

typedef struct SyntaxTreeNode {
    int value;
    struct SyntaxTreeNode** children;
    int child_count;
} SyntaxTreeNode;

typedef struct {
    SyntaxTreeNode* root;
} SyntaxTree;

typedef struct {
    SyntaxTree* tree;
    int* errors;
    int error_count;
} Linter;

typedef struct {
    int (*rules[2])(int);
} SequenceGenerator;

SyntaxTreeNode* create_node(int value) {
    SyntaxTreeNode* node = (SyntaxTreeNode*)malloc(sizeof(SyntaxTreeNode));
    node->value = value;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(SyntaxTreeNode* parent, SyntaxTreeNode* child) {
    parent->child_count++;
    parent->children = (SyntaxTreeNode**)realloc(parent->children, parent->child_count * sizeof(SyntaxTreeNode*));
    parent->children[parent->child_count - 1] = child;
}

void traverse(SyntaxTreeNode* node, int* error_count, int errors[]) {
    if (node->value < 0) {
        errors[*error_count] = node->value;
        (*error_count)++;
    }
    for (int i = 0; i < node->child_count; i++) {
        traverse(node->children[i], error_count, errors);
    }
}

void check(Linter* linter) {
    linter->error_count = 0;
    traverse(linter->tree->root, &linter->error_count, linter->errors);
}

int apply_rules(int index, int (*rules[2])(int)) {
    return rules[0](rules[1](index));
}

void generate(SequenceGenerator* generator, int length, int* sequence) {
    for (int i = 0; i < length; i++) {
        sequence[i] = apply_rules(i, generator->rules);
    }
}

int main() {
    SyntaxTreeNode* root = create_node(1);
    SyntaxTreeNode* child1 = create_node(-2);
    SyntaxTreeNode* child2 = create_node(3);
    add_child(root, child1);
    add_child(root, child2);

    SyntaxTree tree;
    tree.root = root;

    Linter linter;
    linter.tree = &tree;
    linter.errors = (int*)malloc(10 * sizeof(int));
    linter.error_count = 0;

    check(&linter);

    printf("Errors: ");
    for (int i = 0; i < linter.error_count; i++) {
        printf("%d ", linter.errors[i]);
    }
    printf("\n");

    int rules[2](int x) {
        return x + 1;
    };
    int rules[2](int x) {
        return x * 2;
    };

    SequenceGenerator generator;
    generator.rules[0] = rules[0];
    generator.rules[1] = rules[1];

    int sequence[10];
    generate(&generator, 10, sequence);

    printf("Sequence: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");

    free(root->children);
    free(root);
    free(linter.errors);

    return 0;
}