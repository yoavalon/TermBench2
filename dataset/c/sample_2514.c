#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10
#define MAX_PATH 20

typedef struct Node {
    char name;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

typedef struct {
    char name;
    Node* neighbors;
} GraphNode;

typedef struct {
    GraphNode nodes[MAX_NODES];
    int node_count;
} Graph;

void enqueue(Queue* q, char data[], int path_length) {
    Node* temp = (Node*)malloc(sizeof(Node));
    strncpy(temp->name, data, sizeof(temp->name));
    temp->next = NULL;
    if (q->front == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void dequeue(Queue* q, char data[], int* path_length) {
    if (q->front == NULL) {
        return;
    }
    Node* temp = q->front;
    strncpy(data, temp->name, sizeof(data));
    *path_length = strlen(data);
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

int is_empty(Queue* q) {
    return q->front == NULL;
}

int main() {
    GraphNode graph_nodes[MAX_NODES] = {
        {'A', NULL}, {'B', NULL}, {'C', NULL}, {'D', NULL}, {'E', NULL},
        {'F', NULL}, {'G', NULL}
    };
    Graph graph = {graph_nodes, 7};

    graph.nodes[0].neighbors = (Node*)malloc(sizeof(Node) * 2);
    graph.nodes[0].neighbors[0] = (Node){'B', NULL};
    graph.nodes[0].neighbors[1] = (Node){'C', NULL};

    graph.nodes[1].neighbors = (Node*)malloc(sizeof(Node) * 2);
    graph.nodes[1].neighbors[0] = (Node){'D', NULL};
    graph.nodes[1].neighbors[1] = (Node){'E', NULL};

    graph.nodes[2].neighbors = (Node*)malloc(sizeof(Node) * 1);
    graph.nodes[2].neighbors[0] = (Node){'F', NULL};

    graph.nodes[3].neighbors = (Node*)malloc(sizeof(Node) * 1);
    graph.nodes[3].neighbors[0] = (Node){'G', NULL};

    graph.nodes[4].neighbors = (Node*)malloc(sizeof(Node) * 1);
    graph.nodes[4].neighbors[0] = (Node){'F', NULL};

    graph.nodes[5].neighbors = (Node*)malloc(sizeof(Node) * 1);
    graph.nodes[5].neighbors[0] = (Node){'G', NULL};

    graph.nodes[6].neighbors = NULL;

    Queue queue = {NULL, NULL};
    char start_node[] = "A";
    char goal_node[] = "G";
    char path[MAX_PATH];
    int path_length = 0;

    enqueue(&queue, start_node, path_length);
    char visited[MAX_NODES];
    memset(visited, 0, sizeof(visited));
    visited[0] = 1;

    while (!is_empty(&queue)) {
        char current_node[MAX_NODES];
        dequeue(&queue, current_node, &path_length);
        if (strcmp(current_node, goal_node) == 0) {
            printf("%s\n", current_node);
            break;
        }
        for (int i = 0; i < graph.node_count; i++) {
            if (graph.nodes[i].name == current_node[0]) {
                Node* neighbor = graph.nodes[i].neighbors;
                while (neighbor != NULL) {
                    if (!visited[neighbor->name - 'A']) {
                        visited[neighbor->name - 'A'] = 1;
                        char new_path[MAX_PATH];
                        strcpy(new_path, current_node);
                        strncat(new_path, neighbor->name, 1);
                        enqueue(&queue, new_path, strlen(new_path));
                    }
                    neighbor = neighbor->next;
                }
                break;
            }
        }
    }

    return 0;
}