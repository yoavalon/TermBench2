#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH 100
#define MAX_NEIGHBORS 100

typedef struct {
    char name;
    int neighbors_count;
    char neighbors[MAX_NEIGHBORS];
} Node;

typedef struct {
    int size;
    Node nodes[MAX_NEIGHBORS];
} Graph;

typedef struct {
    int size;
    char path[MAX_PATH];
} Path;

typedef struct {
    int size;
    Path paths[MAX_PATH];
} Paths;

void dfs(Graph *graph, char node, char visited[], Path *path, Paths *paths) {
    visited[node - 'A'] = 1;
    path->path[path->size++] = node;
    int i;
    for (i = 0; i < graph->nodes[node - 'A'].neighbors_count; i++) {
        char neighbor = graph->nodes[node - 'A'].neighbors[i];
        if (!visited[neighbor - 'A']) {
            dfs(graph, neighbor, visited, path, paths);
        }
    }
    path->size--;
    visited[node - 'A'] = 0;
}

Path shortest_path(Graph *graph, char start, char end) {
    Paths paths = {0};
    Path path = {0};
    char visited[MAX_NEIGHBORS] = {0};
    dfs(graph, start, visited, &path, &paths);

    Path best_path = {0};
    int min_length = MAX_PATH;

    for (int i = 0; i < paths.size; i++) {
        if (paths.paths[i].path[paths.paths[i].size - 1] == end && paths.paths[i].size < min_length) {
            min_length = paths.paths[i].size;
            best_path = paths.paths[i];
        }
    }

    return best_path;
}

int main() {
    Graph graph = {0};
    Node nodes[] = {
        {'A', 2, {'B', 'C'}},
        {'B', 1, {'D'}},
        {'C', 1, {'D'}},
        {'D', 0, {0}}
    };

    for (int i = 0; i < 4; i++) {
        graph.nodes[i] = nodes[i];
        graph.size++;
    }

    char start_node = 'A';
    char end_node = 'D';
    Path result = shortest_path(&graph, start_node, end_node);

    for (int i = 0; i < result.size; i++) {
        printf("%c", result.path[i]);
    }
    printf("\n");

    return 0;
}