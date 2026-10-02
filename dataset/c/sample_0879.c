#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 9

typedef struct {
    int V;
    int** graph;
} Graph;

typedef struct {
    Graph* graph;
} ShortestPath;

Graph* Graph_init(int vertices) {
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

int min_distance(int* dist, int* sptSet, int V) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (dist[v] < min && sptSet[v] == 0) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* dijkstra(ShortestPath* sp, int src) {
    int* dist = (int*)malloc(sp->graph->V * sizeof(int));
    int* sptSet = (int*)malloc(sp->graph->V * sizeof(int));
    for (int v = 0; v < sp->graph->V; v++) {
        dist[v] = INT_MAX;
        sptSet[v] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < sp->graph->V - 1; count++) {
        int u = min_distance(dist, sptSet, sp->graph->V);
        sptSet[u] = 1;
        for (int v = 0; v < sp->graph->V; v++) {
            if (!sptSet[v] && sp->graph->graph[u][v] && dist[u] != INT_MAX && dist[u] + sp->graph->graph[u][v] < dist[v]) {
                dist[v] = dist[u] + sp->graph->graph[u][v];
            }
        }
    }
    return dist;
}

void main() {
    Graph* g = Graph_init(9);
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
    ShortestPath sp;
    sp.graph = g;
    int* dist = dijkstra(&sp, 0);
    for (int i = 0; i < g->V; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
    free(dist);
    free(sptSet);
    for (int i = 0; i < g->V; i++) {
        free(g->graph[i]);
    }
    free(g->graph);
    free(g);
}