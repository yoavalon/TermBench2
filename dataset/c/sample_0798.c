#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int visited;
} Node;

typedef struct {
    Node **nodes;
    int size;
} Graph;

typedef struct {
    char **path;
    int size;
} Path;

Graph *create_graph(int size) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->nodes = (Node **)malloc(size * sizeof(Node *));
    graph->size = size;
    return graph;
}

void add_node(Graph *graph, char *name, int visited) {
    graph->nodes[graph->size - 1] = (Node *)malloc(sizeof(Node));
    graph->nodes[graph->size - 1]->name = (char *)malloc(strlen(name) + 1);
    strcpy(graph->nodes[graph->size - 1]->name, name);
    graph->nodes[graph->size - 1]->visited = visited;
}

Path *create_path(int size) {
    Path *path = (Path *)malloc(sizeof(Path));
    path->path = (char **)malloc(size * sizeof(char *));
    path->size = 0;
    return path;
}

void add_to_path(Path *path, char *name) {
    path->path[path->size] = (char *)malloc(strlen(name) + 1);
    strcpy(path->path[path->size], name);
    path->size++;
}

Path *dfs(Graph *graph, char *node, Path *path) {
    for (int i = 0; i < graph->size; i++) {
        if (strcmp(graph->nodes[i]->name, node) == 0) {
            graph->nodes[i]->visited = 1;
            break;
        }
    }
    add_to_path(path, node);
    if (path->size == graph->size) {
        return path;
    }
    for (int i = 0; i < graph->size; i++) {
        if (graph->nodes[i]->visited == 0) {
            Path *result = dfs(graph, graph->nodes[i]->name, path);
            if (result) {
                return result;
            }
        }
    }
    return NULL;
}

Path *shortest_path(Graph *graph, char *start) {
    Path *path = create_path(graph->size);
    return dfs(graph, start, path);
}

int main() {
    Graph *graph = create_graph(6);
    add_node(graph, "A", 0);
    add_node(graph, "B", 0);
    add_node(graph, "C", 0);
    add_node(graph, "D", 0);
    add_node(graph, "E", 0);
    add_node(graph, "F", 0);

    Path *result = shortest_path(graph, "A");
    if (result) {
        for (int i = 0; i < result->size; i++) {
            printf("%s ", result->path[i]);
        }
    }
    printf("\n");

    for (int i = 0; i < graph->size; i++) {
        free(graph->nodes[i]->name);
        free(graph->nodes[i]);
    }
    free(graph->nodes);
    free(graph);

    for (int i = 0; i < result->size; i++) {
        free(result->path[i]);
    }
    free(result->path);
    free(result);

    return 0;
}