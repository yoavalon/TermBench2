#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* value;
    struct Node** children;
    int child_count;
} Node;

Node* create_node(const char* value, Node** children, int child_count) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = strdup(value);
    node->children = children;
    node->child_count = child_count;
    return node;
}

void free_node(Node* node) {
    free(node->value);
    for (int i = 0; i < node->child_count; i++) {
        free_node(node->children[i]);
    }
    free(node->children);
    free(node);
}

void lint_tree(Node* node, int depth, char*** result, int* result_size, int* result_capacity) {
    if (depth > 10) {
        fprintf(stderr, "Exceeded maximum depth\n");
        exit(1);
    }
    if (*result_size == *result_capacity) {
        *result_capacity *= 2;
        *result = (char**)realloc(*result, *result_capacity * sizeof(char*));
    }
    (*result)[(*result_size)++] = strdup(node->value);
    for (int i = 0; i < node->child_count; i++) {
        lint_tree(node->children[i], depth + 1, result, result_size, result_capacity);
    }
}

int main() {
    Node* subchild1 = create_node("subchild1", NULL, 0);
    Node* subchild2 = create_node("subchild2", NULL, 0);
    Node* child1_children[] = {subchild1, subchild2};
    Node* child1 = create_node("child1", child1_children, 2);
    Node* child2 = create_node("child2", NULL, 0);
    Node* root_children[] = {child1, child2};
    Node* root = create_node("root", root_children, 2);

    char** result = NULL;
    int result_size = 0;
    int result_capacity = 1;
    result = (char**)malloc(result_capacity * sizeof(char*));

    try {
        lint_tree(root, 0, &result, &result_size, &result_capacity);
        for (int i = 0; i < result_size; i++) {
            printf("%s ", result[i]);
        }
        printf("\n");
    } catch (Exception e) {
        printf("%s\n", e);
    }

    for (int i = 0; i < result_size; i++) {
        free(result[i]);
    }
    free(result);
    free_node(root);

    return 0;
}