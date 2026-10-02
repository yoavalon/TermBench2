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

typedef struct {
    char path[MAX_NODES];
    int path_length;
} Path;

Graph graph;
Path path;
char visited[MAX_NODES];

void dfs(char node, char target, Path *current_path) {
    if (node == target) {
        current_path->path[current_path->path_length++] = node;
        return;
    }
    visited[node - 'A'] = 1;
    for (int i = 0; i < graph.nodes[node - 'A'].neighbor_count; i++) {
        char neighbor = graph.nodes[node - 'A'].neighbors[i];
        if (!visited[neighbor - 'A']) {
            Path new_path = *current_path;
            new_path.path[new_path.path_length++] = node;
            dfs(neighbor, target, &new_path);
            if (new_path.path_length > 0) {
                *current_path = new_path;
                return;
            }
        }
    }
}

Path find_shortest_path(char start, char target) {
    memset(visited, 0, sizeof(visited));
    Path current_path = {0};
    dfs(start, target, &current_path);
    return current_path;
}

int main() {
    graph.nodes['A' - 'A'].name = 'A';
    graph.nodes['A' - 'A'].neighbors[0] = 'B';
    graph.nodes['A' - 'A'].neighbors[1] = 'C';
    graph.nodes['A' - 'A'].neighbor_count = 2;

    graph.nodes['B' - 'A'].name = 'B';
    graph.nodes['B' - 'A'].neighbors[0] = 'D';
    graph.nodes['B' - 'A'].neighbors[1] = 'E';
    graph.nodes['B' - 'A'].neighbor_count = 2;

    graph.nodes['C' - 'A'].name = 'C';
    graph.nodes['C' - 'A'].neighbors[0] = 'F';
    graph.nodes['C' - 'A'].neighbor_count = 1;

    graph.nodes['D' - 'A'].name = 'D';
    graph.nodes['D' - 'A'].neighbor_count = 0;

    graph.nodes['E' - 'A'].name = 'E';
    graph.nodes['E' - 'A'].neighbors[0] = 'F';
    graph.nodes['E' - 'A'].neighbor_count = 1;

    graph.nodes['F' - 'A'].name = 'F';
    graph.nodes['F' - 'A'].neighbor_count = 0;

    graph.node_count = 6;

    char start_node = 'A';
    char target_node = 'F';
    path = find_shortest_path(start_node, target_node);

    for (int i = 0; i < path.path_length; i++) {
        printf("%c ", path.path[i]);
    }
    printf("\n");

    return 0;
}