#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int node;
    int dist;
} NodeDist;

typedef struct {
    NodeDist* data;
    int size;
    int capacity;
} Queue;

typedef struct {
    int* data;
    int size;
} Set;

void initQueue(Queue* queue, int capacity) {
    queue->data = (NodeDist*)malloc(capacity * sizeof(NodeDist));
    queue->size = 0;
    queue->capacity = capacity;
}

void enqueue(Queue* queue, NodeDist item) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->data = (NodeDist*)realloc(queue->data, queue->capacity * sizeof(NodeDist));
    }
    queue->data[queue->size++] = item;
}

NodeDist dequeue(Queue* queue) {
    NodeDist item = queue->data[0];
    for (int i = 1; i < queue->size; i++) {
        queue->data[i - 1] = queue->data[i];
    }
    queue->size--;
    return item;
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

void initSet(Set* set, int capacity) {
    set->data = (int*)malloc(capacity * sizeof(int));
    set->size = 0;
}

void add(Set* set, int item) {
    for (int i = 0; i < set->size; i++) {
        if (set->data[i] == item) return;
    }
    if (set->size == set->capacity) {
        set->capacity *= 2;
        set->data = (int*)realloc(set->data, set->capacity * sizeof(int));
    }
    set->data[set->size++] = item;
}

int contains(Set* set, int item) {
    for (int i = 0; i < set->size; i++) {
        if (set->data[i] == item) return 1;
    }
    return 0;
}

int find_shortest_path(int** graph, int start, int end, int num_nodes) {
    Queue queue;
    Set visited;
    initQueue(&queue, 10);
    initSet(&visited, 10);
    NodeDist item = {start, 0};
    enqueue(&queue, item);
    add(&visited, start);
    while (!isEmpty(&queue)) {
        item = dequeue(&queue);
        if (item.node == end) {
            free(queue.data);
            free(visited.data);
            return item.dist;
        }
        for (int i = 0; graph[item.node][i] != -1; i++) {
            int neighbor = graph[item.node][i];
            if (!contains(&visited, neighbor)) {
                add(&visited, neighbor);
                NodeDist neighbor_item = {neighbor, item.dist + 1};
                enqueue(&queue, neighbor_item);
            }
        }
    }
    free(queue.data);
    free(visited.data);
    return -1;
}

int main() {
    int num_nodes = 5;
    int* graph[5];
    graph[0] = (int[]){1, 2, -1};
    graph[1] = (int[]){2, 3, -1};
    graph[2] = (int[]){3, 4, -1};
    graph[3] = (int[]){4, -1};
    graph[4] = (int[]){-1};
    printf("%d\n", find_shortest_path(graph, 0, 4, num_nodes));
    return 0;
}