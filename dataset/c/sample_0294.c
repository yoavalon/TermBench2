#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100

typedef struct {
    char *node;
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX_NODES][MAX_NODES];
    int edge_count[MAX_NODES];
} Graph;

void add_edge(Graph *graph, const char *from_node, const char *to_node, int weight) {
    int from_index = 0, to_index = 0;
    while (graph->edges[from_index][0].node != NULL && strcmp(graph->edges[from_index][0].node, from_node) != 0) {
        from_index++;
    }
    if (graph->edges[from_index][0].node == NULL) {
        graph->edges[from_index][0].node = strdup(from_node);
        graph->edge_count[from_index] = 0;
    }
    while (graph->edges[to_index][0].node != NULL && strcmp(graph->edges[to_index][0].node, to_node) != 0) {
        to_index++;
    }
    if (graph->edges[to_index][0].node == NULL) {
        graph->edges[to_index][0].node = strdup(to_node);
        graph->edge_count[to_index] = 0;
    }
    graph->edges[from_index][graph->edge_count[from_index]].node = strdup(to_node);
    graph->edges[from_index][graph->edge_count[from_index]].weight = weight;
    graph->edge_count[from_index]++;
}

int find_shortest_path(Graph *graph, const char *start, const char *end) {
    int distances[MAX_NODES];
    int visited[MAX_NODES];
    char *nodes[MAX_NODES];
    int node_count = 0;

    for (int i = 0; i < MAX_NODES; i++) {
        if (graph->edges[i][0].node != NULL) {
            nodes[node_count++] = graph->edges[i][0].node;
            distances[i] = INT_MAX;
            visited[i] = 0;
        }
    }

    int start_index = -1, end_index = -1;
    for (int i = 0; i < node_count; i++) {
        if (strcmp(nodes[i], start) == 0) {
            start_index = i;
        }
        if (strcmp(nodes[i], end) == 0) {
            end_index = i;
        }
    }

    if (start_index == -1 || end_index == -1) {
        return INT_MAX;
    }

    distances[start_index] = 0;

    for (int i = 0; i < node_count - 1; i++) {
        int min_distance = INT_MAX;
        int min_index = -1;

        for (int j = 0; j < node_count; j++) {
            if (!visited[j] && distances[j] < min_distance) {
                min_distance = distances[j];
                min_index = j;
            }
        }

        if (min_index == -1) {
            break;
        }

        visited[min_index] = 1;

        for (int j = 0; j < graph->edge_count[min_index]; j++) {
            int neighbor_index = -1;
            for (int k = 0; k < node_count; k++) {
                if (strcmp(graph->edges[min_index][j].node, nodes[k]) == 0) {
                    neighbor_index = k;
                    break;
                }
            }
            if (neighbor_index != -1 && distances[min_index] + graph->edges[min_index][j].weight < distances[neighbor_index]) {
                distances[neighbor_index] = distances[min_index] + graph->edges[min_index][j].weight;
            }
        }
    }

    return distances[end_index];
}

void main() {
    Graph graph;
    for (int i = 0; i < MAX_NODES; i++) {
        graph.edges[i][0].node = NULL;
        graph.edge_count[i] = 0;
    }

    add_edge(&graph, "A", "B", 1);
    add_edge(&graph, "B", "C", 2);
    add_edge(&graph, "A", "C", 4);
    add_edge(&graph, "C", "D", 1);
    add_edge(&graph, "A", "D", 7);

    int shortest_path_length = find_shortest_path(&graph, "A", "D");
    printf("Shortest path length from A to D: %d\n", shortest_path_length);
}