#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Node {
    char name;
    double weight;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjacency_list[256];
} Graph;

typedef struct PriorityQueue {
    Node* priority_queue[1024];
    int size;
} PriorityQueue;

void init_graph(Graph* graph) {
    for (int i = 0; i < 256; i++) {
        graph->adjacency_list[i] = NULL;
    }
}

void add_edge(Graph* graph, char from, char to, double weight) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->name = to;
    new_node->weight = weight;
    new_node->next = graph->adjacency_list[from];
    graph->adjacency_list[from] = new_node;
}

int compare(const void* a, const void* b) {
    Node* node_a = *(Node**)a;
    Node* node_b = *(Node**)b;
    return node_a->weight - node_b->weight;
}

void push(PriorityQueue* pq, Node* node) {
    pq->priority_queue[pq->size++] = node;
    qsort(pq->priority_queue, pq->size, sizeof(Node*), compare);
}

Node* pop(PriorityQueue* pq) {
    if (pq->size == 0) return NULL;
    return pq->priority_queue[--pq->size];
}

void dijkstra(Graph* graph, char start) {
    double dist[256];
    for (int i = 0; i < 256; i++) {
        dist[i] = INFINITY;
    }
    dist[start] = 0;

    PriorityQueue pq;
    pq.size = 0;
    Node* start_node = (Node*)malloc(sizeof(Node));
    start_node->name = start;
    start_node->weight = 0;
    push(&pq, start_node);

    while (pq.size > 0) {
        Node* current_node = pop(&pq);
        if (current_node->weight > dist[current_node->name]) continue;

        Node* neighbor = graph->adjacency_list[current_node->name];
        while (neighbor != NULL) {
            double distance = current_node->weight + neighbor->weight;
            if (distance < dist[neighbor->name]) {
                dist[neighbor->name] = distance;
                Node* new_node = (Node*)malloc(sizeof(Node));
                new_node->name = neighbor->name;
                new_node->weight = distance;
                push(&pq, new_node);
            }
            neighbor = neighbor->next;
        }
    }

    for (int i = 0; i < 256; i++) {
        if (dist[i] != INFINITY) {
            printf("%c: %f\n", i, dist[i]);
        }
    }
}

void main() {
    Graph graph;
    init_graph(&graph);
    add_edge(&graph, 'A', 'B', 1.1);
    add_edge(&graph, 'A', 'C', 4.2);
    add_edge(&graph, 'B', 'A', 1.1);
    add_edge(&graph, 'B', 'C', 2.3);
    add_edge(&graph, 'B', 'D', 5.5);
    add_edge(&graph, 'C', 'A', 4.2);
    add_edge(&graph, 'C', 'B', 2.3);
    add_edge(&graph, 'C', 'D', 1.0);
    add_edge(&graph, 'D', 'B', 5.5);
    add_edge(&graph, 'D', 'C', 1.0);

    dijkstra(&graph, 'A');
}