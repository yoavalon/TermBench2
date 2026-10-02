#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 10

typedef struct {
    int node;
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX_NODES];
    int size;
} NodeList;

typedef struct {
    NodeList list[MAX_NODES];
} Graph;

typedef struct {
    int node;
    int dist;
} QueueItem;

typedef struct {
    QueueItem items[MAX_NODES];
    int front;
    int rear;
} Queue;

typedef struct {
    int prev[MAX_NODES];
} Path;

Graph build_graph(int edges[][3], int num_edges) {
    Graph graph;
    for (int i = 0; i < MAX_NODES; i++) {
        graph.list[i].size = 0;
    }
    for (int i = 0; i < num_edges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        graph.list[u].edges[graph.list[u].size++] = (Edge){v, w};
        graph.list[v].edges[graph.list[v].size++] = (Edge){u, w};
    }
    return graph;
}

void enqueue(Queue *q, int node, int dist) {
    q->items[q->rear].node = node;
    q->items[q->rear].dist = dist;
    q->rear++;
}

QueueItem dequeue(Queue *q) {
    QueueItem item = q->items[q->front];
    q->front++;
    return item;
}

int is_empty(Queue *q) {
    return q->front == q->rear;
}

void dijkstra(Graph graph, int start, int end, int *distances, Path *path) {
    for (int i = 0; i < MAX_NODES; i++) {
        distances[i] = INT_MAX;
        path->prev[i] = -1;
    }
    distances[start] = 0;
    Queue q;
    q.front = 0;
    q.rear = 0;
    enqueue(&q, start, 0);
    while (!is_empty(&q)) {
        QueueItem current = dequeue(&q);
        if (current.dist > distances[current.node]) {
            continue;
        }
        if (current.node == end) {
            break;
        }
        for (int i = 0; i < graph.list[current.node].size; i++) {
            Edge neighbor = graph.list[current.node].edges[i];
            int distance = current.dist + neighbor.weight;
            if (distance < distances[neighbor.node]) {
                distances[neighbor.node] = distance;
                path->prev[neighbor.node] = current.node;
                enqueue(&q, neighbor.node, distance);
            }
        }
    }
}

int reconstruct_path(Path path, int start, int end, int *shortest_path) {
    int index = 0;
    for (int at = end; at != -1; at = path.prev[at]) {
        shortest_path[index++] = at;
    }
    return index;
}

int main() {
    int edges[][3] = {{0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 3, 7}, {2, 5, 4}, {2, 8, 2}, {3, 4, 9}, {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, {7, 8, 7}};
    int num_edges = sizeof(edges) / sizeof(edges[0]);
    Graph graph = build_graph(edges, num_edges);
    int start_node = 0;
    int end_node = 4;
    int distances[MAX_NODES];
    Path path;
    dijkstra(graph, start_node, end_node, distances, &path);
    int shortest_path[MAX_NODES];
    int path_length = reconstruct_path(path, start_node, end_node, shortest_path);
    printf("Shortest path: ");
    for (int i = path_length - 1; i >= 0; i--) {
        printf("%d ", shortest_path[i]);
    }
    printf("\nDistance: %d\n", distances[end_node]);
    return 0;
}