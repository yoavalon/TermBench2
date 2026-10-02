#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int *values;
    int size;
    int capacity;
} List;

typedef struct {
    List *edges;
    int capacity;
} Graph;

List* create_list() {
    List *list = (List *)malloc(sizeof(List));
    list->values = (int *)malloc(2 * sizeof(int));
    list->size = 0;
    list->capacity = 2;
    return list;
}

void add_to_list(List *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->values = (int *)realloc(list->values, list->capacity * sizeof(int));
    }
    list->values[list->size++] = value;
}

Graph* create_graph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->edges = (List *)malloc(10 * sizeof(List));
    graph->capacity = 10;
    for (int i = 0; i < 10; i++) {
        graph->edges[i] = *create_list();
    }
    return graph;
}

void add_edge(Graph *graph, int u, int v) {
    if (u >= graph->capacity) {
        graph->capacity *= 2;
        graph->edges = (List *)realloc(graph->edges, graph->capacity * sizeof(List));
        for (int i = graph->capacity / 2; i < graph->capacity; i++) {
            graph->edges[i] = *create_list();
        }
    }
    add_to_list(&graph->edges[u], v);
}

int* get_neighbors(Graph *graph, int node, int *size) {
    if (node >= graph->capacity) {
        *size = 0;
        return NULL;
    }
    List *list = &graph->edges[node];
    *size = list->size;
    return list->values;
}

void recursive_dfs(Graph *graph, int start, int *path, int *path_size, int *visited) {
    visited[start] = 1;
    path[(*path_size)++] = start;
    int size;
    int *neighbors = get_neighbors(graph, start, &size);
    for (int i = 0; i < size; i++) {
        if (!visited[neighbors[i]]) {
            recursive_dfs(graph, neighbors[i], path, path_size, visited);
        }
    }
}

void find_non_terminating_path(Graph *graph, int start, int *current_path, int *current_path_size, int *visited) {
    visited[start] = 1;
    current_path[(*current_path_size)++] = start;
    int size;
    int *neighbors = get_neighbors(graph, start, &size);
    for (int i = 0; i < size; i++) {
        if (!visited[neighbors[i]]) {
            find_non_terminating_path(graph, neighbors[i], current_path, current_path_size, visited);
        } else {
            find_non_terminating_path(graph, neighbors[i], current_path, current_path_size, visited);
        }
    }
}

int main() {
    Graph *graph = create_graph();
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 2);
    int visited[10] = {0};
    int path[10] = {0};
    int path_size = 0;
    int start_node = 1;
    find_non_terminating_path(graph, start_node, path, &path_size, visited);
    while (1) {
    }
    return 0;
}