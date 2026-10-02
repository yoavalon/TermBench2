#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int node;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

typedef struct {
    int* nodes;
    int** edges;
    int num_nodes;
    int num_edges;
} Graph;

typedef struct {
    int* path;
    int length;
} Path;

void enqueue(Queue* queue, int node, Path path) {
    QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
    new_node->node = node;
    new_node->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

int is_empty(Queue* queue) {
    return queue->front == NULL;
}

void dequeue(Queue* queue, int* node, Path* path) {
    if (is_empty(queue)) return;
    QueueNode* temp = queue->front;
    *node = temp->node;
    queue->front = queue->front->next;
    if (queue->front == NULL) queue->rear = NULL;
    free(temp);
}

int contains(int* array, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) return 1;
    }
    return 0;
}

int* get_neighbors(Graph* graph, int node, int* size) {
    int* neighbors = (int*)malloc(graph->num_edges * sizeof(int));
    *size = 0;
    for (int i = 0; i < graph->num_edges; i++) {
        if (graph->edges[i][0] == node || graph->edges[i][1] == node) {
            neighbors[(*size)++] = (graph->edges[i][0] == node) ? graph->edges[i][1] : graph->edges[i][0];
        }
    }
    return neighbors;
}

Path bfs(Graph* graph, int start, int goal) {
    Queue queue = {NULL, NULL};
    Path initial_path = {&start, 1};
    enqueue(&queue, start, initial_path);
    int* visited = (int*)calloc(graph->num_nodes, sizeof(int));
    Path result = {NULL, 0};

    while (!is_empty(&queue)) {
        int node;
        Path path;
        dequeue(&queue, &node, &path);

        if (node == goal) {
            result = path;
            break;
        }

        if (!contains(visited, graph->num_nodes, node)) {
            visited[node - 1] = 1;
            int* neighbors;
            int size;
            neighbors = get_neighbors(graph, node, &size);
            for (int i = 0; i < size; i++) {
                if (!contains(visited, graph->num_nodes, neighbors[i])) {
                    Path new_path = {NULL, 0};
                    new_path.path = (int*)malloc((path.length + 1) * sizeof(int));
                    for (int j = 0; j < path.length; j++) {
                        new_path.path[j] = path.path[j];
                    }
                    new_path.path[path.length] = neighbors[i];
                    new_path.length = path.length + 1;
                    enqueue(&queue, neighbors[i], new_path);
                }
            }
            free(neighbors);
        }
    }

    free(visited);
    return result;
}

int main() {
    int nodes[] = {1, 2, 3, 4, 5};
    int edges[][2] = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}};
    int num_nodes = sizeof(nodes) / sizeof(nodes[0]);
    int num_edges = sizeof(edges) / sizeof(edges[0]);
    Graph graph = {nodes, edges, num_nodes, num_edges};

    int start_node = 1;
    int goal_node = 5;
    Path result = bfs(&graph, start_node, goal_node);

    if (result.length > 0) {
        for (int i = 0; i < result.length; i++) {
            printf("%d ", result.path[i]);
        }
        printf("\n");
    } else {
        printf("No path found\n");
    }

    return 0;
}