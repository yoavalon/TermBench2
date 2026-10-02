#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int distance;
} Node;

typedef struct {
    Node *data;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (Node*)malloc(queue->capacity * sizeof(Node));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, char *name, int distance) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear].name = strdup(name);
    queue->data[queue->rear].distance = distance;
    queue->size = queue->size + 1;
}

Node dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        Node empty = {NULL, -1};
        return empty;
    }
    Node item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int find_shortest_path(char *graph[], char *start, char *end) {
    Queue *q = createQueue(100);
    char visited[100][100] = {0};
    enqueue(q, start, 0);
    while (!isEmpty(q)) {
        Node n = dequeue(q);
        if (strcmp(n.name, end) == 0) {
            free(n.name);
            free(q->data);
            free(q);
            return n.distance;
        }
        visited[n.distance][strlen(n.name)] = 1;
        for (int i = 0; graph[i] != NULL; i++) {
            char *neighbor = strtok(graph[i], ",");
            while (neighbor != NULL) {
                if (visited[n.distance][strlen(neighbor)] == 0) {
                    enqueue(q, neighbor, n.distance + 1);
                }
                neighbor = strtok(NULL, ",");
            }
        }
        free(n.name);
    }
    free(q->data);
    free(q);
    return -1;
}

int main() {
    char *g[] = {
        "A,B,C",
        "B,D,E",
        "C,F",
        "D,G",
        "E,F",
        "F,G",
        NULL
    };
    int result = find_shortest_path(g, "A", "G");
    printf("%d\n", result);
    return 0;
}