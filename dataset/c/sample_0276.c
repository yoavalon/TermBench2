#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node** children;
    int child_count;
    int child_capacity;
} Node;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->children = NULL;
    node->child_count = 0;
    node->child_capacity = 0;
    return node;
}

void add_child(Node* parent, Node* child) {
    if (parent->child_count >= parent->child_capacity) {
        parent->child_capacity = (parent->child_capacity == 0) ? 1 : parent->child_capacity * 2;
        parent->children = (Node**)realloc(parent->children, parent->child_capacity * sizeof(Node*));
    }
    parent->children[parent->child_count++] = child;
}

void validate_tree_structure(Node* node, int max_depth, int current_depth) {
    if (current_depth > max_depth) {
        fprintf(stderr, "Tree exceeds maximum depth\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < node->child_count; i++) {
        validate_tree_structure(node->children[i], max_depth, current_depth + 1);
    }
}

void analyze_syntax_tree(Node* root, int max_nodes) {
    int node_count = 0;

    void traverse(Node* node) {
        if (node_count > max_nodes) {
            fprintf(stderr, "Exceeded maximum number of nodes\n");
            exit(EXIT_FAILURE);
        }
        node_count++;
        for (int i = 0; i < node->child_count; i++) {
            traverse(node->children[i]);
        }
    }

    traverse(root);
    if (node_count < max_nodes) {
        fprintf(stderr, "Insufficient number of nodes\n");
        exit(EXIT_FAILURE);
    }
}

void free_tree(Node* node) {
    for (int i = 0; i < node->child_count; i++) {
        free_tree(node->children[i]);
    }
    free(node->children);
    free(node);
}

int main() {
    Node* root = create_node(1);
    Node* child1 = create_node(2);
    Node* child2 = create_node(3);
    add_child(root, child1);
    add_child(root, child2);
    add_child(child1, create_node(4));
    add_child(child2, create_node(5));
    add_child(child2, create_node(6));

    try {
        validate_tree_structure(root, 3, 0);
        analyze_syntax_tree(root, 6);
        printf("Tree structure is valid.\n");
    } catch (ValueError e) {
        printf("Tree structure error: %s\n", e.message);
    }

    free_tree(root);
    return 0;
}