#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_NODES 100

typedef struct {
    int to;
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX_NODES];
    int edge_count;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int node_count;
} Graph;

void init_graph(Graph *graph) {
    graph->node_count = 0;
}

void add_node(Graph *graph, int node) {
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].edge_count == 0) {
            graph->node_count++;
            return;
        }
    }
    graph->node_count++;
}

void add_edge(Graph *graph, int from_node, int to_node, int weight) {
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].edge_count == 0) {
            continue;
        }
        if (i == from_node) {
            graph->nodes[i].edges[graph->nodes[i].edge_count].to = to_node;
            graph->nodes[i].edges[graph->nodes[i].edge_count].weight = weight;
            graph->nodes[i].edge_count++;
            return;
        }
    }
}

int dijkstra(Graph *graph, int start, int end) {
    int distances[MAX_NODES];
    bool visited[MAX_NODES];
    for (int i = 0; i < graph->node_count; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }
    distances[start] = 0;

    for (int count = 0; count < graph->node_count - 1; count++) {
        int min_distance = INT_MAX, min_index;

        for (int v = 0; v < graph->node_count; v++) {
            if (!visited[v] && distances[v] <= min_distance) {
                min_distance = distances[v];
                min_index = v;
            }
        }

        visited[min_index] = true;

        for (int i = 0; i < graph->nodes[min_index].edge_count; i++) {
            int v = graph->nodes[min_index].edges[i].to;
            if (!visited[v] && graph->nodes[min_index].edges[i].weight && distances[min_index] != INT_MAX && distances[min_index] + graph->nodes[min_index].edges[i].weight < distances[v]) {
                distances[v] = distances[min_index] + graph->nodes[min_index].edges[i].weight;
            }
        }
    }
    return distances[end];
}

void main() {
    Graph graph;
    init_graph(&graph);
    add_node(&graph, 1);
    add_node(&graph, 2);
    add_node(&graph, 3);
    add_node(&graph, 4);
    add_edge(&graph, 0, 1, 10);
    add_edge(&graph, 0, 2, 15);
    add_edge(&graph, 1, 2, 7);
    add_edge(&graph, 1, 3, 12);
    add_edge(&graph, 2, 3, 10);
    printf("%d\n", dijkstra(&graph, 0, 3));
}