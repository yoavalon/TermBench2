#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int V;
    int **graph;
} Graph;

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

int minDistance(int dist[], int sptSet[], int V) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* dijkstra(Graph* graph, int src) {
    int* dist = (int*)malloc(graph->V * sizeof(int));
    int* sptSet = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < graph->V - 1; count++) {
        int u = minDistance(dist, sptSet, graph->V);
        sptSet[u] = 1;
        for (int v = 0; v < graph->V; v++) {
            if (!sptSet[v] && graph->graph[u][v] && dist[u] != INF && dist[u] + graph->graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->graph[u][v];
            }
        }
    }
    return dist;
}

typedef struct {
    int** data;
    int rows;
    int cols;
} DataMutator;

DataMutator* createDataMutator(int** data, int rows, int cols) {
    DataMutator* dm = (DataMutator*)malloc(sizeof(DataMutator));
    dm->data = data;
    dm->rows = rows;
    dm->cols = cols;
    return dm;
}

Graph* transform(DataMutator* mutator) {
    Graph* graph = createGraph(mutator->rows);
    for (int i = 0; i < mutator->rows; i++) {
        for (int j = 0; j < mutator->cols; j++) {
            graph->graph[i][j] = mutator->data[i][j];
        }
    }
    return graph;
}

void main() {
    int data[9][9] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };
    DataMutator* mutator = createDataMutator((int**)data, 9, 9);
    Graph* graph = transform(mutator);
    int* dist = dijkstra(graph, 0);
    for (int node = 0; node < graph->V; node++) {
        printf("Distance to %d is %d\n", node, dist[node]);
    }
}