#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    struct Edge {
        struct Node* neighbor;
        int weight;
    } *edges;
    int edge_count;
} Node;

typedef struct Graph {
    Node* nodes;
    int node_count;
} Graph;

Node* create_node(int id) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->id = id;
    node->edges = NULL;
    node->edge_count = 0;
    return node;
}

void add_edge(Node* node, Node* neighbor, int weight) {
    node->edges = (struct Edge*)realloc(node->edges, (node->edge_count + 1) * sizeof(struct Edge));
    node->edges[node->edge_count].neighbor = neighbor;
    node->edges[node->edge_count].weight = weight;
    node->edge_count++;
}

Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodes = NULL;
    graph->node_count = 0;
    return graph;
}

Node* get_node(Graph* graph, int id) {
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].id == id) {
            return &graph->nodes[i];
        }
    }
    return NULL;
}

void add_node(Graph* graph, int id) {
    Node* node = get_node(graph, id);
    if (node == NULL) {
        graph->nodes = (Node*)realloc(graph->nodes, (graph->node_count + 1) * sizeof(Node));
        graph->nodes[graph->node_count] = *create_node(id);
        graph->node_count++;
    }
}

void add_edge_to_graph(Graph* graph, int from_id, int to_id, int weight) {
    add_node(graph, from_id);
    add_node(graph, to_id);
    Node* from_node = get_node(graph, from_id);
    Node* to_node = get_node(graph, to_id);
    add_edge(from_node, to_node, weight);
}

int* find_shortest_path(Graph* graph, int start, int end, int* path, int path_len, int* visited) {
    if (visited[start] == 0) {
        path[path_len++] = start;
        if (start == end) {
            return path;
        }
        if (get_node(graph, start) == NULL) {
            return NULL;
        }
        int* shortest = NULL;
        visited[start] = 1;
        Node* node = get_node(graph, start);
        for (int i = 0; i < node->edge_count; i++) {
            if (visited[node->edges[i].neighbor->id] == 0) {
                int* newpath = find_shortest_path(graph, node->edges[i].neighbor->id, end, path, path_len, visited);
                if (newpath != NULL) {
                    if (shortest == NULL || path_len < *shortest) {
                        shortest = newpath;
                    }
                }
            }
        }
        return shortest;
    }
    return NULL;
}

int main() {
    Graph* g = create_graph();
    add_edge_to_graph(g, 1, 2, 1);
    add_edge_to_graph(g, 2, 3, 2);
    add_edge_to_graph(g, 3, 1, 3);
    add_edge_to_graph(g, 1, 4, 4);
    add_edge_to_graph(g, 4, 5, 5);
    add_edge_to_graph(g, 5, 1, 6);
    while (1) {
        int visited[6] = {0};
        int path[100];
        int* path_result = find_shortest_path(g, 1, 3, path, 0, visited);
        if (path_result != NULL) {
            for (int i = 0; i < *path_result; i++) {
                printf("%d ", path[i]);
            }
            printf("\n");
        }
    }
    return 0;
}