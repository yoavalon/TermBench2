#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NEIGHBORS 100

typedef struct {
    char name[2];
    int neighbors_count;
    char neighbors[MAX_NEIGHBORS][2];
} Node;

typedef struct {
    char node[2];
    int path_length;
    char path[MAX_NODES][2];
} QueueElement;

typedef struct {
    QueueElement elements[MAX_NODES];
    int front;
    int rear;
} Queue;

void init_queue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int is_empty(Queue *q) {
    return q->front > q->rear;
}

void enqueue(Queue *q, QueueElement element) {
    q->elements[++q->rear] = element;
}

QueueElement dequeue(Queue *q) {
    return q->elements[q->front++];
}

int bfs(Node graph[], int graph_size, char start[], char end[]) {
    Queue queue;
    init_queue(&queue);

    QueueElement first_element;
    first_element.path_length = 1;
    strcpy(first_element.node, start);
    strcpy(first_element.path[0], start);
    enqueue(&queue, first_element);

    int visited[MAX_NODES] = {0};

    while (!is_empty(&queue)) {
        QueueElement current = dequeue(&queue);
        if (strcmp(current.node, end) == 0) {
            for (int i = 0; i < current.path_length; i++) {
                printf("%s", current.path[i]);
                if (i < current.path_length - 1) {
                    printf(" -> ");
                }
            }
            printf("\n");
            return 1;
        }
        if (!visited[current.path_length - 1]) {
            visited[current.path_length - 1] = 1;
            for (int i = 0; i < graph_size; i++) {
                if (strcmp(graph[i].name, current.node) == 0) {
                    for (int j = 0; j < graph[i].neighbors_count; j++) {
                        QueueElement new_element;
                        new_element.path_length = current.path_length + 1;
                        strcpy(new_element.node, graph[i].neighbors[j]);
                        for (int k = 0; k < current.path_length; k++) {
                            strcpy(new_element.path[k], current.path[k]);
                        }
                        strcpy(new_element.path[current.path_length], graph[i].neighbors[j]);
                        enqueue(&queue, new_element);
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    Node graph[] = {
        {"A", 2, {"B", "C"}},
        {"B", 2, {"D", "E"}},
        {"C", 1, {"F"}},
        {"D", 0, {}},
        {"E", 1, {"F"}},
        {"F", 0, {}}
    };
    int graph_size = 6;

    char start[] = "A";
    char end[] = "F";

    bfs(graph, graph_size, start, end);

    return 0;
}