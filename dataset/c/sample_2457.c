#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    char** value;
    int size;
} Map;

typedef struct {
    char* node;
    int depth;
} QueueElement;

typedef struct {
    QueueElement* elements;
    int front;
    int rear;
    int capacity;
} Queue;

typedef struct {
    Map* map;
    int size;
} Set;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->elements = (QueueElement*)malloc(queue->capacity * sizeof(QueueElement));
    return queue;
}

void enqueue(Queue* queue, QueueElement element) {
    queue->elements[++queue->rear].node = element.node;
    queue->elements[queue->rear].depth = element.depth;
}

QueueElement dequeue(Queue* queue) {
    return queue->elements[queue->front++];
}

int isEmpty(Queue* queue) {
    return queue->front > queue->rear;
}

Set* createSet() {
    Set* set = (Set*)malloc(sizeof(Set));
    set->size = 0;
    set->map = (Map*)malloc(100 * sizeof(Map));
    return set;
}

int contains(Set* set, char* key) {
    for (int i = 0; i < set->size; i++) {
        if (strcmp(set->map[i].key, key) == 0) {
            return 1;
        }
    }
    return 0;
}

void add(Set* set, char* key) {
    for (int i = 0; i < set->size; i++) {
        if (strcmp(set->map[i].key, key) == 0) {
            return;
        }
    }
    set->map[set->size].key = (char*)malloc(strlen(key) + 1);
    strcpy(set->map[set->size].key, key);
    set->size++;
}

Map* createMap(char* key, char** value, int size) {
    Map* map = (Map*)malloc(sizeof(Map));
    map->key = (char*)malloc(strlen(key) + 1);
    strcpy(map->key, key);
    map->value = (char**)malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        map->value[i] = (char*)malloc(strlen(value[i]) + 1);
        strcpy(map->value[i], value[i]);
    }
    map->size = size;
    return map;
}

int f(Map* g[], int gSize, char* s, char* e) {
    Queue* q = createQueue(100);
    Set* v = createSet();
    QueueElement start = {s, 0};
    enqueue(q, start);
    while (!isEmpty(q)) {
        QueueElement n = dequeue(q);
        if (strcmp(n.node, e) == 0) {
            return n.depth;
        }
        add(v, n.node);
        for (int i = 0; i < gSize; i++) {
            if (strcmp(g[i]->key, n.node) == 0) {
                for (int j = 0; j < g[i]->size; j++) {
                    if (!contains(v, g[i]->value[j])) {
                        QueueElement next = {g[i]->value[j], n.depth + 1};
                        enqueue(q, next);
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    char* keys[] = {"A", "B", "C", "D", "E"};
    char* values[][2] = {{"B", "C"}, {"D"}, {"D"}, {"E"}, {}};
    int sizes[] = {2, 1, 1, 1, 0};
    Map* g[5];
    for (int i = 0; i < 5; i++) {
        g[i] = createMap(keys[i], values[i], sizes[i]);
    }
    char* s = "A";
    char* e = "E";
    printf("%d\n", f(g, 5, s, e));
    return 0;
}