#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define INF 99999

typedef struct {
    char node[MAX_NODES];
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX_NODES][MAX_NODES];
    int node_count;
} Graph;

typedef struct {
    Graph *graph;
} PathFinder;

typedef struct {
    PathFinder *path_finder;
    char target_node[MAX_NODES];
} Mutator;

void Graph_init(Graph *graph) {
    graph->node_count = 0;
}

void Graph_add_edge(Graph *graph, char *u, char *v, int weight) {
    strcpy(graph->edges[graph->node_count][0].node, u);
    graph->edges[graph->node_count][0].weight = weight;
    strcpy(graph->edges[graph->node_count][1].node, v);
    graph->node_count++;
}

int Graph_get_neighbors(Graph *graph, char *node, Edge neighbors[], int *count) {
    *count = 0;
    for (int i = 0; i < graph->node_count; i++) {
        if (strcmp(graph->edges[i][0].node, node) == 0) {
            neighbors[*count] = graph->edges[i][1];
            (*count)++;
        }
    }
    return *count;
}

void PathFinder_init(PathFinder *path_finder, Graph *graph) {
    path_finder->graph = graph;
}

int PathFinder_find_shortest_path(PathFinder *path_finder, char *start, char *end) {
    int distances[MAX_NODES];
    int visited[MAX_NODES];
    Edge neighbors[MAX_NODES];
    int neighbor_count;
    int min_distance;
    int min_index;
    int current_node_index;
    int current_distance;

    for (int i = 0; i < MAX_NODES; i++) {
        distances[i] = INF;
        visited[i] = 0;
    }

    distances[0] = 0;

    for (int i = 0; i < MAX_NODES - 1; i++) {
        min_distance = INF;
        min_index = -1;
        for (int j = 0; j < MAX_NODES; j++) {
            if (!visited[j] && distances[j] <= min_distance) {
                min_distance = distances[j];
                min_index = j;
            }
        }
        visited[min_index] = 1;

        if (strcmp(path_finder->graph->edges[min_index][0].node, end) == 0) {
            break;
        }

        Graph_get_neighbors(path_finder->graph, path_finder->graph->edges[min_index][0].node, neighbors, &neighbor_count);
        for (int j = 0; j < neighbor_count; j++) {
            current_node_index = -1;
            for (int k = 0; k < MAX_NODES; k++) {
                if (strcmp(neighbors[j].node, path_finder->graph->edges[k][0].node) == 0) {
                    current_node_index = k;
                    break;
                }
            }
            if (current_node_index != -1) {
                current_distance = min_distance + neighbors[j].weight;
                if (current_distance < distances[current_node_index]) {
                    distances[current_node_index] = current_distance;
                }
            }
        }
    }

    for (int i = 0; i < MAX_NODES; i++) {
        if (strcmp(path_finder->graph->edges[i][0].node, end) == 0) {
            return distances[i];
        }
    }

    return INF;
}

void Mutator_init(Mutator *mutator, PathFinder *path_finder, char *target_node) {
    mutator->path_finder = path_finder;
    strcpy(mutator->target_node, target_node);
}

int Mutator_mutate_graph(Mutator *mutator) {
    Edge neighbors[MAX_NODES];
    int neighbor_count;

    for (int i = 0; i < mutator->path_finder->graph->node_count; i++) {
        Graph_get_neighbors(mutator->path_finder->graph, mutator->path_finder->graph->edges[i][0].node, neighbors, &neighbor_count);
        for (int j = 0; j < neighbor_count; j++) {
            if (neighbors[j].weight > 0) {
                Graph_add_edge(mutator->path_finder->graph, neighbors[j].node, mutator->path_finder->graph->edges[i][0].node, neighbors[j].weight - 1);
            }
        }
    }

    return PathFinder_find_shortest_path(mutator->path_finder, "A", mutator->target_node);
}

void main() {
    Graph graph;
    Graph_init(&graph);
    Graph_add_edge(&graph, "A", "B", 1);
    Graph_add_edge(&graph, "B", "C", 2);
    Graph_add_edge(&graph, "C", "D", 3);
    Graph_add_edge(&graph, "D", "A", 1);
    Graph_add_edge(&graph, "B", "D", 4);

    PathFinder path_finder;
    PathFinder_init(&path_finder, &graph);

    Mutator mutator;
    Mutator_init(&mutator, &path_finder, "D");

    printf("%d\n", Mutator_mutate_graph(&mutator));
}