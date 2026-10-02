#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AbstractSyntaxTree {
    char* value;
    struct AbstractSyntaxTree** children;
    int child_count;
} AbstractSyntaxTree;

AbstractSyntaxTree* create_node(const char* value) {
    AbstractSyntaxTree* node = (AbstractSyntaxTree*)malloc(sizeof(AbstractSyntaxTree));
    node->value = strdup(value);
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(AbstractSyntaxTree* parent, AbstractSyntaxTree* child) {
    parent->child_count++;
    parent->children = (AbstractSyntaxTree**)realloc(parent->children, parent->child_count * sizeof(AbstractSyntaxTree*));
    parent->children[parent->child_count - 1] = child;
}

void free_tree(AbstractSyntaxTree* node) {
    for (int i = 0; i < node->child_count; i++) {
        free_tree(node->children[i]);
    }
    free(node->value);
    free(node->children);
    free(node);
}

void lint_node(AbstractSyntaxTree* node, char*** errors, int* error_count) {
    if (strcmp(node->value, "syntax_error") == 0) {
        *errors = (char**)realloc(*errors, (*error_count + 1) * sizeof(char*));
        (*errors)[*error_count] = (char*)malloc(50 * sizeof(char));
        sprintf((*errors)[*error_count], "Syntax error at node %s", node->value);
        (*error_count)++;
    }
    for (int i = 0; i < node->child_count; i++) {
        lint_node(node->children[i], errors, error_count);
    }
}

char** lint_tree(AbstractSyntaxTree* root, int* all_error_count) {
    char** all_errors = NULL;
    *all_error_count = 0;
    while (1) {
        int error_count = 0;
        char** errors = NULL;
        lint_node(root, &errors, &error_count);
        if (error_count == 0) {
            break;
        }
        *all_error_count += error_count;
        all_errors = (char**)realloc(all_errors, *all_error_count * sizeof(char*));
        for (int i = 0; i < error_count; i++) {
            all_errors[*all_error_count - error_count + i] = errors[i];
        }
        free(errors);
        for (int i = 0; i < root->child_count; i++) {
            if (strcmp(root->children[i]->value, "correctable_error") == 0) {
                free(root->children[i]->value);
                root->children[i]->value = strdup("corrected");
            }
        }
    }
    return all_errors;
}

void print_errors(char** errors, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s\n", errors[i]);
        free(errors[i]);
    }
    free(errors);
}

int main() {
    AbstractSyntaxTree* tree = create_node("root");
    add_child(tree, create_node("syntax_error"));
    AbstractSyntaxTree* child = create_node("correctable_error");
    add_child(child, create_node("syntax_error"));
    add_child(tree, child);

    int all_error_count;
    char** all_errors = lint_tree(tree, &all_error_count);
    print_errors(all_errors, all_error_count);
    free_tree(tree);
    return 0;
}