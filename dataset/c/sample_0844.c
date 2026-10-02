#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Graph {
    int V;
    int** graph;
} Graph;

Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = vertices;
    g->graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        g->graph[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            g->graph[i][j] = 0;
        }
    }
    return g;
}

void addEdge(Graph* graph, int u, int v, int weight) {
    graph->graph[u][v] = weight;
    graph->graph[v][u] = weight;
}

int minDistance(int dist[], int sptSet[], int V) {
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < V; v++) {
        if (dist[v] < min && !sptSet[v]) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* dijkstra(Graph* graph, int src) {
    int V = graph->V;
    int* dist = (int*)malloc(V * sizeof(int));
    int* sptSet = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph->graph[u][v] && dist[u] != INT_MAX && dist[u] + graph->graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->graph[u][v];
            }
        }
    }
    return dist;
}

void main() {
    Graph* g = createGraph(9);
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
    int* dist = dijkstra(g, 0);
    printf("Vertex \tDistance from Source\n");
    for (int node = 0; node < g->V; node++) {
        printf("%d \t%d\n", node, dist[node]);
    }
}