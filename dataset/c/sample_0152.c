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
    char path[MAX_NODES];
    int length;
} Path;

typedef struct {
    Node nodes[MAX_NODES];
    int node_count;
} Graph;

typedef struct {
    Node* node;
    Path path;
} QueueElement;

typedef struct {
    QueueElement elements[MAX_NODES * MAX_NEIGHBORS];
    int front;
    int rear;
} Queue;

void init_queue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int is_empty(Queue* q) {
    return q->front > q->rear;
}

void enqueue(Queue* q, Node* node, Path* path) {
    q->rear++;
    q->elements[q->rear].node = node;
    memcpy(q->elements[q->rear].path.path, path->path, path->length);
    q->elements[q->rear].path.length = path->length;
}

QueueElement dequeue(Queue* q) {
    QueueElement element = q->elements[q->front];
    q->front++;
    return element;
}

int bfs(Graph* graph, char start, char end, Path* result) {
    Queue queue;
    init_queue(&queue);

    Path initial_path;
    initial_path.path[0] = start;
    initial_path.length = 1;
    enqueue(&queue, graph->nodes, &initial_path);

    int visited[MAX_NODES] = {0};
    visited[start - 'A'] = 1;

    while (!is_empty(&queue)) {
        QueueElement element = dequeue(&queue);
        Node* current_node = element.node;
        Path current_path = element.path;

        if (current_node->name == end) {
            memcpy(result->path, current_path.path, current_path.length);
            result->length = current_path.length;
            return 1;
        }

        for (int i = 0; i < current_node->neighbor_count; i++) {
            char neighbor = current_node->neighbors[i];
            if (!visited[neighbor - 'A']) {
                visited[neighbor - 'A'] = 1;
                Path new_path;
                memcpy(new_path.path, current_path.path, current_path.length);
                new_path.path[current_path.length] = neighbor;
                new_path.length = current_path.length + 1;
                enqueue(&queue, &graph->nodes[neighbor - 'A'], &new_path);
            }
        }
    }

    return 0;
}

void find_shortest_path(Graph* graph, char start, char end, Path* result) {
    bfs(graph, start, end, result);
}

int main() {
    Graph graph;
    graph.node_count = 6;
    graph.nodes[0].name = 'A';
    graph.nodes[0].neighbors[0] = 'B';
    graph.nodes[0].neighbors[1] = 'C';
    graph.nodes[0].neighbor_count = 2;
    graph.nodes[1].name = 'B';
    graph.nodes[1].neighbors[0] = 'D';
    graph.nodes[1].neighbors[1] = 'E';
    graph.nodes[1].neighbor_count = 2;
    graph.nodes[2].name = 'C';
    graph.nodes[2].neighbors[0] = 'F';
    graph.nodes[2].neighbor_count = 1;
    graph.nodes[3].name = 'D';
    graph.nodes[3].neighbor_count = 0;
    graph.nodes[4].name = 'E';
    graph.nodes[4].neighbors[0] = 'F';
    graph.nodes[4].neighbor_count = 1;
    graph.nodes[5].name = 'F';
    graph.nodes[5].neighbor_count = 0;

    char start_node = 'A';
    char end_node = 'F';
    Path path;
    find_shortest_path(&graph, start_node, end_node, &path);

    for (int i = 0; i < path.length; i++) {
        printf("%c ", path.path[i]);
    }
    printf("\n");

    return 0;
}