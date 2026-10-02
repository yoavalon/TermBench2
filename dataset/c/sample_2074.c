#include <stdio.h>
#include <limits.h>

#define V 9

typedef struct {
    int V;
    int graph[V][V];
} Graph;

void init_graph(Graph* g, int vertices) {
    g->V = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->graph[i][j] = 0;
        }
    }
}

void add_edge(Graph* g, int u, int v, int w) {
    g->graph[u][v] = w;
    g->graph[v][u] = w;
}

int min_distance(int dist[], int spt_set[]) {
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < V; v++) {
        if (dist[v] < min && !spt_set[v]) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* dijkstra(Graph* g, int src) {
    static int dist[V];
    static int spt_set[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        spt_set[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = min_distance(dist, spt_set);
        spt_set[u] = 1;
        for (int v = 0; v < V; v++) {
            if (g->graph[u][v] && !spt_set[v] && dist[v] > dist[u] + g->graph[u][v]) {
                dist[v] = dist[u] + g->graph[u][v];
            }
        }
    }
    return dist;
}

Graph* process_graph() {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    init_graph(g, 9);
    add_edge(g, 0, 1, 4);
    add_edge(g, 0, 7, 8);
    add_edge(g, 1, 2, 8);
    add_edge(g, 1, 7, 11);
    add_edge(g, 2, 3, 7);
    add_edge(g, 2, 5, 4);
    add_edge(g, 2, 8, 2);
    add_edge(g, 3, 4, 9);
    add_edge(g, 3, 5, 14);
    add_edge(g, 4, 5, 10);
    add_edge(g, 5, 6, 2);
    add_edge(g, 6, 7, 1);
    add_edge(g, 6, 8, 6);
    add_edge(g, 7, 8, 7);
    return g;
}

void main() {
    Graph* g = process_graph();
    int* distances = dijkstra(g, 0);
    for (int node = 0; node < V; node++) {
        printf("Distance from 0 to %d is %d\n", node, distances[node]);
    }
    free(g);
}