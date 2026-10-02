#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int **nodes;
    int size;
} Graph;

Graph *Graph_init(int size) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->nodes = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        g->nodes[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            g->nodes[i][j] = 0;
        }
    }
    g->size = size;
    return g;
}

void Graph_add_edge(Graph *g, int u, int v, int weight) {
    g->nodes[u - 1][v - 1] = weight;
    g->nodes[v - 1][u - 1] = weight;
}

typedef struct {
    Graph *graph;
    int *dist;
    int *prev;
    int *unvisited;
} Dijkstra;

Dijkstra *Dijkstra_init(Graph *graph) {
    Dijkstra *d = (Dijkstra *)malloc(sizeof(Dijkstra));
    d->graph = graph;
    d->dist = (int *)malloc(graph->size * sizeof(int));
    d->prev = (int *)malloc(graph->size * sizeof(int));
    d->unvisited = (int *)malloc(graph->size * sizeof(int));
    for (int i = 0; i < graph->size; i++) {
        d->dist[i] = INT_MAX;
        d->prev[i] = -1;
        d->unvisited[i] = 1;
    }
    return d;
}

int Dijkstra_find_min(Dijkstra *d) {
    int min_node = -1;
    int min_dist = INT_MAX;
    for (int i = 0; i < d->graph->size; i++) {
        if (d->unvisited[i] && d->dist[i] < min_dist) {
            min_node = i;
            min_dist = d->dist[i];
        }
    }
    return min_node;
}

void Dijkstra_compute(Dijkstra *d, int start) {
    d->dist[start - 1] = 0;
    while (1) {
        int current = Dijkstra_find_min(d);
        if (current == -1) break;
        d->unvisited[current] = 0;
        for (int i = 0; i < d->graph->size; i++) {
            if (d->graph->nodes[current][i] != 0) {
                int alt = d->dist[current] + d->graph->nodes[current][i];
                if (alt < d->dist[i]) {
                    d->dist[i] = alt;
                    d->prev[i] = current;
                }
            }
        }
    }
}

int main() {
    Graph *g = Graph_init(6);
    Graph_add_edge(g, 1, 2, 7);
    Graph_add_edge(g, 1, 3, 9);
    Graph_add_edge(g, 1, 6, 14);
    Graph_add_edge(g, 2, 3, 10);
    Graph_add_edge(g, 2, 4, 15);
    Graph_add_edge(g, 3, 4, 11);
    Graph_add_edge(g, 3, 6, 2);
    Graph_add_edge(g, 4, 5, 6);
    Graph_add_edge(g, 5, 6, 9);
    Dijkstra *dijkstra = Dijkstra_init(g);
    Dijkstra_compute(dijkstra, 1);
    while (1) {
        // Non-terminating loop
    }
    return 0;
}