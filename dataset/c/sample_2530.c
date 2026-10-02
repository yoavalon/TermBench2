#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char vertex;
    int cost;
} Edge;

typedef struct {
    char vertex;
    int cost;
    Edge *edges;
    int edge_count;
} GraphNode;

typedef struct {
    int cost;
    char *path;
    int path_length;
} Result;

typedef struct {
    int cost;
    char vertex;
    char *path;
    int path_length;
} QueueElement;

typedef struct {
    QueueElement *elements;
    int size;
    int capacity;
} PriorityQueue;

void enqueue(PriorityQueue *queue, QueueElement element) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->elements = realloc(queue->elements, queue->capacity * sizeof(QueueElement));
    }
    queue->elements[queue->size++] = element;
}

QueueElement dequeue(PriorityQueue *queue) {
    int min_index = 0;
    for (int i = 1; i < queue->size; i++) {
        if (queue->elements[i].cost < queue->elements[min_index].cost) {
            min_index = i;
        }
    }
    QueueElement min_element = queue->elements[min_index];
    for (int i = min_index; i < queue->size - 1; i++) {
        queue->elements[i] = queue->elements[i + 1];
    }
    queue->size--;
    return min_element;
}

int is_empty(PriorityQueue *queue) {
    return queue->size == 0;
}

int contains(const char *arr, int size, char value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1;
        }
    }
    return 0;
}

Result dijkstra(GraphNode *graph, int graph_size, char start, char end) {
    PriorityQueue queue;
    queue.elements = malloc(graph_size * sizeof(QueueElement));
    queue.size = 0;
    queue.capacity = graph_size;
    QueueElement initial = {0, start, NULL, 0};
    enqueue(&queue, initial);

    char *seen = malloc(graph_size * sizeof(char));
    int seen_size = 0;

    while (!is_empty(&queue)) {
        QueueElement current = dequeue(&queue);
        if (!contains(seen, seen_size, current.vertex)) {
            seen[seen_size++] = current.vertex;
            char *new_path = malloc((current.path_length + 1) * sizeof(char));
            if (current.path_length > 0) {
                memcpy(new_path, current.path, current.path_length * sizeof(char));
            }
            new_path[current.path_length] = current.vertex;
            if (current.vertex == end) {
                Result result = {current.cost, new_path, current.path_length + 1};
                free(queue.elements);
                free(seen);
                return result;
            }
            for (int i = 0; i < graph_size; i++) {
                if (graph[i].vertex == current.vertex) {
                    for (int j = 0; j < graph[i].edge_count; j++) {
                        if (!contains(seen, seen_size, graph[i].edges[j].vertex)) {
                            QueueElement next = {current.cost + graph[i].edges[j].cost, graph[i].edges[j].vertex, new_path, current.path_length + 1};
                            enqueue(&queue, next);
                        }
                    }
                }
            }
        }
    }
    Result result = {INT_MAX, NULL, 0};
    free(queue.elements);
    free(seen);
    return result;
}

int main() {
    GraphNode graph[] = {
        {'A', 2, (Edge[]){{'B', 1}, {'C', 4}}, 2},
        {'B', 3, (Edge[]){{'A', 1}, {'C', 2}, {'D', 5}}, 3},
        {'C', 3, (Edge[]){{'A', 4}, {'B', 2}, {'D', 1}}, 3},
        {'D', 2, (Edge[]){{'B', 5}, {'C', 1}}, 2}
    };
    int graph_size = sizeof(graph) / sizeof(graph[0]);
    char start = 'A';
    char end = 'D';
    Result result = dijkstra(graph, graph_size, start, end);
    printf("%d ", result.cost);
    for (int i = 0; i < result.path_length; i++) {
        printf("%c", result.path[i]);
    }
    printf("\n");
    free(result.path);
    return 0;
}