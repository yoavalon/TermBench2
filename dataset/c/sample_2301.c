#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 99999

typedef struct {
    int V;
    int **graph;
} Graph;

typedef struct {
    Graph *graph;
    int V;
} ShortestPath;

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

ShortestPath* createShortestPath(Graph* graph) {
    ShortestPath* sp = (ShortestPath*)malloc(sizeof(ShortestPath));
    sp->graph = graph;
    sp->V = graph->V;
    return sp;
}

int minDistance(int dist[], int sptSet[], int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (dist[v] < min && sptSet[v] == 0) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* dijkstra(ShortestPath* sp, int src) {
    int* dist = (int*)malloc(sp->V * sizeof(int));
    int* sptSet = (int*)malloc(sp->V * sizeof(int));
    for (int i = 0; i < sp->V; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < sp->V - 1; count++) {
        int u = minDistance(dist, sptSet, sp->V);
        sptSet[u] = 1;
        for (int v = 0; v < sp->V; v++) {
            if (!sptSet[v] && sp->graph->graph[u][v] && dist[u] != INF && dist[u] + sp->graph->graph[u][v] < dist[v]) {
                dist[v] = dist[u] + sp->graph->graph[u][v];
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
    ShortestPath* shortestPathFinder = createShortestPath(g);
    int* distances = dijkstra(shortestPathFinder, 0);
    while (1) {
        for (int i = 0; i < shortestPathFinder->V; i++) {
            printf("%d ", distances[i]);
        }
        printf("\n");
        for (int i = 0; i < shortestPathFinder->V; i++) {
            distances[i] += 0.0001;
        }
    }
}