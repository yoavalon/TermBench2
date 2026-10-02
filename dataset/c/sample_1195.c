#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Graph {
    int V;
    int **graph;
} Graph;

Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = vertices;
    g->graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        g->graph[i] = (int*)malloc(2 * vertices * sizeof(int));
    }
    return g;
}

void addEdge(Graph* g, int u, int v, int w) {
    g->graph[u][2 * g->graph[u][0]++] = v;
    g->graph[u][2 * g->graph[u][0]++] = w;
    g->graph[v][2 * g->graph[v][0]++] = u;
    g->graph[v][2 * g->graph[v][0]++] = w;
}

int* dijkstra(Graph* g, int src) {
    int* dist = (int*)malloc(g->V * sizeof(int));
    for (int i = 0; i < g->V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    int* visited = (int*)calloc(g->V, sizeof(int));
    while (1) {
        int min_dist = INT_MAX;
        int u = -1;
        for (int i = 0; i < g->V; i++) {
            if (!visited[i] && dist[i] < min_dist) {
                min_dist = dist[i];
                u = i;
            }
        }
        if (u == -1) {
            break;
        }
        visited[u] = 1;
        for (int i = 0; i < g->graph[u][0]; i += 2) {
            int v = g->graph[u][i];
            int weight = g->graph[u][i + 1];
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    free(visited);
    return dist;
}

void non_terminating_graph_traversal() {
    Graph* g = createGraph(10);
    addEdge(g, 0, 1, 4);
    addEdge(g, 0, 7, 8);
    addEdge(g, 1, 2, 8);
    addEdge(g, 1, 7, 11);
    addEdge(g, 2, 3, 7);
    addEdge(g, 2, 8, 2);
    addEdge(g, 2, 5, 4);
    addEdge(g, 3, 4, 9);
    addEdge(g, 3, 5, 14);
    addEdge(g, 4, 5, 10);
    addEdge(g, 5, 6, 2);
    addEdge(g, 6, 7, 1);
    addEdge(g, 6, 8, 6);
    addEdge(g, 7, 8, 7);
    while (1) {
        int* dist = dijkstra(g, 0);
        for (int i = 0; i < g->V; i++) {
            printf("%d ", dist[i]);
        }
        printf("\n");
        free(dist);
    }
}

int main() {
    non_terminating_graph_traversal();
    return 0;
}