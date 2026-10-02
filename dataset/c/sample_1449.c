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
    self->graph[v][u] = weight;
}

int Graph_min_distance(Graph *self, int dist[], int spt_set[]) {
    int min = INT_MAX;
    int min_index = 0;
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
    static int spt_set[V];
    for (int i = 0; i < self->V; i++) {
        dist[i] = INT_MAX;
        spt_set[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < self->V - 1; count++) {
        int u = Graph_min_distance(self, dist, spt_set);
        spt_set[u] = 1;
        for (int v = 0; v < self->V; v++) {
            if (self->graph[u][v] && spt_set[v] == 0 && dist[v] > dist[u] + self->graph[u][v]) {
                dist[v] = dist[u] + self->graph[u][v];
            }
        }
    }
    return dist;
}

void main() {
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
    int *dist = Graph_dijkstra(&g, 0);
    for (int node = 0; node < V; node++) {
        printf("Distance from source to %d: %d\n", node, dist[node]);
    }
}