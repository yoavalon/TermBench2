#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NEIGHBORS 10

typedef struct {
    char name;
    char neighbors[MAX_NEIGHBORS];
    int neighbor_count;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int node_count;
} Graph;

typedef struct {
    char data[MAX_NODES];
    int front;
    int rear;
} Queue;

void init_queue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int is_empty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, char value) {
    if (q->rear == MAX_NODES - 1) {
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->data[++q->rear] = value;
}

char dequeue(Queue *q) {
    if (is_empty(q)) {
        return '\0';
    }
    char value = q->data[q->front++];
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return value;
}

int bfs(Graph *graph, char start, char end) {
    Queue queue;
    init_queue(&queue);
    enqueue(&queue, start);
    int visited[MAX_NODES] = {0};
    int distances[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        distances[i] = -1;
    }
    distances[start - 'A'] = 0;

    while (!is_empty(&queue)) {
        char node = dequeue(&queue);
        if (node == end) {
            return distances[node - 'A'];
        }
        if (!visited[node - 'A']) {
            visited[node - 'A'] = 1;
            for (int i = 0; i < graph->nodes[node - 'A'].neighbor_count; i++) {
                char neighbor = graph->nodes[node - 'A'].neighbors[i];
                if (!visited[neighbor - 'A']) {
                    distances[neighbor - 'A'] = distances[node - 'A'] + 1;
                    enqueue(&queue, neighbor);
                }
            }
        }
    }
    return -1;
}

int shortest_path(Graph *graph, char start, char end) {
    return bfs(graph, start, end);
}

int main() {
    Graph graph;
    graph.node_count = 6;
    strcpy(graph.nodes[0].neighbors, "BD");
    graph.nodes[0].neighbor_count = 2;
    strcpy(graph.nodes[1].neighbors, "AE");
    graph.nodes[1].neighbor_count = 2;
    strcpy(graph.nodes[2].neighbors, "F");
    graph.nodes[2].neighbor_count = 1;
    strcpy(graph.nodes[3].neighbors, "B");
    graph.nodes[3].neighbor_count = 1;
    strcpy(graph.nodes[4].neighbors, "BE");
    graph.nodes[4].neighbor_count = 2;
    strcpy(graph.nodes[5].neighbors, "CF");
    graph.nodes[5].neighbor_count = 2;

    printf("%d\n", shortest_path(&graph, 'A', 'F'));
    return 0;
}