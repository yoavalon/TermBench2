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

void traverse(Node* node) {
    if (node == NULL) {
        return;
    }
    lint(node);
    for (int i = 0; i < node->child_count; i++) {
        traverse(node->children[i]);
    }
}

void lint(Node* node) {
    if (strcmp(node->value, "error") == 0) {
        fprintf(stderr, "Syntax error detected\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    Node* child1_1 = create_node("child1.1", NULL, 0);
    Node* child1 = create_node("child1", (Node*[]){create_node("error", NULL, 0), child1_1}, 2);
    Node* child2 = create_node("child2", NULL, 0);
    Node* tree = create_node("root", (Node*[]){child1, child2}, 2);

    traverse(tree);

    return 0;
}