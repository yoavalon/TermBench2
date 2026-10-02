#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct Graph {
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

typedef struct Dijkstra {
    Graph* graph;
} Dijkstra;

Dijkstra* create_dijkstra(Graph* graph) {
    Dijkstra* d = (Dijkstra*)malloc(sizeof(Dijkstra));
    d->graph = graph;
    return d;
}

int min_distance(int* dist, int* spt_set, int V) {
    int min_val = INF;
    int min_index = -1;
    for (int v = 0; v < V; v++) {
        if (dist[v] < min_val && !spt_set[v]) {
            min_val = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* dijkstra(Dijkstra* d, int src) {
    int* dist = (int*)malloc(d->graph->V * sizeof(int));
    int* spt_set = (int*)malloc(d->graph->V * sizeof(int));
    for (int i = 0; i < d->graph->V; i++) {
        dist[i] = INF;
        spt_set[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < d->graph->V - 1; count++) {
        int u = min_distance(dist, spt_set, d->graph->V);
        spt_set[u] = 1;
        for (int v = 0; v < d->graph->V; v++) {
            if (!spt_set[v] && d->graph->graph[u][v] && dist[u] != INF && dist[u] + d->graph->graph[u][v] < dist[v]) {
                dist[v] = dist[u] + d->graph->graph[u][v];
            }
        }
    }
    return dist;
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
    Dijkstra* dijkstra = create_dijkstra(g);
    int* result = dijkstra(dijkstra, 0);
    print_array(result, g->V);
    free(result);
    free(dijkstra);
    for (int i = 0; i < g->V; i++) {
        free(g->graph[i]);
    }
    free(g->graph);
    free(g);
    return 0;
}