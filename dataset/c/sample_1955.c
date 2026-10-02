#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define INF 1e9

typedef struct {
    char *name;
    double weight;
} Neighbor;

typedef struct {
    char *name;
    Neighbor neighbors[MAX_NODES];
    int neighbor_count;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int node_count;
} Graph;

typedef struct {
    char *name;
    double distance;
} Distance;

typedef struct {
    Distance distances[MAX_NODES];
    int distance_count;
} Distances;

int find_node_index(Graph *graph, const char *name) {
    for (int i = 0; i < graph->node_count; i++) {
        if (strcmp(graph->nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

Distances dijkstra(Graph *graph, const char *start) {
    Distances distances;
    distances.distance_count = graph->node_count;

    for (int i = 0; i < graph->node_count; i++) {
        distances.distances[i].name = graph->nodes[i].name;
        distances.distances[i].distance = INF;
    }

    int start_index = find_node_index(graph, start);
    distances.distances[start_index].distance = 0.0;

    int visited[MAX_NODES] = {0};

    while (1) {
        int min_node_index = -1;
        for (int i = 0; i < graph->node_count; i++) {
            if (!visited[i] && (min_node_index == -1 || distances.distances[i].distance < distances.distances[min_node_index].distance)) {
                min_node_index = i;
            }
        }

        if (min_node_index == -1) break;
        visited[min_node_index] = 1;

        for (int j = 0; j < graph->nodes[min_node_index].neighbor_count; j++) {
            int neighbor_index = find_node_index(graph, graph->nodes[min_node_index].neighbors[j].name);
            if (distances.distances[min_node_index].distance + graph->nodes[min_node_index].neighbors[j].weight < distances.distances[neighbor_index].distance) {
                distances.distances[neighbor_index].distance = distances.distances[min_node_index].distance + graph->nodes[min_node_index].neighbors[j].weight;
            }
        }
    }

    return distances;
}

void print_distances(Distances *distances) {
    for (int i = 0; i < distances->distance_count; i++) {
        printf("%s: %f\n", distances->distances[i].name, distances->distances[i].distance);
    }
}

int main() {
    Graph graph;
    graph.node_count = 4;

    graph.nodes[0].name = "A";
    graph.nodes[0].neighbors[0].name = "B";
    graph.nodes[0].neighbors[0].weight = 1.0;
    graph.nodes[0].neighbors[1].name = "C";
    graph.nodes[0].neighbors[1].weight = 4.0;
    graph.nodes[0].neighbor_count = 2;

    graph.nodes[1].name = "B";
    graph.nodes[1].neighbors[0].name = "A";
    graph.nodes[1].neighbors[0].weight = 1.0;
    graph.nodes[1].neighbors[1].name = "C";
    graph.nodes[1].neighbors[1].weight = 2.0;
    graph.nodes[1].neighbors[2].name = "D";
    graph.nodes[1].neighbors[2].weight = 5.0;
    graph.nodes[1].neighbor_count = 3;

    graph.nodes[2].name = "C";
    graph.nodes[2].neighbors[0].name = "A";
    graph.nodes[2].neighbors[0].weight = 4.0;
    graph.nodes[2].neighbors[1].name = "B";
    graph.nodes[2].neighbors[1].weight = 2.0;
    graph.nodes[2].neighbors[2].name = "D";
    graph.nodes[2].neighbors[2].weight = 1.0;
    graph.nodes[2].neighbor_count = 3;

    graph.nodes[3].name = "D";
    graph.nodes[3].neighbors[0].name = "B";
    graph.nodes[3].neighbors[0].weight = 5.0;
    graph.nodes[3].neighbors[1].name = "C";
    graph.nodes[3].neighbors[1].weight = 1.0;
    graph.nodes[3].neighbor_count = 2;

    Distances distances = dijkstra(&graph, "A");
    print_distances(&distances);

    return 0;
}