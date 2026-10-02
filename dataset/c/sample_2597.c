#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char node;
    char* path;
} QueueItem;

typedef struct {
    QueueItem* items;
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue* q, int capacity) {
    q->items = (QueueItem*)malloc(capacity * sizeof(QueueItem));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

int isFull(Queue* q, int capacity) {
    return q->size == capacity;
}

void enqueue(Queue* q, QueueItem item, int capacity) {
    if (isFull(q, capacity)) {
        return;
    }
    q->rear = (q->rear + 1) % capacity;
    q->items[q->rear] = item;
    q->size++;
}

QueueItem dequeue(Queue* q) {
    if (isEmpty(q)) {
        QueueItem emptyItem = {'\0', NULL};
        return emptyItem;
    }
    QueueItem item = q->items[q->front];
    q->front = (q->front + 1) % q->size;
    q->size--;
    return item;
}

char** find_shortest_path(char** graph, int graphSize, char start, char end) {
    Queue queue;
    initQueue(&queue, graphSize);
    QueueItem firstItem = {start, (char*)malloc(2)};
    firstItem.path[0] = start;
    firstItem.path[1] = '\0';
    enqueue(&queue, firstItem, graphSize);
    char* visited = (char*)calloc(graphSize, sizeof(char));
    while (!isEmpty(&queue)) {
        QueueItem item = dequeue(&queue);
        char node = item.node;
        char* path = item.path;
        if (node == end) {
            return &path;
        }
        if (!visited[node - 'A']) {
            visited[node - 'A'] = 1;
            for (int i = 0; graph[node - 'A'][i] != '\0'; i++) {
                char neighbor = graph[node - 'A'][i];
                char* newPath = (char*)malloc(strlen(path) + 2);
                strcpy(newPath, path);
                newPath[strlen(path)] = neighbor;
                newPath[strlen(path) + 1] = '\0';
                QueueItem newItem = {neighbor, newPath};
                enqueue(&queue, newItem, graphSize);
            }
        }
    }
    return NULL;
}

int main() {
    char* graph[] = {
        "BC",
        "ADE",
        "CF",
        "B",
        "BF",
        "CE"
    };
    char** path = find_shortest_path(graph, 6, 'A', 'F');
    if (path != NULL) {
        printf("%s\n", *path);
    }
    return 0;
}