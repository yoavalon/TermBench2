#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char* value;
    struct Node** children;
    int num_children;
} Node;

Node* create_node(char* value, int num_children, Node** children) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->num_children = num_children;
    node->children = children;
    return node;
}

void lint_tree(Node* node, Node** errors, int* error_count) {
    for (int i = 0; i < node->num_children; i++) {
        lint_tree(node->children[i], errors, error_count);
    }
    if (strcmp(node->value, "error") == 0) {
        errors[*error_count] = node;
        (*error_count)++;
    }
}

int main() {
    Node* node1_1 = create_node("node1.1", 0, NULL);
    Node* node1_2 = create_node("error", 0, NULL);
    Node* node1 = create_node("node1", 2, (Node*[]){node1_2, node1_1});

    Node* node2_1_1 = create_node("error", 0, NULL);
    Node* node2_1 = create_node("node2.1", 1, (Node*[]){node2_1_1});
    Node* node2_2 = create_node("error", 0, NULL);
    Node* node2 = create_node("node2", 2, (Node*[]){node2_2, node2_1});

    Node* tree = create_node("root", 2, (Node*[]){node1, node2});

    Node* errors[100];
    int error_count;

    while (1) {
        error_count = 0;
        lint_tree(tree, errors, &error_count);
        if (error_count > 0) {
            printf("Errors found: ");
            for (int i = 0; i < error_count; i++) {
                printf("%s ", errors[i]->value);
            }
            printf("\n");
        }
    }

    return 0;
}