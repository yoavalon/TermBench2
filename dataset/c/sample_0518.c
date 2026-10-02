#include <stdio.h>
#include <limits.h>

#define V 9

typedef struct {
    int V;
    int graph[V][V];
} Graph;

Graph* Graph_new(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->graph[i][j] = 0;
        }
    }
    return g;
}

void Graph_add_edge(Graph* g, int u, int v, int w) {
    g->graph[u][v] = w;
    g->graph[v][u] = w;
}

int Graph_min_distance(Graph* g, int dist[], int spt_set[]) {
    int min = INT_MAX;
    int min_index = 0;
    for (int v = 0; v < g->V; v++) {
        if (dist[v] < min && spt_set[v] == 0) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* dijkstra(Graph* graph, int src) {
    int* dist = (int*)malloc(graph->V * sizeof(int));
    int* spt_set = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        dist[i] = INT_MAX;
        spt_set[i] = 0;
    }
    dist[src] = 0;
    for (int cout = 0; cout < graph->V; cout++) {
        int u = Graph_min_distance(graph, dist, spt_set);
        spt_set[u] = 1;
        for (int v = 0; v < graph->V; v++) {
            if (graph->graph[u][v] && spt_set[v] == 0 && dist[v] > dist[u] + graph->graph[u][v]) {
                dist[v] = dist[u] + graph->graph[u][v];
            }
        }
    }
    return dist;
}

void main() {
    Graph* g = Graph_new(9);
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
    while (1) {
        int src = 0;
        int* dist = dijkstra(g, src);
        printf("Vertex \t Distance from Source\n");
        for (int node = 0; node < g->V; node++) {
            printf("%d \t %d\n", node, dist[node]);
        }
        free(dist);
    }
}