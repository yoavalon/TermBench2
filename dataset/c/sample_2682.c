#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define INF 999999

typedef struct {
    char name;
    int weight;
} Neighbor;

typedef struct {
    Neighbor neighbors[MAX_NODES];
    int count;
} Node;

typedef struct {
    Node nodes[256]; // Assuming ASCII characters
} Graph;

typedef struct {
    char item;
    int priority;
} QueueElement;

typedef struct {
    QueueElement elements[MAX_NODES];
    int size;
} PriorityQueue;

void init_graph(Graph *graph) {
    memset(graph->nodes, 0, sizeof(graph->nodes));
}

void add_edge(Graph *graph, char u, char v, int weight) {
    int index_u = (int)u;
    int index_v = (int)v;
    if (graph->nodes[index_u].count == 0) {
        graph->nodes[index_u].count = 0;
    }
    if (graph->nodes[index_v].count == 0) {
        graph->nodes[index_v].count = 0;
    }
    graph->nodes[index_u].neighbors[graph->nodes[index_u].count++] = (Neighbor){v, weight};
    graph->nodes[index_v].neighbors[graph->nodes[index_v].count++] = (Neighbor){u, weight};
}

Node* get_neighbors(Graph *graph, char node) {
    return &graph->nodes[(int)node];
}

void init_priority_queue(PriorityQueue *queue) {
    queue->size = 0;
}

void add_to_queue(PriorityQueue *queue, char item, int priority) {
    for (int i = 0; i < queue->size; i++) {
        if (queue->elements[i].priority > priority) {
            for (int j = queue->size; j > i; j--) {
                queue->elements[j] = queue->elements[j - 1];
            }
            queue->elements[i] = (QueueElement){item, priority};
            queue->size++;
            return;
        }
    }
    queue->elements[queue->size++] = (QueueElement){item, priority};
}

char get_from_queue(PriorityQueue *queue) {
    if (queue->size == 0) {
        return '\0';
    }
    char item = queue->elements[0].item;
    for (int i = 0; i < queue->size - 1; i++) {
        queue->elements[i] = queue->elements[i + 1];
    }
    queue->size--;
    return item;
}

int is_queue_empty(PriorityQueue *queue) {
    return queue->size == 0;
}

void dijkstra(Graph *graph, char start, char end, char *path, int *path_length) {
    PriorityQueue queue;
    init_priority_queue(&queue);
    add_to_queue(&queue, start, 0);
    int distances[256];
    char previous_nodes[256];
    for (int i = 0; i < 256; i++) {
        distances[i] = INF;
        previous_nodes[i] = '\0';
    }
    distances[(int)start] = 0;
    while (!is_queue_empty(&queue)) {
        char current = get_from_queue(&queue);
        if (current == end) {
            break;
        }
        Node *neighbors = get_neighbors(graph, current);
        for (int i = 0; i < neighbors->count; i++) {
            Neighbor neighbor = neighbors->neighbors[i];
            int distance = distances[(int)current] + neighbor.weight;
            if (distance < distances[(int)neighbor.name]) {
                distances[(int)neighbor.name] = distance;
                previous_nodes[(int)neighbor.name] = current;
                add_to_queue(&queue, neighbor.name, distance);
            }
        }
    }
    *path_length = 0;
    char current = end;
    while (current != '\0') {
        path[(*path_length)++] = current;
        current = previous_nodes[(int)current];
    }
    for (int i = 0; i < *path_length / 2; i++) {
        char temp = path[i];
        path[i] = path[*path_length - i - 1];
        path[*path_length - i - 1] = temp;
    }
}

void main() {
    Graph graph;
    init_graph(&graph);
    add_edge(&graph, 'A', 'B', 1);
    add_edge(&graph, 'A', 'C', 4);
    add_edge(&graph, 'B', 'C', 2);
    add_edge(&graph, 'B', 'D', 5);
    add_edge(&graph, 'C', 'D', 1);
    add_edge(&graph, 'D', 'E', 3);
    char path[MAX_NODES];
    int path_length;
    dijkstra(&graph, 'A', 'E', path, &path_length);
    for (int i = 0; i < path_length; i++) {
        printf("%c", path[i]);
    }
    printf("\n");
}