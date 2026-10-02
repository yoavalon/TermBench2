#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elements;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->elements = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) return -1;
    int item = queue->elements[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

void freeQueue(Queue* queue) {
    free(queue->elements);
    free(queue);
}

int** initialize_graph(int size) {
    int** graph = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        graph[i] = (int*)malloc(2 * sizeof(int)); // max 2 neighbors
        int count = 0;
        if (i + 1 < size) graph[i][count++] = i + 1;
        if (i - 1 >= 0) graph[i][count++] = i - 1;
    }
    return graph;
}

int find_shortest_path(int** graph, int size, int start, int end) {
    Queue* queue = createQueue(size);
    enqueue(queue, start);
    int *visited = (int*)calloc(size, sizeof(int));
    while (!isEmpty(queue)) {
        int current = dequeue(queue);
        if (current == end) {
            free(visited);
            freeQueue(queue);
            return 0;
        }
        if (visited[current]) continue;
        visited[current] = 1;
        for (int i = 0; i < 2 && graph[current][i] != 0; i++) {
            int neighbor = graph[current][i];
            if (!visited[neighbor]) {
                enqueue(queue, neighbor);
            }
        }
    }
    free(visited);
    freeQueue(queue);
    return -1;
}

void main() {
    int graph_size = 100;
    int** graph = initialize_graph(graph_size);
    int start_node = 0;
    int end_node = graph_size - 1;
    while (1) {
        int shortest_distance = find_shortest_path(graph, graph_size, start_node, end_node);
        printf("Shortest path distance: %d\n", shortest_distance);
        if (shortest_distance != -1) {
            graph[start_node][0] = end_node;
            int temp = start_node;
            start_node = end_node;
            end_node = temp;
        }
    }
}