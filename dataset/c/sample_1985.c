c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITY 1000000

typedef struct {
    char *key;
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} List;

typedef struct {
    List *adjacencyList;
    int size;
} Graph;

typedef struct {
    char *key;
    int value;
} Entry;

typedef struct {
    Entry *entries;
    int size;
} Map;

typedef struct {
    char *key;
    Map *value;
    struct HeapNode *next;
} HeapNode;

typedef struct {
    HeapNode *head;
} MinHeap;

Map* createMap(int size) {
    Map *map = (Map*)malloc(sizeof(Map));
    map->entries = (Entry*)malloc(size * sizeof(Entry));
    map->size = size;
    for (int i = 0; i < size; i++) {
        map->entries[i].key = NULL;
        map->entries[i].value = INFINITY;
    }
    return map;
}

void setMap(Map *map, char *key, int value) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == NULL || strcmp(map->entries[i].key, key) == 0) {
            map->entries[i].key = key;
            map->entries[i].value = value;
            return;
        }
    }
}

int getMap(Map *map, char *key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key != NULL && strcmp(map->entries[i].key, key) == 0) {
            return map->entries[i].value;
        }
    }
    return INFINITY;
}

MinHeap* createMinHeap() {
    MinHeap *heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->head = NULL;
    return heap;
}

void insertMinHeap(MinHeap *heap, char *key, int value) {
    HeapNode *newNode = (HeapNode*)malloc(sizeof(HeapNode));
    newNode->key = key;
    newNode->value = createMap(1);
    setMap(newNode->value, key, value);
    newNode->next = heap->head;
    heap->head = newNode;
}

void extractMinHeap(MinHeap *heap, char **key, int *value) {
    HeapNode *minNode = heap->head;
    HeapNode *prev = NULL;
    while (minNode->next != NULL) {
        if (getMap(minNode->next->value, minNode->next->key) < getMap(minNode->value, minNode->key)) {
            minNode = minNode->next;
        }
        prev = minNode;
    }
    if (prev == NULL) {
        heap->head = minNode->next;
    } else {
        prev->next = minNode->next;
    }
    *key = minNode->key;
    *value = getMap(minNode->value, minNode->key);
    free(minNode->value);
    free(minNode);
}

int isEmptyMinHeap(MinHeap *heap) {
    return heap->head == NULL;
}

Graph* createGraph(int size) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->adjacencyList = (List*)malloc(size * sizeof(List));
    graph->size = size;
    for (int i = 0; i < size; i++) {
        graph->adjacencyList[i].head = NULL;
    }
    return graph;
}

void addEdge(Graph *graph, char *start, char *end, int weight) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = end;
    newNode->value = weight;
    newNode->next = graph->adjacencyList[hash(start)].head;
    graph->adjacencyList[hash(start)].head = newNode;
}

int hash(char *key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash * 31 + key[i]) % graph->size;
    }
    return hash;
}

Map* dijkstra(Graph *graph, char *start) {
    Map *dist = createMap(graph->size);
    setMap(dist, start, 0);
    MinHeap *heap = createMinHeap();
    insertMinHeap(heap, start, 0);
    while (!isEmptyMinHeap(heap)) {
        char *currentNode;
        int currentDist;
        extractMinHeap(heap, &currentNode, &currentDist);
        if (currentDist > getMap(dist, currentNode)) {
            continue;
        }
        Node *neighbor = graph->adjacencyList[hash(currentNode)].head;
        while (neighbor != NULL) {
            int distance = currentDist + neighbor->value;
            if (distance < getMap(dist, neighbor->key)) {
                setMap(dist, neighbor->key, distance);
                insertMinHeap(heap, neighbor->key, distance);
            }
            neighbor = neighbor->next;
        }
    }
    return dist;
}

int findShortestPath(Graph *graph, char *start, char *end) {
    Map *distances = dijkstra(graph, start);
    return getMap(distances, end);
}

int main() {
    Graph *graph = createGraph(4);
    addEdge(graph, "A", "B", 1);
    addEdge(graph, "A", "C", 4);
    addEdge(graph, "B", "A", 1);
    addEdge(graph, "B", "C", 2);
    addEdge(graph, "B", "D", 5);
    addEdge(graph, "C", "A", 4);
    addEdge(graph, "C", "B", 2);
    addEdge(graph, "C", "D", 1);
    addEdge(graph, "D", "B", 5);
    addEdge(graph, "D", "C", 1);
    printf("%d\n", findShortestPath(graph, "A", "D"));
    return 0;
}