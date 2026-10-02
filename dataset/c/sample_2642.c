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
        if (dist[v] < min && spt_set[v] == 0)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(Graph* graph, int src, int dist[]) {
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
}

typedef struct {
    Graph* graph;
    int start;
} Sequence;

void generate_sequence(Sequence* seq, int sequence[]) {
    int dist[V];
    dijkstra(seq->graph, seq->start, dist);
    int index = 0;
    for (int i = 0; i < V; i++)
        if (i != seq->start)
            sequence[index++] = dist[i];
}

void main() {
    Graph g;
    g.V = V;
    g.graph[0][1] = 4; g.graph[0][7] = 8;
    g.graph[1][0] = 4; g.graph[1][2] = 8; g.graph[1][7] = 11;
    g.graph[2][1] = 8; g.graph[2][3] = 7; g.graph[2][5] = 4; g.graph[2][8] = 2;
    g.graph[3][2] = 7; g.graph[3][4] = 9; g.graph[3][5] = 14;
    g.graph[4][3] = 9; g.graph[4][5] = 10;
    g.graph[5][2] = 4; g.graph[5][3] = 14; g.graph[5][4] = 10; g.graph[5][6] = 2;
    g.graph[6][5] = 2; g.graph[6][7] = 1; g.graph[6][8] = 6;
    g.graph[7][0] = 8; g.graph[7][1] = 11; g.graph[7][6] = 1; g.graph[7][8] = 7;
    g.graph[8][2] = 2; g.graph[8][6] = 6; g.graph[8][7] = 7;

    Sequence seq;
    seq.graph = &g;
    seq.start = 0;

    int sequence[V-1];
    generate_sequence(&seq, sequence);

    for (int i = 0; i < V-1; i++)
        printf("%d ", sequence[i]);
}