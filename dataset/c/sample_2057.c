#include <stdio.h>
#include <limits.h>

typedef struct {
    int V;
    int** graph;
} Graph;

Graph* Graph_new(int vertices) {
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

int min_distance(int* dist, int* spt_set, int V) {
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < V; v++) {
        if (dist[v] < min && spt_set[v] == 0) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* dijkstra(Graph* g, int src) {
    int* dist = (int*)malloc(g->V * sizeof(int));
    int* spt_set = (int*)malloc(g->V * sizeof(int));
    for (int i = 0; i < g->V; i++) {
        dist[i] = INT_MAX;
        spt_set[i] = 0;
    }
    dist[src] = 0;
    for (int cout = 0; cout < g->V; cout++) {
        int u = min_distance(dist, spt_set, g->V);
        spt_set[u] = 1;
        for (int v = 0; v < g->V; v++) {
            if (g->graph[u][v] && spt_set[v] == 0 && dist[v] > dist[u] + g->graph[u][v]) {
                dist[v] = dist[u] + g->graph[u][v];
            }
        }
    }
    return dist;
}

Graph* initialize_graph() {
    Graph* g = Graph_new(9);
    g->graph[0][1] = 4;
    g->graph[0][7] = 8;
    g->graph[1][0] = 4;
    g->graph[1][2] = 8;
    g->graph[1][7] = 11;
    g->graph[2][1] = 8;
    g->graph[2][3] = 7;
    g->graph[2][5] = 4;
    g->graph[2][8] = 2;
    g->graph[3][2] = 7;
    g->graph[3][4] = 9;
    g->graph[3][5] = 14;
    g->graph[4][3] = 9;
    g->graph[4][5] = 10;
    g->graph[5][2] = 4;
    g->graph[5][3] = 14;
    g->graph[5][4] = 10;
    g->graph[5][6] = 2;
    g->graph[6][5] = 2;
    g->graph[6][7] = 1;
    g->graph[6][8] = 6;
    g->graph[7][0] = 8;
    g->graph[7][1] = 11;
    g->graph[7][6] = 1;
    g->graph[7][8] = 7;
    g->graph[8][2] = 2;
    g->graph[8][6] = 6;
    g->graph[8][7] = 7;
    return g;
}

void main() {
    Graph* g = initialize_graph();
    int* result = dijkstra(g, 0);
    for (int i = 0; i < g->V; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}