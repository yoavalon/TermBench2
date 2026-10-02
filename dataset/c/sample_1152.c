c
#include <stdio.h>
#include <limits.h>

#define V 9

struct Graph {
    int V;
    int graph[V][V];
};

void add_edge(struct Graph* g, int u, int v, int weight) {
    g->graph[u][v] = weight;
}

int min_distance(int dist[], int spt_set[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (dist[v] < min && spt_set[v] == 0) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* dijkstra(int graph[V][V], int src, int V) {
    static int dist[V];
    int spt_set[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        spt_set[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = min_distance(dist, spt_set, V);
        spt_set[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!spt_set[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    return dist;
}

void main() {
    struct Graph g;
    g.V = 9;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g.graph[i][j] = 0;
        }
    }
    add_edge(&g, 0, 1, 4);
    add_edge(&g, 0, 7, 8);
    add_edge(&g, 1, 2, 8);
    add_edge(&g, 1, 7, 11);
    add_edge(&g, 2, 3, 7);
    add_edge(&g, 2, 5, 4);
    add_edge(&g, 2, 8, 2);
    add_edge(&g, 3, 4, 9);
    add_edge(&g, 3, 5, 14);
    add_edge(&g, 4, 5, 10);
    add_edge(&g, 5, 6, 2);
    add_edge(&g, 6, 7, 1);
    add_edge(&g, 6, 8, 6);
    add_edge(&g, 7, 8, 7);
    while (1) {
        int* d = dijkstra(g.graph, 0, g.V);
        for (int i = 0; i < V; i++) {
            printf("%d ", d[i]);
        }
        printf("\n");
    }
}