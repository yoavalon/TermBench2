#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 26
#define MAX_PATH 100

typedef struct Node {
    char name;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* queue, char name, char path[], int path_len) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->name = name;
    new_node->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    memcpy(new_node->path, path, path_len);
}

char* dequeue(Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    char* result = temp->path;
    free(temp);
    return result;
}

int bfs(char graph[][MAX_NODES], int num_nodes, char start, char end) {
    Queue queue;
    queue.front = queue.rear = NULL;
    int visited[MAX_NODES] = {0};
    char path[MAX_PATH];
    path[0] = start;
    path[1] = '\0';
    enqueue(&queue, start, path, 2);
    visited[start - 'A'] = 1;
    while (queue.front != NULL) {
        char name = dequeue(&queue);
        if (name == end) {
            return 1;
        }
        for (int i = 0; i < num_nodes; i++) {
            if (graph[name - 'A'][i] != '\0' && !visited[graph[name - 'A'][i] - 'A']) {
                path[strlen(path)] = graph[name - 'A'][i];
                path[strlen(path) + 1] = '\0';
                enqueue(&queue, graph[name - 'A'][i], path, strlen(path) + 1);
                visited[graph[name - 'A'][i] - 'A'] = 1;
            }
        }
    }
    return 0;
}

void shortest_path(char graph[][MAX_NODES], int num_nodes, char start, char end) {
    if (bfs(graph, num_nodes, start, end)) {
        printf("%c %c\n", start, end);
    } else {
        printf("No path found\n");
    }
}

int main() {
    char graph[MAX_NODES][MAX_NODES] = {
        {'B', 'C', '\0'},
        {'D', 'E', '\0'},
        {'F', '\0'},
        {'\0'},
        {'F', '\0'},
        {'\0'}
    };
    int num_nodes = 6;
    char start_node = 'A';
    char end_node = 'F';
    shortest_path(graph, num_nodes, start_node, end_node);
    return 0;
}