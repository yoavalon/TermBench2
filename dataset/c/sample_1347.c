#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

typedef struct {
    char key;
    char* value;
    int value_size;
} MapEntry;

typedef struct {
    MapEntry* entries;
    int size;
} Map;

void init_queue(Queue* q) {
    q->front = q->rear = NULL;
}

int is_empty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, char data, char** path, int path_size) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    Node* path_node = (Node*)malloc(sizeof(Node));
    path_node->data = data;
    path_node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        q->rear->next = path_node;
    } else {
        q->rear->next = temp;
        q->rear = temp;
        q->rear->next = path_node;
    }
}

char* dequeue(Queue* q, char** path, int* path_size) {
    if (is_empty(q)) return NULL;

    Node* temp = q->front;
    q->front = q->front->next;

    char* result = (char*)malloc(2 * sizeof(char));
    result[0] = temp->data;
    result[1] = '\0';

    Node* path_node = q->front;
    int size = 0;
    while (path_node) {
        size++;
        path_node = path_node->next;
    }

    *path = (char*)malloc(size * sizeof(char));
    path_node = q->front;
    for (int i = 0; i < size; i++) {
        (*path)[i] = path_node->data;
        path_node = path_node->next;
    }
    *path_size = size;

    free(temp);
    return result;
}

void free_queue(Queue* q) {
    while (!is_empty(q)) {
        char* temp = dequeue(q, NULL, NULL);
        free(temp);
    }
}

void init_map(Map* m, int size) {
    m->entries = (MapEntry*)malloc(size * sizeof(MapEntry));
    m->size = size;
    for (int i = 0; i < size; i++) {
        m->entries[i].key = '\0';
        m->entries[i].value = NULL;
        m->entries[i].value_size = 0;
    }
}

void add_map_entry(Map* m, char key, char* value, int value_size) {
    for (int i = 0; i < m->size; i++) {
        if (m->entries[i].key == '\0') {
            m->entries[i].key = key;
            m->entries[i].value = value;
            m->entries[i].value_size = value_size;
            break;
        }
    }
}

char* get_map_value(Map* m, char key) {
    for (int i = 0; i < m->size; i++) {
        if (m->entries[i].key == key) {
            return m->entries[i].value;
        }
    }
    return NULL;
}

int is_visited(char* visited, char node) {
    for (int i = 0; visited[i] != '\0'; i++) {
        if (visited[i] == node) {
            return 1;
        }
    }
    return 0;
}

void add_to_visited(char* visited, char node) {
    for (int i = 0; visited[i] != '\0'; i++) {
        if (visited[i] == '\0') {
            visited[i] = node;
            break;
        }
    }
}

char* bfs(Map* graph, char start, char end) {
    Queue queue;
    init_queue(&queue);

    char* initial_path = (char*)malloc(2 * sizeof(char));
    initial_path[0] = start;
    initial_path[1] = '\0';
    enqueue(&queue, start, &initial_path, 1);

    char visited[26] = {0}; // Assuming all nodes are letters A-Z

    while (!is_empty(&queue)) {
        char node;
        char* path;
        int path_size;
        node = dequeue(&queue, &path, &path_size)[0];

        if (node == end) {
            return path;
        }

        if (!is_visited(visited, node)) {
            add_to_visited(visited, node);

            char* neighbors = get_map_value(graph, node);
            for (int i = 0; i < neighbors[i] != '\0'; i++) {
                char* new_path = (char*)malloc((path_size + 2) * sizeof(char));
                strncpy(new_path, path, path_size);
                new_path[path_size] = neighbors[i];
                new_path[path_size + 1] = '\0';
                enqueue(&queue, neighbors[i], &new_path, path_size + 1);
            }
        }

        free(path);
    }

    free_queue(&queue);
    return NULL;
}

char* shortest_path(Map* graph, char start, char end) {
    return bfs(graph, start, end);
}

int main() {
    Map graph;
    init_map(&graph, 6);

    char* neighbors_A = (char*)malloc(3 * sizeof(char));
    neighbors_A[0] = 'B';
    neighbors_A[1] = 'C';
    neighbors_A[2] = '\0';
    add_map_entry(&graph, 'A', neighbors_A, 3);

    char* neighbors_B = (char*)malloc(3 * sizeof(char));
    neighbors_B[0] = 'D';
    neighbors_B[1] = 'E';
    neighbors_B[2] = '\0';
    add_map_entry(&graph, 'B', neighbors_B, 3);

    char* neighbors_C = (char*)malloc(2 * sizeof(char));
    neighbors_C[0] = 'F';
    neighbors_C[1] = '\0';
    add_map_entry(&graph, 'C', neighbors_C, 2);

    char* neighbors_D = (char*)malloc(1 * sizeof(char));
    neighbors_D[0] = '\0';
    add_map_entry(&graph, 'D', neighbors_D, 1);

    char* neighbors_E = (char*)malloc(2 * sizeof(char));
    neighbors_E[0] = 'F';
    neighbors_E[1] = '\0';
    add_map_entry(&graph, 'E', neighbors_E, 2);

    char* neighbors_F = (char*)malloc(1 * sizeof(char));
    neighbors_F[0] = '\0';
    add_map_entry(&graph, 'F', neighbors_F, 1);

    char start = 'A';
    char end = 'F';
    char* path = shortest_path(&graph, start, end);
    if (path) {
        printf("Shortest path: ");
        for (int i = 0; path[i] != '\0'; i++) {
            printf("%c", path[i]);
        }
        printf("\n");
    } else {
        printf("No path found\n");
    }

    for (int i = 0; i < graph.size; i++) {
        free(graph.entries[i].value);
    }
    free(graph.entries);

    return 0;
}