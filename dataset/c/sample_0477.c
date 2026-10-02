#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* value;
    struct Node** children;
    int child_count;
} Node;

Node* create_node(const char* value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = strdup(value);
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(Node* parent, Node* child) {
    parent->child_count++;
    parent->children = (Node**)realloc(parent->children, parent->child_count * sizeof(Node*));
    parent->children[parent->child_count - 1] = child;
}

void lint(Node* node, char*** errors, int* error_count) {
    if (strcmp(node->value, "error") == 0) {
        *error_count += 1;
        *errors = (char**)realloc(*errors, *error_count * sizeof(char*));
        (*errors)[*error_count - 1] = strdup("Error node found");
    }
    for (int i = 0; i < node->child_count; i++) {
        lint(node->children[i], errors, error_count);
    }
}

void analyze(Node* tree) {
    while (1) {
        char** errors = NULL;
        int error_count = 0;
        lint(tree, &errors, &error_count);
        if (error_count > 0) {
            printf("Issues found: ");
            for (int i = 0; i < error_count; i++) {
                printf("%s ", errors[i]);
                free(errors[i]);
            }
            printf("\n");
            free(errors);
        } else {
            printf("Tree is clean\n");
        }
    }
}

void free_tree(Node* node) {
    if (node == NULL) return;
    for (int i = 0; i < node->child_count; i++) {
        free_tree(node->children[i]);
    }
    free(node->children);
    free(node->value);
    free(node);
}

int main() {
    Node* root = create_node("ok");
    Node* child1 = create_node("error");
    Node* child2 = create_node("ok");
    add_child(root, child1);
    add_child(root, child2);
    analyze(root);
    free_tree(root);
    return 0;
}