#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10
#define MAX_NEIGHBORS 10

typedef struct {
    char *name;
    char *neighbors[MAX_NEIGHBORS];
    int neighbor_count;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int node_count;
} Graph;

typedef struct {
    char *name;
    struct List *next;
} List;

typedef struct {
    List *head;
    List *tail;
} Queue;

void enqueue(Queue *queue, char *name) {
    List *new_node = (List *)malloc(sizeof(List));
    new_node->name = strdup(name);
    new_node->next = NULL;
    if (queue->tail == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

char *dequeue(Queue *queue) {
    if (queue->head == NULL) {
        return NULL;
    }
    List *temp = queue->head;
    char *name = strdup(temp->name);
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(temp);
    return name;
}

int contains(List *list, char *name) {
    while (list != NULL) {
        if (strcmp(list->name, name) == 0) {
            return 1;
        }
        list = list->next;
    }
    return 0;
}

List *bfs(Graph *graph, char *start, char *end, List *visited) {
    if (visited == NULL) {
        visited = (List *)malloc(sizeof(List));
        visited->head = NULL;
        visited->tail = NULL;
    }
    enqueue(visited, start);
    if (strcmp(start, end) == 0) {
        List *path = (List *)malloc(sizeof(List));
        path->name = strdup(start);
        path->next = NULL;
        return path;
    }
    Node *current = NULL;
    for (int i = 0; i < graph->node_count; i++) {
        if (strcmp(graph->nodes[i].name, start) == 0) {
            current = &graph->nodes[i];
            break;
        }
    }
    if (current == NULL) {
        return NULL;
    }
    for (int i = 0; i < current->neighbor_count; i++) {
        char *neighbor = current->neighbors[i];
        if (!contains(visited, neighbor)) {
            List *path = bfs(graph, neighbor, end, visited);
            if (path != NULL) {
                List *new_path = (List *)malloc(sizeof(List));
                new_path->name = strdup(start);
                new_path->next = path;
                return new_path;
            }
        }
    }
    return NULL;
}

int main() {
    Graph graph;
    graph.node_count = 0;

    Node node_A = {"A", (char *[]){ "B", "C" }, 2};
    Node node_B = {"B", (char *[]){ "D", "E" }, 2};
    Node node_C = {"C", (char *[]){ "F" }, 1};
    Node node_D = {"D", NULL, 0};
    Node node_E = {"E", (char *[]){ "F" }, 1};
    Node node_F = {"F", NULL, 0};

    graph.nodes[graph.node_count++] = node_A;
    graph.nodes[graph.node_count++] = node_B;
    graph.nodes[graph.node_count++] = node_C;
    graph.nodes[graph.node_count++] = node_D;
    graph.nodes[graph.node_count++] = node_E;
    graph.nodes[graph.node_count++] = node_F;

    List *visited = NULL;
    List *path = bfs(&graph, "A", "F", visited);

    while (path != NULL) {
        printf("%s ", path->name);
        List *temp = path;
        path = path->next;
        free(temp);
    }
    printf("\n");

    return 0;
}