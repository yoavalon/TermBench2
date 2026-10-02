#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    char node;
    float weight;
} Neighbor;

typedef struct {
    char node;
    float distance;
    Neighbor *neighbors;
    int neighbor_count;
} GraphNode;

typedef struct {
    GraphNode *nodes;
    int node_count;
} Graph;

typedef struct {
    char node;
    float distance;
} PriorityQueueElement;

typedef struct {
    PriorityQueueElement *elements;
    int size;
} PriorityQueue;

void init_priority_queue(PriorityQueue *pq, int capacity) {
    pq->elements = (PriorityQueueElement *)malloc(capacity * sizeof(PriorityQueueElement));
    pq->size = 0;
}

void free_priority_queue(PriorityQueue *pq) {
    free(pq->elements);
}

void push(PriorityQueue *pq, PriorityQueueElement element) {
    pq->elements[pq->size++] = element;
}

PriorityQueueElement pop(PriorityQueue *pq) {
    PriorityQueueElement min = pq->elements[0];
    for (int i = 1; i < pq->size; i++) {
        if (pq->elements[i].distance < min.distance) {
            min = pq->elements[i];
        }
    }
    for (int i = 0; i < pq->size - 1; i++) {
        pq->elements[i] = pq->elements[i + 1];
    }
    pq->size--;
    return min;
}

int is_empty(PriorityQueue *pq) {
    return pq->size == 0;
}

void dijkstra(Graph *graph, char start, float *distances) {
    for (int i = 0; i < graph->node_count; i++) {
        distances[i] = INT_MAX;
    }
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].node == start) {
            distances[i] = 0;
            break;
        }
    }
    PriorityQueue pq;
    init_priority_queue(&pq, graph->node_count);
    push(&pq, (PriorityQueueElement){start, 0});

    while (!is_empty(&pq)) {
        PriorityQueueElement current = pop(&pq);
        for (int i = 0; i < graph->node_count; i++) {
            if (graph->nodes[i].node == current.node) {
                if (current.distance > distances[i]) {
                    continue;
                }
                for (int j = 0; j < graph->nodes[i].neighbor_count; j++) {
                    Neighbor neighbor = graph->nodes[i].neighbors[j];
                    float distance = current.distance + neighbor.weight;
                    for (int k = 0; k < graph->node_count; k++) {
                        if (graph->nodes[k].node == neighbor.node) {
                            if (distance < distances[k]) {
                                distances[k] = distance;
                                push(&pq, (PriorityQueueElement){neighbor.node, distance});
                                break;
                            }
                        }
                    }
                }
                break;
            }
        }
    }
    free_priority_queue(&pq);
}

void main() {
    Graph graph;
    graph.node_count = 4;
    graph.nodes = (GraphNode *)malloc(graph.node_count * sizeof(GraphNode));

    graph.nodes[0].node = 'A';
    graph.nodes[0].neighbor_count = 2;
    graph.nodes[0].neighbors = (Neighbor *)malloc(2 * sizeof(Neighbor));
    graph.nodes[0].neighbors[0] = (Neighbor) {'B', 1.0};
    graph.nodes[0].neighbors[1] = (Neighbor) {'C', 4.0};

    graph.nodes[1].node = 'B';
    graph.nodes[1].neighbor_count = 3;
    graph.nodes[1].neighbors = (Neighbor *)malloc(3 * sizeof(Neighbor));
    graph.nodes[1].neighbors[0] = (Neighbor) {'A', 1.0};
    graph.nodes[1].neighbors[1] = (Neighbor) {'C', 2.0};
    graph.nodes[1].neighbors[2] = (Neighbor) {'D', 5.0};

    graph.nodes[2].node = 'C';
    graph.nodes[2].neighbor_count = 3;
    graph.nodes[2].neighbors = (Neighbor *)malloc(3 * sizeof(Neighbor));
    graph.nodes[2].neighbors[0] = (Neighbor) {'A', 4.0};
    graph.nodes[2].neighbors[1] = (Neighbor) {'B', 2.0};
    graph.nodes[2].neighbors[2] = (Neighbor) {'D', 1.0};

    graph.nodes[3].node = 'D';
    graph.nodes[3].neighbor_count = 2;
    graph.nodes[3].neighbors = (Neighbor *)malloc(2 * sizeof(Neighbor));
    graph.nodes[3].neighbors[0] = (Neighbor) {'B', 5.0};
    graph.nodes[3].neighbors[1] = (Neighbor) {'C', 1.0};

    float distances[graph.node_count];
    dijkstra(&graph, 'A', distances);

    for (int i = 0; i < graph.node_count; i++) {
        printf("%c: %f\n", graph.nodes[i].node, distances[i]);
    }

    for (int i = 0; i < graph.node_count; i++) {
        free(graph.nodes[i].neighbors);
    }
    free(graph.nodes);
}