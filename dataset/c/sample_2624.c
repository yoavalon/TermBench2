#include <stdio.h>
#include <stdlib.h>

typedef struct AbstractSyntaxTree {
    int value;
    struct AbstractSyntaxTree** children;
    int child_count;
    int child_capacity;
} AbstractSyntaxTree;

AbstractSyntaxTree* create_ast(int value) {
    AbstractSyntaxTree* ast = (AbstractSyntaxTree*)malloc(sizeof(AbstractSyntaxTree));
    ast->value = value;
    ast->children = (AbstractSyntaxTree**)malloc(sizeof(AbstractSyntaxTree*) * 10);
    ast->child_count = 0;
    ast->child_capacity = 10;
    return ast;
}

void add_child(AbstractSyntaxTree* parent, AbstractSyntaxTree* child) {
    if (parent->child_count == parent->child_capacity) {
        parent->child_capacity *= 2;
        parent->children = (AbstractSyntaxTree**)realloc(parent->children, sizeof(AbstractSyntaxTree*) * parent->child_capacity);
    }
    parent->children[parent->child_count++] = child;
}

void traverse(AbstractSyntaxTree* ast, int* results, int* index) {
    results[(*index)++] = ast->value;
    for (int i = 0; i < ast->child_count; i++) {
        traverse(ast->children[i], results, index);
    }
}

typedef struct SequenceChecker {
    int* sequence;
    int length;
} SequenceChecker;

SequenceChecker* create_sequence_checker(int* sequence, int length) {
    SequenceChecker* checker = (SequenceChecker*)malloc(sizeof(SequenceChecker));
    checker->sequence = sequence;
    checker->length = length;
    return checker;
}

int is_valid(SequenceChecker* checker) {
    for (int i = 0; i < checker->length - 1; i++) {
        if (checker->sequence[i] > checker->sequence[i + 1]) {
            return 0;
        }
    }
    return 1;
}

typedef struct Linter {
    AbstractSyntaxTree* ast;
} Linter;

Linter* create_linter(AbstractSyntaxTree* ast) {
    Linter* linter = (Linter*)malloc(sizeof(Linter));
    linter->ast = ast;
    return linter;
}

int lint(Linter* linter) {
    int* results = (int*)malloc(sizeof(int) * 100);
    int index = 0;
    traverse(linter->ast, results, &index);
    SequenceChecker* checker = create_sequence_checker(results, index);
    int valid = is_valid(checker);
    free(results);
    free(checker);
    return valid;
}

void main() {
    AbstractSyntaxTree* root = create_ast(1);
    AbstractSyntaxTree* node1 = create_ast(2);
    AbstractSyntaxTree* node2 = create_ast(3);
    AbstractSyntaxTree* node3 = create_ast(4);
    AbstractSyntaxTree* node4 = create_ast(5);
    add_child(root, node1);
    add_child(root, node2);
    add_child(node1, node3);
    add_child(node1, node4);
    Linter* linter = create_linter(root);
    printf("%d\n", lint(linter));
    free(root);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(linter);
}