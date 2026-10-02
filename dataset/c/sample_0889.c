#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nodes;
    int edges;
    int **capacity;
    int **flow;
} SupplyChainOptimizer;

void SupplyChainOptimizer_init(SupplyChainOptimizer *self, int nodes, int edges, int **capacity) {
    self->nodes = nodes;
    self->edges = edges;
    self->capacity = capacity;
    self->flow = (int **)malloc(nodes * sizeof(int *));
    for (int i = 0; i < nodes; i++) {
        self->flow[i] = (int *)calloc(nodes, sizeof(int));
    }
}

int SupplyChainOptimizer_find_path(SupplyChainOptimizer *self, int source, int sink, int *parent) {
    int *visited = (int *)calloc(self->nodes, sizeof(int));
    int *queue = (int *)malloc(self->nodes * sizeof(int));
    int queue_size = 0;
    queue[queue_size++] = source;
    visited[source] = 1;
    while (queue_size > 0) {
        int u = queue[0];
        for (int ind = 0; ind < self->nodes; ind++) {
            if (!visited[ind] && self->capacity[u][ind] - self->flow[u][ind] > 0) {
                queue[queue_size++] = ind;
                visited[ind] = 1;
                parent[ind] = u;
                if (ind == sink) {
                    free(visited);
                    free(queue);
                    return 1;
                }
            }
        }
        for (int i = 0; i < queue_size - 1; i++) {
            queue[i] = queue[i + 1];
        }
        queue_size--;
    }
    free(visited);
    free(queue);
    return 0;
}

int SupplyChainOptimizer_optimize_flow(SupplyChainOptimizer *self, int source, int sink) {
    int *parent = (int *)calloc(self->nodes, sizeof(int));
    int max_flow = 0;
    while (SupplyChainOptimizer_find_path(self, source, sink, parent)) {
        int path_flow = INT_MAX;
        int s = sink;
        while (s != source) {
            path_flow = path_flow < self->capacity[parent[s]][s] - self->flow[parent[s]][s] ? path_flow : self->capacity[parent[s]][s] - self->flow[parent[s]][s];
            s = parent[s];
        }
        int v = sink;
        while (v != source) {
            int u = parent[v];
            self->flow[u][v] += path_flow;
            self->flow[v][u] -= path_flow;
            v = parent[v];
        }
        max_flow += path_flow;
    }
    free(parent);
    return max_flow;
}

void main() {
    int nodes = 6;
    int edges = 7;
    int capacity[6][6] = {{0, 16, 13, 0, 0, 0}, {0, 0, 10, 12, 0, 0}, {0, 4, 0, 0, 14, 0}, {0, 0, 9, 0, 0, 20}, {0, 0, 0, 7, 0, 4}, {0, 0, 0, 0, 0, 0}};
    int *capacity_ptr[6];
    for (int i = 0; i < 6; i++) {
        capacity_ptr[i] = capacity[i];
    }
    SupplyChainOptimizer optimizer;
    SupplyChainOptimizer_init(&optimizer, nodes, edges, capacity_ptr);
    int result = SupplyChainOptimizer_optimize_flow(&optimizer, 0, 5);
    printf("The maximum possible flow is %d \n", result);
}