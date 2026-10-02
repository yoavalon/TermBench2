#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char **values;
    int size;
} Node;

typedef struct {
    Node *nodes;
    int size;
} Graph;

typedef struct {
    char **elements;
    int size;
    int capacity;
} Queue;

void init_queue(Queue *queue, int capacity) {
    queue->elements = (char **)malloc(capacity * sizeof(char *));
    queue->size = 0;
    queue->capacity = capacity;
}

void enqueue(Queue *queue, char *element) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->elements = (char **)realloc(queue->elements, queue->capacity * sizeof(char *));
    }
    queue->elements[queue->size++] = strdup(element);
}

char *dequeue(Queue *queue) {
    if (queue->size == 0) {
        return NULL;
    }
    char *element = queue->elements[0];
    for (int i = 0; i < queue->size - 1; i++) {
        queue->elements[i] = queue->elements[i + 1];
    }
    queue->size--;
    return element;
}

int is_empty(Queue *queue) {
    return queue->size == 0;
}

void free_queue(Queue *queue) {
    for (int i = 0; i < queue->size; i++) {
        free(queue->elements[i]);
    }
    free(queue->elements);
}

int find_node(Graph *graph, char *key) {
    for (int i = 0; i < graph->size; i++) {
        if (strcmp(graph->nodes[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}

void bfs(Graph *graph, char *start, char *end) {
    Queue queue;
    init_queue(&queue, 10);
    enqueue(&queue, start);
    char **visited = (char **)calloc(graph->size, sizeof(char *));
    int visited_count = 0;

    while (!is_empty(&queue)) {
        char *node = dequeue(&queue);
        int node_index = find_node(graph, node);

        if (strcmp(node, end) == 0) {
            printf("%s\n", node);
            free(node);
            free_queue(&queue);
            free(visited);
            return;
        }

        visited[visited_count++] = node;

        for (int i = 0; i < graph->nodes[node_index].size; i++) {
            char *neighbor = graph->nodes[node_index].values[i];
            int neighbor_index = find_node(graph, neighbor);
            int already_visited = 0;
            for (int j = 0; j < visited_count; j++) {
                if (strcmp(visited[j], neighbor) == 0) {
                    already_visited = 1;
                    break;
                }
            }
            if (!already_visited) {
                enqueue(&queue, neighbor);
            }
        }
    }

    printf("No path found\n");
    free_queue(&queue);
    free(visited);
}

int main() {
    Graph graph;
    graph.nodes = (Node *)malloc(6 * sizeof(Node));
    graph.size = 6;

    graph.nodes[0].key = strdup("A");
    graph.nodes[0].values = (char **)malloc(2 * sizeof(char *));
    graph.nodes[0].values[0] = strdup("B");
    graph.nodes[0].values[1] = strdup("C");
    graph.nodes[0].size = 2;

    graph.nodes[1].key = strdup("B");
    graph.nodes[1].values = (char **)malloc(3 * sizeof(char *));
    graph.nodes[1].values[0] = strdup("A");
    graph.nodes[1].values[1] = strdup("D");
    graph.nodes[1].values[2] = strdup("E");
    graph.nodes[1].size = 3;

    graph.nodes[2].key = strdup("C");
    graph.nodes[2].values = (char **)malloc(2 * sizeof(char *));
    graph.nodes[2].values[0] = strdup("A");
    graph.nodes[2].values[1] = strdup("F");
    graph.nodes[2].size = 2;

    graph.nodes[3].key = strdup("D");
    graph.nodes[3].values = (char **)malloc(1 * sizeof(char *));
    graph.nodes[3].values[0] = strdup("B");
    graph.nodes[3].size = 1;

    graph.nodes[4].key = strdup("E");
    graph.nodes[4].values = (char **)malloc(2 * sizeof(char *));
    graph.nodes[4].values[0] = strdup("B");
    graph.nodes[4].values[1] = strdup("F");
    graph.nodes[4].size = 2;

    graph.nodes[5].key = strdup("F");
    graph.nodes[5].values = (char **)malloc(2 * sizeof(char *));
    graph.nodes[5].values[0] = strdup("C");
    graph.nodes[5].values[1] = strdup("E");
    graph.nodes[5].size = 2;

    bfs(&graph, "A", "F");

    for (int i = 0; i < graph.size; i++) {
        free(graph.nodes[i].key);
        for (int j = 0; j < graph.nodes[i].size; j++) {
            free(graph.nodes[i].values[j]);
        }
        free(graph.nodes[i].values);
    }
    free(graph.nodes);

    return 0;
}