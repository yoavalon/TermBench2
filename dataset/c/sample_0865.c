#include <stdio.h>
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

void addEdge(Graph* g, int u, int v, int weight) {
    g->graph[u][v] = weight;
    g->graph[v][u] = weight;
}

int minDistance(int* dist, int* visited, int V) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* dijkstra(Graph* g, int start) {
    int* distance = (int*)malloc(g->V * sizeof(int));
    int* visited = (int*)malloc(g->V * sizeof(int));
    for (int i = 0; i < g->V; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }
    distance[start] = 0;

    for (int count = 0; count < g->V - 1; count++) {
        int u = minDistance(distance, visited, g->V);
        visited[u] = 1;
        for (int v = 0; v < g->V; v++) {
            if (!visited[v] && g->graph[u][v] && distance[u] != INT_MAX && distance[u] + g->graph[u][v] < distance[v]) {
                distance[v] = distance[u] + g->graph[u][v];
            }
        }
    }
    return distance;
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
    int start_vertex = 0;
    int* distances = dijkstra(g, start_vertex);
    for (int i = 0; i < g->V; i++) {
        printf("Distance from %d to %d is %d\n", start_vertex, i, distances[i]);
    }
}