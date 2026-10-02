#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int node;
    int weight;
} Edge;

typedef struct {
    int node;
    Edge* edges;
    int edge_count;
} Node;

typedef struct {
    Node* nodes;
    int node_count;
} Graph;

typedef struct {
    Graph* graph;
} PathFinder;

typedef struct {
    Graph* graph;
    PathFinder* path_finder;
} SequenceGenerator;

Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodes = (Node*)malloc(10 * sizeof(Node));
    graph->node_count = 0;
    return graph;
}

void add_node(Graph* graph, int node) {
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].node == node) return;
    }
    graph->nodes[graph->node_count].node = node;
    graph->nodes[graph->node_count].edges = (Edge*)malloc(10 * sizeof(Edge));
    graph->nodes[graph->node_count].edge_count = 0;
    graph->node_count++;
}

void add_edge(Graph* graph, int node1, int node2, int weight) {
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].node == node1) {
            for (int j = 0; j < graph->nodes[i].edge_count; j++) {
                if (graph->nodes[i].edges[j].node == node2) return;
            }
            graph->nodes[i].edges[graph->nodes[i].edge_count].node = node2;
            graph->nodes[i].edges[graph->nodes[i].edge_count].weight = weight;
            graph->nodes[i].edge_count++;
        }
        if (graph->nodes[i].node == node2) {
            graph->nodes[i].edges[graph->nodes[i].edge_count].node = node1;
            graph->nodes[i].edges[graph->nodes[i].edge_count].weight = weight;
            graph->nodes[i].edge_count++;
        }
    }
}

Edge* get_neighbors(Graph* graph, int node, int* count) {
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].node == node) {
            *count = graph->nodes[i].edge_count;
            return graph->nodes[i].edges;
        }
    }
    *count = 0;
    return NULL;
}

PathFinder* create_path_finder(Graph* graph) {
    PathFinder* path_finder = (PathFinder*)malloc(sizeof(PathFinder));
    path_finder->graph = graph;
    return path_finder;
}

int dijkstra(PathFinder* path_finder, int start, int end) {
    int distances[10];
    for (int i = 0; i < 10; i++) {
        distances[i] = INT_MAX;
    }
    distances[start] = 0;
    int priority_queue[10][2];
    int queue_size = 0;
    priority_queue[queue_size][0] = 0;
    priority_queue[queue_size][1] = start;
    queue_size++;
    while (queue_size > 0) {
        int current_distance = INT_MAX;
        int current_node = -1;
        for (int i = 0; i < queue_size; i++) {
            if (priority_queue[i][0] < current_distance) {
                current_distance = priority_queue[i][0];
                current_node = priority_queue[i][1];
            }
        }
        for (int i = 0; i < queue_size; i++) {
            if (priority_queue[i][1] == current_node) {
                for (int j = i; j < queue_size - 1; j++) {
                    priority_queue[j][0] = priority_queue[j + 1][0];
                    priority_queue[j][1] = priority_queue[j + 1][1];
                }
                queue_size--;
                break;
            }
        }
        if (current_node == end) {
            return distances[end];
        }
        int count;
        Edge* neighbors = get_neighbors(path_finder->graph, current_node, &count);
        for (int i = 0; i < count; i++) {
            int distance = current_distance + neighbors[i].weight;
            if (distance < distances[neighbors[i].node]) {
                distances[neighbors[i].node] = distance;
                priority_queue[queue_size][0] = distance;
                priority_queue[queue_size][1] = neighbors[i].node;
                queue_size++;
            }
        }
    }
    return -1;
}

SequenceGenerator* create_sequence_generator(Graph* graph, PathFinder* path_finder) {
    SequenceGenerator* sequence_generator = (SequenceGenerator*)malloc(sizeof(SequenceGenerator));
    sequence_generator->graph = graph;
    sequence_generator->path_finder = path_finder;
    return sequence_generator;
}

int generate_sequence(SequenceGenerator* sequence_generator) {
    int start_node = rand() % 10;
    int end_node = rand() % 10;
    while (end_node == start_node) {
        end_node = rand() % 10;
    }
    return dijkstra(sequence_generator->path_finder, start_node, end_node);
}

int main() {
    Graph* graph = create_graph();
    for (int i = 0; i < 10; i++) {
        add_node(graph, i);
    }
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            add_edge(graph, i, j, rand() % 10 + 1);
        }
    }
    PathFinder* path_finder = create_path_finder(graph);
    SequenceGenerator* sequence_generator = create_sequence_generator(graph, path_finder);
    while (1) {
        printf("%d\n", generate_sequence(sequence_generator));
    }
    return 0;
}