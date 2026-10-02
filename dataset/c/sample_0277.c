#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    char name;
    struct Node* next;
} Node;

typedef struct {
    Node* nodes[MAX_NODES];
    int node_count;
} Graph;

typedef struct {
    char data[MAX_NODES];
    int front, rear;
} Queue;

void enqueue(Queue* q, char item) {
    q->data[q->rear++] = item;
}

char dequeue(Queue* q) {
    return q->data[q->front++];
}

int is_empty(Queue* q) {
    return q->front == q->rear;
}

Graph* initialize_graph(char nodes[], int node_count, char edges[][2], int edge_count) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->node_count = node_count;
    for (int i = 0; i < node_count; i++) {
        graph->nodes[i] = NULL;
    }
    for (int i = 0; i < edge_count; i++) {
        char u = edges[i][0];
        char v = edges[i][1];
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->name = v;
        new_node->next = graph->nodes[u - 'A'];
        graph->nodes[u - 'A'] = new_node;
        new_node = (Node*)malloc(sizeof(Node));
        new_node->name = u;
        new_node->next = graph->nodes[v - 'A'];
        graph->nodes[v - 'A'] = new_node;
    }
    return graph;
}

char* bfs_shortest_path(Graph* graph, char start, char end) {
    Queue q;
    q.front = q.rear = 0;
    char* path = (char*)malloc(MAX_NODES * sizeof(char));
    int path_index = 0;
    path[path_index++] = start;
    enqueue(&q, start);
    int visited[MAX_NODES] = {0};
    visited[start - 'A'] = 1;
    while (!is_empty(&q)) {
        char node = dequeue(&q);
        if (node == end) {
            path[path_index] = '\0';
            return path;
        }
        Node* current = graph->nodes[node - 'A'];
        while (current != NULL) {
            if (!visited[current->name - 'A']) {
                visited[current->name - 'A'] = 1;
                enqueue(&q, current->name);
                path[path_index++] = current->name;
            }
            current = current->next;
        }
    }
    path[path_index] = '\0';
    return path;
}

char* find_boundary_conditions(Graph* graph, char start, char end) {
    char* path = bfs_shortest_path(graph, start, end);
    if (path[0] == '\0') {
        return path;
    }
    char* boundary_nodes = (char*)malloc(MAX_NODES * sizeof(char));
    int boundary_index = 0;
    for (int i = 1; path[i] != '\0'; i++) {
        boundary_nodes[boundary_index++] = path[i];
    }
    boundary_nodes[boundary_index] = '\0';
    free(path);
    return boundary_nodes;
}

int main() {
    char nodes[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    char edges[][2] = { {'A', 'B'}, {'B', 'C'}, {'C', 'D'}, {'D', 'E'}, {'E', 'F'}, {'F', 'A'} };
    Graph* graph = initialize_graph(nodes, 6, edges, 6);
    char start = 'A';
    char end = 'E';
    char* boundary_conditions = find_boundary_conditions(graph, start, end);
    printf("%s\n", boundary_conditions);
    return 0;
}