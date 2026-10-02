#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* value;
    struct Node** children;
    int child_count;
    int child_capacity;
} Node;

void init_node(Node* node, const char* value) {
    node->value = strdup(value);
    node->children = NULL;
    node->child_count = 0;
    node->child_capacity = 0;
}

void add_child(Node* node, Node* child) {
    if (node->child_count == node->child_capacity) {
        node->child_capacity = node->child_capacity == 0 ? 1 : node->child_capacity * 2;
        node->children = realloc(node->children, node->child_capacity * sizeof(Node*));
    }
    node->children[node->child_count++] = child;
}

void traverse(Node* node, void (*visitor)(Node*)) {
    visitor(node);
    for (int i = 0; i < node->child_count; i++) {
        traverse(node->children[i], visitor);
    }
}

void check_lint(Node* node, char*** errors, int* error_count) {
    if (strcmp(node->value, "error") == 0) {
        *errors = realloc(*errors, (*error_count + 1) * sizeof(char*));
        (*errors)[*error_count] = malloc(50 * sizeof(char));
        sprintf((*errors)[*error_count], "Error found at node: %s", node->value);
        (*error_count)++;
    }
}

void lint_tree(Node* root, char*** errors, int* error_count) {
    void visitor(Node* node) {
        check_lint(node, errors, error_count);
    }
    traverse(root, visitor);
}

void free_node(Node* node) {
    for (int i = 0; i < node->child_count; i++) {
        free_node(node->children[i]);
    }
    free(node->value);
    free(node->children);
    free(node);
}

void free_errors(char** errors, int error_count) {
    for (int i = 0; i < error_count; i++) {
        free(errors[i]);
    }
    free(errors);
}

int main() {
    Node* root = malloc(sizeof(Node));
    init_node(root, "root");
    Node* child1 = malloc(sizeof(Node));
    init_node(child1, "child1");
    Node* child2 = malloc(sizeof(Node));
    init_node(child2, "error");
    Node* child3 = malloc(sizeof(Node));
    init_node(child3, "child3");
    add_child(root, child1);
    add_child(root, child2);
    add_child(root, child3);
    add_child(child1, malloc(sizeof(Node)));
    init_node(child1->children[0], "grandchild1");
    add_child(child2, malloc(sizeof(Node)));
    init_node(child2->children[0], "grandchild2");
    add_child(child3, malloc(sizeof(Node)));
    init_node(child3->children[0], "error");

    char** errors = NULL;
    int error_count = 0;
    lint_tree(root, &errors, &error_count);

    for (int i = 0; i < error_count; i++) {
        printf("%s\n", errors[i]);
    }

    free_errors(errors, error_count);
    free_node(root);

    return 0;
}