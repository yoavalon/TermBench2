#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name;
    struct Edge *edges;
    struct Node *next;
} Node;

typedef struct Edge {
    Node *node;
    int weight;
    struct Edge *next;
} Edge;

typedef struct Graph {
    Node *nodes;
} Graph;

Graph *create_graph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->nodes = NULL;
    return graph;
}

void add_node(Graph *graph, char node) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->name = node;
    new_node->edges = NULL;
    new_node->next = graph->nodes;
    graph->nodes = new_node;
}

void add_edge(Graph *graph, char node1, char node2, int weight) {
    Node *n1 = graph->nodes, *n2 = graph->nodes;
    while (n1 && n1->name != node1) n1 = n1->next;
    while (n2 && n2->name != node2) n2 = n2->next;
    if (n1 && n2) {
        Edge *new_edge1 = (Edge *)malloc(sizeof(Edge));
        new_edge1->node = n2;
        new_edge1->weight = weight;
        new_edge1->next = n1->edges;
        n1->edges = new_edge1;

        Edge *new_edge2 = (Edge *)malloc(sizeof(Edge));
        new_edge2->node = n1;
        new_edge2->weight = weight;
        new_edge2->next = n2->edges;
        n2->edges = new_edge2;
    }
}

Edge *find_neighbors(Graph *graph, char node) {
    Node *n = graph->nodes;
    while (n && n->name != node) n = n->next;
    if (n) return n->edges;
    return NULL;
}

void shortest_path_helper(Graph *graph, char start, char end, char *path, int path_len, char *shortest_path, int *shortest_len) {
    path[path_len++] = start;
    if (start == end) {
        if (shortest_len == NULL || path_len < *shortest_len) {
            memcpy(shortest_path, path, path_len);
            *shortest_len = path_len;
        }
        return;
    }
    Edge *neighbors = find_neighbors(graph, start);
    while (neighbors) {
        char neighbor = neighbors->node->name;
        int i;
        for (i = 0; i < path_len; i++) {
            if (path[i] == neighbor) break;
        }
        if (i == path_len) {
            shortest_path_helper(graph, neighbor, end, path, path_len, shortest_path, shortest_len);
        }
        neighbors = neighbors->next;
    }
}

void shortest_path(Graph *graph, char start, char end) {
    char path[26];
    char shortest_path[26];
    int shortest_len = -1;
    shortest_path_helper(graph, start, end, path, 0, shortest_path, &shortest_len);
    for (int i = 0; i < shortest_len; i++) {
        printf("%c ", shortest_path[i]);
    }
    printf("\n");
}

int main() {
    Graph *g = create_graph();
    char nodes[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    for (int i = 0; i < 6; i++) {
        add_node(g, nodes[i]);
    }
    char edges[][3] = {{'A', 'B', 1}, {'A', 'C', 4}, {'B', 'C', 2}, {'B', 'D', 5}, {'C', 'D', 1}, {'D', 'E', 3}, {'E', 'F', 2}};
    for (int i = 0; i < 7; i++) {
        add_edge(g, edges[i][0], edges[i][1], edges[i][2]);
    }
    shortest_path(g, 'A', 'F');
    return 0;
}