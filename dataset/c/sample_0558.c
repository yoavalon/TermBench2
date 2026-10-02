#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Node {
    char name[2];
    struct Edge* edges;
    struct Node* next;
} Node;

typedef struct Edge {
    Node* target;
    int weight;
    struct Edge* next;
} Edge;

typedef struct Graph {
    Node* nodes;
} Graph;

Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodes = NULL;
    return graph;
}

Node* find_node(Graph* graph, const char* name) {
    Node* current = graph->nodes;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void add_edge(Graph* graph, const char* u, const char* v, int weight) {
    Node* source = find_node(graph, u);
    if (source == NULL) {
        source = (Node*)malloc(sizeof(Node));
        strcpy(source->name, u);
        source->edges = NULL;
        source->next = graph->nodes;
        graph->nodes = source;
    }
    Node* target = find_node(graph, v);
    if (target == NULL) {
        target = (Node*)malloc(sizeof(Node));
        strcpy(target->name, v);
        target->edges = NULL;
        target->next = graph->nodes;
        graph->nodes = target;
    }
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->target = target;
    edge->weight = weight;
    edge->next = source->edges;
    source->edges = edge;
}

int* dijkstra(Graph* graph, const char* start) {
    int distances[26];
    for (int i = 0; i < 26; i++) {
        distances[i] = INT_MAX;
    }
    Node* start_node = find_node(graph, start);
    if (start_node != NULL) {
        distances[start_node - graph->nodes] = 0;
    }
    Node* unvisited = graph->nodes;
    while (unvisited != NULL) {
        Node* current = unvisited;
        int min_distance = INT_MAX;
        for (Node* node = unvisited; node != NULL; node = node->next) {
            if (distances[node - graph->nodes] < min_distance) {
                current = node;
                min_distance = distances[node - graph->nodes];
            }
        }
        unvisited = unvisited->next;
        for (Edge* edge = current->edges; edge != NULL; edge = edge->next) {
            int distance = distances[current - graph->nodes] + edge->weight;
            if (distance < distances[edge->target - graph->nodes]) {
                distances[edge->target - graph->nodes] = distance;
            }
        }
    }
    return distances;
}

void find_shortest_path(Graph* graph, const char* start, const char* end) {
    int* distances = dijkstra(graph, start);
    Node* end_node = find_node(graph, end);
    if (end_node != NULL) {
        char path[26];
        int path_index = 0;
        Node* current = end_node;
        while (current != NULL) {
            path[path_index++] = current->name[0];
            for (Edge* edge = current->edges; edge != NULL; edge = edge->next) {
                if (distances[current - graph->nodes] == distances[edge->target - graph->nodes] + edge->weight) {
                    current = edge->target;
                    break;
                }
            }
            if (current == NULL) {
                break;
            }
        }
        path[path_index++] = start[0];
        for (int i = path_index - 1; i >= 0; i--) {
            printf("%c ", path[i]);
        }
        printf("\n");
    }
    free(distances);
}

int main() {
    Graph* graph = create_graph();
    add_edge(graph, "A", "B", 1);
    add_edge(graph, "B", "C", 2);
    add_edge(graph, "C", "D", 3);
    add_edge(graph, "D", "A", 4);
    find_shortest_path(graph, "A", "D");
    return 0;
}