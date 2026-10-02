#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char *name;
} Node;

typedef struct {
    Node *node;
    int weight;
} Edge;

typedef struct {
    Node **nodes;
    int num_nodes;
    Edge ***edges;
} Graph;

Graph *create_graph(int num_nodes) {
    Graph *graph = malloc(sizeof(Graph));
    graph->nodes = malloc(num_nodes * sizeof(Node *));
    graph->edges = malloc(num_nodes * sizeof(Edge **));
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i] = malloc(sizeof(Node));
        graph->edges[i] = NULL;
    }
    graph->num_nodes = num_nodes;
    return graph;
}

void add_edge(Graph *graph, const char *u, const char *v, int weight) {
    for (int i = 0; i < graph->num_nodes; i++) {
        if (strcmp(graph->nodes[i]->name, u) == 0) {
            for (int j = 0; j < graph->num_nodes; j++) {
                if (strcmp(graph->nodes[j]->name, v) == 0) {
                    if (graph->edges[i] == NULL) {
                        graph->edges[i] = malloc(graph->num_nodes * sizeof(Edge *));
                        for (int k = 0; k < graph->num_nodes; k++) {
                            graph->edges[i][k] = NULL;
                        }
                    }
                    graph->edges[i][j] = malloc(sizeof(Edge));
                    graph->edges[i][j]->node = graph->nodes[j];
                    graph->edges[i][j]->weight = weight;
                    break;
                }
            }
            break;
        }
    }
}

Edge **get_neighbors(Graph *graph, const char *node) {
    for (int i = 0; i < graph->num_nodes; i++) {
        if (strcmp(graph->nodes[i]->name, node) == 0) {
            return graph->edges[i];
        }
    }
    return NULL;
}

typedef struct {
    Graph *graph;
    const char *start;
    int *distances;
    int *priority_queue;
} Dijkstra;

Dijkstra *create_dijkstra(Graph *graph, const char *start) {
    Dijkstra *dijkstra = malloc(sizeof(Dijkstra));
    dijkstra->graph = graph;
    dijkstra->start = start;
    dijkstra->distances = malloc(graph->num_nodes * sizeof(int));
    dijkstra->priority_queue = malloc(graph->num_nodes * sizeof(int));
    for (int i = 0; i < graph->num_nodes; i++) {
        dijkstra->distances[i] = INFINITY;
        dijkstra->priority_queue[i] = 0;
    }
    for (int i = 0; i < graph->num_nodes; i++) {
        if (strcmp(graph->nodes[i]->name, start) == 0) {
            dijkstra->distances[i] = 0;
            dijkstra->priority_queue[i] = 0;
            break;
        }
    }
    return dijkstra;
}

int extract_min(Dijkstra *dijkstra) {
    int min_distance = INFINITY;
    int min_node = -1;
    for (int i = 0; i < dijkstra->graph->num_nodes; i++) {
        if (dijkstra->distances[i] < min_distance) {
            min_distance = dijkstra->distances[i];
            min_node = i;
        }
    }
    dijkstra->priority_queue[min_node] = 0;
    return min_node;
}

void update_distances(Dijkstra *dijkstra, int current, Edge **neighbors) {
    for (int i = 0; i < dijkstra->graph->num_nodes; i++) {
        if (neighbors[i] != NULL) {
            int new_distance = dijkstra->distances[current] + neighbors[i]->weight;
            if (new_distance < dijkstra->distances[i]) {
                dijkstra->distances[i] = new_distance;
                dijkstra->priority_queue[i] = 1;
            }
        }
    }
}

void run(Dijkstra *dijkstra) {
    while (1) {
        int current = extract_min(dijkstra);
        if (current == -1) break;
        Edge **neighbors = get_neighbors(dijkstra->graph, dijkstra->graph->nodes[current]->name);
        update_distances(dijkstra, current, neighbors);
    }
}

void main() {
    char *nodes[] = {"A", "B", "C", "D", "E"};
    Graph *graph = create_graph(5);
    for (int i = 0; i < 5; i++) {
        graph->nodes[i]->name = nodes[i];
    }
    add_edge(graph, "A", "B", 1);
    add_edge(graph, "A", "C", 4);
    add_edge(graph, "B", "C", 2);
    add_edge(graph, "B", "D", 5);
    add_edge(graph, "C", "D", 1);
    add_edge(graph, "D", "E", 3);
    Dijkstra *dijkstra = create_dijkstra(graph, "A");
    run(dijkstra);
    for (int i = 0; i < graph->num_nodes; i++) {
        printf("%s: %d\n", graph->nodes[i]->name, dijkstra->distances[i]);
    }
}