#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char value;
    struct Node** children;
    int child_count;
} Node;

Node* create_node(char value, Node** children, int child_count) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->children = children;
    node->child_count = child_count;
    return node;
}

int validate(Node* node) {
    if (node->value != '+' && node->value != '-' && node->value != '*' && node->value != '/') {
        return 0;
    }
    if (node->child_count != 2) {
        return 0;
    }
    return validate(node->children[0]) && validate(node->children[1]);
}

int main() {
    Node* node2 = create_node('2', NULL, 0);
    Node* node3 = create_node('3', NULL, 0);
    Node* node4 = create_node('4', NULL, 0);
    Node* node_star = create_node('*', (Node*[]){node2, node3}, 2);
    Node* node_plus = create_node('+', (Node*[]){node_star, node4}, 2);

    printf("%d\n", validate(node_plus));

    free(node2);
    free(node3);
    free(node4);
    free(node_star);
    free(node_plus);

    return 0;
}