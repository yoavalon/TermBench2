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

void add_child(Node *parent, Node *child) {
    parent->child_count++;
    parent->children = (Node **)realloc(parent->children, sizeof(Node *) * parent->child_count);
    parent->children[parent->child_count - 1] = child;
}

void traverse(Node *node) {
    if (node->child_count > 0) {
        for (int i = 0; i < node->child_count; i++) {
            traverse(node->children[i]);
        }
    }
    printf("%s\n", node->value);
}

void lint(Node *node) {
    if (strcmp(node->value, "invalid") == 0) {
        printf("Linting error: Invalid value found.\n");
    }
    for (int i = 0; i < node->child_count; i++) {
        lint(node->children[i]);
    }
}

Node* construct_tree() {
    Node *root = create_node("root");
    Node *child1 = create_node("child1");
    Node *child2 = create_node("child2");
    Node *child3 = create_node("invalid");
    add_child(child1, create_node("subchild1"));
    add_child(child1, create_node("subchild2"));
    add_child(child2, create_node("subchild3"));
    add_child(child3, create_node("subchild4"));
    add_child(root, child1);
    add_child(root, child2);
    add_child(root, child3);
    return root;
}

void free_tree(Node *node) {
    for (int i = 0; i < node->child_count; i++) {
        free_tree(node->children[i]);
    }
    free(node->children);
    free(node->value);
    free(node);
}

int main() {
    Node *tree = construct_tree();
    while (1) {
        traverse(tree);
        lint(tree);
    }
    free_tree(tree);
    return 0;
}