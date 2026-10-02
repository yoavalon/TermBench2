#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

typedef struct {
    int* nodes;
    int num_nodes;
    int** adj_list;
} Graph;

typedef struct {
    Graph* graph;
} ShortestPathFinder;

Queue* create_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, int data, int dist) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
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

int dequeue(Queue* queue, int* data, int* dist) {
    if (is_empty(queue)) {
        return 0;
    }
    Node* temp = queue->front;
    *data = temp->data;
    *dist = temp->data >> 16; // Assuming data is stored as (node << 16 | dist)
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return 1;
}

Graph* create_graph(int* nodes, int num_nodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodes = nodes;
    graph->num_nodes = num_nodes;
    graph->adj_list = (int**)malloc(num_nodes * sizeof(int*));
    for (int i = 0; i < num_nodes; i++) {
        graph->adj_list[i] = (int*)malloc(num_nodes * sizeof(int));
        for (int j = 0; j < num_nodes; j++) {
            graph->adj_list[i][j] = 0;
        }
    }
    return graph;
}

void add_edge(Graph* graph, int node1, int node2) {
    graph->adj_list[node1][node2] = 1;
    graph->adj_list[node2][node1] = 1;
}

int bfs(ShortestPathFinder* spf, int start, int end) {
    Queue* queue = create_queue();
    enqueue(queue, start, 0);
    int visited[spf->graph->num_nodes];
    for (int i = 0; i < spf->graph->num_nodes; i++) {
        visited[i] = 0;
    }
    while (!is_empty(queue)) {
        int node, dist;
        dequeue(queue, &node, &dist);
        if (node == end) {
            return dist;
        }
        if (!visited[node]) {
            visited[node] = 1;
            for (int i = 0; i < spf->graph->num_nodes; i++) {
                if (spf->graph->adj_list[node][i]) {
                    enqueue(queue, i, dist + 1);
                }
            }
        }
    }
    return -1;
}

void main() {
    int nodes[] = {0, 1, 2, 3, 4, 5, 6};
    int num_nodes = sizeof(nodes) / sizeof(nodes[0]);
    Graph* graph = create_graph(nodes, num_nodes);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 5);
    add_edge(graph, 5, 6);
    add_edge(graph, 0, 3);
    add_edge(graph, 3, 6);
    ShortestPathFinder spf;
    spf.graph = graph;
    int result = bfs(&spf, 0, 6);
    printf("%d\n", result);
}