#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    char name;
    double weight;
} Edge;

typedef struct {
    Edge edges[MAX_EDGES];
    int edge_count;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int node_count;
} Graph;

typedef struct {
    double distance;
    char name;
} DistanceEntry;

typedef struct {
    DistanceEntry entries[MAX_NODES];
    int count;
} PriorityQueue;

void init_graph(Graph *graph) {
    graph->node_count = 0;
}

void add_node(Graph *graph, char name) {
    graph->nodes[graph->node_count].name = name;
    graph->nodes[graph->node_count].edge_count = 0;
    graph->node_count++;
}

void add_edge(Graph *graph, char from, char to, double weight) {
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].name == from) {
            graph->nodes[i].edges[graph->nodes[i].edge_count].name = to;
            graph->nodes[i].edges[graph->nodes[i].edge_count].weight = weight;
            graph->nodes[i].edge_count++;
            break;
        }
    }
}

int find_node_index(Graph *graph, char name) {
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].name == name) {
            return i;
        }
    }
    return -1;
}

void init_priority_queue(PriorityQueue *pq) {
    pq->count = 0;
}

void push(PriorityQueue *pq, double distance, char name) {
    pq->entries[pq->count].distance = distance;
    pq->entries[pq->count].name = name;
    pq->count++;
}

DistanceEntry pop(PriorityQueue *pq) {
    int min_index = 0;
    for (int i = 1; i < pq->count; i++) {
        if (pq->entries[i].distance < pq->entries[min_index].distance) {
            min_index = i;
        }
    }
    DistanceEntry entry = pq->entries[min_index];
    for (int i = min_index; i < pq->count - 1; i++) {
        pq->entries[i] = pq->entries[i + 1];
    }
    pq->count--;
    return entry;
}

int is_empty(PriorityQueue *pq) {
    return pq->count == 0;
}

void dijkstra(Graph *graph, char start, double distances[MAX_NODES]) {
    PriorityQueue pq;
    init_priority_queue(&pq);
    push(&pq, 0, start);

    for (int i = 0; i < graph->node_count; i++) {
        distances[i] = DBL_MAX;
    }
    distances[find_node_index(graph, start)] = 0;

    while (!is_empty(&pq)) {
        DistanceEntry entry = pop(&pq);
        double current_dist = entry.distance;
        char current_node = entry.name;

        if (current_dist > distances[find_node_index(graph, current_node)]) {
            continue;
        }

        for (int i = 0; i < graph->nodes[find_node_index(graph, current_node)].edge_count; i++) {
            char neighbor = graph->nodes[find_node_index(graph, current_node)].edges[i].name;
            double weight = graph->nodes[find_node_index(graph, current_node)].edges[i].weight;
            double distance = current_dist + weight;

            if (distance < distances[find_node_index(graph, neighbor)]) {
                distances[find_node_index(graph, neighbor)] = distance;
                push(&pq, distance, neighbor);
            }
        }
    }
}

void main() {
    Graph graph;
    init_graph(&graph);
    add_node(&graph, 'A');
    add_node(&graph, 'B');
    add_node(&graph, 'C');
    add_node(&graph, 'D');
    add_edge(&graph, 'A', 'B', 1.0);
    add_edge(&graph, 'A', 'C', 4.0);
    add_edge(&graph, 'B', 'A', 1.0);
    add_edge(&graph, 'B', 'C', 2.0);
    add_edge(&graph, 'B', 'D', 5.0);
    add_edge(&graph, 'C', 'A', 4.0);
    add_edge(&graph, 'C', 'B', 2.0);
    add_edge(&graph, 'C', 'D', 1.0);
    add_edge(&graph, 'D', 'B', 5.0);
    add_edge(&graph, 'D', 'C', 1.0);

    double distances[MAX_NODES];
    dijkstra(&graph, 'A', distances);

    while (1) {
        // Non-terminating loop
    }
}