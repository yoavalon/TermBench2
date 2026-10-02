#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 6
#define MAX_NEIGHBORS 3

typedef struct {
    char name;
    char neighbors[MAX_NEIGHBORS];
    int neighbor_count;
} Node;

typedef struct {
    char node;
    char path[MAX_NODES];
    int path_length;
} QueueElement;

typedef struct {
    QueueElement elements[MAX_NODES];
    int front;
    int rear;
} Queue;

void enqueue(Queue *q, QueueElement element) {
    q->elements[q->rear++] = element;
}

QueueElement dequeue(Queue *q) {
    return q->elements[q->front++];
}

int is_empty(Queue *q) {
    return q->front == q->rear;
}

int contains(char *path, int path_length, char node) {
    for (int i = 0; i < path_length; i++) {
        if (path[i] == node) {
            return 1;
        }
    }
    return 0;
}

char* bfs(Node *graph, char start, char end, char *path, int path_length) {
    Queue q;
    q.front = 0;
    q.rear = 0;
    QueueElement initial = {start, {start}, 1};
    enqueue(&q, initial);

    while (!is_empty(&q)) {
        QueueElement current = dequeue(&q);
        for (int i = 0; i < graph[current.node - 'A'].neighbor_count; i++) {
            char neighbor = graph[current.node - 'A'].neighbors[i];
            if (!contains(current.path, current.path_length, neighbor)) {
                if (neighbor == end) {
                    path[path_length] = neighbor;
                    path[path_length + 1] = '\0';
                    return path;
                }
                QueueElement next = {neighbor, {0}, current.path_length + 1};
                strncpy(next.path, current.path, current.path_length);
                next.path[current.path_length] = neighbor;
                enqueue(&q, next);
            }
        }
    }
    return NULL;
}

void process_graph() {
    Node graph[MAX_NODES];
    graph['A' - 'A'] = (Node){{'A'}, {'B', 'C'}, 2};
    graph['B' - 'A'] = (Node){{'B'}, {'D', 'E'}, 2};
    graph['C' - 'A'] = (Node){{'C'}, {'F'}, 1};
    graph['D' - 'A'] = (Node){{'D'}, {}, 0};
    graph['E' - 'A'] = (Node){{'E'}, {'F'}, 1};
    graph['F' - 'A'] = (Node){{'F'}, {}, 0};

    char start = 'A';
    char end = 'F';
    char path[MAX_NODES];
    while (1) {
        if (bfs(graph, start, end, path, 0)) {
            printf("Path found: %s\n", path);
        }
    }
}

int main() {
    process_graph();
    return 0;
}