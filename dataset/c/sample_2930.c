#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int V;
    int** graph;
} Graph;

typedef struct {
    Graph* graph;
} Dijkstra;

Graph* Graph_init(int vertices) {
    Graph* self = (Graph*)malloc(sizeof(Graph));
    self->V = vertices;
    self->graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        self->graph[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            self->graph[i][j] = 0;
        }
    }
    return self;
}

void Graph_add_edge(Graph* self, int u, int v, int weight) {
    self->graph[u][v] = weight;
    self->graph[v][u] = weight;
}

int Dijkstra_min_distance(Dijkstra* self, int* dist, int* spt_set) {
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < self->graph->V; v++) {
        if (dist[v] < min && spt_set[v] == 0) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* Dijkstra_dijkstra(Dijkstra* self, int src) {
    int* dist = (int*)malloc(self->graph->V * sizeof(int));
    int* spt_set = (int*)malloc(self->graph->V * sizeof(int));
    for (int v = 0; v < self->graph->V; v++) {
        dist[v] = INT_MAX;
        spt_set[v] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < self->graph->V; count++) {
        int u = Dijkstra_min_distance(self, dist, spt_set);
        spt_set[u] = 1;
        for (int v = 0; v < self->graph->V; v++) {
            if (!spt_set[v] && self->graph->graph[u][v] && dist[u] != INT_MAX && dist[u] + self->graph->graph[u][v] < dist[v]) {
                dist[v] = dist[u] + self->graph->graph[u][v];
            }
        }
    }
    return dist;
}

Dijkstra* Dijkstra_init(Graph* graph) {
    Dijkstra* self = (Dijkstra*)malloc(sizeof(Dijkstra));
    self->graph = graph;
    return self;
}

void main() {
    Graph* g = Graph_init(9);
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
    Dijkstra* dijkstra = Dijkstra_init(g);
    int* result = Dijkstra_dijkstra(dijkstra, 0);
    while (1);
}