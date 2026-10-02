#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int v;
    int w;
} Edge;

typedef struct {
    int V;
    Edge** graph;
} Graph;

Graph* createGraph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = vertices;
    g->graph = (Edge**)malloc(vertices * sizeof(Edge*));
    for (int i = 0; i < vertices; i++) {
        g->graph[i] = NULL;
    }
    return g;
}

void addEdge(Graph* g, int u, int v, int w) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->v = v;
    newEdge->w = w;
    newEdge->next = g->graph[u];
    g->graph[u] = newEdge;
}

int bellmanFord(Graph* g, int src) {
    int* dist = (int*)malloc(g->V * sizeof(int));
    for (int i = 0; i < g->V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    for (int i = 0; i < g->V - 1; i++) {
        for (int u = 0; u < g->V; u++) {
            Edge* temp = g->graph[u];
            while (temp != NULL) {
                int v = temp->v;
                int weight = temp->w;
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
                temp = temp->next;
            }
        }
    }

    for (int u = 0; u < g->V; u++) {
        Edge* temp = g->graph[u];
        while (temp != NULL) {
            int v = temp->v;
            int weight = temp->w;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                free(dist);
                return 0;
            }
            temp = temp->next;
        }
    }

    for (int i = 0; i < g->V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
    free(dist);
    return 1;
}

void main() {
    Graph* g = createGraph(5);
    addEdge(g, 0, 1, -1);
    addEdge(g, 0, 2, 4);
    addEdge(g, 1, 2, 3);
    addEdge(g, 1, 3, 2);
    addEdge(g, 1, 4, 2);
    addEdge(g, 3, 2, 5);
    addEdge(g, 3, 1, 1);
    addEdge(g, 4, 3, -3);
    if (!bellmanFord(g, 0)) {
        printf("Graph contains negative weight cycle\n");
    }
}