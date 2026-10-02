#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char* value;
    struct Node** children;
    int child_count;
} Node;

typedef struct AbstractSyntaxTree {
    Node* root;
} AbstractSyntaxTree;

typedef struct SemanticLint {
    AbstractSyntaxTree* ast;
} SemanticLint;

Node* create_node(char* value, Node** children, int child_count) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->children = children;
    node->child_count = child_count;
    return node;
}

AbstractSyntaxTree* create_abstract_syntax_tree(Node* root) {
    AbstractSyntaxTree* ast = (AbstractSyntaxTree*)malloc(sizeof(AbstractSyntaxTree));
    ast->root = root;
    return ast;
}

SemanticLint* create_semantic_lint(AbstractSyntaxTree* ast) {
    SemanticLint* linter = (SemanticLint*)malloc(sizeof(SemanticLint));
    linter->ast = ast;
    return linter;
}

void _traverse(Node* node, char*** result, int* result_size) {
    if (node) {
        *result = realloc(*result, (*result_size + 1) * sizeof(char*));
        (*result)[*result_size] = node->value;
        (*result_size)++;
        for (int i = 0; i < node->child_count; i++) {
            _traverse(node->children[i], result, result_size);
        }
    }
}

char** traverse(AbstractSyntaxTree* ast, int* result_size) {
    char** result = NULL;
    *result_size = 0;
    _traverse(ast->root, &result, result_size);
    return result;
}

int _has_issue(Node* node) {
    return node->value && strcmp(node->value, "invalid") == 0;
}

char** analyze(SemanticLint* linter, int* issue_size) {
    char** issues = NULL;
    *issue_size = 0;
    int result_size = 0;
    char** result = traverse(linter->ast, &result_size);
    for (int i = 0; i < result_size; i++) {
        if (_has_issue(create_node(result[i], NULL, 0))) {
            issues = realloc(issues, (*issue_size + 1) * sizeof(char*));
            issues[*issue_size] = result[i];
            (*issue_size)++;
        }
    }
    free(result);
    return issues;
}

void main() {
    Node* child21 = create_node("valid", NULL, 0);
    Node* child22 = create_node("invalid", NULL, 0);
    Node* child2 = create_node("invalid", (Node*[]){child21, child22}, 2);
    Node* root = create_node("root", (Node*[]){create_node("valid", NULL, 0), child2}, 2);
    AbstractSyntaxTree* ast = create_abstract_syntax_tree(root);
    SemanticLint* linter = create_semantic_lint(ast);
    int issue_size = 0;
    char** issues = analyze(linter, &issue_size);
    printf("Issues found: ");
    for (int i = 0; i < issue_size; i++) {
        printf("%s ", issues[i]);
    }
    printf("\n");
    free(issues);
    free(linter);
    free(ast);
    free(root);
    free(child2);
    free(child21);
    free(child22);
}