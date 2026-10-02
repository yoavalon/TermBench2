#include <stdio.h>
#include <limits.h>

#define V 9

typedef struct Graph {
    int V;
    int graph[V][V];
} Graph;

void Graph_init(Graph* g, int vertices) {
    g->V = vertices;
    for (int row = 0; row < vertices; row++) {
        for (int column = 0; column < vertices; column++) {
            g->graph[row][column] = 0;
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
        if (dist[v] < min && !spt_set[v]) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* Graph_dijkstra(Graph* g, int src) {
    static int dist[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    int spt_set[V];
    for (int i = 0; i < V; i++) {
        spt_set[i] = 0;
    }
    for (int count = 0; count < V; count++) {
        int u = Graph_min_distance(g, dist, spt_set);
        spt_set[u] = 1;
        for (int v = 0; v < V; v++) {
            if (g->graph[u][v] && !spt_set[v] && dist[v] > dist[u] + g->graph[u][v]) {
                dist[v] = dist[u] + g->graph[u][v];
            }
        }
    }
    return dist;
}

Graph* process_graph() {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    Graph_init(g, 9);
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
    return g;
}

void main() {
    Graph* graph = process_graph();
    int* distances = Graph_dijkstra(graph, 0);
    for (int i = 0; i < V; i++) {
        printf("%d ", distances[i]);
    }
    printf("\n");
}