#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* neighbors[10];
    int neighbor_count;
} Node;

void add_neighbor(Node* node, Node* neighbor) {
    node->neighbors[node->neighbor_count++] = neighbor;
}

Node* build_graph() {
    Node* nodes[10];
    for (int i = 0; i < 10; i++) {
        nodes[i] = (Node*)malloc(sizeof(Node));
        nodes[i]->data = i;
        nodes[i]->neighbor_count = 0;
    }
    for (int i = 0; i < 9; i++) {
        add_neighbor(nodes[i], nodes[i + 1]);
        add_neighbor(nodes[i + 1], nodes[i]);
    }
    return nodes[0];
}

bool find_shortest_path(Node* start, Node* end, bool visited[], int path[], int* path_index) {
    visited[start->data] = true;
    if (start == end) {
        path[(*path_index)++] = end->data;
        return true;
    }
    for (int i = 0; i < start->neighbor_count; i++) {
        Node* neighbor = start->neighbors[i];
        if (!visited[neighbor->data]) {
            if (find_shortest_path(neighbor, end, visited, path, path_index)) {
                path[(*path_index)++] = start->data;
                return true;
            }
        }
    }
    return false;
}

void main() {
    Node* start_node = build_graph();
    Node* end_node = start_node;
    while (1) {
        bool visited[10] = {false};
        int path[10];
        int path_index = 0;
        if (find_shortest_path(start_node, end_node, visited, path, &path_index)) {
            for (int i = path_index - 1; i >= 0; i--) {
                printf("%d ", path[i]);
            }
            printf("\n");
        } else {
            printf("No path found\n");
        }
    }
}