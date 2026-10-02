#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    char* node;
    float weight;
    struct neighbor* next;
} neighbor;

typedef struct {
    char* node;
    neighbor* neighbors;
} graph_node;

typedef struct {
    graph_node** nodes;
    int size;
} graph;

graph* create_graph(int size) {
    graph* g = (graph*)malloc(sizeof(graph));
    g->nodes = (graph_node**)malloc(size * sizeof(graph_node*));
    g->size = size;
    for (int i = 0; i < size; i++) {
        g->nodes[i] = NULL;
    }
    return g;
}

void add_edge(graph* g, const char* from, const char* to, float weight) {
    for (int i = 0; i < g->size; i++) {
        if (g->nodes[i] != NULL && strcmp(g->nodes[i]->node, from) == 0) {
            neighbor* new_neighbor = (neighbor*)malloc(sizeof(neighbor));
            new_neighbor->node = strdup(to);
            new_neighbor->weight = weight;
            new_neighbor->next = g->nodes[i]->neighbors;
            g->nodes[i]->neighbors = new_neighbor;
            break;
        }
    }
}

void add_node(graph* g, const char* node) {
    for (int i = 0; i < g->size; i++) {
        if (g->nodes[i] == NULL) {
            graph_node* new_node = (graph_node*)malloc(sizeof(graph_node));
            new_node->node = strdup(node);
            new_node->neighbors = NULL;
            g->nodes[i] = new_node;
            break;
        }
    }
}

int find_node_index(graph* g, const char* node) {
    for (int i = 0; i < g->size; i++) {
        if (g->nodes[i] != NULL && strcmp(g->nodes[i]->node, node) == 0) {
            return i;
        }
    }
    return -1;
}

float find_shortest_path(graph* g, const char* start, const char* end) {
    float distances[g->size];
    for (int i = 0; i < g->size; i++) {
        distances[i] = INFINITY;
    }
    int start_index = find_node_index(g, start);
    distances[start_index] = 0;
    int* queue = (int*)malloc(g->size * sizeof(int));
    int queue_size = 0;
    queue[queue_size++] = start_index;
    while (queue_size > 0) {
        int current = queue[0];
        for (int i = 0; i < queue_size; i++) {
            queue[i] = queue[i + 1];
        }
        queue_size--;
        for (neighbor* neighbor = g->nodes[current]->neighbors; neighbor != NULL; neighbor = neighbor->next) {
            int neighbor_index = find_node_index(g, neighbor->node);
            float distance = distances[current] + neighbor->weight;
            if (distance < distances[neighbor_index]) {
                distances[neighbor_index] = distance;
                queue[queue_size++] = neighbor_index;
            }
        }
    }
    int end_index = find_node_index(g, end);
    return distances[end_index];
}

void free_graph(graph* g) {
    for (int i = 0; i < g->size; i++) {
        if (g->nodes[i] != NULL) {
            for (neighbor* neighbor = g->nodes[i]->neighbors; neighbor != NULL; neighbor = neighbor->next) {
                free(neighbor->node);
                free(neighbor);
            }
            free(g->nodes[i]->node);
            free(g->nodes[i]);
        }
    }
    free(g->nodes);
    free(g);
}

int main() {
    graph* g = create_graph(4);
    add_node(g, "A");
    add_node(g, "B");
    add_node(g, "C");
    add_node(g, "D");
    add_edge(g, "A", "B", 1.0);
    add_edge(g, "A", "C", 4.0);
    add_edge(g, "B", "A", 1.0);
    add_edge(g, "B", "C", 2.0);
    add_edge(g, "B", "D", 5.0);
    add_edge(g, "C", "A", 4.0);
    add_edge(g, "C", "B", 2.0);
    add_edge(g, "C", "D", 1.0);
    add_edge(g, "D", "B", 5.0);
    add_edge(g, "D", "C", 1.0);
    const char* start = "A";
    const char* end = "D";
    float result = find_shortest_path(g, start, end);
    printf("%f\n", result);
    free_graph(g);
    return 0;
}