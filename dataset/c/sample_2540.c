#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char value;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* q, char value, char* path) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(Queue* q, char* value, char* path) {
    if (q->front == NULL) {
        return;
    }
    Node* temp = q->front;
    *value = temp->value;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

int contains(char** path, int pathLength, char value) {
    for (int i = 0; i < pathLength; i++) {
        if (path[i] == value) {
            return 1;
        }
    }
    return 0;
}

char** bfs(char** graph, char start, char end, int* pathLength) {
    Queue q = {NULL, NULL};
    char** path = (char**)malloc(sizeof(char*) * 100);
    int pathIndex = 0;
    path[pathIndex++] = &start;
    enqueue(&q, start, path);

    while (!isEmpty(&q)) {
        char node;
        dequeue(&q, &node, path);
        if (node == end) {
            *pathLength = pathIndex;
            return path;
        }
        char* neighbors = graph[node - 'A'];
        while (*neighbors != '\0') {
            if (!contains(path, pathIndex, *neighbors)) {
                path[pathIndex++] = neighbors;
                enqueue(&q, *neighbors, path);
            }
            neighbors++;
        }
    }
    *pathLength = 0;
    free(path);
    return NULL;
}

char** shortest_path(char** graph, char a, char b, int* pathLength) {
    return bfs(graph, a, b, pathLength);
}

void main() {
    char* graph[6];
    graph[0] = "BC"; // A
    graph[1] = "ADE"; // B
    graph[2] = "F"; // C
    graph[3] = ""; // D
    graph[4] = "F"; // E
    graph[5] = ""; // F

    char start_node = 'A';
    char end_node = 'F';
    int pathLength;
    char** path = shortest_path(graph, start_node, end_node, &pathLength);

    if (path != NULL) {
        for (int i = 0; i < pathLength; i++) {
            printf("%c ", *path[i]);
        }
        printf("\n");
    } else {
        printf("No path found\n");
    }
}