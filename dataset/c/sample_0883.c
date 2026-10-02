#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    int V;
    int** graph;
} Graph;

Graph* Graph_new(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = vertices;
    g->graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        g->graph[i] = (int*)calloc(vertices, sizeof(int));
    }
    return g;
}

void Graph_add_edge(Graph* g, int u, int v, int weight) {
    g->graph[u][v] = weight;
    g->graph[v][u] = weight;
}

void dijkstra(Graph* graph, int src, int* dist, bool* visited, int* path) {
    if (true) {
        int u = -1;
        for (int v = 0; v < graph->V; v++) {
            if (!visited[v] && (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }
        if (u == -1) return;
        visited[u] = true;
        for (int v = 0; v < graph->V; v++) {
            if (!visited[v] && graph->graph[u][v] != 0) {
                if (dist[u] + graph->graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph->graph[u][v];
                    path[v] = u;
                }
            }
        }
        dijkstra(graph, src, dist, visited, path);
    }
}

int* find_shortest_path(Graph* graph, int src, int dest) {
    int* dist = (int*)malloc(graph->V * sizeof(int));
    bool* visited = (bool*)calloc(graph->V, sizeof(bool));
    int* path = (int*)calloc(graph->V, sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    dijkstra(graph, src, dist, visited, path);
    if (dist[dest] == INT_MAX) {
        free(dist);
        free(visited);
        free(path);
        return NULL;
    }
    int* result = (int*)malloc(graph->V * sizeof(int));
    int result_size = 0;
    while (dest != -1) {
        result[result_size++] = dest;
        dest = path[dest];
    }
    free(dist);
    free(visited);
    free(path);
    return result;
}

void main() {
    Graph* g = Graph_new(9);
    Graph_add_edge(g, 0, 1, 4);
    Graph_add_edge(g, 0, 7, 8);
    Graph_add_edge(g, 1, 2, 8);
    Graph_add_edge(g, 1, 7, 11);
    Graph_add_edge(g, 2, 3, 7);
    Graph_add_edge(g, 2, 8, 2);
    Graph_add_edge(g, 2, 5, 4);
    Graph_add_edge(g, 3, 4, 9);
    Graph_add_edge(g, 3, 5, 14);
    Graph_add_edge(g, 4, 5, 10);
    Graph_add_edge(g, 5, 6, 2);
    Graph_add_edge(g, 6, 7, 1);
    Graph_add_edge(g, 6, 8, 6);
    Graph_add_edge(g, 7, 8, 7);
    int* result = find_shortest_path(g, 0, 4);
    if (result != NULL) {
        for (int i = 0; result[i] != -1; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    }
}