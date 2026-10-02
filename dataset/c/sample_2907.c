#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Node {
    char name;
    struct Edge *edges;
} Node;

typedef struct Edge {
    Node *neighbor;
    int weight;
    struct Edge *next;
} Edge;

typedef struct Graph {
    Node *nodes;
    int size;
} Graph;

typedef struct Dijkstra {
    Graph *graph;
} Dijkstra;

Graph *create_graph(int size) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->nodes = (Node *)malloc(size * sizeof(Node));
    graph->size = size;
    return graph;
}

void add_node(Graph *graph, char name, int index) {
    graph->nodes[index].name = name;
    graph->nodes[index].edges = NULL;
}

void add_edge(Graph *graph, char node1, char node2, int weight) {
    int index1 = node1 - 'A';
    int index2 = node2 - 'A';
    Edge *edge1 = (Edge *)malloc(sizeof(Edge));
    edge1->neighbor = &graph->nodes[index2];
    edge1->weight = weight;
    edge1->next = graph->nodes[index1].edges;
    graph->nodes[index1].edges = edge1;
    Edge *edge2 = (Edge *)malloc(sizeof(Edge));
    edge2->neighbor = &graph->nodes[index1];
    edge2->weight = weight;
    edge2->next = graph->nodes[index2].edges;
    graph->nodes[index2].edges = edge2;
}

int find_shortest_path(Dijkstra *dijkstra, char start, char end) {
    int distances[26];
    for (int i = 0; i < 26; i++) {
        distances[i] = INT_MAX;
    }
    distances[start - 'A'] = 0;
    Edge *priority_queue[26];
    int queue_size = 1;
    priority_queue[0] = (Edge *)malloc(sizeof(Edge));
    priority_queue[0]->neighbor = &dijkstra->graph->nodes[start - 'A'];
    priority_queue[0]->weight = 0;
    while (queue_size > 0) {
        int min_distance = INT_MAX;
        int min_index = -1;
        for (int i = 0; i < queue_size; i++) {
            if (priority_queue[i]->weight < min_distance) {
                min_distance = priority_queue[i]->weight;
                min_index = i;
            }
        }
        Edge *current_edge = priority_queue[min_index];
        for (int i = min_index; i < queue_size - 1; i++) {
            priority_queue[i] = priority_queue[i + 1];
        }
        queue_size--;
        if (current_edge->weight > distances[current_edge->neighbor->name - 'A']) {
            continue;
        }
        Edge *current = current_edge->neighbor->edges;
        while (current != NULL) {
            int distance = current_edge->weight + current->weight;
            if (distance < distances[current->neighbor->name - 'A']) {
                distances[current->neighbor->name - 'A'] = distance;
                priority_queue[queue_size] = (Edge *)malloc(sizeof(Edge));
                priority_queue[queue_size]->neighbor = current->neighbor;
                priority_queue[queue_size]->weight = distance;
                queue_size++;
            }
            current = current->next;
        }
    }
    return distances[end - 'A'];
}

void main() {
    Graph *graph = create_graph(5);
    add_node(graph, 'A', 0);
    add_node(graph, 'B', 1);
    add_node(graph, 'C', 2);
    add_node(graph, 'D', 3);
    add_node(graph, 'E', 4);
    add_edge(graph, 'A', 'B', 1);
    add_edge(graph, 'A', 'C', 4);
    add_edge(graph, 'B', 'C', 2);
    add_edge(graph, 'B', 'D', 5);
    add_edge(graph, 'C', 'D', 1);
    add_edge(graph, 'D', 'E', 3);
    Dijkstra dijkstra;
    dijkstra.graph = graph;
    while (1) {
        int result = find_shortest_path(&dijkstra, 'A', 'E');
        printf("Shortest path from A to E: %d\n", result);
    }
}