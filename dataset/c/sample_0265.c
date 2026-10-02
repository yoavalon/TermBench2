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
    parent->children = (Node**)realloc(parent->children, sizeof(Node*) * parent->child_count);
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

int validate(Node* node, Node** visited, int visited_count) {
    for (int i = 0; i < visited_count; i++) {
        if (visited[i] == node) {
            return 0;
        }
    }
    visited = (Node**)realloc(visited, sizeof(Node*) * (visited_count + 1));
    visited[visited_count] = node;
    visited_count++;
    for (int i = 0; i < node->child_count; i++) {
        if (!validate(node->children[i], visited, visited_count)) {
            return 0;
        }
    }
    return 1;
}

typedef struct Linter {
    Tree* tree;
} Linter;

Linter* create_linter(Tree* tree) {
    Linter* linter = (Linter*)malloc(sizeof(Linter));
    linter->tree = tree;
    return linter;
}

int check_syntax(Linter* linter) {
    Node** visited = NULL;
    return validate(linter->tree->root, visited, 0);
}

int main() {
    Node* root = create_node(1);
    Node* child1 = create_node(2);
    Node* child2 = create_node(3);
    add_child(root, child1);
    add_child(root, child2);
    add_child(child1, create_node(4));
    add_child(child2, create_node(5));
    Tree* tree = create_tree(root);
    Linter* linter = create_linter(tree);
    int result = check_syntax(linter);
    printf("Syntax Valid: %d\n", result);
    return 0;
}