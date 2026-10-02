#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char node[2];
    int weight;
} Edge;

typedef struct {
    char node[2];
    Edge edges[10];
    int edge_count;
} Node;

typedef struct {
    Node nodes[5];
    int node_count;
} Graph;

Graph initialize_graph(char nodes[5][2], Edge edges[5][2]) {
    Graph graph;
    graph.node_count = 5;
    for (int i = 0; i < 5; i++) {
        strcpy(graph.nodes[i].node, nodes[i]);
        graph.nodes[i].edge_count = 0;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            if (strcmp(edges[i][j].node, graph.nodes[i].node) == 0) {
                graph.nodes[i].edges[graph.nodes[i].edge_count++] = edges[i][1 - j];
            }
        }
    }
    return graph;
}

typedef struct {
    int cost;
    char path[26];
    int path_length;
} Path;

int compare(const void *a, const void *b) {
    Path *p1 = (Path *)a;
    Path *p2 = (Path *)b;
    return p1->cost - p2->cost;
}

Path find_shortest_path(Graph graph, char start[2], char end[2]) {
    Path paths[100];
    int path_count = 0;
    paths[path_count].cost = 0;
    paths[path_count].path_length = 0;
    strcpy(paths[path_count].path, start);
    path_count++;
    int visited[5] = {0};
    while (path_count > 0) {
        qsort(paths, path_count, sizeof(Path), compare);
        Path current = paths[--path_count];
        visited[current.path[current.path_length - 1] - 'A'] = 1;
        if (strcmp(current.path + current.path_length - 2, end) == 0) {
            return current;
        }
        for (int i = 0; i < graph.nodes[current.path[current.path_length - 1] - 'A'].edge_count; i++) {
            if (!visited[graph.nodes[current.path[current.path_length - 1] - 'A'].edges[i].node[0] - 'A']) {
                Path new_path = current;
                new_path.cost += graph.nodes[current.path[current.path_length - 1] - 'A'].edges[i].weight;
                new_path.path[new_path.path_length++] = graph.nodes[current.path[current.path_length - 1] - 'A'].edges[i].node[0];
                new_path.path[new_path.path_length++] = graph.nodes[current.path[current.path_length - 1] - 'A'].edges[i].node[1];
                paths[path_count++] = new_path;
            }
        }
    }
    Path result;
    result.cost = 999999;
    return result;
}

int main() {
    char nodes[5][2] = { {'A', '\0'}, {'B', '\0'}, {'C', '\0'}, {'D', '\0'}, {'E', '\0'} };
    Edge edges[5][2] = {
        { {'B', '\0'}, 1 },
        { {'C', '\0'}, 2 },
        { {'D', '\0'}, 3 },
        { {'E', '\0'}, 4 },
        { {'A', '\0'}, 5 }
    };
    Graph graph = initialize_graph(nodes, edges);
    char start[2] = {'A', '\0'};
    char end[2] = {'E', '\0'};
    Path result = find_shortest_path(graph, start, end);
    printf("Cost: %d, Path: %s\n", result.cost, result.path);
    return 0;
}