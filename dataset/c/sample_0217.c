#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    struct Edge *edges;
    int edge_count;
} Node;

typedef struct {
    Node *u;
    Node *v;
    int weight;
} Edge;

typedef struct {
    Node *nodes;
    int node_count;
} Graph;

typedef struct {
    int priority;
    Node *item;
} PriorityQueueElement;

typedef struct {
    PriorityQueueElement *elements;
    int count;
} PriorityQueue;

void add_edge(Graph *graph, Node *u, Node *v, int weight) {
    Edge *new_edge = (Edge *)malloc(sizeof(Edge));
    new_edge->u = u;
    new_edge->v = v;
    new_edge->weight = weight;

    Edge *temp_edges = (Edge *)realloc(u->edges, (u->edge_count + 1) * sizeof(Edge));
    if (temp_edges != NULL) {
        u->edges = temp_edges;
        u->edges[u->edge_count] = *new_edge;
        u->edge_count++;
    }

    temp_edges = (Edge *)realloc(v->edges, (v->edge_count + 1) * sizeof(Edge));
    if (temp_edges != NULL) {
        v->edges = temp_edges;
        v->edges[v->edge_count] = *new_edge;
        v->edge_count++;
    }
}

void add(PriorityQueue *queue, Node *item, int priority) {
    PriorityQueueElement new_element;
    new_element.item = item;
    new_element.priority = priority;

    queue->elements = (PriorityQueueElement *)realloc(queue->elements, (queue->count + 1) * sizeof(PriorityQueueElement));
    if (queue->elements != NULL) {
        queue->elements[queue->count] = new_element;
        queue->count++;
    }

    for (int i = queue->count - 1; i > 0; i--) {
        if (queue->elements[i].priority < queue->elements[i - 1].priority) {
            PriorityQueueElement temp = queue->elements[i];
            queue->elements[i] = queue->elements[i - 1];
            queue->elements[i - 1] = temp;
        } else {
            break;
        }
    }
}

Node *remove(PriorityQueue *queue) {
    Node *item = queue->elements[0].item;
    queue->elements = (PriorityQueueElement *)realloc(queue->elements, (queue->count - 1) * sizeof(PriorityQueueElement));
    queue->count--;
    return item;
}

int empty(PriorityQueue *queue) {
    return queue->count == 0;
}

int dijkstra(Graph *graph, Node *start, Node *end) {
    PriorityQueue queue;
    queue.elements = NULL;
    queue.count = 0;
    add(&queue, start, 0);

    int *cost_so_far = (int *)malloc(graph->node_count * sizeof(int));
    for (int i = 0; i < graph->node_count; i++) {
        cost_so_far[i] = INT_MAX;
    }
    cost_so_far[start - graph->nodes] = 0;

    int *came_from = (int *)malloc(graph->node_count * sizeof(int));
    for (int i = 0; i < graph->node_count; i++) {
        came_from[i] = -1;
    }

    while (!empty(&queue)) {
        Node *current = remove(&queue);
        if (current == end) {
            break;
        }
        for (int i = 0; i < current->edge_count; i++) {
            Edge *edge = &current->edges[i];
            Node *neighbor = (edge->u == current) ? edge->v : edge->u;
            int new_cost = cost_so_far[current - graph->nodes] + edge->weight;
            if (new_cost < cost_so_far[neighbor - graph->nodes]) {
                cost_so_far[neighbor - graph->nodes] = new_cost;
                came_from[neighbor - graph->nodes] = current - graph->nodes;
                add(&queue, neighbor, new_cost);
            }
        }
    }

    printf("Shortest path from %s to %s: ", start->name, end->name);
    int current = end - graph->nodes;
    while (current != -1) {
        printf("%s ", graph->nodes[current].name);
        current = came_from[current];
    }
    printf("\n");
    printf("Cost of the path: %d\n", cost_so_far[end - graph->nodes]);

    free(cost_so_far);
    free(came_from);
    free(queue.elements);

    return 0;
}

int main() {
    Graph graph;
    graph.node_count = 5;
    graph.nodes = (Node *)malloc(graph.node_count * sizeof(Node));
    for (int i = 0; i < graph.node_count; i++) {
        graph.nodes[i].name = (char *)malloc(2 * sizeof(char));
        sprintf(graph.nodes[i].name, "A%d", i + 1);
        graph.nodes[i].edges = NULL;
        graph.nodes[i].edge_count = 0;
    }

    add_edge(&graph, &graph.nodes[0], &graph.nodes[1], 1);
    add_edge(&graph, &graph.nodes[1], &graph.nodes[2], 2);
    add_edge(&graph, &graph.nodes[2], &graph.nodes[3], 1);
    add_edge(&graph, &graph.nodes[3], &graph.nodes[4], 3);
    add_edge(&graph, &graph.nodes[0], &graph.nodes[4], 10);

    dijkstra(&graph, &graph.nodes[0], &graph.nodes[4]);

    for (int i = 0; i < graph.node_count; i++) {
        free(graph.nodes[i].edges);
        free(graph.nodes[i].name);
    }
    free(graph.nodes);

    return 0;
}