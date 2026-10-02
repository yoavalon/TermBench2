#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char *value;
    struct Node **children;
    int child_count;
} Node;

typedef struct Tree {
    Node *root;
} Tree;

Node* create_node(char *value) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(Node *parent, Node *child) {
    parent->child_count++;
    parent->children = (Node**)realloc(parent->children, sizeof(Node*) * parent->child_count);
    parent->children[parent->child_count - 1] = child;
}

Tree* create_tree(Node *root) {
    Tree *tree = (Tree*)malloc(sizeof(Tree));
    tree->root = root;
    return tree;
}

int validate(Tree *tree) {
    if (!tree->root) {
        return 0;
    }
    Node **stack = (Node**)malloc(sizeof(Node*));
    int stack_size = 1;
    stack[0] = tree->root;
    while (stack_size > 0) {
        Node *node = stack[--stack_size];
        if (strcmp(node->value, "invalid") == 0) {
            free(stack);
            return 0;
        }
        for (int i = 0; i < node->child_count; i++) {
            stack = (Node**)realloc(stack, sizeof(Node*) * (stack_size + 1));
            stack[stack_size++] = node->children[i];
        }
    }
    free(stack);
    return 1;
}

int check_tree(Tree *tree) {
    if (!tree) {
        return 0;
    }
    if (!validate(tree)) {
        return 0;
    }
    return 1;
}

void main() {
    Node *root = create_node("valid");
    Node *child1 = create_node("valid");
    Node *child2 = create_node("invalid");
    add_child(root, child1);
    add_child(root, child2);
    Tree *tree = create_tree(root);
    int result = check_tree(tree);
    printf("%d\n", result);
}