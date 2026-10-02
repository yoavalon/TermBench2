#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char value;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* queue, char value, char* path) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    char* newPath = (char*)malloc(strlen(path) + 2);
    strcpy(newPath, path);
    strcat(newPath, &value);
    strcat(newPath, ",");
    newNode->next = queue->rear;
    queue->rear = newNode;
    if (queue->front == NULL) {
        queue->front = newNode;
    }
}

void dequeue(Queue* queue, char* node, char* path) {
    if (queue->front == NULL) {
        return;
    }
    Node* temp = queue->front;
    queue->front = temp->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    *node = temp->value;
    strcpy(path, temp->next);
    free(temp);
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

typedef struct {
    char value;
    int count;
    char* neighbors;
} GraphNode;

typedef struct {
    int size;
    GraphNode* nodes;
} Graph;

char* bfs(Graph* graph, char start, char end) {
    Queue queue = {NULL, NULL};
    enqueue(&queue, start, &start);
    int visited[256] = {0};
    while (!isEmpty(&queue)) {
        char node;
        char path[100];
        dequeue(&queue, &node, path);
        if (node == end) {
            return strdup(path);
        }
        if (!visited[node]) {
            visited[node] = 1;
            for (int i = 0; i < graph->nodes[node].count; i++) {
                enqueue(&queue, graph->nodes[node].neighbors[i], path);
            }
        }
    }
    return strdup("");
}

int main() {
    Graph graph;
    graph.size = 6;
    graph.nodes = (GraphNode*)malloc(graph.size * sizeof(GraphNode));
    graph.nodes['A'] = (GraphNode){'A', 2, "BC"};
    graph.nodes['B'] = (GraphNode){'B', 2, "DE"};
    graph.nodes['C'] = (GraphNode){'C', 1, "F"};
    graph.nodes['D'] = (GraphNode){'D', 0, ""};
    graph.nodes['E'] = (GraphNode){'E', 1, "F"};
    graph.nodes['F'] = (GraphNode){'F', 0, ""};
    char* path = bfs(&graph, 'A', 'F');
    printf("%s\n", path);
    free(path);
    free(graph.nodes);
    return 0;
}