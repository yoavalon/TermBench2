#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    char name;
    int cost;
} Edge;

typedef struct {
    Edge edges[MAX_EDGES];
    int edge_count;
} Node;

typedef struct {
    int cost;
    char name;
    char path[MAX_NODES];
    int path_length;
} PriorityQueueElement;

typedef struct {
    PriorityQueueElement elements[MAX_NODES];
    int size;
} PriorityQueue;

void swap(PriorityQueueElement *a, PriorityQueueElement *b) {
    PriorityQueueElement temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(PriorityQueue *q, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < q->size && q->elements[left].cost < q->elements[smallest].cost) {
        smallest = left;
    }

    if (right < q->size && q->elements[right].cost < q->elements[smallest].cost) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&q->elements[i], &q->elements[smallest]);
        heapify(q, smallest);
    }
}

void extract_min(PriorityQueue *q) {
    if (q->size <= 0) return;
    if (q->size == 1) {
        q->size--;
        return;
    }
    q->elements[0] = q->elements[q->size - 1];
    q->size--;
    heapify(q, 0);
}

void insert(PriorityQueue *q, PriorityQueueElement element) {
    if (q->size == MAX_NODES) return;
    int i = q->size;
    q->size++;
    while (i > 0 && q->elements[(i - 1) / 2].cost > element.cost) {
        q->elements[i] = q->elements[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    q->elements[i] = element;
}

int dijkstra(Node graph[], char start, char end, int node_count) {
    PriorityQueue q;
    q.size = 0;
    PriorityQueueElement start_element = {0, start, {start}, 1};
    insert(&q, start_element);
    int seen[MAX_NODES] = {0};
    seen[start - 'A'] = 1;

    while (q.size > 0) {
        PriorityQueueElement current = q.elements[0];
        extract_min(&q);
        if (current.name == end) {
            printf("Path from %c to %c: ", start, end);
            for (int i = 0; i < current.path_length; i++) {
                printf("%c ", current.path[i]);
            }
            printf("with cost: %d\n", current.cost);
            return current.cost;
        }
        for (int i = 0; i < graph[current.name - 'A'].edge_count; i++) {
            Edge next_edge = graph[current.name - 'A'].edges[i];
            if (!seen[next_edge.name - 'A']) {
                PriorityQueueElement next_element = {current.cost + next_edge.cost, next_edge.name, {0}, current.path_length + 1};
                for (int j = 0; j < current.path_length; j++) {
                    next_element.path[j] = current.path[j];
                }
                next_element.path[current.path_length] = next_edge.name;
                insert(&q, next_element);
                seen[next_edge.name - 'A'] = 1;
            }
        }
    }
    return -1;
}

int main() {
    Node graph[MAX_NODES];
    graph['A' - 'A'].edges[0] = (Edge){'B', 1};
    graph['A' - 'A'].edges[1] = (Edge){'C', 4};
    graph['A' - 'A'].edge_count = 2;
    graph['B' - 'A'].edges[0] = (Edge){'A', 1};
    graph['B' - 'A'].edges[1] = (Edge){'C', 2};
    graph['B' - 'A'].edges[2] = (Edge){'D', 5};
    graph['B' - 'A'].edge_count = 3;
    graph['C' - 'A'].edges[0] = (Edge){'A', 4};
    graph['C' - 'A'].edges[1] = (Edge){'B', 2};
    graph['C' - 'A'].edges[2] = (Edge){'D', 1};
    graph['C' - 'A'].edge_count = 3;
    graph['D' - 'A'].edges[0] = (Edge){'B', 5};
    graph['D' - 'A'].edges[1] = (Edge){'C', 1};
    graph['D' - 'A'].edge_count = 2;

    char start = 'A', end = 'D';
    while (1) {
        dijkstra(graph, start, end, 4);
    }
    return 0;
}