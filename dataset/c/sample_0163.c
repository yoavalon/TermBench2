#include <stdio.h>
#include <stdlib.h>

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

void traverse(Node* node, int depth) {
    if (depth == 0) {
        return;
    }
    for (int i = 0; i < node->child_count; i++) {
        traverse(node->children[i], depth - 1);
    }
}

void analyze_syntax_tree(Node* root, int max_depth) {
    traverse(root, max_depth);
}

void free_node(Node* node) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < node->child_count; i++) {
        free_node(node->children[i]);
    }
    free(node->value);
    free(node);
}

int main() {
    Node* child1 = create_node("child1", NULL, 0);
    Node* grandchild1 = create_node("grandchild1", NULL, 0);
    Node* child2 = create_node("child2", (Node*[]){grandchild1}, 1);
    Node* root = create_node("root", (Node*[]){child1, child2}, 2);

    analyze_syntax_tree(root, 2);

    free_node(root);
    return 0;
}