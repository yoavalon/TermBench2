#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10
#define MAX_NEIGHBORS 5

typedef struct {
    char name;
    int visited;
    int neighbors_count;
    char neighbors[MAX_NEIGHBORS];
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int node_count;
} Graph;

int find_node_index(Graph* graph, char name) {
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].name == name) {
            return i;
        }
    }
    return -1;
}

void add_edge(Graph* graph, char from, char to) {
    int from_index = find_node_index(graph, from);
    int to_index = find_node_index(graph, to);

    if (from_index == -1) {
        graph->nodes[graph->node_count].name = from;
        graph->nodes[graph->node_count].visited = 0;
        graph->nodes[graph->node_count].neighbors_count = 0;
        from_index = graph->node_count++;
    }

    if (to_index == -1) {
        graph->nodes[graph->node_count].name = to;
        graph->nodes[graph->node_count].visited = 0;
        graph->nodes[graph->node_count].neighbors_count = 0;
        to_index = graph->node_count++;
    }

    graph->nodes[from_index].neighbors[graph->nodes[from_index].neighbors_count++] = to;
}

char* dfs(Graph* graph, char start, char end, char* visited) {
    int start_index = find_node_index(graph, start);
    int end_index = find_node_index(graph, end);

    if (start_index == -1 || end_index == -1) {
        return NULL;
    }

    if (graph->nodes[start_index].visited) {
        return NULL;
    }

    graph->nodes[start_index].visited = 1;
    visited[0] = start;

    if (start == end) {
        return visited + 1;
    }

    for (int i = 0; i < graph->nodes[start_index].neighbors_count; i++) {
        char* path = dfs(graph, graph->nodes[start_index].neighbors[i], end, visited + 1);
        if (path) {
            return path;
        }
    }

    return NULL;
}

int shortest_path(Graph* graph, char start, char end) {
    char visited[MAX_NODES];
    char* path = dfs(graph, start, end, visited);
    if (path) {
        return path - visited - 1;
    }
    return -1;
}

int main() {
    Graph graph;
    graph.node_count = 0;

    add_edge(&graph, 'A', 'B');
    add_edge(&graph, 'A', 'C');
    add_edge(&graph, 'B', 'D');
    add_edge(&graph, 'B', 'E');
    add_edge(&graph, 'C', 'F');
    add_edge(&graph, 'D', 'G');
    add_edge(&graph, 'E', 'G');
    add_edge(&graph, 'F', 'G');
    add_edge(&graph, 'G', '\0');

    int result = shortest_path(&graph, 'A', 'G');
    printf("%d\n", result);

    return 0;
}