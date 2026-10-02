#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} Queue;

typedef struct {
    char key;
    char** neighbors;
    int size;
    int capacity;
} GraphNode;

typedef struct {
    GraphNode* nodes;
    int size;
    int capacity;
} Graph;

void enqueue(Queue* queue, char value, char* path) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (queue->head == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}

Node* dequeue(Queue* queue) {
    if (queue->head == NULL) {
        return NULL;
    }

    Node* temp = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    return temp;
}

int is_empty(Queue* queue) {
    return queue->head == NULL;
}

void add_neighbor(GraphNode* node, char neighbor) {
    if (node->size == node->capacity) {
        node->capacity *= 2;
        node->neighbors = (char**)realloc(node->neighbors, node->capacity * sizeof(char*));
    }
    node->neighbors[node->size++] = (char*)malloc(2 * sizeof(char));
    node->neighbors[node->size - 1][0] = neighbor;
    node->neighbors[node->size - 1][1] = '\0';
}

GraphNode* get_node(Graph* graph, char key) {
    for (int i = 0; i < graph->size; i++) {
        if (graph->nodes[i].key == key) {
            return &graph->nodes[i];
        }
    }
    return NULL;
}

Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->size = 0;
    graph->capacity = 4;
    graph->nodes = (GraphNode*)malloc(graph->capacity * sizeof(GraphNode));
    return graph;
}

void add_edge(Graph* graph, char from, char to) {
    GraphNode* fromNode = get_node(graph, from);
    if (fromNode == NULL) {
        if (graph->size == graph->capacity) {
            graph->capacity *= 2;
            graph->nodes = (GraphNode*)realloc(graph->nodes, graph->capacity * sizeof(GraphNode));
        }
        fromNode = &graph->nodes[graph->size++];
        fromNode->key = from;
        fromNode->size = 0;
        fromNode->capacity = 4;
        fromNode->neighbors = (char**)malloc(fromNode->capacity * sizeof(char*));
    }

    add_neighbor(fromNode, to);
}

char** bfs_shortest_path(Graph* graph, char start, char end) {
    Queue queue = {NULL, NULL};
    enqueue(&queue, start, NULL);
    int* visited = (int*)calloc(256, sizeof(int));

    while (!is_empty(&queue)) {
        Node* current = dequeue(&queue);
        char currentNode = current->value;
        if (currentNode == end) {
            char** path = (char**)malloc(256 * sizeof(char*));
            int pathIndex = 0;
            while (current) {
                path[pathIndex++] = (char*)malloc(2 * sizeof(char));
                path[pathIndex - 1][0] = current->value;
                path[pathIndex - 1][1] = '\0';
                current = current->next;
            }
            free(visited);
            return path;
        }
        if (!visited[(unsigned char)currentNode]) {
            visited[(unsigned char)currentNode] = 1;
            GraphNode* node = get_node(graph, currentNode);
            if (node) {
                for (int i = 0; i < node->size; i++) {
                    char neighbor = node->neighbors[i][0];
                    if (!visited[(unsigned char)neighbor]) {
                        enqueue(&queue, neighbor, NULL);
                    }
                }
            }
        }
    }
    free(visited);
    return NULL;
}

void main() {
    Graph* graph = create_graph();
    add_edge(graph, 'A', 'B');
    add_edge(graph, 'A', 'C');
    add_edge(graph, 'B', 'D');
    add_edge(graph, 'B', 'E');
    add_edge(graph, 'C', 'F');
    add_edge(graph, 'E', 'F');

    char start = 'A';
    char end = 'F';
    char** path = bfs_shortest_path(graph, start, end);
    if (path) {
        int i = 0;
        while (path[i]) {
            printf("%c", path[i][0]);
            if (path[i + 1]) {
                printf(" -> ");
            }
            free(path[i]);
            i++;
        }
        printf("\n");
    } else {
        printf("No path found\n");
    }

    // Cleanup
    for (int i = 0; i < graph->size; i++) {
        for (int j = 0; j < graph->nodes[i].size; j++) {
            free(graph->nodes[i].neighbors[j]);
        }
        free(graph->nodes[i].neighbors);
    }
    free(graph->nodes);
    free(graph);
}