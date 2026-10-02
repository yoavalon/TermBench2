#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 5
#define MAX_EDGES 10

typedef struct {
    char name;
    int edges[MAX_EDGES][2];
    int edge_count;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int node_count;
} Graph;

void add_edge(Graph* graph, char node1, char node2, int weight) {
    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].name == node1) {
            graph->nodes[i].edges[graph->nodes[i].edge_count][0] = node2;
            graph->nodes[i].edges[graph->nodes[i].edge_count][1] = weight;
            graph->nodes[i].edge_count++;
        }
        if (graph->nodes[i].name == node2) {
            graph->nodes[i].edges[graph->nodes[i].edge_count][0] = node1;
            graph->nodes[i].edges[graph->nodes[i].edge_count][1] = weight;
            graph->nodes[i].edge_count++;
        }
    }
}

int dijkstra(Graph* graph, char start, char end, char* path) {
    int distances[MAX_NODES];
    char previous[MAX_NODES];
    char visited[MAX_NODES];
    char queue[MAX_NODES];
    int queue_size = 0;

    for (int i = 0; i < graph->node_count; i++) {
        distances[i] = INT_MAX;
        previous[i] = '\0';
        visited[i] = 0;
    }

    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].name == start) {
            distances[i] = 0;
            break;
        }
    }

    queue[queue_size++] = start;

    while (queue_size > 0) {
        int min_distance = INT_MAX;
        int min_index = -1;

        for (int i = 0; i < queue_size; i++) {
            int index = 0;
            for (int j = 0; j < graph->node_count; j++) {
                if (graph->nodes[j].name == queue[i]) {
                    index = j;
                    break;
                }
            }
            if (distances[index] < min_distance) {
                min_distance = distances[index];
                min_index = index;
            }
        }

        char current = queue[min_index];
        for (int i = min_index; i < queue_size - 1; i++) {
            queue[i] = queue[i + 1];
        }
        queue_size--;

        if (current == end) {
            int path_index = 0;
            for (char prev = end; prev != '\0'; prev = previous[prev - 'A']) {
                path[path_index++] = prev;
            }
            path[path_index] = '\0';
            return 1;
        }

        visited[min_index] = 1;

        for (int i = 0; i < graph->nodes[min_index].edge_count; i++) {
            int neighbor_index = 0;
            for (int j = 0; j < graph->node_count; j++) {
                if (graph->nodes[j].name == graph->nodes[min_index].edges[i][0]) {
                    neighbor_index = j;
                    break;
                }
            }
            if (!visited[neighbor_index]) {
                int new_distance = distances[min_index] + graph->nodes[min_index].edges[i][1];
                if (new_distance < distances[neighbor_index]) {
                    distances[neighbor_index] = new_distance;
                    previous[neighbor_index] = current;
                    int in_queue = 0;
                    for (int j = 0; j < queue_size; j++) {
                        if (queue[j] == graph->nodes[neighbor_index].name) {
                            in_queue = 1;
                            break;
                        }
                    }
                    if (!in_queue) {
                        queue[queue_size++] = graph->nodes[neighbor_index].name;
                    }
                }
            }
        }
    }

    return 0;
}

int main() {
    char nodes[MAX_NODES] = {'A', 'B', 'C', 'D', 'E'};
    Graph graph = {{0}, 5};

    for (int i = 0; i < graph.node_count; i++) {
        graph.nodes[i].name = nodes[i];
        graph.nodes[i].edge_count = 0;
    }

    add_edge(&graph, 'A', 'B', 1);
    add_edge(&graph, 'B', 'C', 2);
    add_edge(&graph, 'C', 'D', 3);
    add_edge(&graph, 'D', 'E', 4);
    add_edge(&graph, 'E', 'A', 5);

    char path[MAX_NODES];
    if (dijkstra(&graph, 'A', 'E', path)) {
        for (int i = 0; path[i] != '\0'; i++) {
            printf("%c ", path[i]);
        }
        printf("\n");
    } else {
        printf("No path found\n");
    }

    return 0;
}