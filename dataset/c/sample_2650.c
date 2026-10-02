#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 100

typedef struct {
    char name[10];
    int weight;
} Edge;

typedef struct {
    char name[10];
    Edge edges[MAX_EDGES];
    int edge_count;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int node_count;
} Graph;

void add_edge(Graph *graph, const char *u, const char *v, int weight) {
    int i;
    for (i = 0; i < graph->node_count; i++) {
        if (strcmp(graph->nodes[i].name, u) == 0) {
            break;
        }
    }
    if (i == graph->node_count) {
        strcpy(graph->nodes[i].name, u);
        graph->nodes[i].edge_count = 0;
        graph->node_count++;
    }
    strcpy(graph->nodes[i].edges[graph->nodes[i].edge_count].name, v);
    graph->nodes[i].edges[graph->nodes[i].edge_count].weight = weight;
    graph->nodes[i].edge_count++;
}

Edge* get_neighbors(Graph *graph, const char *node) {
    int i;
    for (i = 0; i < graph->node_count; i++) {
        if (strcmp(graph->nodes[i].name, node) == 0) {
            return graph->nodes[i].edges;
        }
    }
    return NULL;
}

typedef struct {
    int cost;
    const char *name;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} PriorityQueue;

void pq_init(PriorityQueue *pq) {
    pq->front = NULL;
    pq->rear = NULL;
}

void pq_push(PriorityQueue *pq, int cost, const char *name, const char *path[]) {
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    new_node->cost = cost;
    strcpy(new_node->name, name);
    new_node->next = NULL;

    if (pq->rear == NULL) {
        pq->front = pq->rear = new_node;
        return;
    }

    QueueNode *temp;
    for (temp = pq->front; temp->next != NULL && temp->next->cost < cost; temp = temp->next);

    new_node->next = temp->next;
    temp->next = new_node;

    if (temp == pq->rear) {
        pq->rear = new_node;
    }
}

QueueNode* pq_pop(PriorityQueue *pq) {
    if (pq->front == NULL) {
        return NULL;
    }
    QueueNode *temp = pq->front;
    pq->front = pq->front->next;
    if (pq->front == NULL) {
        pq->rear = NULL;
    }
    return temp;
}

int dijkstra(Graph *graph, const char *start, const char *end, int *cost, const char *path[]) {
    PriorityQueue pq;
    pq_init(&pq);
    pq_push(&pq, 0, start, path);

    char visited[MAX_NODES][10];
    int visited_count = 0;
    while (pq.front != NULL) {
        QueueNode *node = pq_pop(&pq);
        if (node == NULL) {
            continue;
        }
        int i;
        for (i = 0; i < visited_count; i++) {
            if (strcmp(visited[i], node->name) == 0) {
                free(node);
                continue;
            }
        }
        strcpy(visited[visited_count], node->name);
        visited_count++;
        path[visited_count - 1] = node->name;
        if (strcmp(node->name, end) == 0) {
            *cost = node->cost;
            free(node);
            return 1;
        }
        Edge *neighbors = get_neighbors(graph, node->name);
        if (neighbors != NULL) {
            for (i = 0; i < graph->nodes[0].edge_count; i++) {
                if (neighbors[i].name[0] != '\0') {
                    pq_push(&pq, node->cost + neighbors[i].weight, neighbors[i].name, path);
                }
            }
        }
        free(node);
    }
    *cost = -1;
    return 0;
}

int main() {
    Graph graph;
    graph.node_count = 0;

    add_edge(&graph, "A", "B", 1);
    add_edge(&graph, "A", "C", 4);
    add_edge(&graph, "B", "C", 2);
    add_edge(&graph, "B", "D", 5);
    add_edge(&graph, "C", "D", 1);

    int cost;
    const char *path[MAX_NODES];
    if (dijkstra(&graph, "A", "D", &cost, path)) {
        printf("Cost: %d, Path: ", cost);
        for (int i = 0; i < MAX_NODES && path[i] != NULL; i++) {
            printf("%s ", path[i]);
        }
        printf("\n");
    } else {
        printf("No path found\n");
    }

    return 0;
}