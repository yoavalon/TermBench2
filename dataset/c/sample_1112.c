#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int node;
    int weight;
} Edge;

typedef struct {
    int node;
    int distance;
} Distance;

typedef struct {
    int key;
    Edge* edges;
    int edge_count;
} Node;

typedef struct {
    Node* nodes;
    int node_count;
} Graph;

Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodes = NULL;
    graph->node_count = 0;
    return graph;
}

void add_node(Graph* graph, int node) {
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].key == node) {
            return;
        }
    }
    graph->nodes = (Node*)realloc(graph->nodes, (graph->node_count + 1) * sizeof(Node));
    graph->nodes[graph->node_count].key = node;
    graph->nodes[graph->node_count].edges = NULL;
    graph->nodes[graph->node_count].edge_count = 0;
    graph->node_count++;
}

void add_edge(Graph* graph, int node1, int node2, int weight) {
    int index1 = -1, index2 = -1;
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].key == node1) {
            index1 = i;
        }
        if (graph->nodes[i].key == node2) {
            index2 = i;
        }
    }
    if (index1 != -1 && index2 != -1) {
        graph->nodes[index1].edges = (Edge*)realloc(graph->nodes[index1].edges, (graph->nodes[index1].edge_count + 1) * sizeof(Edge));
        graph->nodes[index1].edges[graph->nodes[index1].edge_count].node = node2;
        graph->nodes[index1].edges[graph->nodes[index1].edge_count].weight = weight;
        graph->nodes[index1].edge_count++;

        graph->nodes[index2].edges = (Edge*)realloc(graph->nodes[index2].edges, (graph->nodes[index2].edge_count + 1) * sizeof(Edge));
        graph->nodes[index2].edges[graph->nodes[index2].edge_count].node = node1;
        graph->nodes[index2].edges[graph->nodes[index2].edge_count].weight = weight;
        graph->nodes[index2].edge_count++;
    }
}

Edge* get_neighbors(Graph* graph, int node) {
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].key == node) {
            return graph->nodes[i].edges;
        }
    }
    return NULL;
}

typedef struct {
    Graph* graph;
} ShortestPath;

ShortestPath* create_shortest_path(Graph* graph) {
    ShortestPath* path_finder = (ShortestPath*)malloc(sizeof(ShortestPath));
    path_finder->graph = graph;
    return path_finder;
}

int dijkstra(ShortestPath* path_finder, int start, int end) {
    int* distances = (int*)calloc(path_finder->graph->node_count, sizeof(int));
    for (int i = 0; i < path_finder->graph->node_count; i++) {
        distances[i] = 1000000; // infinity
    }
    distances[start] = 0;

    Distance* priority_queue = (Distance*)malloc(path_finder->graph->node_count * sizeof(Distance));
    int queue_size = 0;
    priority_queue[queue_size].node = start;
    priority_queue[queue_size].distance = 0;
    queue_size++;

    while (queue_size > 0) {
        int current_distance = priority_queue[0].distance;
        int current_node = priority_queue[0].node;
        for (int i = 0; i < queue_size - 1; i++) {
            priority_queue[i] = priority_queue[i + 1];
        }
        queue_size--;

        if (current_distance > distances[current_node]) {
            continue;
        }

        Edge* neighbors = get_neighbors(path_finder->graph, current_node);
        for (int i = 0; i < neighbors[i].node != -1; i++) {
            int distance = current_distance + neighbors[i].weight;
            if (distance < distances[neighbors[i].node]) {
                distances[neighbors[i].node] = distance;
                priority_queue[queue_size].node = neighbors[i].node;
                priority_queue[queue_size].distance = distance;
                queue_size++;
            }
        }
    }

    int result = distances[end];
    free(distances);
    free(priority_queue);
    return result;
}

int main() {
    Graph* graph = create_graph();
    for (int i = 0; i < 10; i++) {
        add_node(graph, i);
    }
    for (int i = 0; i < 10; i++) {
        add_edge(graph, i, (i + 1) % 10, 1);
    }
    ShortestPath* path_finder = create_shortest_path(graph);
    while (1) {
        int result = dijkstra(path_finder, 0, 9);
        printf("%d\n", result);
    }
    return 0;
}