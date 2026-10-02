#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int V;
    int **graph;
} Graph;

Graph* create_graph(int vertices) {
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

void add_edge(Graph* g, int u, int v, int w) {
    g->graph[u][v] = w;
    g->graph[v][u] = w;
}

void print_solution(int dist[], int V) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int min_distance(int dist[], int spt_set[], int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (spt_set[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(Graph* g, int src) {
    int *dist = (int*)malloc(g->V * sizeof(int));
    int *spt_set = (int*)malloc(g->V * sizeof(int));
    for (int i = 0; i < g->V; i++) {
        dist[i] = INF;
        spt_set[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < g->V - 1; count++) {
        int u = min_distance(dist, spt_set, g->V);
        spt_set[u] = 1;
        for (int v = 0; v < g->V; v++) {
            if (!spt_set[v] && g->graph[u][v] && dist[u] != INF && dist[u] + g->graph[u][v] < dist[v]) {
                dist[v] = dist[u] + g->graph[u][v];
            }
        }
    }
    print_solution(dist, g->V);
    free(dist);
    free(spt_set);
}

void free_graph(Graph* g) {
    for (int i = 0; i < g->V; i++) {
        free(g->graph[i]);
    }
    free(g->graph);
    free(g);
}

int main() {
    Graph* g = create_graph(9);
    add_edge(g, 0, 1, 4);
    add_edge(g, 0, 7, 8);
    add_edge(g, 1, 2, 8);
    add_edge(g, 1, 7, 11);
    add_edge(g, 2, 3, 7);
    add_edge(g, 2, 8, 2);
    add_edge(g, 2, 5, 4);
    add_edge(g, 3, 4, 9);
    add_edge(g, 3, 5, 14);
    add_edge(g, 4, 5, 10);
    add_edge(g, 5, 6, 2);
    add_edge(g, 6, 7, 1);
    add_edge(g, 6, 8, 6);
    add_edge(g, 7, 8, 7);
    dijkstra(g, 0);
    free_graph(g);
    return 0;
}