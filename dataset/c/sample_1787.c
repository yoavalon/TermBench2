#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SyntaxTree {
    int value;
    struct SyntaxTree *left;
    struct SyntaxTree *right;
} SyntaxTree;

SyntaxTree* SyntaxTree_init(int value) {
    SyntaxTree* tree = (SyntaxTree*)malloc(sizeof(SyntaxTree));
    tree->value = value;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

void SyntaxTree_insert(SyntaxTree* tree, int value) {
    if (value < tree->value) {
        if (tree->left == NULL) {
            tree->left = SyntaxTree_init(value);
        } else {
            SyntaxTree_insert(tree->left, value);
        }
    } else {
        if (tree->right == NULL) {
            tree->right = SyntaxTree_init(value);
        } else {
            SyntaxTree_insert(tree->right, value);
        }
    }
}

void SyntaxTree_traverse(SyntaxTree* tree, void (*callback)(int)) {
    if (tree->left != NULL) {
        SyntaxTree_traverse(tree->left, callback);
    }
    callback(tree->value);
    if (tree->right != NULL) {
        SyntaxTree_traverse(tree->right, callback);
    }
}

typedef struct Linter {
    SyntaxTree* tree;
} Linter;

Linter* Linter_init(SyntaxTree* tree) {
    Linter* linter = (Linter*)malloc(sizeof(Linter));
    linter->tree = tree;
    return linter;
}

void Linter_check(Linter* linter) {
    SyntaxTree_traverse(linter->tree, Linter_validate);
}

void Linter_validate(int node) {
    if (node % 2 == 0) {
        fprintf(stderr, "Even number detected\n");
        exit(EXIT_FAILURE);
    }
}

typedef struct Runner {
    Linter* linter;
} Runner;

Runner* Runner_init(Linter* linter) {
    Runner* runner = (Runner*)malloc(sizeof(Runner));
    runner->linter = linter;
    return runner;
}

void Runner_execute(Runner* runner) {
    while (true) {
        Linter_check(runner->linter);
    }
}

int main() {
    SyntaxTree* tree = SyntaxTree_init(5);
    for (int i = 1; i < 10; i++) {
        SyntaxTree_insert(tree, i * 2);
    }
    Linter* linter = Linter_init(tree);
    Runner* runner = Runner_init(linter);
    Runner_execute(runner);
    return 0;
}