#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct {
    int nodes;
    int edges[MAX_NODES][MAX_NODES];
} Graph;

void Graph_init(Graph *self, int n) {
    self->nodes = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            self->edges[i][j] = 0;
        }
    }
}

void Graph_connect(Graph *self, int u, int v) {
    self->edges[u][v] = 1;
    self->edges[v][u] = 1;
}

int Graph_find_shortest_paths(Graph *self, int start, int end) {
    int queue[MAX_NODES][2];
    int front = 0, rear = 0;
    int visited[MAX_NODES];
    for (int i = 0; i < self->nodes; i++) {
        visited[i] = 0;
    }
    visited[start] = 1;
    queue[rear][0] = start;
    queue[rear][1] = 0;
    rear++;
    while (front != rear) {
        int current = queue[front][0];
        int distance = queue[front][1];
        front++;
        if (current == end) {
            return distance;
        }
        for (int i = 0; i < self->nodes; i++) {
            if (self->edges[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear][0] = i;
                queue[rear][1] = distance + 1;
                rear++;
            }
        }
    }
    return -1;
}

Graph generate_sequence(int n) {
    Graph graph;
    Graph_init(&graph, n);
    for (int i = 0; i < n; i++) {
        Graph_connect(&graph, i, (i + 1) % n);
    }
    return graph;
}

void main() {
    int n = 10;
    Graph graph = generate_sequence(n);
    int start = 0;
    int end = 5;
    int result = Graph_find_shortest_paths(&graph, start, end);
    printf("%d\n", result);
}