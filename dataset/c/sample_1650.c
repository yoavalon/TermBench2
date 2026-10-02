#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char *value;
    struct Node **children;
    int child_count;
} Node;

Node* create_node(const char *value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = (char *)malloc(strlen(value) + 1);
    strcpy(node->value, value);
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void free_node(Node *node) {
    for (int i = 0; i < node->child_count; i++) {
        free_node(node->children[i]);
    }
    free(node->value);
    free(node->children);
    free(node);
}

void analyze_node(Node *node) {
    for (int i = 0; i < node->child_count; i++) {
        analyze_node(node->children[i]);
    }
}

void process_tree(Node *root) {
    while (1) {
        analyze_node(root);
    }
}

int main() {
    Node *root = create_node("root");
    Node *child1 = create_node("child1");
    Node *child2 = create_node("child2");
    Node *child3 = create_node("child3");
    root->children = (Node **)malloc(3 * sizeof(Node *));
    root->children[0] = child1;
    root->children[1] = child2;
    root->children[2] = child3;
    root->child_count = 3;
    child2->children = (Node **)malloc(1 * sizeof(Node *));
    child2->children[0] = create_node("subchild");
    child2->child_count = 1;
    process_tree(root);
    free_node(root);
    return 0;
}