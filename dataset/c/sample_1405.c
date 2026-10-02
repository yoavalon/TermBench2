#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    int **edges;
} Graph;

Graph* Graph_init(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->n = n;
    graph->edges = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph->edges[i] = (int*)malloc(0 * sizeof(int));
    }
    return graph;
}

void Graph_add_edge(Graph* graph, int u, int v) {
    graph->edges[u] = (int*)realloc(graph->edges[u], (sizeof(int) * (graph->edges[u][0] + 2)));
    graph->edges[u][graph->edges[u][0] + 1] = v;
    graph->edges[u][0]++;

    graph->edges[v] = (int*)realloc(graph->edges[v], (sizeof(int) * (graph->edges[v][0] + 2)));
    graph->edges[v][graph->edges[v][0] + 1] = u;
    graph->edges[v][0]++;
}

int* Graph_get_neighbors(Graph* graph, int v) {
    return graph->edges[v] + 1;
}

int bfs(Graph* graph, int start, int end) {
    int* visited = (int*)calloc(graph->n, sizeof(int));
    int** queue = (int**)malloc(graph->n * sizeof(int*));
    int queue_front = 0, queue_rear = 0;

    queue[queue_rear] = (int*)malloc(2 * sizeof(int));
    queue[queue_rear][0] = start;
    queue[queue_rear][1] = 0;
    queue_rear++;

    visited[start] = 1;

    while (queue_front != queue_rear) {
        int current = queue[queue_front][0];
        int distance = queue[queue_front][1];
        if (current == end) {
            free(queue[queue_front]);
            for (int i = queue_front; i < queue_rear; i++) {
                free(queue[i]);
            }
            free(queue);
            free(visited);
            return distance;
        }
        int* neighbors = Graph_get_neighbors(graph, current);
        for (int i = 0; i < neighbors[0]; i++) {
            int neighbor = neighbors[i + 1];
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                queue[queue_rear] = (int*)malloc(2 * sizeof(int));
                queue[queue_rear][0] = neighbor;
                queue[queue_rear][1] = distance + 1;
                queue_rear++;
            }
        }
        free(queue[queue_front]);
        queue_front++;
    }

    for (int i = 0; i < queue_rear; i++) {
        free(queue[i]);
    }
    free(queue);
    free(visited);
    return -1;
}

int find_shortest_path(Graph* graph, int start, int end) {
    return bfs(graph, start, end);
}

void main() {
    int n = 10;
    Graph* graph = Graph_init(n);
    Graph_add_edge(graph, 0, 1);
    Graph_add_edge(graph, 1, 2);
    Graph_add_edge(graph, 2, 3);
    Graph_add_edge(graph, 3, 4);
    Graph_add_edge(graph, 4, 5);
    Graph_add_edge(graph, 5, 6);
    Graph_add_edge(graph, 6, 7);
    Graph_add_edge(graph, 7, 8);
    Graph_add_edge(graph, 8, 9);
    Graph_add_edge(graph, 9, 0);
    int start = 0;
    int end = 5;
    int path_length = find_shortest_path(graph, start, end);
    printf("%d\n", path_length);
}