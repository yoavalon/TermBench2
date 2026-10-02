#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 9

typedef struct {
    int vertex;
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX_NODES];
    int size;
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->size = 0;
    return graph;
}

void addEdge(Graph* graph, int u, int v, int weight) {
    graph->edges[graph->size].vertex = v;
    graph->edges[graph->size].weight = weight;
    graph->size++;
}

typedef struct {
    int distance;
    int visited;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int size;
} PriorityQueue;

PriorityQueue* createPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(PriorityQueue* pq, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->nodes[left].distance < pq->nodes[smallest].distance)
        smallest = left;

    if (right < pq->size && pq->nodes[right].distance < pq->nodes[smallest].distance)
        smallest = right;

    if (smallest != i) {
        swap(&pq->nodes[i].distance, &pq->nodes[smallest].distance);
        heapify(pq, smallest);
    }
}

void insert(PriorityQueue* pq, int distance) {
    int i = pq->size++;
    pq->nodes[i].distance = distance;
    pq->nodes[i].visited = 0;

    while (i != 0 && pq->nodes[(i - 1) / 2].distance > pq->nodes[i].distance) {
        swap(&pq->nodes[i].distance, &pq->nodes[(i - 1) / 2].distance);
        i = (i - 1) / 2;
    }
}

int extractMin(PriorityQueue* pq) {
    if (pq->size <= 0)
        return INT_MAX;
    if (pq->size == 1) {
        pq->size--;
        return pq->nodes[0].distance;
    }

    int root = pq->nodes[0].distance;
    pq->nodes[0] = pq->nodes[--pq->size];
    heapify(pq, 0);

    return root;
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

void dijkstra(Graph* graph, int start, int distances[]) {
    for (int i = 0; i < MAX_NODES; i++)
        distances[i] = INT_MAX;

    distances[start] = 0;

    PriorityQueue* pq = createPriorityQueue();
    insert(pq, 0);

    while (!isEmpty(pq)) {
        int u = extractMin(pq);

        for (int i = 0; i < graph->size; i++) {
            int v = graph->edges[i].vertex;
            int weight = graph->edges[i].weight;

            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                insert(pq, distances[v]);
            }
        }
    }
}

int findShortestPath(Graph* graph, int start, int end) {
    int distances[MAX_NODES];
    dijkstra(graph, start, distances);
    return distances[end];
}

void main() {
    Graph* g = createGraph();
    addEdge(g, 0, 1, 4);
    addEdge(g, 0, 7, 8);
    addEdge(g, 1, 2, 8);
    addEdge(g, 1, 7, 11);
    addEdge(g, 2, 3, 7);
    addEdge(g, 2, 5, 4);
    addEdge(g, 2, 8, 2);
    addEdge(g, 3, 4, 9);
    addEdge(g, 3, 5, 14);
    addEdge(g, 4, 5, 10);
    addEdge(g, 5, 6, 2);
    addEdge(g, 6, 7, 1);
    addEdge(g, 6, 8, 6);
    addEdge(g, 7, 8, 7);

    int shortestPath = findShortestPath(g, 0, 4);
    printf("%d\n", shortestPath);
}