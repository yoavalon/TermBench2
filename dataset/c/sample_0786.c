#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* name;
    struct Node* next;
} Node;

typedef struct Graph {
    char* name;
    Node* neighbors;
} Graph;

Graph* create_graph(const char* name) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->name = strdup(name);
    graph->neighbors = NULL;
    return graph;
}

void add_neighbor(Graph* graph, Graph* neighbor) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->name = strdup(neighbor->name);
    new_node->next = graph->neighbors;
    graph->neighbors = new_node;
}

int contains(const char* array[], int size, const char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(array[i], name) == 0) {
            return 1;
        }
    }
    return 0;
}

char** find_path(Graph* graph, const char* start, const char* end, char** path, int* path_size) {
    if (path == NULL) {
        path = (char**)malloc(sizeof(char*) * 100);
        *path_size = 0;
    }
    path[*path_size] = strdup(start);
    (*path_size)++;
    if (strcmp(start, end) == 0) {
        return path;
    }
    Node* current = graph->neighbors;
    while (current != NULL) {
        if (!contains(path, *path_size, current->name)) {
            char** newpath = find_path(graph, current->name, end, path, path_size);
            if (newpath != NULL) {
                return newpath;
            }
        }
        current = current->next;
    }
    return NULL;
}

int shortest_path(Graph* graph, const char* start, const char* end) {
    char** path = NULL;
    int path_size = 0;
    path = find_path(graph, start, end, path, &path_size);
    return path != NULL ? path_size - 1 : -1;
}

void free_path(char** path, int size) {
    for (int i = 0; i < size; i++) {
        free(path[i]);
    }
    free(path);
}

int main() {
    Graph* g = create_graph("A");
    Graph* B = create_graph("B");
    Graph* C = create_graph("C");
    Graph* D = create_graph("D");
    Graph* E = create_graph("E");
    Graph* F = create_graph("F");

    add_neighbor(g, B);
    add_neighbor(g, C);
    add_neighbor(B, D);
    add_neighbor(B, E);
    add_neighbor(C, F);
    add_neighbor(E, F);

    int result = shortest_path(g, "A", "F");
    printf("%d\n", result);

    // Free allocated memory
    free_path(g, 1);
    free_path(B, 1);
    free_path(C, 1);
    free_path(D, 1);
    free_path(E, 1);
    free_path(F, 1);

    return 0;
}