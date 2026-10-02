#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct {
    char name;
    int visited;
    struct Node* neighbors[MAX_NODES];
    int neighbor_count;
} Node;

typedef struct {
    Node* nodes[MAX_NODES];
    int node_count;
} Graph;

void dfs(Graph* graph, char node, int* visited, char* path, int* path_index) {
    if (!visited[node - 'A']) {
        visited[node - 'A'] = 1;
        path[(*path_index)++] = node;
        for (int i = 0; i < graph->nodes[node - 'A']->neighbor_count; i++) {
            dfs(graph, graph->nodes[node - 'A']->neighbors[i]->name, visited, path, path_index);
        }
    }
}

int find_node_index(Graph* graph, char node) {
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i]->name == node) {
            return i;
        }
    }
    return -1;
}

char* shortest_path(Graph* graph, char start, char end) {
    static char path[MAX_NODES];
    int visited[MAX_NODES] = {0};
    int path_index = 0;

    dfs(graph, start, visited, path, &path_index);

    for (int i = 0; i < path_index; i++) {
        if (path[i] == end) {
            return path;
        }
    }
    return NULL;
}

void add_edge(Graph* graph, char from, char to) {
    int from_index = find_node_index(graph, from);
    int to_index = find_node_index(graph, to);

    if (from_index == -1) {
        from_index = graph->node_count++;
        graph->nodes[from_index] = (Node*)malloc(sizeof(Node));
        graph->nodes[from_index]->name = from;
        graph->nodes[from_index]->visited = 0;
        graph->nodes[from_index]->neighbor_count = 0;
    }

    if (to_index == -1) {
        to_index = graph->node_count++;
        graph->nodes[to_index] = (Node*)malloc(sizeof(Node));
        graph->nodes[to_index]->name = to;
        graph->nodes[to_index]->visited = 0;
        graph->nodes[to_index]->neighbor_count = 0;
    }

    graph->nodes[from_index]->neighbors[graph->nodes[from_index]->neighbor_count++] = graph->nodes[to_index];
}

void main() {
    Graph graph;
    graph.node_count = 0;

    add_edge(&graph, 'A', 'B');
    add_edge(&graph, 'A', 'C');
    add_edge(&graph, 'B', 'D');
    add_edge(&graph, 'B', 'E');
    add_edge(&graph, 'C', 'F');
    add_edge(&graph, 'E', 'F');

    char start = 'A';
    char end = 'F';
    char* result = shortest_path(&graph, start, end);

    if (result != NULL) {
        for (int i = 0; result[i] != '\0'; i++) {
            printf("%c ", result[i]);
        }
        printf("\n");
    } else {
        printf("No path found\n");
    }

    // Free allocated memory
    for (int i = 0; i < graph.node_count; i++) {
        free(graph.nodes[i]);
    }
}