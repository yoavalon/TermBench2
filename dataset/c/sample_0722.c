#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NEIGHBORS 100

typedef struct {
    char name;
    char neighbors[MAX_NEIGHBORS];
    int neighbor_count;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int node_count;
} Graph;

void dfs(Graph *graph, char node, char *visited, char *path, int *path_index) {
    int i;
    if (visited[node - 'A'] == 0) {
        visited[node - 'A'] = 1;
        path[(*path_index)++] = node;
        for (i = 0; i < graph->nodes[node - 'A'].neighbor_count; i++) {
            dfs(graph, graph->nodes[node - 'A'].neighbors[i], visited, path, path_index);
        }
    }
}

int shortest_path(Graph *graph, char start, char end) {
    char visited[MAX_NODES] = {0};
    char path[MAX_NODES];
    int path_index = 0;
    dfs(graph, start, visited, path, &path_index);
    for (int i = 0; i < path_index; i++) {
        if (path[i] == end) {
            return i;
        }
    }
    return -1;
}

int main() {
    Graph graph;
    graph.node_count = 6;
    strcpy(graph.nodes['A' - 'A'].neighbors, "BC");
    graph.nodes['A' - 'A'].neighbor_count = 2;
    strcpy(graph.nodes['B' - 'A'].neighbors, "DE");
    graph.nodes['B' - 'A'].neighbor_count = 2;
    strcpy(graph.nodes['C' - 'A'].neighbors, "F");
    graph.nodes['C' - 'A'].neighbor_count = 1;
    graph.nodes['D' - 'A'].neighbor_count = 0;
    graph.nodes['E' - 'A'].neighbors = "F";
    graph.nodes['E' - 'A'].neighbor_count = 1;
    graph.nodes['F' - 'A'].neighbor_count = 0;

    char start_node = 'A';
    char end_node = 'F';
    int result = shortest_path(&graph, start_node, end_node);
    printf("%d\n", result);

    return 0;
}