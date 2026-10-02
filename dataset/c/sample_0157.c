#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *node;
    int path_len;
    char **path;
} QueueElement;

typedef struct {
    QueueElement *data;
    int size;
    int capacity;
} Queue;

Queue* create_queue(int capacity) {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (QueueElement*)malloc(sizeof(QueueElement) * capacity);
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

void enqueue(Queue *queue, QueueElement element) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->data = (QueueElement*)realloc(queue->data, sizeof(QueueElement) * queue->capacity);
    }
    queue->data[queue->size++] = element;
}

QueueElement dequeue(Queue *queue) {
    if (queue->size == 0) {
        QueueElement empty = {"", 0, NULL};
        return empty;
    }
    QueueElement element = queue->data[0];
    for (int i = 0; i < queue->size - 1; i++) {
        queue->data[i] = queue->data[i + 1];
    }
    queue->size--;
    return element;
}

int is_empty(Queue *queue) {
    return queue->size == 0;
}

void free_queue(Queue *queue) {
    for (int i = 0; i < queue->size; i++) {
        free(queue->data[i].path);
    }
    free(queue->data);
    free(queue);
}

int bfs(char **graph[], int start, int end, int num_nodes) {
    Queue *queue = create_queue(10);
    QueueElement element = {graph[start], 1, (char**)malloc(sizeof(char*) * 10)};
    element.path[0] = graph[start];
    enqueue(queue, element);
    int *visited = (int*)calloc(num_nodes, sizeof(int));
    while (!is_empty(queue)) {
        element = dequeue(queue);
        int node = 0;
        for (int i = 0; i < num_nodes; i++) {
            if (strcmp(graph[i], element.node) == 0) {
                node = i;
                break;
            }
        }
        if (!visited[node]) {
            visited[node] = 1;
            if (node == end) {
                free(visited);
                free_queue(queue);
                free(element.path);
                return element.path_len - 1;
            }
            for (int i = 0; graph[node][i] != NULL; i++) {
                int neighbor = 0;
                for (int j = 0; j < num_nodes; j++) {
                    if (strcmp(graph[j], graph[node][i]) == 0) {
                        neighbor = j;
                        break;
                    }
                }
                if (!visited[neighbor]) {
                    QueueElement new_element = {graph[neighbor], element.path_len + 1, (char**)malloc(sizeof(char*) * 10)};
                    for (int j = 0; j < element.path_len; j++) {
                        new_element.path[j] = element.path[j];
                    }
                    new_element.path[element.path_len] = graph[neighbor];
                    enqueue(queue, new_element);
                }
            }
        }
        free(element.path);
    }
    free(visited);
    free_queue(queue);
    return -1;
}

int find_shortest_path(char **graph[], int start, int end, int num_nodes) {
    return bfs(graph, start, end, num_nodes);
}

void main() {
    char *graph[6][3] = {
        {"A", "B", "C", NULL},
        {"B", "D", "E", NULL},
        {"C", "F", NULL},
        {"D", NULL},
        {"E", "F", NULL},
        {"F", NULL}
    };
    int start = 0;
    int end = 5;
    int result = find_shortest_path((char***)graph, start, end, 6);
    printf("%d\n", result);
}