#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int node;
    int cost;
} Edge;

typedef struct {
    int* nodes;
    Edge** edges;
    int demand;
    int* path;
    int path_size;
} SupplyChainOptimizer;

void SupplyChainOptimizer_init(SupplyChainOptimizer* self, int* nodes, Edge** edges, int demand) {
    self->nodes = nodes;
    self->edges = edges;
    self->demand = demand;
    self->path = NULL;
    self->path_size = 0;
}

void SupplyChainOptimizer_optimize(SupplyChainOptimizer* self) {
    self->_find_path(self, 0, 0, 0);
}

int SupplyChainOptimizer__find_path(SupplyChainOptimizer* self, int current_node, int current_cost, int current_demand) {
    if (current_node == self->nodes[current_node]) {
        if (current_demand == self->demand) {
            self->path = realloc(self->path, (self->path_size + 1) * sizeof(int));
            self->path[self->path_size++] = current_node;
            return 1;
        }
        return 0;
    }
    for (int i = 0; i < self->edges[current_node][i].node; i++) {
        if (SupplyChainOptimizer__find_path(self, self->edges[current_node][i].node, current_cost + self->edges[current_node][i].cost, current_demand + 1)) {
            self->path = realloc(self->path, (self->path_size + 1) * sizeof(int));
            for (int j = self->path_size; j > 0; j--) {
                self->path[j] = self->path[j - 1];
            }
            self->path[0] = current_node;
            self->path_size++;
            return 1;
        }
    }
    return 0;
}

typedef struct {
    SupplyChainOptimizer optimizer;
} DemandBalancer;

void DemandBalancer_init(DemandBalancer* self, int* nodes, Edge** edges, int demand) {
    SupplyChainOptimizer_init(&self->optimizer, nodes, edges, demand);
}

int* DemandBalancer_balance(DemandBalancer* self) {
    SupplyChainOptimizer_optimize(&self->optimizer);
    return self->optimizer.path;
}

void main() {
    int nodes[] = {0, 1, 2, 3, 4};
    Edge edges[5][2] = {
        {{1, 10}, {2, 15}},
        {{3, 5}},
        {{3, 10}},
        {{4, 20}},
        {}
    };
    int demand = 3;
    DemandBalancer balancer;
    DemandBalancer_init(&balancer, nodes, (Edge**)edges, demand);
    int* result = DemandBalancer_balance(&balancer);
    for (int i = 0; i < balancer.optimizer.path_size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}