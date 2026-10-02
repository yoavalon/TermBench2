#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    int nodes;
    int **edges;
    int *demand;
    int *supply;
    int **flow;
} SupplyChainOptimizer;

SupplyChainOptimizer* create_optimizer(int nodes, int **edges, int *demand, int *supply) {
    SupplyChainOptimizer *optimizer = (SupplyChainOptimizer*)malloc(sizeof(SupplyChainOptimizer));
    optimizer->nodes = nodes;
    optimizer->edges = edges;
    optimizer->demand = demand;
    optimizer->supply = supply;
    optimizer->flow = (int**)malloc(nodes * sizeof(int*));
    for (int i = 0; i < nodes; i++) {
        optimizer->flow[i] = (int*)calloc(nodes, sizeof(int));
    }
    return optimizer;
}

bool find_path(SupplyChainOptimizer *optimizer, int source, int sink, int *parent) {
    bool *visited = (bool*)calloc(optimizer->nodes, sizeof(bool));
    int *queue = (int*)malloc(optimizer->nodes * sizeof(int));
    int front = 0, rear = 0;
    queue[rear++] = source;
    visited[source] = true;
    while (front != rear) {
        int u = queue[front++];
        for (int v = 0; v < optimizer->nodes; v++) {
            if (!visited[v] && optimizer->flow[u][v] < optimizer->edges[u][v]) {
                queue[rear++] = v;
                visited[v] = true;
                parent[v] = u;
                if (v == sink) {
                    free(queue);
                    free(visited);
                    return true;
                }
            }
        }
    }
    free(queue);
    free(visited);
    return false;
}

int max_flow(SupplyChainOptimizer *optimizer, int source, int sink) {
    int *parent = (int*)malloc(optimizer->nodes * sizeof(int));
    int max_flow_value = 0;
    while (find_path(optimizer, source, sink, parent)) {
        int path_flow = INT_MAX;
        int s = sink;
        while (s != source) {
            path_flow = path_flow < (optimizer->edges[parent[s]][s] - optimizer->flow[parent[s]][s]) ? path_flow : (optimizer->edges[parent[s]][s] - optimizer->flow[parent[s]][s]);
            s = parent[s];
        }
        int v = sink;
        while (v != source) {
            int u = parent[v];
            optimizer->flow[u][v] += path_flow;
            optimizer->flow[v][u] -= path_flow;
            v = parent[v];
        }
        max_flow_value += path_flow;
    }
    free(parent);
    return max_flow_value;
}

void main() {
    int nodes = 6;
    int edges[6][6] = {{0, 16, 13, 0, 0, 0}, {0, 0, 10, 12, 0, 0}, {0, 4, 0, 0, 14, 0}, {0, 0, 9, 0, 0, 20}, {0, 0, 0, 7, 0, 4}, {0, 0, 0, 0, 0, 0}};
    int demand[6] = {0, 0, 0, 0, 0, 25};
    int supply[6] = {25, 0, 0, 0, 0, 0};
    int **edges_ptr = (int**)malloc(nodes * sizeof(int*));
    for (int i = 0; i < nodes; i++) {
        edges_ptr[i] = (int*)malloc(nodes * sizeof(int));
        for (int j = 0; j < nodes; j++) {
            edges_ptr[i][j] = edges[i][j];
        }
    }
    SupplyChainOptimizer *optimizer = create_optimizer(nodes, edges_ptr, demand, supply);
    int result = max_flow(optimizer, 0, 5);
    printf("Maximum flow from source to sink is %d\n", result);
    for (int i = 0; i < nodes; i++) {
        free(optimizer->flow[i]);
        free(edges_ptr[i]);
    }
    free(optimizer->flow);
    free(optimizer->edges);
    free(optimizer);
    free(optimizer);
}