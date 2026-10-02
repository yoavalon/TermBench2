#include <stdio.h>
#include <limits.h>

#define V 9

typedef struct {
    int V;
    int graph[V][V];
} Graph;

int min_distance(int dist[], int spt_set[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (spt_set[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(Graph* graph, int src) {
    int dist[V];
    int spt_set[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, spt_set[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = min_distance(dist, spt_set);
        spt_set[u] = 1;

        for (int v = 0; v < V; v++)
            if (!spt_set[v] && graph->graph[u][v] && dist[u] != INT_MAX && dist[u] + graph->graph[u][v] < dist[v])
                dist[v] = dist[u] + graph->graph[u][v];
    }

    for (int i = 0; i < V; i++)
        printf("%d \t", dist[i]);
}

Graph* construct_graph() {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    g->graph[0][1] = 4; g->graph[0][7] = 8;
    g->graph[1][0] = 4; g->graph[1][2] = 8; g->graph[1][7] = 11;
    g->graph[2][1] = 8; g->graph[2][3] = 7; g->graph[2][5] = 4; g->graph[2][8] = 2;
    g->graph[3][2] = 7; g->graph[3][4] = 9; g->graph[3][5] = 14;
    g->graph[4][3] = 9; g->graph[4][5] = 10;
    g->graph[5][2] = 4; g->graph[5][3] = 14; g->graph[5][4] = 10; g->graph[5][6] = 2;
    g->graph[6][5] = 2; g->graph[6][7] = 1; g->graph[6][8] = 6;
    g->graph[7][0] = 8; g->graph[7][1] = 11; g->graph[7][6] = 1; g->graph[7][8] = 7;
    g->graph[8][2] = 2; g->graph[8][6] = 6; g->graph[8][7] = 7;
    return g;
}

int main() {
    Graph* graph = construct_graph();
    dijkstra(graph, 0);
    return 0;
}