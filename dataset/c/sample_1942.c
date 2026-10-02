#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

typedef struct Graph {
    int num_nodes;
    int** adj_list;
} Graph;

void enqueue(Queue* queue, int value, int dist) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
        return;
    }

    queue->rear->next = new_node;
    queue->rear = new_node;
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return -1;
    }

    Node* temp = queue->front;
    int value = temp->value;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return value;
}

bool is_empty(Queue* queue) {
    return queue->front == NULL;
}

void bfs(Graph* graph, int start, int end) {
    Queue queue = {NULL, NULL};
    enqueue(&queue, start, 0);
    bool* visited = (bool*)calloc(graph->num_nodes, sizeof(bool));

    while (!is_empty(&queue)) {
        int node = dequeue(&queue);
        int dist = dequeue(&queue);

        if (node == end) {
            printf("%d\n", dist);
            free(visited);
            return;
        }

        if (!visited[node]) {
            visited[node] = true;
            for (int i = 0; i < graph->num_nodes; i++) {
                if (graph->adj_list[node][i] == 1) {
                    enqueue(&queue, i, dist + 1);
                }
            }
        }
    }

    printf("-1\n");
    free(visited);
}

void main() {
    Graph graph;
    graph.num_nodes = 4;
    graph.adj_list = (int**)malloc(graph.num_nodes * sizeof(int*));

    for (int i = 0; i < graph.num_nodes; i++) {
        graph.adj_list[i] = (int*)calloc(graph.num_nodes, sizeof(int));
    }

    graph.adj_list[0][1] = 1;
    graph.adj_list[0][2] = 1;
    graph.adj_list[1][2] = 1;
    graph.adj_list[2][0] = 1;
    graph.adj_list[2][3] = 1;
    graph.adj_list[3][3] = 1;

    int start = 0;
    int end = 3;
    bfs(&graph, start, end);

    for (int i = 0; i < graph.num_nodes; i++) {
        free(graph.adj_list[i]);
    }
    free(graph.adj_list);
}