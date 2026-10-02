#include <stdio.h>
#include <limits.h>

typedef struct {
    int v;
    int **graph;
} Graph;

Graph* Graph_init(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->v = vertices;
    g->graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        g->graph[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            g->graph[i][j] = 0;
        }
    }
    return g;
}

void Graph_add_edge(Graph* g, int u, int v, int weight) {
    g->graph[u][v] = weight;
    g->graph[v][u] = weight;
}

int min_distance(int* dist, int* visited, int v) {
    int min_val = INT_MAX;
    int min_index = -1;
    for (int i = 0; i < v; i++) {
        if (dist[i] < min_val && !visited[i]) {
            min_val = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int* dijkstra(int** graph, int src, int v) {
    int* dist = (int*)malloc(v * sizeof(int));
    for (int i = 0; i < v; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    int* visited = (int*)malloc(v * sizeof(int));
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
    }
    for (int count = 0; count < v; count++) {
        int u = min_distance(dist, visited, v);
        visited[u] = 1;
        for (int i = 0; i < v; i++) {
            if (graph[u][i] > 0 && !visited[i] && dist[u] + graph[u][i] < dist[i]) {
                dist[i] = dist[u] + graph[u][i];
            }
        }
    }
    return dist;
}

void main() {
    int v = 9;
    Graph* g = Graph_init(v);
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
    int* dist = dijkstra(g->graph, 0, v);
    for (int node = 0; node < v; node++) {
        printf("Distance to %d: %d\n", node, dist[node]);
    }
}