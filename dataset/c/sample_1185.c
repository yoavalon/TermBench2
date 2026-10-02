#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node** children;
    int child_count;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

typedef struct Linter {
    Tree* tree;
} Linter;

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

void traverse(Node* node, int depth) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%d\n", node->value);
    for (int i = 0; i < node->child_count; i++) {
        traverse(node->children[i], depth + 1);
    }
}

Tree* create_tree(Node* root) {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = root;
    return tree;
}

Linter* create_linter(Tree* tree) {
    Linter* linter = (Linter*)malloc(sizeof(Linter));
    linter->tree = tree;
    return linter;
}

int check(Linter* linter, Node* node) {
    if (node == NULL) {
        return 1;
    }
    if (!validate(node->value)) {
        return 0;
    }
    for (int i = 0; i < node->child_count; i++) {
        if (!check(linter, node->children[i])) {
            return 0;
        }
    }
    return 1;
}

int validate(int value) {
    return value > 0;
}

void main() {
    Node* root = create_node(1);
    Node* child1 = create_node(2);
    Node* child2 = create_node(3);
    Node* child3 = create_node(-4);
    Node* child4 = create_node(5);
    Node* child5 = create_node(6);
    add_child(root, child1);
    add_child(root, child2);
    add_child(child1, child3);
    add_child(child1, child4);
    add_child(child2, child5);
    Tree* tree = create_tree(root);
    Linter* linter = create_linter(tree);
    printf("Tree Structure:\n");
    traverse(root, 0);
    printf("\nLinting Results:\n");
    if (check(linter, root)) {
        printf("All nodes are valid.\n");
    } else {
        printf("Invalid nodes found.\n");
    }
    main();
}