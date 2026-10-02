#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 26

typedef struct {
    char *key;
    char *neighbors[MAX_NODES];
    int neighbor_count;
} GraphNode;

typedef struct {
    GraphNode **nodes;
    int size;
} Graph;

typedef struct {
    char **items;
    int front;
    int rear;
    int size;
} Queue;

Graph *create_graph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->nodes = (GraphNode **)malloc(sizeof(GraphNode *) * MAX_NODES);
    graph->size = 0;
    return graph;
}

GraphNode *create_graph_node(char *key) {
    GraphNode *node = (GraphNode *)malloc(sizeof(GraphNode));
    node->key = strdup(key);
    node->neighbor_count = 0;
    return node;
}

void add_edge(Graph *graph, char *node, char *neighbor) {
    int i;
    for (i = 0; i < graph->size; i++) {
        if (strcmp(graph->nodes[i]->key, node) == 0) {
            break;
        }
    }
    if (i == graph->size) {
        graph->nodes[graph->size++] = create_graph_node(node);
    }
    for (i = 0; i < graph->size; i++) {
        if (strcmp(graph->nodes[i]->key, neighbor) == 0) {
            break;
        }
    }
    if (i == graph->size) {
        graph->nodes[graph->size++] = create_graph_node(neighbor);
    }
    graph->nodes[i]->neighbors[graph->nodes[i]->neighbor_count++] = strdup(neighbor);
}

char **get_neighbors(Graph *graph, char *node) {
    for (int i = 0; i < graph->size; i++) {
        if (strcmp(graph->nodes[i]->key, node) == 0) {
            return graph->nodes[i]->neighbors;
        }
    }
    return NULL;
}

Queue *create_queue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->items = (char **)malloc(sizeof(char *) * MAX_NODES);
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

void enqueue(Queue *queue, char *item) {
    queue->rear = (queue->rear + 1) % MAX_NODES;
    queue->items[queue->rear] = strdup(item);
    queue->size++;
}

char *dequeue(Queue *queue) {
    if (queue->size == 0) {
        return NULL;
    }
    char *item = queue->items[queue->front];
    queue->front = (queue->front + 1) % MAX_NODES;
    queue->size--;
    return item;
}

bool is_empty(Queue *queue) {
    return queue->size == 0;
}

bool bfs(Graph *graph, char *start, char *goal) {
    Queue *queue = create_queue();
    bool visited[MAX_NODES] = {false};
    int node_index;
    for (node_index = 0; node_index < graph->size; node_index++) {
        if (strcmp(graph->nodes[node_index]->key, start) == 0) {
            break;
        }
    }
    enqueue(queue, graph->nodes[node_index]->key);
    visited[node_index] = true;
    while (!is_empty(queue)) {
        char *current = dequeue(queue);
        char **neighbors = get_neighbors(graph, current);
        for (int i = 0; i < graph->nodes[node_index]->neighbor_count; i++) {
            for (node_index = 0; node_index < graph->size; node_index++) {
                if (strcmp(graph->nodes[node_index]->key, neighbors[i]) == 0) {
                    break;
                }
            }
            if (!visited[node_index]) {
                visited[node_index] = true;
                enqueue(queue, graph->nodes[node_index]->key);
                if (strcmp(graph->nodes[node_index]->key, goal) == 0) {
                    return true;
                }
            }
        }
    }
    return false;
}

void main() {
    Graph *graph = create_graph();
    add_edge(graph, "A", "B");
    add_edge(graph, "B", "C");
    add_edge(graph, "C", "D");
    add_edge(graph, "D", "E");
    add_edge(graph, "E", "F");
    add_edge(graph, "F", "G");
    add_edge(graph, "G", "H");
    add_edge(graph, "H", "I");
    add_edge(graph, "I", "J");
    add_edge(graph, "J", "K");
    char *start_node = "A";
    char *goal_node = "K";
    while (true) {
        if (bfs(graph, start_node, goal_node)) {
            printf("Goal reached.\n");
        } else {
            printf("Goal not found.\n");
        }
    }
}