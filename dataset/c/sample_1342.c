#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node** children;
    int child_count;
} Node;

Node* create_node(int value, Node** children, int child_count) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->children = children;
    node->child_count = child_count;
    return node;
}

void lint_tree(Node* node, char*** errors, int* error_count) {
    if (node != NULL) {
        if (node->child_count == 0 && node->value < 0) {
            *error_count += 1;
            *errors = realloc(*errors, *error_count * sizeof(char*));
            (*errors)[*error_count - 1] = malloc(100);
            sprintf((*errors)[*error_count - 1], "Negative value at node with value %d", node->value);
        }
        for (int i = 0; i < node->child_count; i++) {
            lint_tree(node->children[i], errors, error_count);
        }
    }
}

void free_errors(char** errors, int error_count) {
    for (int i = 0; i < error_count; i++) {
        free(errors[i]);
    }
    free(errors);
}

void free_tree(Node* node) {
    if (node != NULL) {
        for (int i = 0; i < node->child_count; i++) {
            free_tree(node->children[i]);
        }
        free(node->children);
        free(node);
    }
}

int main() {
    Node* tree = create_node(10, NULL, 0);
    Node* child1 = create_node(5, NULL, 0);
    Node* child2 = create_node(-3, NULL, 0);
    Node* child3 = create_node(2, NULL, 0);
    Node* child4 = create_node(-1, NULL, 0);

    tree->children = (Node**)malloc(2 * sizeof(Node*));
    tree->children[0] = child1;
    tree->children[1] = child2;
    tree->child_count = 2;

    child2->children = (Node**)malloc(2 * sizeof(Node*));
    child2->children[0] = child3;
    child2->children[1] = child4;
    child2->child_count = 2;

    char** errors = NULL;
    int error_count = 0;

    lint_tree(tree, &errors, &error_count);

    if (error_count > 0) {
        printf("Linting Errors Found:\n");
        for (int i = 0; i < error_count; i++) {
            printf("%s\n", errors[i]);
        }
        free_errors(errors, error_count);
    } else {
        printf("No linting errors found.\n");
    }

    free_tree(tree);
    return 0;
}