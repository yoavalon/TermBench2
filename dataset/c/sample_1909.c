#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    char name;
    double weight;
} Neighbor;

typedef struct {
    char name;
    Neighbor *neighbors;
    int num_neighbors;
} Node;

typedef struct {
    Node *nodes;
    int num_nodes;
} Graph;

typedef struct {
    double distance;
    char visited;
} DistanceInfo;

double dijkstra(Graph graph, char start, char end) {
    DistanceInfo *distances = (DistanceInfo *)malloc(graph.num_nodes * sizeof(DistanceInfo));
    for (int i = 0; i < graph.num_nodes; i++) {
        distances[i].distance = INFINITY;
        distances[i].visited = 0;
    }
    char *unvisited = (char *)malloc(graph.num_nodes * sizeof(char));
    for (int i = 0; i < graph.num_nodes; i++) {
        unvisited[i] = graph.nodes[i].name;
    }
    char current = start;
    distances[0].distance = 0;
    while (current != end) {
        for (int i = 0; i < graph.num_nodes; i++) {
            if (graph.nodes[i].name == current) {
                for (int j = 0; j < graph.nodes[i].num_neighbors; j++) {
                    double distance = distances[i].distance + graph.nodes[i].neighbors[j].weight;
                    for (int k = 0; k < graph.num_nodes; k++) {
                        if (graph.nodes[k].name == graph.nodes[i].neighbors[j].name && distance < distances[k].distance) {
                            distances[k].distance = distance;
                        }
                    }
                }
                break;
            }
        }
        for (int i = 0; i < graph.num_nodes; i++) {
            if (unvisited[i] == current) {
                unvisited[i] = '\0';
                break;
            }
        }
        int found = 0;
        char next_current = '\0';
        for (int i = 0; i < graph.num_nodes; i++) {
            if (unvisited[i] != '\0' && (!found || distances[i].distance < distances[found].distance)) {
                found = i;
                next_current = unvisited[i];
            }
        }
        if (next_current == '\0') {
            break;
        }
        current = next_current;
    }
    double result = INFINITY;
    for (int i = 0; i < graph.num_nodes; i++) {
        if (graph.nodes[i].name == end) {
            result = distances[i].distance;
            break;
        }
    }
    free(distances);
    free(unvisited);
    return result;
}

void main() {
    Node nodes[] = {
        {'A', (Neighbor[]){{'B', 1.0}, {'C', 4.0}}, 2},
        {'B', (Neighbor[]){{'A', 1.0}, {'C', 2.0}, {'D', 5.0}}, 3},
        {'C', (Neighbor[]){{'A', 4.0}, {'B', 2.0}, {'D', 1.0}}, 3},
        {'D', (Neighbor[]){{'B', 5.0}, {'C', 1.0}}, 2}
    };
    Graph graph = {nodes, 4};
    char start = 'A';
    char end = 'D';
    printf("%f\n", dijkstra(graph, start, end));
}