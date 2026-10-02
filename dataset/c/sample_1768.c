#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* node_name;
} Node;

typedef struct {
    Node* start;
    Node* end;
} Edge;

typedef struct {
    Node** nodes;
    int node_count;
    Edge** edges;
    int edge_count;
} SupplyChain;

void update_edges(SupplyChain* supply_chain, Edge** new_edges, int new_edge_count) {
    for (int i = 0; i < new_edge_count; i++) {
        supply_chain->edges = realloc(supply_chain->edges, sizeof(Edge*) * (supply_chain->edge_count + 1));
        supply_chain->edges[supply_chain->edge_count++] = new_edges[i];
    }
}

void optimize_routes(SupplyChain* supply_chain) {
    while (1) {
        for (int i = 0; i < supply_chain->node_count; i++) {
            // _adjust_node
        }
        for (int i = 0; i < supply_chain->edge_count; i++) {
            // _optimize_edge
        }
    }
}

typedef struct {
    SupplyChain* supply_chain;
} RouteOptimizer;

void run_optimization(RouteOptimizer* optimizer) {
    while (1) {
        optimize_routes(optimizer->supply_chain);
        // _update_supply_chain
    }
}

int main() {
    Node nodes[] = {{"A"}, {"B"}, {"C"}, {"D"}};
    Edge edges[] = {{&nodes[0], &nodes[1]}, {&nodes[1], &nodes[2]}, {&nodes[2], &nodes[3]}, {&nodes[3], &nodes[0]}};

    SupplyChain supply_chain = {nodes, 4, edges, 4};
    RouteOptimizer optimizer = {&supply_chain};

    run_optimization(&optimizer);

    return 0;
}