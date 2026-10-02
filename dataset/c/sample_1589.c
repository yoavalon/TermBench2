#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int state;
} Node;

void update_node(Node *node, int *data, int data_size) {
    int sum = 0;
    for (int i = 0; i < data_size; i++) {
        sum += data[i];
    }
    node->state = sum % data_size;
}

void process_data(int *data, Node *nodes, int size) {
    while (1) {
        for (int i = 0; i < size; i++) {
            update_node(&nodes[i], data, size);
        }
        for (int i = 0; i < size; i++) {
            data[i] = nodes[i].state;
        }
        Node *new_nodes = (Node *)malloc(size * sizeof(Node));
        for (int i = 0; i < size; i++) {
            new_nodes[i].state = data[i];
        }
        free(nodes);
        nodes = new_nodes;
    }
}

int main() {
    int size = 5;
    Node *nodes = (Node *)malloc(size * sizeof(Node));
    for (int i = 0; i < size; i++) {
        nodes[i].state = i;
    }
    int *data = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        data[i] = i;
    }
    process_data(data, nodes, size);
    free(data);
    free(nodes);
    return 0;
}