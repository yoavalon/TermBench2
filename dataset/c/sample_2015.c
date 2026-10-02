#include <stdio.h>
#include <limits.h>

typedef struct {
    int V;
    int graph[9][9];
} Graph;

void Graph_init(Graph* g, int vertices) {
    g->V = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->graph[i][j] = 0;
        }
    }
}

void Graph_add_edge(Graph* g, int u, int v, int weight) {
    g->graph[u][v] = weight;
    g->graph[v][u] = weight;
}

int Graph_min_distance(Graph* g, int dist[], int spt_set[]) {
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < g->V; v++) {
        if (dist[v] < min && spt_set[v] == 0) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void Graph_dijkstra(Graph* g, int src, int dist[]) {
    for (int i = 0; i < g->V; i++) {
        dist[i] = INT_MAX;
        spt_set[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < g->V - 1; count++) {
        int u = Graph_min_distance(g, dist, spt_set);
        spt_set[u] = 1;
        for (int v = 0; v < g->V; v++) {
            if (g->graph[u][v] && spt_set[v] == 0 && dist[v] > dist[u] + g->graph[u][v]) {
                dist[v] = dist[u] + g->graph[u][v];
            }
        }
    }
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
    int dist[9];
    Graph_dijkstra(&g, 0, dist);
    printf("Vertex \tDistance from Source\n");
    for (int node = 0; node < g.V; node++) {
        printf("%d \t %d\n", node, dist[node]);
    }
}