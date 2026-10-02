c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char node;
    char* path;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

typedef struct {
    char key;
    char** neighbors;
    int size;
} GraphNode;

typedef struct {
    GraphNode* nodes;
    int size;
} Graph;

void enqueue(Queue* queue, char node, char* path) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->node = node;
    new_node->path = strdup(path);
    new_node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
        return;
    }

    queue->rear->next = new_node;
    queue->rear = new_node;
}

Node* dequeue(Queue* queue) {
    if (queue->front == NULL)
        return NULL;

    Node* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    return temp;
}

int is_visited(char* visited, int size, char node) {
    for (int i = 0; i < size; i++) {
        if (visited[i] == node)
            return 1;
    }
    return 0;
}

char* graph_traversal(Graph* graph, char start, char end) {
    Queue queue = {NULL, NULL};
    char visited[26] = {0};
    int visited_count = 0;

    char start_path[2] = {start, '\0'};
    enqueue(&queue, start, start_path);

    while (queue.front != NULL) {
        Node* current = dequeue(&queue);
        char node = current->node;
        char* path = current->path;

        if (node == end) {
            return path;
        }

        if (!is_visited(visited, visited_count, node)) {
            visited[visited_count++] = node;
            for (int i = 0; i < graph->nodes[node - 'A'].size; i++) {
                char neighbor = graph->nodes[node - 'A'].neighbors[i];
                char new_path[26];
                snprintf(new_path, sizeof(new_path), "%s%c", path, neighbor);
                enqueue(&queue, neighbor, new_path);
            }
        }

        free(current->path);
        free(current);
    }

    return NULL;
}

Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodes = (GraphNode*)malloc(6 * sizeof(GraphNode));
    graph->size = 6;

    char* neighbors_A[] = {"B", "C"};
    char* neighbors_B[] = {"D", "E"};
    char* neighbors_C[] = {"F"};
    char* neighbors_D[] = {};
    char* neighbors_E[] = {"F"};
    char* neighbors_F[] = {};

    graph->nodes[0] = (GraphNode){'A', neighbors_A, 2};
    graph->nodes[1] = (GraphNode){'B', neighbors_B, 2};
    graph->nodes[2] = (GraphNode){'C', neighbors_C, 1};
    graph->nodes[3] = (GraphNode){'D', neighbors_D, 0};
    graph->nodes[4] = (GraphNode){'E', neighbors_E, 1};
    graph->nodes[5] = (GraphNode){'F', neighbors_F, 0};

    return graph;
}

void free_graph(Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        free(graph->nodes[i].neighbors);
    }
    free(graph->nodes);
    free(graph);
}

int main() {
    Graph* graph = create_graph();
    char* result = graph_traversal(graph, 'A', 'F');
    if (result != NULL) {
        printf("%s\n", result);
        free(result);
    } else {
        printf("Path not found\n");
    }
    free_graph(graph);
    return 0;
}