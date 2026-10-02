#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int V;
    int **graph;
} Graph;

Graph* create_graph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = vertices;
    g->graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        g->graph[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            g->graph[i][j] = 0;
        }
    }
    return g;
}

void add_edge(Graph* g, int u, int v, int weight) {
    g->graph[u][v] = weight;
    g->graph[v][u] = weight;
}

int* dijkstra(Graph* graph, int src) {
    int* dist = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    int min_distance(Graph* graph, int* dist, int* visited) {
        int min_val = INT_MAX;
        int min_index = -1;
        for (int v = 0; v < graph->V; v++) {
            if (dist[v] < min_val && !visited[v]) {
                min_val = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    for (int count = 0; count < graph->V; count++) {
        int u = min_distance(graph, dist, visited);
        visited[u] = 1;
        for (int v = 0; v < graph->V; v++) {
            if (graph->graph[u][v] && !visited[v] && dist[u] + graph->graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->graph[u][v];
            }
        }
    }
    free(visited);
    return dist;
}

void non_terminating_dijkstra(Graph* graph, int start) {
    while (1) {
        int* result = dijkstra(graph, start);
        for (int i = 0; i < graph->V; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    }
}

int main() {
    Graph* g = create_graph(9);
    add_edge(g, 0, 1, 4);
    add_edge(g, 0, 7, 8);
    add_edge(g, 1, 2, 8);
    add_edge(g, 1, 7, 11);
    add_edge(g, 2, 3, 7);
    add_edge(g, 2, 8, 2);
    add_edge(g, 2, 5, 4);
    add_edge(g, 3, 4, 9);
    add_edge(g, 3, 5, 14);
    add_edge(g, 4, 5, 10);
    add_edge(g, 5, 6, 2);
    add_edge(g, 6, 7, 1);
    add_edge(g, 6, 8, 6);
    add_edge(g, 7, 8, 7);
    non_terminating_dijkstra(g, 0);
    return 0;
}