#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Graph {
    int V;
    int** graph;
} Graph;

Graph* Graph_new(int vertices) {
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

void Graph_add_edge(Graph* g, int u, int v, int weight) {
    g->graph[u][v] = weight;
    g->graph[v][u] = weight;
}

int Graph_min_distance(Graph* g, int* dist, int* spt_set) {
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < g->V; v++) {
        if (dist[v] < min && spt_set[v] == 0) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* Graph_dijkstra(Graph* g, int src) {
    int* dist = (int*)malloc(g->V * sizeof(int));
    int* spt_set = (int*)malloc(g->V * sizeof(int));
    for (int i = 0; i < g->V; i++) {
        dist[i] = INT_MAX;
        spt_set[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < g->V - 1; count++) {
        int u = Graph_min_distance(g, dist, spt_set);
        spt_set[u] = 1;
        for (int v = 0; v < g->V; v++) {
            if (g->graph[u][v] && spt_set[v] == 0 && dist[v] > dist[u] + g->graph[u][v]) {
                dist[v] = dist[u] + g->graph[u][v];
            }
        }
    }
    return dist;
}

typedef struct Router {
    Graph* graph;
} Router;

Router* Router_new(Graph* graph) {
    Router* r = (Router*)malloc(sizeof(Router));
    r->graph = graph;
    return r;
}

int* Router_find_shortest_paths(Router* r, int start) {
    return Graph_dijkstra(r->graph, start);
}

typedef struct Network {
    Graph* graph;
    Router* router;
} Network;

Network* Network_new(int vertices) {
    Network* n = (Network*)malloc(sizeof(Network));
    n->graph = Graph_new(vertices);
    n->router = Router_new(n->graph);
    return n;
}

void Network_connect_nodes(Network* n, int u, int v, int weight) {
    Graph_add_edge(n->graph, u, v, weight);
}

int* Network_shortest_paths_from(Network* n, int node) {
    return Router_find_shortest_paths(n->router, node);
}

void main() {
    Network* network = Network_new(5);
    Network_connect_nodes(network, 0, 1, 10);
    Network_connect_nodes(network, 0, 3, 5);
    Network_connect_nodes(network, 1, 2, 1);
    Network_connect_nodes(network, 1, 3, 2);
    Network_connect_nodes(network, 1, 4, 3);
    Network_connect_nodes(network, 2, 4, 1);
    Network_connect_nodes(network, 3, 2, 4);
    Network_connect_nodes(network, 3, 4, 2);
    Network_connect_nodes(network, 4, 2, 6);
    Network_connect_nodes(network, 4, 0, 7);
    int* paths = Network_shortest_paths_from(network, 0);
    for (int i = 0; i < network->graph->V; i++) {
        printf("%d ", paths[i]);
    }
    printf("\n");
    free(paths);
    free(network);
}