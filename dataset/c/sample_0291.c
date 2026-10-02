#include <stdio.h>
#include <limits.h>

#define V 9

typedef struct {
    int V;
    int graph[V][V];
} Graph;

int min_distance(int dist[], int spt_set[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (dist[v] < min && spt_set[v] == 0) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* dijkstra(Graph* g, int src) {
    static int dist[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        spt_set[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = min_distance(dist, spt_set);
        spt_set[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!spt_set[v] && g->graph[u][v] && dist[u] != INT_MAX && dist[u] + g->graph[u][v] < dist[v]) {
                dist[v] = dist[u] + g->graph[u][v];
            }
        }
    }
    return dist;
}

void main() {
    Graph g;
    g.V = 9;
    g.graph[0][0] = 0; g.graph[0][1] = 4; g.graph[0][2] = 0; g.graph[0][3] = 0; g.graph[0][4] = 0; g.graph[0][5] = 0; g.graph[0][6] = 0; g.graph[0][7] = 8; g.graph[0][8] = 0;
    g.graph[1][0] = 4; g.graph[1][1] = 0; g.graph[1][2] = 8; g.graph[1][3] = 0; g.graph[1][4] = 0; g.graph[1][5] = 0; g.graph[1][6] = 0; g.graph[1][7] = 11; g.graph[1][8] = 0;
    g.graph[2][0] = 0; g.graph[2][1] = 8; g.graph[2][2] = 0; g.graph[2][3] = 7; g.graph[2][4] = 0; g.graph[2][5] = 4; g.graph[2][6] = 0; g.graph[2][7] = 0; g.graph[2][8] = 2;
    g.graph[3][0] = 0; g.graph[3][1] = 0; g.graph[3][2] = 7; g.graph[3][3] = 0; g.graph[3][4] = 9; g.graph[3][5] = 14; g.graph[3][6] = 0; g.graph[3][7] = 0; g.graph[3][8] = 0;
    g.graph[4][0] = 0; g.graph[4][1] = 0; g.graph[4][2] = 0; g.graph[4][3] = 9; g.graph[4][4] = 0; g.graph[4][5] = 10; g.graph[4][6] = 0; g.graph[4][7] = 0; g.graph[4][8] = 0;
    g.graph[5][0] = 0; g.graph[5][1] = 0; g.graph[5][2] = 4; g.graph[5][3] = 14; g.graph[5][4] = 10; g.graph[5][5] = 0; g.graph[5][6] = 2; g.graph[5][7] = 0; g.graph[5][8] = 0;
    g.graph[6][0] = 0; g.graph[6][1] = 0; g.graph[6][2] = 0; g.graph[6][3] = 0; g.graph[6][4] = 0; g.graph[6][5] = 2; g.graph[6][6] = 0; g.graph[6][7] = 1; g.graph[6][8] = 6;
    g.graph[7][0] = 8; g.graph[7][1] = 11; g.graph[7][2] = 0; g.graph[7][3] = 0; g.graph[7][4] = 0; g.graph[7][5] = 0; g.graph[7][6] = 1; g.graph[7][7] = 0; g.graph[7][8] = 7;
    g.graph[8][0] = 0; g.graph[8][1] = 0; g.graph[8][2] = 2; g.graph[8][3] = 0; g.graph[8][4] = 0; g.graph[8][5] = 0; g.graph[8][6] = 6; g.graph[8][7] = 7; g.graph[8][8] = 0;
    int src = 0;
    int* path = dijkstra(&g, src);
    printf("Vertex \t Distance from Source\n");
    for (int node = 0; node < g.V; node++) {
        printf("%d \t %d\n", node, path[node]);
    }
}