#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char* name;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

typedef struct Graph {
    List* adjLists;
    char** vertices;
    int size;
} Graph;

List* createList() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

void addNode(List* list, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->name = strdup(name);
    newNode->next = list->head;
    list->head = newNode;
}

Graph* createGraph(char** vertices, int size) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->adjLists = (List*)malloc(size * sizeof(List));
    graph->vertices = vertices;
    graph->size = size;
    for (int i = 0; i < size; i++) {
        graph->adjLists[i] = createList();
    }
    return graph;
}

int getVertexIndex(Graph* graph, char* vertex) {
    for (int i = 0; i < graph->size; i++) {
        if (strcmp(graph->vertices[i], vertex) == 0) {
            return i;
        }
    }
    return -1;
}

void addEdge(Graph* graph, char* src, char* dest) {
    int srcIndex = getVertexIndex(graph, src);
    int destIndex = getVertexIndex(graph, dest);
    if (srcIndex != -1 && destIndex != -1) {
        addNode(&graph->adjLists[srcIndex], dest);
    }
}

bool dfs(Graph* graph, char* start, char* end, char** path, int* pathIndex, bool* visited) {
    int startIndex = getVertexIndex(graph, start);
    if (startIndex == -1) {
        return false;
    }
    path[*pathIndex] = strdup(start);
    (*pathIndex)++;
    visited[startIndex] = true;
    if (strcmp(start, end) == 0) {
        return true;
    }
    Node* temp = graph->adjLists[startIndex].head;
    while (temp != NULL) {
        int tempIndex = getVertexIndex(graph, temp->name);
        if (!visited[tempIndex]) {
            bool result = dfs(graph, temp->name, end, path, pathIndex, visited);
            if (result) {
                return true;
            }
        }
        temp = temp->next;
    }
    return false;
}

char** shortest_path(Graph* graph, char* start, char* end, int* pathLength) {
    char** path = (char**)malloc(graph->size * sizeof(char*));
    bool* visited = (bool*)calloc(graph->size, sizeof(bool));
    *pathLength = 0;
    if (dfs(graph, start, end, path, pathLength, visited)) {
        return path;
    }
    free(path);
    free(visited);
    return NULL;
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->size; i++) {
        Node* temp = graph->adjLists[i].head;
        while (temp != NULL) {
            Node* next = temp->next;
            free(temp->name);
            free(temp);
            temp = next;
        }
    }
    free(graph->adjLists);
    free(graph);
}

int main() {
    char* vertices[] = {"A", "B", "C", "D", "E"};
    int size = sizeof(vertices) / sizeof(vertices[0]);
    Graph* graph = createGraph(vertices, size);
    addEdge(graph, "A", "B");
    addEdge(graph, "A", "C");
    addEdge(graph, "B", "C");
    addEdge(graph, "B", "D");
    addEdge(graph, "C", "D");
    addEdge(graph, "D", "E");

    char* start = "A";
    char* end = "E";
    int pathLength;
    char** result = shortest_path(graph, start, end, &pathLength);
    if (result) {
        for (int i = 0; i < pathLength; i++) {
            printf("%s ", result[i]);
        }
        printf("\n");
        for (int i = 0; i < pathLength; i++) {
            free(result[i]);
        }
        free(result);
    }
    freeGraph(graph);
    return 0;
}