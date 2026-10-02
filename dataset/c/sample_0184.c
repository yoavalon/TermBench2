#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10
#define MAX_NEIGHBORS 10

typedef struct {
    char node;
    int dist;
} QueueElement;

typedef struct {
    QueueElement elements[MAX_NODES * MAX_NEIGHBORS];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->rear < q->front;
}

void enqueue(Queue *q, QueueElement e) {
    q->elements[++q->rear] = e;
}

QueueElement dequeue(Queue *q) {
    return q->elements[q->front++];
}

int bfs(char graph[][MAX_NEIGHBORS], int graphSize[], char start, char end) {
    Queue queue;
    initQueue(&queue);
    QueueElement element = {start, 0};
    enqueue(&queue, element);
    int visited[MAX_NODES];
    memset(visited, 0, sizeof(visited));
    while (!isEmpty(&queue)) {
        element = dequeue(&queue);
        char node = element.node;
        int dist = element.dist;
        if (node == end) {
            return dist;
        }
        if (!visited[node - 'A']) {
            visited[node - 'A'] = 1;
            for (int i = 0; i < graphSize[node - 'A']; i++) {
                QueueElement neighbor = {graph[node - 'A'][i], dist + 1};
                enqueue(&queue, neighbor);
            }
        }
    }
    return -1;
}

int main() {
    char graph[MAX_NODES][MAX_NEIGHBORS] = {
        {'B', 'C', '\0'},
        {'D', 'E', '\0'},
        {'F', '\0'},
        {'\0'},
        {'F', '\0'},
        {'\0'}
    };
    int graphSize[MAX_NODES] = {2, 2, 1, 0, 1, 0};
    char start = 'A';
    char end = 'F';
    printf("%d\n", bfs(graph, graphSize, start, end));
    return 0;
}