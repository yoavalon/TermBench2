#include <stdio.h>
#include <limits.h>

#define V 9

typedef struct {
    int V;
    int graph[V][V];
} Graph;

void Graph_init(Graph *self, int vertices) {
    self->V = vertices;
    for (int row = 0; row < vertices; row++) {
        for (int column = 0; column < vertices; column++) {
            self->graph[row][column] = 0;
        }
    }
}

void Graph_add_edge(Graph *self, int u, int v, int weight) {
    self->graph[u][v] = weight;
}

int Graph_min_distance(Graph *self, int dist[], int spt_set[]) {
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < self->V; v++) {
        if (dist[v] < min && spt_set[v] == 0) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* Graph_dijkstra(Graph *self, int src) {
    static int dist[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    int spt_set[V];
    for (int i = 0; i < V; i++) {
        spt_set[i] = 0;
    }
    for (int count = 0; count < V - 1; count++) {
        int u = Graph_min_distance(self, dist, spt_set);
        spt_set[u] = 1;
        for (int v = 0; v < V; v++) {
            if (spt_set[v] == 0 && self->graph[u][v] && dist[u] != INT_MAX && dist[u] + self->graph[u][v] < dist[v]) {
                dist[v] = dist[u] + self->graph[u][v];
            }
        }
    }
    return dist;
}

Graph process_graph() {
    Graph g;
    Graph_init(&g, 9);
    Graph_add_edge(&g, 0, 1, 4);
    Graph_add_edge(&g, 0, 7, 8);
    Graph_add_edge(&g, 1, 2, 8);
    Graph_add_edge(&g, 1, 7, 11);
    Graph_add_edge(&g, 2, 3, 7);
    Graph_add_edge(&g, 2, 8, 2);
    Graph_add_edge(&g, 2, 5, 4);
    Graph_add_edge(&g, 3, 4, 9);
    Graph_add_edge(&g, 3, 5, 14);
    Graph_add_edge(&g, 4, 5, 10);
    Graph_add_edge(&g, 5, 6, 2);
    Graph_add_edge(&g, 6, 7, 1);
    Graph_add_edge(&g, 6, 8, 6);
    Graph_add_edge(&g, 7, 8, 7);
    return g;
}

void main() {
    Graph g = process_graph();
    int* result = Graph_dijkstra(&g, 0);
    for (int i = 0; i < V; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}