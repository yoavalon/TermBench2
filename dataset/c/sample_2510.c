#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { NUMBER, OPERATOR } NodeType;

typedef struct Node {
    NodeType type;
    int value;
    struct Node** children;
    int num_children;
} Node;

typedef struct {
    Node** nodes;
    int size;
} Sequence;

int validate_node(Node* node) {
    if (node == NULL)
        return 0;
    if (node->type == NUMBER) {
        return 1;
    } else if (node->type == OPERATOR) {
        if (node->children == NULL || node->num_children == 0)
            return 0;
        for (int i = 0; i < node->num_children; i++) {
            if (!validate_node(node->children[i]))
                return 0;
        }
        return 1;
    }
    return 0;
}

int check_sequence(Sequence* sequence) {
    if (sequence == NULL || sequence->nodes == NULL)
        return 0;
    for (int i = 0; i < sequence->size; i++) {
        if (!validate_node(sequence->nodes[i]))
            return 0;
    }
    return 1;
}

int main() {
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->type = NUMBER;
    node1->value = 1;
    node1->children = NULL;
    node1->num_children = 0;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->type = NUMBER;
    node2->value = 2;
    node2->children = NULL;
    node2->num_children = 0;

    Node* node3 = (Node*)malloc(sizeof(Node));
    node3->type = NUMBER;
    node3->value = 3;
    node3->children = NULL;
    node3->num_children = 0;

    Node* node4 = (Node*)malloc(sizeof(Node));
    node4->type = OPERATOR;
    node4->value = '+';
    node4->children = (Node**)malloc(2 * sizeof(Node*));
    node4->children[0] = node2;
    node4->children[1] = node3;
    node4->num_children = 2;

    Node** sequence_nodes = (Node**)malloc(2 * sizeof(Node*));
    sequence_nodes[0] = node1;
    sequence_nodes[1] = node4;

    Sequence sequence;
    sequence.nodes = sequence_nodes;
    sequence.size = 2;

    if (check_sequence(&sequence)) {
        printf("Sequence is valid.\n");
    } else {
        printf("Sequence is invalid.\n");
    }

    free(node1);
    free(node2);
    free(node3);
    free(node4->children);
    free(node4);
    free(sequence_nodes);

    return 0;
}