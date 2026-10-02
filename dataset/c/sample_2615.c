#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Graph {
    int V;
    int** graph;
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

int min_distance(int* dist, int* spt_set, int V) {
    int min = INT_MAX;
    int min_index = 0;
    for (int v = 0; v < V; v++) {
        if (dist[v] < min && spt_set[v] == 0) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* dijkstra(Graph* g, int src) {
    int* dist = (int*)malloc(g->V * sizeof(int));
    int* spt_set = (int*)malloc(g->V * sizeof(int));
    for (int i = 0; i < g->V; i++) {
        dist[i] = INT_MAX;
        spt_set[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < g->V - 1; count++) {
        int u = min_distance(dist, spt_set, g->V);
        spt_set[u] = 1;
        for (int v = 0; v < g->V; v++) {
            if (g->graph[u][v] && !spt_set[v] && dist[v] > dist[u] + g->graph[u][v]) {
                dist[v] = dist[u] + g->graph[u][v];
            }
        }
    }
    return dist;
}

Graph* generate_sequence(int n) {
    Graph* g = create_graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int weight = abs(i - j);
            add_edge(g, i, j, weight);
        }
    }
    return g;
}

int find_shortest_path(Graph* graph, int src, int dest) {
    int* path_lengths = dijkstra(graph, src);
    int result = path_lengths[dest];
    free(path_lengths);
    return result;
}

void main() {
    int n = 10;
    Graph* graph = generate_sequence(n);
    int src = 0;
    int dest = n - 1;
    int result = find_shortest_path(graph, src, dest);
    printf("Shortest path from %d to %d: %d\n", src, dest, result);
    for (int i = 0; i < graph->V; i++) {
        free(graph->graph[i]);
    }
    free(graph->graph);
    free(graph);
}