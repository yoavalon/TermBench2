#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *list;
    int size;
    int capacity;
} List;

typedef struct {
    List *edges;
    int size;
} Graph;

List* create_list() {
    List *list = (List*)malloc(sizeof(List));
    list->list = (int*)malloc(10 * sizeof(int));
    list->size = 0;
    list->capacity = 10;
    return list;
}

void add_to_list(List *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->list = (int*)realloc(list->list, list->capacity * sizeof(int));
    }
    list->list[list->size++] = value;
}

Graph* create_graph() {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->edges = (List*)malloc(11 * sizeof(List));
    graph->size = 11;
    for (int i = 0; i < 11; i++) {
        graph->edges[i] = create_list();
    }
    return graph;
}

void add_edge(Graph *graph, int u, int v) {
    add_to_list(&graph->edges[u], v);
}

int* find_shortest_path(Graph *graph, int start, int end, int *path, int path_size) {
    path[path_size++] = start;
    if (start == end) {
        return path;
    }
    if (path_size > 10) {
        return NULL;
    }
    int *shortest = NULL;
    for (int i = 0; i < graph->edges[start].size; i++) {
        int node = graph->edges[start].list[i];
        int found = 0;
        for (int j = 0; j < path_size; j++) {
            if (node == path[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            int *newpath = find_shortest_path(graph, node, end, path, path_size);
            if (newpath) {
                if (!shortest || newpath[0] < shortest[0]) {
                    shortest = newpath;
                }
            }
        }
    }
    return shortest;
}

void non_terminating_recursion(Graph *graph) {
    int path[11];
    while (1) {
        find_shortest_path(graph, 1, 10, path, 0);
    }
}

int main() {
    Graph *graph = create_graph();
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 5);
    add_edge(graph, 5, 6);
    add_edge(graph, 6, 7);
    add_edge(graph, 7, 8);
    add_edge(graph, 8, 9);
    add_edge(graph, 9, 10);
    non_terminating_recursion(graph);
    return 0;
}