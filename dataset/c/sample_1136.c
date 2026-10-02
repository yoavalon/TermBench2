#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int node;
    int weight;
} Edge;

typedef struct {
    int key;
    Edge* edges;
    int size;
    int capacity;
} Graph;

Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->edges = NULL;
    graph->size = 0;
    graph->capacity = 0;
    return graph;
}

void add_edge(Graph* graph, int u, int v, int weight) {
    for (int i = 0; i < graph->size; i++) {
        if (graph->edges[i].key == u) {
            graph->edges[i].edges = (Edge*)realloc(graph->edges[i].edges, (graph->edges[i].size + 1) * sizeof(Edge));
            graph->edges[i].edges[graph->edges[i].size].node = v;
            graph->edges[i].edges[graph->edges[i].size].weight = weight;
            graph->edges[i].size++;
            return;
        }
    }
    graph->edges = (Edge*)realloc(graph->edges, (graph->size + 1) * sizeof(Edge));
    graph->edges[graph->size].key = u;
    graph->edges[graph->size].edges = (Edge*)malloc(sizeof(Edge));
    graph->edges[graph->size].edges[0].node = v;
    graph->edges[graph->size].edges[0].weight = weight;
    graph->edges[graph->size].size = 1;
    graph->size++;
}

Edge* get_neighbors(Graph* graph, int node) {
    for (int i = 0; i < graph->size; i++) {
        if (graph->edges[i].key == node) {
            return graph->edges[i].edges;
        }
    }
    return NULL;
}

int* find_path(Graph* graph, int start, int end, int* path, int path_size) {
    path[path_size++] = start;
    if (start == end) {
        return path;
    }
    Edge* neighbors = get_neighbors(graph, start);
    if (neighbors == NULL) {
        return NULL;
    }
    for (int i = 0; i < graph->size; i++) {
        for (int j = 0; j < neighbors[i].size; j++) {
            if (neighbors[i].edges[j].node != start) {
                int* newpath = find_path(graph, neighbors[i].edges[j].node, end, path, path_size);
                if (newpath != NULL) {
                    return newpath;
                }
            }
        }
    }
    return NULL;
}

int* shortest_path(Graph* graph, int start, int end, int* path, int path_size, int* min_weight) {
    path[path_size++] = start;
    if (start == end) {
        *min_weight = 0;
        return path;
    }
    Edge* neighbors = get_neighbors(graph, start);
    if (neighbors == NULL) {
        *min_weight = 999999;
        return NULL;
    }
    int* min_path = NULL;
    for (int i = 0; i < graph->size; i++) {
        for (int j = 0; j < neighbors[i].size; j++) {
            if (neighbors[i].edges[j].node != start) {
                int* newpath = (int*)malloc(10 * sizeof(int));
                int* new_weight = (int*)malloc(sizeof(int));
                newpath = shortest_path(graph, neighbors[i].edges[j].node, end, newpath, 0, new_weight);
                if (newpath != NULL) {
                    int total_weight = neighbors[i].edges[j].weight + *new_weight;
                    if (total_weight < *min_weight) {
                        *min_weight = total_weight;
                        min_path = (int*)realloc(min_path, (path_size + 1) * sizeof(int));
                        for (int k = 0; k < path_size; k++) {
                            min_path[k] = path[k];
                        }
                        min_path[path_size] = neighbors[i].edges[j].node;
                    }
                    free(newpath);
                    free(new_weight);
                }
            }
        }
    }
    return min_path;
}

int main() {
    Graph* g = create_graph();
    add_edge(g, 1, 2, 7);
    add_edge(g, 1, 3, 9);
    add_edge(g, 2, 3, 10);
    add_edge(g, 2, 4, 15);
    add_edge(g, 3, 4, 11);
    add_edge(g, 3, 6, 2);
    add_edge(g, 4, 5, 6);
    add_edge(g, 5, 6, 9);
    while (1) {
        int* path = (int*)malloc(10 * sizeof(int));
        int* min_weight = (int*)malloc(sizeof(int));
        path = find_path(g, 1, 6, path, 0);
        if (path != NULL) {
            printf("Path found: ");
            for (int i = 0; i < 10; i++) {
                if (path[i] == 0) break;
                printf("%d ", path[i]);
            }
            printf("\n");
        }
        int* min_path = (int*)malloc(10 * sizeof(int));
        min_path = shortest_path(g, 1, 6, min_path, 0, min_weight);
        if (min_path != NULL) {
            printf("Shortest path: ");
            for (int i = 0; i < 10; i++) {
                if (min_path[i] == 0) break;
                printf("%d ", min_path[i]);
            }
            printf("with weight %d\n", *min_weight);
        }
        free(path);
        free(min_path);
        free(min_weight);
    }
    return 0;
}