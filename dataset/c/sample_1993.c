#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name;
    double weight;
} Neighbor;

typedef struct {
    Neighbor* neighbors;
    int size;
} Node;

typedef struct {
    Node** nodes;
    int size;
} Graph;

typedef struct {
    char name;
    double dist;
} QueueElement;

typedef struct {
    QueueElement* elements;
    int size;
    int capacity;
} Queue;

int find_node(Graph* graph, char name) {
    for (int i = 0; i < graph->size; i++) {
        if (graph->nodes[i]->name == name) {
            return i;
        }
    }
    return -1;
}

void enqueue(Queue* queue, QueueElement element) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        queue->elements = realloc(queue->elements, queue->capacity * sizeof(QueueElement));
    }
    queue->elements[queue->size++] = element;
}

QueueElement dequeue(Queue* queue) {
    QueueElement element = queue->elements[0];
    for (int i = 0; i < queue->size - 1; i++) {
        queue->elements[i] = queue->elements[i + 1];
    }
    queue->size--;
    return element;
}

double find_shortest_path(Graph* graph, char start, char end) {
    Queue queue;
    queue.size = 0;
    queue.capacity = 1;
    queue.elements = malloc(queue.capacity * sizeof(QueueElement));
    enqueue(&queue, (QueueElement){start, 0.0});

    int* visited = calloc(graph->size, sizeof(int));

    while (queue.size > 0) {
        QueueElement element = dequeue(&queue);
        char node = element.name;
        double dist = element.dist;

        if (node == end) {
            free(visited);
            free(queue.elements);
            return dist;
        }

        if (visited[find_node(graph, node)]) {
            continue;
        }

        visited[find_node(graph, node)] = 1;

        for (int i = 0; i < graph->nodes[find_node(graph, node)]->size; i++) {
            Neighbor neighbor = graph->nodes[find_node(graph, node)]->neighbors[i];
            enqueue(&queue, (QueueElement){neighbor.name, dist + neighbor.weight});
        }
    }

    free(visited);
    free(queue.elements);
    return -1;
}

int main() {
    Node* nodes[4];
    nodes[0] = malloc(sizeof(Node));
    nodes[0]->name = 'A';
    nodes[0]->size = 2;
    nodes[0]->neighbors = malloc(2 * sizeof(Neighbor));
    nodes[0]->neighbors[0] = (Neighbor) {'B', 1.1};
    nodes[0]->neighbors[1] = (Neighbor) {'C', 4.5};

    nodes[1] = malloc(sizeof(Node));
    nodes[1]->name = 'B';
    nodes[1]->size = 3;
    nodes[1]->neighbors = malloc(3 * sizeof(Neighbor));
    nodes[1]->neighbors[0] = (Neighbor) {'A', 1.1};
    nodes[1]->neighbors[1] = (Neighbor) {'C', 2.3};
    nodes[1]->neighbors[2] = (Neighbor) {'D', 5.6};

    nodes[2] = malloc(sizeof(Node));
    nodes[2]->name = 'C';
    nodes[2]->size = 3;
    nodes[2]->neighbors = malloc(3 * sizeof(Neighbor));
    nodes[2]->neighbors[0] = (Neighbor) {'A', 4.5};
    nodes[2]->neighbors[1] = (Neighbor) {'B', 2.3};
    nodes[2]->neighbors[2] = (Neighbor) {'D', 1.2};

    nodes[3] = malloc(sizeof(Node));
    nodes[3]->name = 'D';
    nodes[3]->size = 2;
    nodes[3]->neighbors = malloc(2 * sizeof(Neighbor));
    nodes[3]->neighbors[0] = (Neighbor) {'B', 5.6};
    nodes[3]->neighbors[1] = (Neighbor) {'C', 1.2};

    Graph graph;
    graph.size = 4;
    graph.nodes = nodes;

    double result = find_shortest_path(&graph, 'A', 'D');
    printf("%.1f\n", result);

    for (int i = 0; i < graph.size; i++) {
        free(graph.nodes[i]->neighbors);
        free(graph.nodes[i]);
    }

    return 0;
}