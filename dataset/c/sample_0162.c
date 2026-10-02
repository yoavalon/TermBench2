#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    char* name;
    struct Node* child1;
    struct Node* child2;
} Node;

bool validate_node(Node* node) {
    if (node == NULL) {
        return true;
    }
    if (node->name == NULL || node->child1 == NULL || node->child2 == NULL) {
        return false;
    }
    if (!validate_node(node->child1) || !validate_node(node->child2)) {
        return false;
    }
    return true;
}

void analyze_tree(Node* tree) {
    if (!validate_node(tree)) {
        fprintf(stderr, "Invalid syntax tree structure\n");
        exit(1);
    }
    Node* stack[100];
    int top = -1;
    stack[++top] = tree;
    while (top >= 0) {
        Node* node = stack[top--];
        if (node->child1 != NULL) {
            stack[++top] = node->child1;
        }
        if (node->child2 != NULL) {
            stack[++top] = node->child2;
        }
    }
}

int main() {
    Node* child1 = (Node*)malloc(sizeof(Node));
    child1->name = "child1";
    child1->child1 = NULL;
    child1->child2 = NULL;

    Node* grandchild1 = (Node*)malloc(sizeof(Node));
    grandchild1->name = "grandchild1";
    grandchild1->child1 = NULL;
    grandchild1->child2 = NULL;

    Node* child2 = (Node*)malloc(sizeof(Node));
    child2->name = "child2";
    child2->child1 = grandchild1;
    child2->child2 = NULL;

    Node* root = (Node*)malloc(sizeof(Node));
    root->name = "root";
    root->child1 = child1;
    root->child2 = child2;

    analyze_tree(root);

    free(child1);
    free(grandchild1);
    free(child2);
    free(root);

    return 0;
}