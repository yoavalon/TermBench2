#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int node;
    int distance;
} NodeDistance;

typedef struct {
    NodeDistance *array;
    int size;
    int capacity;
} PriorityQueue;

void swap(NodeDistance *a, NodeDistance *b) {
    NodeDistance temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(PriorityQueue *pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->array[left].distance < pq->array[smallest].distance)
        smallest = left;

    if (right < pq->size && pq->array[right].distance < pq->array[smallest].distance)
        smallest = right;

    if (smallest != idx) {
        swap(&pq->array[smallest], &pq->array[idx]);
        minHeapify(pq, smallest);
    }
}

void insert(PriorityQueue *pq, NodeDistance nd) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->array = realloc(pq->array, pq->capacity * sizeof(NodeDistance));
    }
    pq->array[pq->size] = nd;
    pq->size++;
    int i = pq->size - 1;
    while (i != 0 && pq->array[(i - 1) / 2].distance > pq->array[i].distance) {
        swap(&pq->array[i], &pq->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

NodeDistance extractMin(PriorityQueue *pq) {
    if (pq->size <= 0) {
        NodeDistance nd = {-1, -1};
        return nd;
    }
    if (pq->size == 1) {
        pq->size--;
        return pq->array[0];
    }

    NodeDistance root = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    minHeapify(pq, 0);

    return root;
}

int dijkstra(int **graph, int numNodes, int start, int end) {
    PriorityQueue pq;
    pq.size = 0;
    pq.capacity = 10;
    pq.array = malloc(pq.capacity * sizeof(NodeDistance));

    int *distances = malloc(numNodes * sizeof(int));
    for (int i = 0; i < numNodes; i++)
        distances[i] = INT_MAX;
    distances[start] = 0;

    insert(&pq, (NodeDistance){start, 0});

    while (pq.size > 0) {
        NodeDistance current = extractMin(&pq);
        int currentNode = current.node;
        int currentDistance = current.distance;

        if (currentNode == end) {
            free(pq.array);
            free(distances);
            return currentDistance;
        }

        for (int neighbor = 0; neighbor < numNodes; neighbor++) {
            if (graph[currentNode][neighbor] != 0) {
                int distance = currentDistance + graph[currentNode][neighbor];
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                    insert(&pq, (NodeDistance){neighbor, distance});
                }
            }
        }
    }
    free(pq.array);
    free(distances);
    return -1;
}

int **buildGraph(int edges[][3], int numEdges, int *numNodes) {
    *numNodes = 0;
    for (int i = 0; i < numEdges; i++) {
        if (edges[i][0] > *numNodes) *numNodes = edges[i][0];
        if (edges[i][1] > *numNodes) *numNodes = edges[i][1];
    }
    *numNodes += 1;

    int **graph = malloc(*numNodes * sizeof(int *));
    for (int i = 0; i < *numNodes; i++)
        graph[i] = calloc(*numNodes, sizeof(int));

    for (int i = 0; i < numEdges; i++) {
        graph[edges[i][0]][edges[i][1]] = edges[i][2];
        graph[edges[i][1]][edges[i][0]] = edges[i][2];
    }

    return graph;
}

void freeGraph(int **graph, int numNodes) {
    for (int i = 0; i < numNodes; i++)
        free(graph[i]);
    free(graph);
}

int main() {
    int edges[][3] = {{1, 2, 7}, {1, 3, 9}, {2, 3, 10}, {2, 4, 15}, {3, 4, 11}};
    int numEdges = sizeof(edges) / sizeof(edges[0]);
    int numNodes;
    int **graph = buildGraph(edges, numEdges, &numNodes);

    printf("%d\n", dijkstra(graph, numNodes, 1, 4));

    freeGraph(graph, numNodes);
    return 0;
}