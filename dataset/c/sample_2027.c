#include <stdio.h>
#include <limits.h>

#define V 9

struct Graph {
    int V;
    int graph[V][V];
};

void Graph_init(struct Graph *g, int vertices) {
    g->V = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->graph[i][j] = 0;
        }
    }
}

void Graph_add_edge(struct Graph *g, int u, int v, int weight) {
    g->graph[u][v] = weight;
    g->graph[v][u] = weight;
}

int Graph_min_distance(int dist[], int spt_set[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (dist[v] < min && !spt_set[v]) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* Graph_dijkstra(struct Graph *g, int src) {
    static int dist[V];
    int spt_set[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        spt_set[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = Graph_min_distance(dist, spt_set);
        spt_set[u] = 1;
        for (int v = 0; v < V; v++) {
            if (g->graph[u][v] && !spt_set[v] && dist[v] > dist[u] + g->graph[u][v]) {
                dist[v] = dist[u] + g->graph[u][v];
            }
        }
    }
    return dist;
}

void main() {
    struct Graph g;
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
    int *result = Graph_dijkstra(&g, 0);
    printf("Vertex \t Distance from Source\n");
    for (int node = 0; node < V; node++) {
        printf("%d \t %d\n", node, result[node]);
    }
}