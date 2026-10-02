#include <stdio.h>
#include <math.h>

double distance(double node1[2], double node2[2]) {
    double x1 = node1[0], y1 = node1[1];
    double x2 = node2[0], y2 = node2[1];
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double* nearest_node(double nodes[][2], int num_nodes, double current[2]) {
    double min_dist = INFINITY;
    double* nearest = NULL;
    for (int i = 0; i < num_nodes; i++) {
        double dist = distance(current, nodes[i]);
        if (dist < min_dist) {
            min_dist = dist;
            nearest = nodes[i];
        }
    }
    return nearest;
}

typedef struct {
    double nodes[10][2]; // Assuming a maximum of 10 nodes
    int num_nodes;
} Graph;

void Graph_init(Graph* graph, double nodes[][2], int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        graph->nodes[i][0] = nodes[i][0];
        graph->nodes[i][1] = nodes[i][1];
    }
    graph->num_nodes = num_nodes;
}

double** Graph_find_shortest_path(Graph* graph, double start[2], double end[2]) {
    double* path[10]; // Assuming a maximum path length of 10
    int path_length = 0;
    double* current = start;
    while (current != end) {
        path[path_length++] = current;
        current = nearest_node(graph->nodes, graph->num_nodes, current);
    }
    path[path_length++] = end;
    return path;
}

int main() {
    double nodes[][2] = {{0, 0}, {1, 2}, {3, 4}, {5, 6}, {7, 8}};
    Graph graph;
    Graph_init(&graph, nodes, 5);
    double start[2] = {0, 0};
    double end[2] = {7, 8};
    while (1) {
        double** path = Graph_find_shortest_path(&graph, start, end);
        printf("Path found: ");
        for (int i = 0; i < 6; i++) { // Assuming the path length is known
            printf("(%f, %f) ", path[i][0], path[i][1]);
        }
        printf("\n");
    }
    return 0;
}