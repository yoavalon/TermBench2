#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *node;
    double cost;
    char **visited;
    int visited_count;
} QueueItem;

typedef struct {
    char *node;
    double weight;
} Neighbor;

typedef struct {
    char *node;
    Neighbor *neighbors;
    int neighbor_count;
} GraphNode;

typedef struct {
    GraphNode *nodes;
    int node_count;
} Graph;

QueueItem *queue;
int queue_size = 0;
int queue_capacity = 10;

void queue_init() {
    queue = (QueueItem *)malloc(queue_capacity * sizeof(QueueItem));
}

void queue_add(QueueItem item) {
    if (queue_size == queue_capacity) {
        queue_capacity *= 2;
        queue = (QueueItem *)realloc(queue, queue_capacity * sizeof(QueueItem));
    }
    queue[queue_size++] = item;
}

QueueItem queue_remove() {
    QueueItem item = queue[0];
    for (int i = 0; i < queue_size - 1; i++) {
        queue[i] = queue[i + 1];
    }
    queue_size--;
    return item;
}

int queue_is_empty() {
    return queue_size == 0;
}

void queue_free() {
    free(queue);
}

Graph *graph_create() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->nodes = NULL;
    graph->node_count = 0;
    return graph;
}

void graph_add_node(Graph *graph, const char *node) {
    graph->nodes = (GraphNode *)realloc(graph->nodes, (graph->node_count + 1) * sizeof(GraphNode));
    graph->nodes[graph->node_count].node = strdup(node);
    graph->nodes[graph->node_count].neighbors = NULL;
    graph->nodes[graph->node_count].neighbor_count = 0;
    graph->node_count++;
}

void graph_add_edge(Graph *graph, const char *from, const char *to, double weight) {
    for (int i = 0; i < graph->node_count; i++) {
        if (strcmp(graph->nodes[i].node, from) == 0) {
            graph->nodes[i].neighbors = (Neighbor *)realloc(graph->nodes[i].neighbors, (graph->nodes[i].neighbor_count + 1) * sizeof(Neighbor));
            graph->nodes[i].neighbors[graph->nodes[i].neighbor_count].node = strdup(to);
            graph->nodes[i].neighbors[graph->nodes[i].neighbor_count].weight = weight;
            graph->nodes[i].neighbor_count++;
            break;
        }
    }
}

void graph_free(Graph *graph) {
    for (int i = 0; i < graph->node_count; i++) {
        free(graph->nodes[i].node);
        for (int j = 0; j < graph->nodes[i].neighbor_count; j++) {
            free(graph->nodes[i].neighbors[j].node);
        }
        free(graph->nodes[i].neighbors);
    }
    free(graph->nodes);
    free(graph);
}

int find_shortest_path(Graph *graph, const char *start, const char *end) {
    queue_init();
    QueueItem item = {strdup(start), 0.0, NULL, 0};
    queue_add(item);
    while (!queue_is_empty()) {
        QueueItem current = queue_remove();
        if (strcmp(current.node, end) == 0) {
            queue_free();
            return (int)current.cost;
        }
        for (int i = 0; i < graph->node_count; i++) {
            if (strcmp(graph->nodes[i].node, current.node) == 0) {
                for (int j = 0; j < graph->nodes[i].neighbor_count; j++) {
                    int visited = 0;
                    for (int k = 0; k < current.visited_count; k++) {
                        if (strcmp(current.visited[k], graph->nodes[i].neighbors[j].node) == 0) {
                            visited = 1;
                            break;
                        }
                    }
                    if (!visited) {
                        QueueItem next = {strdup(graph->nodes[i].neighbors[j].node), current.cost + graph->nodes[i].neighbors[j].weight, (char **)malloc((current.visited_count + 1) * sizeof(char *)), current.visited_count + 1};
                        for (int k = 0; k < current.visited_count; k++) {
                            next.visited[k] = strdup(current.visited[k]);
                        }
                        next.visited[next.visited_count - 1] = strdup(current.node);
                        queue_add(next);
                    }
                }
                break;
            }
        }
        free(current.node);
        for (int i = 0; i < current.visited_count; i++) {
            free(current.visited[i]);
        }
        free(current.visited);
    }
    queue_free();
    return -1;
}

int main() {
    Graph *graph = graph_create();
    graph_add_node(graph, "A");
    graph_add_node(graph, "B");
    graph_add_node(graph, "C");
    graph_add_node(graph, "D");
    graph_add_edge(graph, "A", "B", 1.0);
    graph_add_edge(graph, "A", "C", 4.0);
    graph_add_edge(graph, "B", "A", 1.0);
    graph_add_edge(graph, "B", "D", 2.0);
    graph_add_edge(graph, "C", "A", 4.0);
    graph_add_edge(graph, "C", "D", 1.0);
    graph_add_edge(graph, "D", "B", 2.0);
    graph_add_edge(graph, "D", "C", 1.0);
    int result = find_shortest_path(graph, "A", "D");
    printf("%d\n", result);
    graph_free(graph);
    return 0;
}