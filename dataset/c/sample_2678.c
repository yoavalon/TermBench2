#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 26

typedef struct {
    char vertex;
    int weight;
    struct Edge* next;
} Edge;

typedef struct {
    char vertex;
    Edge* head;
} Vertex;

typedef struct {
    Vertex* vertices;
    int size;
} Graph;

typedef struct {
    int priority;
    char item;
    struct PriorityQueueElement* next;
} PriorityQueueElement;

typedef struct {
    PriorityQueueElement* head;
} PriorityQueue;

void graph_init(Graph* graph) {
    graph->vertices = (Vertex*)malloc(MAX_VERTICES * sizeof(Vertex));
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->vertices[i].vertex = 'A' + i;
        graph->vertices[i].head = NULL;
    }
    graph->size = 0;
}

void add_vertex(Graph* graph, char vertex) {
    if (graph->vertices[vertex - 'A'].head == NULL) {
        graph->vertices[vertex - 'A'].head = (Edge*)malloc(sizeof(Edge));
        graph->vertices[vertex - 'A'].head->next = NULL;
        graph->size++;
    }
}

void add_edge(Graph* graph, char vertex1, char vertex2, int weight) {
    if (graph->vertices[vertex1 - 'A'].head != NULL && graph->vertices[vertex2 - 'A'].head != NULL) {
        Edge* new_edge = (Edge*)malloc(sizeof(Edge));
        new_edge->vertex = vertex2;
        new_edge->weight = weight;
        new_edge->next = graph->vertices[vertex1 - 'A'].head;
        graph->vertices[vertex1 - 'A'].head = new_edge;

        new_edge = (Edge*)malloc(sizeof(Edge));
        new_edge->vertex = vertex1;
        new_edge->weight = weight;
        new_edge->next = graph->vertices[vertex2 - 'A'].head;
        graph->vertices[vertex2 - 'A'].head = new_edge;
    }
}

Edge* get_neighbors(Graph* graph, char vertex) {
    return graph->vertices[vertex - 'A'].head;
}

void priority_queue_init(PriorityQueue* pq) {
    pq->head = NULL;
}

int priority_queue_empty(PriorityQueue* pq) {
    return pq->head == NULL;
}

void priority_queue_put(PriorityQueue* pq, char item, int priority) {
    PriorityQueueElement* new_element = (PriorityQueueElement*)malloc(sizeof(PriorityQueueElement));
    new_element->item = item;
    new_element->priority = priority;
    new_element->next = NULL;

    if (pq->head == NULL || priority < pq->head->priority) {
        new_element->next = pq->head;
        pq->head = new_element;
    } else {
        PriorityQueueElement* current = pq->head;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        new_element->next = current->next;
        current->next = new_element;
    }
}

char priority_queue_get(PriorityQueue* pq) {
    if (!priority_queue_empty(pq)) {
        PriorityQueueElement* first = pq->head;
        char item = first->item;
        pq->head = first->next;
        free(first);
        return item;
    }
    return '\0';
}

void dijkstra(Graph* graph, char start, char end) {
    PriorityQueue queue;
    priority_queue_init(&queue);
    priority_queue_put(&queue, start, 0);

    int distances[MAX_VERTICES];
    char previous[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++) {
        distances[i] = 999999;
        previous[i] = '\0';
    }
    distances[start - 'A'] = 0;

    while (!priority_queue_empty(&queue)) {
        char current = priority_queue_get(&queue);
        if (current == end) {
            break;
        }
        Edge* neighbor = get_neighbors(graph, current);
        while (neighbor != NULL) {
            int distance = distances[current - 'A'] + neighbor->weight;
            if (distance < distances[neighbor->vertex - 'A']) {
                distances[neighbor->vertex - 'A'] = distance;
                previous[neighbor->vertex - 'A'] = current;
                priority_queue_put(&queue, neighbor->vertex, distance);
            }
            neighbor = neighbor->next;
        }
    }

    char path[MAX_VERTICES];
    int path_index = 0;
    while (end != '\0') {
        path[path_index++] = end;
        end = previous[end - 'A'];
    }

    printf("Path: ");
    for (int i = path_index - 1; i >= 0; i--) {
        printf("%c ", path[i]);
    }
    printf("\n");

    printf("Distances: ");
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph->vertices[i].head != NULL) {
            printf("%c: %d ", graph->vertices[i].vertex, distances[i]);
        }
    }
    printf("\n");
}

void main() {
    Graph graph;
    graph_init(&graph);

    char vertices[] = {'A', 'B', 'C', 'D', 'E'};
    for (int i = 0; i < 5; i++) {
        add_vertex(&graph, vertices[i]);
    }
    add_edge(&graph, 'A', 'B', 1);
    add_edge(&graph, 'B', 'C', 2);
    add_edge(&graph, 'C', 'D', 3);
    add_edge(&graph, 'D', 'E', 4);
    add_edge(&graph, 'E', 'A', 5);

    dijkstra(&graph, 'A', 'E');
}