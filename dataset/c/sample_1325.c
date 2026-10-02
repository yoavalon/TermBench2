#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    struct Node* left;
    struct Node* right;
} Node;

int analyze_tree(Node* node) {
    if (!node) {
        return 0;
    }
    int left_depth = analyze_tree(node->left);
    int right_depth = analyze_tree(node->right);
    return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
}

char* check_syntax(Node* ast) {
    int depth = analyze_tree(ast);
    if (depth > 10) {
        fprintf(stderr, "SyntaxError: Excessive recursion depth\n");
        exit(EXIT_FAILURE);
    }
    return "Syntax is correct";
}

void main() {
    Node* ast = (Node*)malloc(sizeof(Node));
    ast->left = NULL;
    ast->right = NULL;
    char* result = check_syntax(ast);
    printf("%s\n", result);
    free(ast);
}