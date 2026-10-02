#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 26
#define MAX_PATH_SIZE 20

typedef struct {
    int cost;
    char node;
    int path_size;
    char path[MAX_PATH_SIZE];
} QueueElement;

typedef struct {
    int size;
    QueueElement *data;
} PriorityQueue;

int compare(const void *a, const void *b) {
    return ((QueueElement *)a)->cost - ((QueueElement *)b)->cost;
}

void push(PriorityQueue *pq, QueueElement *element) {
    pq->data = realloc(pq->data, (pq->size + 1) * sizeof(QueueElement));
    memcpy(&pq->data[pq->size], element, sizeof(QueueElement));
    pq->size++;
    qsort(pq->data, pq->size, sizeof(QueueElement), compare);
}

void pop(PriorityQueue *pq, QueueElement *element) {
    if (pq->size > 0) {
        memcpy(element, &pq->data[0], sizeof(QueueElement));
        memmove(&pq->data[0], &pq->data[1], (pq->size - 1) * sizeof(QueueElement));
        pq->size--;
    }
}

int dijkstra(const char *graph[MAX_NODES][MAX_NODES], int graph_size, char start, char end) {
    PriorityQueue queue;
    queue.size = 0;
    queue.data = NULL;

    QueueElement start_element = {0, start, 1, {start}};
    push(&queue, &start_element);

    int visited[MAX_NODES] = {0};
    visited[start - 'A'] = 1;

    while (queue.size > 0) {
        QueueElement current;
        pop(&queue, &current);

        if (current.node == end) {
            printf("Path: ");
            for (int i = 0; i < current.path_size; i++) {
                printf("%c", current.path[i]);
            }
            printf(", Cost: %d\n", current.cost);
            return current.cost;
        }

        for (int i = 0; i < graph_size; i++) {
            if (graph[current.node - 'A'][i] != NULL) {
                int cost = current.cost + *graph[current.node - 'A'][i];
                if (!visited[i]) {
                    QueueElement new_element = {cost, i + 'A', current.path_size + 1, {0}};
                    memcpy(new_element.path, current.path, current.path_size);
                    new_element.path[current.path_size] = i + 'A';
                    push(&queue, &new_element);
                }
            }
        }
    }

    return -1;
}

int main() {
    const char *graph[MAX_NODES][MAX_NODES] = {
        {'B', 'C', NULL, NULL},
        {'A', 'C', 'D', NULL},
        {'A', 'B', 'D', NULL},
        {NULL, 'B', 'C', NULL}
    };
    int graph_size = 4;

    char start_node = 'A';
    char end_node = 'D';

    dijkstra(graph, graph_size, start_node, end_node);

    return 0;
}