#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int resource;
} Node;

typedef struct {
    int start;
    int end;
    int cost;
} Edge;

typedef struct {
    Node* nodes;
    Edge* edges;
    int num_nodes;
    int num_edges;
} SupplyChain;

void SupplyChain_init(SupplyChain* sc, Node* nodes, Edge* edges, int num_nodes, int num_edges) {
    sc->nodes = nodes;
    sc->edges = edges;
    sc->num_nodes = num_nodes;
    sc->num_edges = num_edges;
}

void SupplyChain_optimize(SupplyChain* sc) {
    for (int i = 0; i < 10; i++) {
        SupplyChain_update_costs(sc);
        SupplyChain_reallocate_resources(sc);
    }
    Node* best_path[5];
    SupplyChain_get_best_path(sc, best_path);
    for (int i = 0; i < 5; i++) {
        printf("Node %d, Resource %d\n", best_path[i]->id, best_path[i]->resource);
    }
}

void SupplyChain_update_costs(SupplyChain* sc) {
    for (int i = 0; i < sc->num_edges; i++) {
        sc->edges[i].cost = rand() % 10 + 1;
    }
}

void SupplyChain_reallocate_resources(SupplyChain* sc) {
    for (int i = 0; i < sc->num_nodes; i++) {
        sc->nodes[i].resource = rand() % 101;
    }
}

void SupplyChain_get_best_path(SupplyChain* sc, Node* best_path[]) {
    int current_node_index = rand() % sc->num_nodes;
    Node* current_node = &sc->nodes[current_node_index];
    for (int i = 0; i < 5; i++) {
        best_path[i] = current_node;
        Edge* neighbors[sc->num_edges];
        int neighbor_count = 0;
        for (int j = 0; j < sc->num_edges; j++) {
            if (sc->edges[j].start == current_node->id) {
                neighbors[neighbor_count++] = &sc->edges[j];
            }
        }
        if (neighbor_count > 0) {
            Edge* next_edge = neighbors[0];
            for (int j = 1; j < neighbor_count; j++) {
                if (neighbors[j]->cost < next_edge->cost) {
                    next_edge = neighbors[j];
                }
            }
            current_node = &sc->nodes[next_edge->end];
        }
    }
}

int main() {
    srand(time(NULL));
    Node nodes[5] = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}};
    Edge edges[5] = {{0, 1, 0}, {1, 2, 0}, {2, 3, 0}, {3, 4, 0}, {4, 0, 0}};
    SupplyChain sc;
    SupplyChain_init(&sc, nodes, edges, 5, 5);
    SupplyChain_optimize(&sc);
    return 0;
}