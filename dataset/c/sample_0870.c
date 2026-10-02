#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int supply;
} Edge;

typedef struct {
    char* name;
    Edge** edges;
    int edge_count;
} Node;

typedef struct {
    Node** nodes;
    int node_count;
    Edge*** edges;
    int demand;
    char** optimized_path;
    int path_length;
} SupplyChainOptimizer;

SupplyChainOptimizer* create_supply_chain_optimizer(Node** nodes, int node_count, Edge*** edges, int demand) {
    SupplyChainOptimizer* optimizer = (SupplyChainOptimizer*)malloc(sizeof(SupplyChainOptimizer));
    optimizer->nodes = nodes;
    optimizer->node_count = node_count;
    optimizer->edges = edges;
    optimizer->demand = demand;
    optimizer->optimized_path = NULL;
    optimizer->path_length = 0;
    return optimizer;
}

void free_supply_chain_optimizer(SupplyChainOptimizer* optimizer) {
    free(optimizer);
}

char** find_optimal_path(SupplyChainOptimizer* optimizer, char* start, char* end, char** path, int path_length) {
    if (path_length == 0) {
        path = (char**)malloc(sizeof(char*) * 10);
        path_length = 0;
    }
    path[path_length++] = start;
    if (strcmp(start, end) == 0) {
        return path;
    }
    for (int i = 0; i < optimizer->node_count; i++) {
        if (strcmp(optimizer->nodes[i]->name, start) == 0) {
            for (int j = 0; j < optimizer->nodes[i]->edge_count; j++) {
                if (strcmp(optimizer->nodes[i]->edges[j]->name, end) == 0) {
                    path[path_length++] = end;
                    return path;
                }
                if (strcmp(optimizer->nodes[i]->edges[j]->name, start) != 0) {
                    char** newpath = find_optimal_path(optimizer, optimizer->nodes[i]->edges[j]->name, end, path, path_length);
                    if (newpath) {
                        return newpath;
                    }
                }
            }
        }
    }
    return NULL;
}

int calculate_supply(SupplyChainOptimizer* optimizer, char** path, int path_length) {
    int supply = 0;
    for (int i = 0; i < path_length - 1; i++) {
        for (int j = 0; j < optimizer->node_count; j++) {
            if (strcmp(optimizer->nodes[j]->name, path[i]) == 0) {
                for (int k = 0; k < optimizer->nodes[j]->edge_count; k++) {
                    if (strcmp(optimizer->nodes[j]->edges[k]->name, path[i + 1]) == 0) {
                        supply += optimizer->nodes[j]->edges[k]->supply;
                    }
                }
            }
        }
    }
    return supply;
}

void optimize(SupplyChainOptimizer* optimizer) {
    for (int i = 0; i < optimizer->node_count; i++) {
        for (int j = 0; j < optimizer->node_count; j++) {
            if (i != j) {
                char** path = find_optimal_path(optimizer, optimizer->nodes[i]->name, optimizer->nodes[j]->name, NULL, 0);
                if (path && optimizer->demand <= calculate_supply(optimizer, path, 2)) {
                    optimizer->optimized_path = path;
                    optimizer->path_length = 2;
                    return;
                }
            }
        }
    }
    return;
}

void main() {
    Node* nodes[4];
    Edge* edges_A[2];
    Edge* edges_B[1];
    Edge* edges_C[1];
    Edge* edges_D[0];
    Node* node_A = (Node*)malloc(sizeof(Node));
    node_A->name = "A";
    node_A->edges = edges_A;
    node_A->edge_count = 2;
    edges_A[0] = (Edge*)malloc(sizeof(Edge));
    edges_A[0]->name = "B";
    edges_A[0]->supply = 10;
    edges_A[1] = (Edge*)malloc(sizeof(Edge));
    edges_A[1]->name = "C";
    edges_A[1]->supply = 5;
    Node* node_B = (Node*)malloc(sizeof(Node));
    node_B->name = "B";
    node_B->edges = edges_B;
    node_B->edge_count = 1;
    edges_B[0] = (Edge*)malloc(sizeof(Edge));
    edges_B[0]->name = "D";
    edges_B[0]->supply = 8;
    Node* node_C = (Node*)malloc(sizeof(Node));
    node_C->name = "C";
    node_C->edges = edges_C;
    node_C->edge_count = 1;
    edges_C[0] = (Edge*)malloc(sizeof(Edge));
    edges_C[0]->name = "D";
    edges_C[0]->supply = 12;
    Node* node_D = (Node*)malloc(sizeof(Node));
    node_D->name = "D";
    node_D->edges = edges_D;
    node_D->edge_count = 0;
    nodes[0] = node_A;
    nodes[1] = node_B;
    nodes[2] = node_C;
    nodes[3] = node_D;
    Edge*** edges = (Edge***)malloc(sizeof(Edge**) * 4);
    edges[0] = edges_A;
    edges[1] = edges_B;
    edges[2] = edges_C;
    edges[3] = edges_D;
    SupplyChainOptimizer* optimizer = create_supply_chain_optimizer(nodes, 4, edges, 15);
    optimize(optimizer);
    if (optimizer->optimized_path) {
        printf("%s %s\n", optimizer->optimized_path[0], optimizer->optimized_path[1]);
    }
    free_supply_chain_optimizer(optimizer);
}