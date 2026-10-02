#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char vertex;
    int path_length;
    char path[26];
} Node;

typedef struct {
    Node *data;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (Node*) malloc(queue->capacity * sizeof(Node));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, Node item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size = queue->size + 1;
}

Node dequeue(Queue* queue) {
    if (isEmpty(queue))
        return (Node){0};
    Node item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int find_shortest_path(char graph[26][26], char start, char end, char path[26]) {
    Queue* queue = createQueue(100);
    Node first = {start, 1, {start}};
    enqueue(queue, first);

    while (!isEmpty(queue)) {
        Node current = dequeue(queue);
        for (int i = 0; i < 26; i++) {
            if (graph[current.vertex - 'A'][i] && !strchr(current.path, 'A' + i)) {
                if ('A' + i == end) {
                    path[0] = '\0';
                    strncat(path, current.path, current.path_length);
                    path[current.path_length] = end;
                    path[current.path_length + 1] = '\0';
                    free(queue->data);
                    free(queue);
                    return 1;
                } else {
                    Node next = {'A' + i, current.path_length + 1, {0}};
                    strncpy(next.path, current.path, current.path_length);
                    next.path[current.path_length] = 'A' + i;
                    next.path[current.path_length + 1] = '\0';
                    enqueue(queue, next);
                }
            }
        }
    }
    free(queue->data);
    free(queue);
    return 0;
}

int main() {
    char graph[26][26] = {0};
    graph['A' - 'A']['B' - 'A'] = 1;
    graph['A' - 'A']['C' - 'A'] = 1;
    graph['B' - 'A']['A' - 'A'] = 1;
    graph['B' - 'A']['D' - 'A'] = 1;
    graph['B' - 'A']['E' - 'A'] = 1;
    graph['C' - 'A']['A' - 'A'] = 1;
    graph['C' - 'A']['F' - 'A'] = 1;
    graph['D' - 'A']['B' - 'A'] = 1;
    graph['E' - 'A']['B' - 'A'] = 1;
    graph['E' - 'A']['F' - 'A'] = 1;
    graph['F' - 'A']['C' - 'A'] = 1;
    graph['F' - 'A']['E' - 'A'] = 1;

    char start = 'A';
    char end = 'F';
    char path[26];
    if (find_shortest_path(graph, start, end, path)) {
        printf("%s\n", path);
    } else {
        printf("No path found\n");
    }
    return 0;
}