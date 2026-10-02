#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node {
    char value[20];
    struct Node* children;
    int child_count;
} Node;

Node* create_node(const char* value) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->value, value);
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(Node* parent, Node* child) {
    parent->child_count++;
    parent->children = (Node*)realloc(parent->children, parent->child_count * sizeof(Node));
    parent->children[parent->child_count - 1] = *child;
}

typedef struct Tree {
    Node* root;
} Tree;

Tree* create_tree(Node* root) {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = root;
    return tree;
}

void traverse_helper(Node* node, char** result, int* result_count) {
    if (node != NULL) {
        result[*result_count] = (char*)malloc(20 * sizeof(char));
        strcpy(result[*result_count], node->value);
        (*result_count)++;
        for (int i = 0; i < node->child_count; i++) {
            traverse_helper(&node->children[i], result, result_count);
        }
    }
}

char** traverse(Tree* tree, int* result_count) {
    char** result = (char**)malloc(10 * sizeof(char*));
    *result_count = 0;
    traverse_helper(tree->root, result, result_count);
    return result;
}

typedef struct SemanticLint {
    Tree* tree;
} SemanticLint;

SemanticLint* create_semantic_lint(Tree* tree) {
    SemanticLint* lint = (SemanticLint*)malloc(sizeof(SemanticLint));
    lint->tree = tree;
    return lint;
}

void check_helper(Node* node, char*** issues, int* issues_count) {
    if (node != NULL) {
        if (strchr(node->value, '.') != NULL) {
            double value = atof(node->value);
            if (fabs(value - round(value * 1e10) / 1e10) >= 1e-9) {
                *issues_count)++;
                *issues = (char**)realloc(*issues, (*issues_count) * sizeof(char*));
                (*issues)[*issues_count - 1] = (char*)malloc(50 * sizeof(char));
                sprintf((*issues)[*issues_count - 1], "Low precision for %s", node->value);
            }
        }
        for (int i = 0; i < node->child_count; i++) {
            check_helper(&node->children[i], issues, issues_count);
        }
    }
}

char** check(SemanticLint* lint, int* issues_count) {
    char** issues = (char**)malloc(1 * sizeof(char*));
    *issues_count = 0;
    check_helper(lint->tree->root, &issues, issues_count);
    return issues;
}

int main() {
    Node* root = create_node("1.0");
    Node* child1 = create_node("0.1");
    Node* child2 = create_node("0.0000000001");
    add_child(root, child1);
    add_child(root, child2);
    Tree* tree = create_tree(root);
    SemanticLint* lint = create_semantic_lint(tree);

    int issues_count;
    char** issues = check(lint, &issues_count);

    for (int i = 0; i < issues_count; i++) {
        printf("%s\n", issues[i]);
        free(issues[i]);
    }
    free(issues);

    free(lint);
    free(tree);
    free(root);
    free(child1);
    free(child2);

    return 0;
}