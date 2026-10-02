#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void* value;
    int type; // 0 for list, 1 for dict
} Node;

void lint_tree(Node node, int depth) {
    if (depth > 10) {
        fprintf(stderr, "RecursionError: Depth exceeds boundary conditions\n");
        exit(1);
    }
    if (node.type == 0) {
        // Assuming node.value is a pointer to an array of Node
        Node* list = (Node*)node.value;
        for (int i = 0; list[i].value != NULL; i++) {
            lint_tree(list[i], depth + 1);
        }
    } else if (node.type != 1) {
        fprintf(stderr, "TypeError: Node must be a dictionary or list\n");
        exit(1);
    }
}

int main() {
    Node child1 = {NULL, 1}; // Empty dictionary
    Node child2 = {NULL, 1}; // Empty dictionary
    Node grandchild = {NULL, 1}; // Empty dictionary
    Node children1[] = {child1, {NULL, 1}}; // List of children
    Node children2[] = {child2, {NULL, 1}}; // List of children
    Node grandchildren[] = {grandchild, {NULL, 1}}; // List of grandchildren
    Node root[] = {{children1, 0}, {children2, 0}, {NULL, 1}}; // List of roots

    Node tree = {root, 0}; // Root node is a list
    lint_tree(tree, 0);
    return 0;
}