c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node** neighbors;
    int neighbor_count;
} Node;

typedef struct Graph {
    Node** nodes;
    int node_count;
} Graph;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->neighbors = (Node**)malloc(sizeof(Node*) * 10);
    node->neighbor_count = 0;
    return node;
}

Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodes = (Node**)malloc(sizeof(Node*) * 10);
    graph->node_count = 0;
    return graph;
}

void add_node(Graph* graph, int value) {
    Node* node = create_node(value);
    graph->nodes[graph->node_count++] = node;
}

void add_edge(Node* node1, Node* node2) {
    node1->neighbors[node1->neighbor_count++] = node2;
    node2->neighbors[node2->neighbor_count++] = node1;
}

int* bfs_shortest_path(Graph* graph, Node* start, Node* end, int* path_length) {
    Node* queue[100];
    int queue_size = 0;
    int* path[100];
    int path_sizes[100];
    queue[queue_size++] = start;
    path_sizes[queue_size - 1] = 1;
    path[queue_size - 1] = (int*)malloc(sizeof(int) * 10);
    path[queue_size - 1][0] = start->value;
    while (queue_size > 0) {
        Node* vertex = queue[0];
        int* current_path = path[0];
        int current_path_size = path_sizes[0];
        for (int i = 0; i < vertex->neighbor_count; i++) {
            Node* next = vertex->neighbors[i];
            int found = 0;
            for (int j = 0; j < current_path_size; j++) {
                if (next->value == current_path[j]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                if (next == end) {
                    *path_length = current_path_size + 1;
                    int* result = (int*)malloc(sizeof(int) * (*path_length));
                    for (int j = 0; j < current_path_size; j++) {
                        result[j] = current_path[j];
                    }
                    result[current_path_size] = next->value;
                    return result;
                } else {
                    queue[queue_size] = next;
                    path_sizes[queue_size] = current_path_size + 1;
                    path[queue_size] = (int*)malloc(sizeof(int) * 10);
                    for (int j = 0; j < current_path_size; j++) {
                        path[queue_size][j] = current_path[j];
                    }
                    path[queue_size][current_path_size] = next->value;
                    queue_size++;
                }
            }
        }
        for (int i = 0; i < queue_size - 1; i++) {
            queue[i] = queue[i + 1];
            path_sizes[i] = path_sizes[i + 1];
            path[i] = path[i + 1];
        }
        queue_size--;
    }
    *path_length = 0;
    return NULL;
}

void main() {
    Graph* graph = create_graph();
    Node* node1 = create_node(1);
    Node* node2 = create_node(2);
    Node* node3 = create_node(3);
    Node* node4 = create_node(4);
    Node* node5 = create_node(5);
    graph->nodes[graph->node_count++] = node1;
    graph->nodes[graph->node_count++] = node2;
    graph->nodes[graph->node_count++] = node3;
    graph->nodes[graph->node_count++] = node4;
    graph->nodes[graph->node_count++] = node5;
    add_edge(node1, node2);
    add_edge(node2, node3);
    add_edge(node3, node4);
    add_edge(node4, node5);
    add_edge(node5, node1);
    while (1) {
        int path_length;
        int* path = bfs_shortest_path(graph, node1, node5, &path_length);
        if (path != NULL) {
            for (int i = 0; i < path_length; i++) {
                printf("%d ", path[i]);
            }
            printf("\n");
            free(path);
        }
    }
}