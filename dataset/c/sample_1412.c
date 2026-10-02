#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    char* node1;
    char* node2;
    int weight;
} Edge;

typedef struct {
    Edge** edges;
    int size;
} Graph;

Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->edges = NULL;
    graph->size = 0;
    return graph;
}

void add_edge(Graph* graph, char* node1, char* node2, int weight) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->node1 = strdup(node1);
    edge->node2 = strdup(node2);
    edge->weight = weight;
    graph->edges = (Edge**)realloc(graph->edges, (graph->size + 1) * sizeof(Edge*));
    graph->edges[graph->size++] = edge;
}

typedef struct {
    char* node;
    int distance;
} NodeDistance;

typedef struct {
    Graph* graph;
} Dijkstra;

Dijkstra* create_dijkstra(Graph* graph) {
    Dijkstra* dijkstra = (Dijkstra*)malloc(sizeof(Dijkstra));
    dijkstra->graph = graph;
    return dijkstra;
}

int find_index(char* node, char* nodes[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(node, nodes[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int find_shortest_path(Dijkstra* dijkstra, char* start, char* end) {
    int num_nodes = dijkstra->graph->size;
    char* nodes[num_nodes];
    NodeDistance distances[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        nodes[i] = dijkstra->graph->edges[i]->node1;
        distances[i].node = nodes[i];
        distances[i].distance = INT_MAX;
    }
    int start_index = find_index(start, nodes, num_nodes);
    distances[start_index].distance = 0;

    while (num_nodes > 0) {
        int min_distance = INT_MAX;
        int min_index = -1;
        for (int i = 0; i < num_nodes; i++) {
            if (distances[i].distance < min_distance) {
                min_distance = distances[i].distance;
                min_index = i;
            }
        }
        if (strcmp(nodes[min_index], end) == 0) {
            break;
        }
        for (int i = 0; i < dijkstra->graph->size; i++) {
            if (strcmp(dijkstra->graph->edges[i]->node1, nodes[min_index]) == 0) {
                int neighbor_index = find_index(dijkstra->graph->edges[i]->node2, nodes, num_nodes);
                if (neighbor_index != -1 && distances[neighbor_index].distance > distances[min_index].distance + dijkstra->graph->edges[i]->weight) {
                    distances[neighbor_index].distance = distances[min_index].distance + dijkstra->graph->edges[i]->weight;
                }
            } else if (strcmp(dijkstra->graph->edges[i]->node2, nodes[min_index]) == 0) {
                int neighbor_index = find_index(dijkstra->graph->edges[i]->node1, nodes, num_nodes);
                if (neighbor_index != -1 && distances[neighbor_index].distance > distances[min_index].distance + dijkstra->graph->edges[i]->weight) {
                    distances[neighbor_index].distance = distances[min_index].distance + dijkstra->graph->edges[i]->weight;
                }
            }
        }
        for (int i = min_index; i < num_nodes - 1; i++) {
            nodes[i] = nodes[i + 1];
            distances[i] = distances[i + 1];
        }
        num_nodes--;
    }

    int end_index = find_index(end, nodes, num_nodes);
    return distances[end_index].distance;
}

int main() {
    Graph* g = create_graph();
    add_edge(g, "A", "B", 1);
    add_edge(g, "B", "C", 2);
    add_edge(g, "C", "D", 3);
    add_edge(g, "A", "D", 10);
    add_edge(g, "B", "D", 4);
    Dijkstra* dijkstra = create_dijkstra(g);
    int result = find_shortest_path(dijkstra, "A", "D");
    printf("%d\n", result);
    return 0;
}