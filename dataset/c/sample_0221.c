#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node** children;
    int child_count;
} Node;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(Node* parent, Node* child) {
    parent->child_count++;
    parent->children = (Node**)realloc(parent->children, parent->child_count * sizeof(Node*));
    parent->children[parent->child_count - 1] = child;
}

typedef struct Tree {
    Node* root;
} Tree;

Tree* create_tree(Node* root) {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = root;
    return tree;
}

void traverse(Node* node, int depth, int** traversal, int* traversal_size) {
    if (node) {
        *traversal_size += 1;
        *traversal = (int*)realloc(*traversal, *traversal_size * 2 * sizeof(int));
        (*traversal)[(*traversal_size - 1) * 2] = node->value;
        (*traversal)[(*traversal_size - 1) * 2 + 1] = depth;
        for (int i = 0; i < node->child_count; i++) {
            traverse(node->children[i], depth + 1, traversal, traversal_size);
        }
    }
}

int check_boundary_conditions(Tree* tree) {
    int* traversal = NULL;
    int traversal_size = 0;
    traverse(tree->root, 0, &traversal, &traversal_size);
    int max_depth = 0;
    for (int i = 0; i < traversal_size; i++) {
        if (traversal[i * 2 + 1] > max_depth) {
            max_depth = traversal[i * 2 + 1];
        }
    }
    if (max_depth > 10) {
        free(traversal);
        return 0;
    }
    if (traversal_size > 20) {
        free(traversal);
        return 0;
    }
    free(traversal);
    return 1;
}

void main() {
    Node* root = create_node(1);
    Node* child1 = create_node(2);
    Node* child2 = create_node(3);
    Node* child3 = create_node(4);
    Node* child4 = create_node(5);
    add_child(root, child1);
    add_child(root, child2);
    add_child(child1, child3);
    add_child(child1, child4);
    Tree* tree = create_tree(root);
    if (check_boundary_conditions(tree)) {
        printf("Boundary conditions satisfied.\n");
    } else {
        printf("Boundary conditions violated.\n");
    }
    free(root->children);
    free(root);
    free(tree);
}