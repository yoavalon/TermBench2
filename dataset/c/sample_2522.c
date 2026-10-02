#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *vertex;
    int path_size;
    char **path;
} QueueNode;

typedef struct {
    QueueNode *data;
    int size;
    int capacity;
} Queue;

Queue* create_queue() {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (QueueNode*)malloc(10 * sizeof(QueueNode));
    queue->size = 0;
    queue->capacity = 10;
    return queue;
}

void enqueue(Queue *queue, QueueNode node) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->data = (QueueNode*)realloc(queue->data, queue->capacity * sizeof(QueueNode));
    }
    queue->data[queue->size++] = node;
}

QueueNode dequeue(Queue *queue) {
    QueueNode node = queue->data[0];
    for (int i = 1; i < queue->size; i++) {
        queue->data[i-1] = queue->data[i];
    }
    queue->size--;
    return node;
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

char** bfs(char **graph[], int graph_size, char *start, char *goal) {
    Queue *queue = create_queue();
    char **path = (char**)malloc(2 * sizeof(char*));
    path[0] = strdup(start);
    path[1] = NULL;
    QueueNode node = {start, 1, path};
    enqueue(queue, node);

    while (!is_empty(queue)) {
        QueueNode current = dequeue(queue);
        for (int i = 0; graph[current.path_size-1][i] != '\0'; i++) {
            char *next = graph[current.path_size-1][i];
            int is_in_path = 0;
            for (int j = 0; j < current.path_size; j++) {
                if (strcmp(current.path[j], next) == 0) {
                    is_in_path = 1;
                    break;
                }
            }
            if (!is_in_path) {
                if (strcmp(next, goal) == 0) {
                    char **new_path = (char**)malloc((current.path_size + 2) * sizeof(char*));
                    for (int j = 0; j < current.path_size; j++) {
                        new_path[j] = strdup(current.path[j]);
                    }
                    new_path[current.path_size] = strdup(next);
                    new_path[current.path_size + 1] = NULL;
                    free_queue(queue);
                    return new_path;
                } else {
                    char **new_path = (char**)malloc((current.path_size + 2) * sizeof(char*));
                    for (int j = 0; j < current.path_size; j++) {
                        new_path[j] = strdup(current.path[j]);
                    }
                    new_path[current.path_size] = strdup(next);
                    new_path[current.path_size + 1] = NULL;
                    QueueNode new_node = {next, current.path_size + 1, new_path};
                    enqueue(queue, new_node);
                }
            }
        }
    }
    free_queue(queue);
    return NULL;
}

char** find_path(char **graph[], int graph_size, char *start, char *goal) {
    char **path = bfs(graph, graph_size, start, goal);
    return path ? path : (char**){NULL};
}

void print_path(char **path) {
    if (path) {
        for (int i = 0; path[i] != NULL; i++) {
            printf("%s ", path[i]);
            free(path[i]);
        }
        printf("\n");
    } else {
        printf("[]\n");
    }
}

int main() {
    char *graph[] = {
        (char*){"B\0C\0"},
        (char*){"D\0E\0"},
        (char*){"F\0"},
        (char*){"\0"},
        (char*){"F\0"},
        (char*){"\0"}
    };
    int graph_size = sizeof(graph) / sizeof(graph[0]);
    char *start_node = "A";
    char *goal_node = "F";
    char **result = find_path(&graph, graph_size, start_node, goal_node);
    print_path(result);
    free(result);
    return 0;
}