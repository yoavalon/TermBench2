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
} LinkedList;

typedef struct {
    char key;
    LinkedList* neighbors;
} GraphNode;

typedef struct {
    GraphNode* nodes;
    int size;
} Graph;

GraphNode* createGraphNode(char key) {
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    node->key = key;
    node->neighbors = (LinkedList*)malloc(sizeof(LinkedList));
    node->neighbors->head = NULL;
    node->neighbors->tail = NULL;
    return node;
}

void addNeighbor(GraphNode* node, char neighbor) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = neighbor;
    newNode->next = NULL;
    if (node->neighbors->head == NULL) {
        node->neighbors->head = newNode;
        node->neighbors->tail = newNode;
    } else {
        node->neighbors->tail->next = newNode;
        node->neighbors->tail = newNode;
    }
}

Graph* createGraph(int size) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodes = (GraphNode*)malloc(size * sizeof(GraphNode));
    graph->size = size;
    return graph;
}

void addNodeToGraph(Graph* graph, char key) {
    for (int i = 0; i < graph->size; i++) {
        if (graph->nodes[i].key == '\0') {
            graph->nodes[i] = *createGraphNode(key);
            break;
        }
    }
}

int isVisited(char* visited, char node) {
    for (int i = 0; i < strlen(visited); i++) {
        if (visited[i] == node) {
            return 1;
        }
    }
    return 0;
}

char* findShortestPath(Graph* graph, char start, char end, char* visited) {
    if (visited == NULL) {
        visited = (char*)malloc(graph->size * sizeof(char));
        visited[0] = '\0';
    }
    visited[strlen(visited)] = start;
    if (start == end) {
        char* path = (char*)malloc(2 * sizeof(char));
        path[0] = start;
        path[1] = '\0';
        return path;
    }
    for (Node* neighbor = graph->nodes->neighbors->head; neighbor != NULL; neighbor = neighbor->next) {
        if (!isVisited(visited, neighbor->value)) {
            char* path = findShortestPath(graph, neighbor->value, end, visited);
            if (path) {
                char* result = (char*)malloc((strlen(path) + 2) * sizeof(char));
                result[0] = start;
                strcpy(result + 1, path);
                free(path);
                return result;
            }
        }
    }
    return NULL;
}

int main() {
    Graph* graph = createGraph(8);
    addNodeToGraph(graph, 'A');
    addNodeToGraph(graph, 'B');
    addNodeToGraph(graph, 'C');
    addNodeToGraph(graph, 'D');
    addNodeToGraph(graph, 'E');
    addNodeToGraph(graph, 'F');
    addNodeToGraph(graph, 'G');
    addNodeToGraph(graph, 'H');
    addNeighbor(&graph->nodes[0], 'B');
    addNeighbor(&graph->nodes[0], 'C');
    addNeighbor(&graph->nodes[1], 'D');
    addNeighbor(&graph->nodes[1], 'E');
    addNeighbor(&graph->nodes[2], 'F');
    addNeighbor(&graph->nodes[3], 'G');
    addNeighbor(&graph->nodes[4], 'F');
    addNeighbor(&graph->nodes[4], 'H');
    addNeighbor(&graph->nodes[5], 'G');
    addNeighbor(&graph->nodes[6], 'H');
    char start = 'A';
    char end = 'H';
    while (1) {
        char* path = findShortestPath(graph, start, end, NULL);
        if (path) {
            printf("%s\n", path);
            free(path);
        }
    }
    return 0;
}