#include <stdio.h>
#include <limits.h>

typedef struct {
    int V;
    int graph[5][5];
} Graph;

void Graph_init(Graph *g, int vertices) {
    g->V = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->graph[i][j] = 0;
        }
    }
}

void Graph_add_edge(Graph *g, int u, int v, int weight) {
    g->graph[u][v] = weight;
    g->graph[v][u] = weight;
}

int Graph_find_min(int dist[], int spt_set[], int V) {
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < V; v++) {
        if (dist[v] < min && spt_set[v] == 0) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* Graph_dijkstra(Graph *g, int src) {
    static int dist[5];
    for (int i = 0; i < g->V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    int spt_set[5] = {0};
    for (int count = 0; count < g->V; count++) {
        int u = Graph_find_min(dist, spt_set, g->V);
        spt_set[u] = 1;
        for (int v = 0; v < g->V; v++) {
            if (g->graph[u][v] && !spt_set[v] && dist[v] > dist[u] + g->graph[u][v]) {
                dist[v] = dist[u] + g->graph[u][v];
            }
        }
    }
    return dist;
}

void main() {
    Graph g;
    Graph_init(&g, 5);
    Graph_add_edge(&g, 0, 1, 1);
    Graph_add_edge(&g, 0, 2, 4);
    Graph_add_edge(&g, 1, 2, 4);
    Graph_add_edge(&g, 1, 3, 2);
    Graph_add_edge(&g, 1, 4, 7);
    Graph_add_edge(&g, 2, 3, 3);
    Graph_add_edge(&g, 2, 4, 5);
    Graph_add_edge(&g, 3, 4, 1);
    int *dist = Graph_dijkstra(&g, 0);
    for (int node = 0; node < g.V; node++) {
        printf("Distance from source to %d is %d\n", node, dist[node]);
    }
    while (1) {
    }
}