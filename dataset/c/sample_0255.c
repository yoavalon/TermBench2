#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct {
    int v;
    int weight;
} Edge;

typedef struct {
    int V;
    Edge *graph[MAX_VERTICES];
} Graph;

Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = vertices;
    for (int i = 0; i < vertices; i++) {
        g->graph[i] = NULL;
    }
    return g;
}

void addEdge(Graph* g, int u, int v, int weight) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->v = v;
    newEdge->weight = weight;
    newEdge->next = g->graph[u];
    g->graph[u] = newEdge;

    newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->v = u;
    newEdge->weight = weight;
    newEdge->next = g->graph[v];
    g->graph[v] = newEdge;
}

int* dijkstra(Graph* g, int src) {
    int dist[g->V];
    for (int i = 0; i < g->V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    int visited[g->V];
    for (int i = 0; i < g->V; i++) {
        visited[i] = 0;
    }

    for (int count = 0; count < g->V - 1; count++) {
        int u = -1;
        int minDist = INT_MAX;
        for (int v = 0; v < g->V; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }
        if (u == -1) break;
        visited[u] = 1;

        Edge* temp = g->graph[u];
        while (temp != NULL) {
            int v = temp->v;
            int weight = temp->weight;
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
            temp = temp->next;
        }
    }
    return dist;
}

int findShortestPath(Graph* g, int start, int end) {
    int* distances = dijkstra(g, start);
    return distances[end];
}

void main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);
    int startNode = 0;
    int endNode = 4;
    int shortestPath = findShortestPath(graph, startNode, endNode);
    printf("Shortest path from %d to %d: %d\n", startNode, endNode, shortestPath);
}