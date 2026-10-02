#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct {
    char name[2];
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX_VERTICES];
    int edge_count;
} Vertex;

typedef struct {
    Vertex vertices[MAX_VERTICES];
    int vertex_count;
} Graph;

void add_edge(Graph *graph, char u, char v, int weight) {
    int i;
    for (i = 0; i < graph->vertex_count; i++) {
        if (graph->vertices[i].name[0] == u) {
            break;
        }
    }
    if (i == graph->vertex_count) {
        graph->vertices[i].name[0] = u;
        graph->vertices[i].name[1] = '\0';
        graph->vertices[i].edge_count = 0;
        graph->vertex_count++;
    }
    graph->vertices[i].edges[graph->vertices[i].edge_count].name[0] = v;
    graph->vertices[i].edges[graph->vertices[i].edge_count].name[1] = '\0';
    graph->vertices[i].edges[graph->vertices[i].edge_count].weight = weight;
    graph->vertices[i].edge_count++;

    for (i = 0; i < graph->vertex_count; i++) {
        if (graph->vertices[i].name[0] == v) {
            break;
        }
    }
    if (i == graph->vertex_count) {
        graph->vertices[i].name[0] = v;
        graph->vertices[i].name[1] = '\0';
        graph->vertices[i].edge_count = 0;
        graph->vertex_count++;
    }
    graph->vertices[i].edges[graph->vertices[i].edge_count].name[0] = u;
    graph->vertices[i].edges[graph->vertices[i].edge_count].name[1] = '\0';
    graph->vertices[i].edges[graph->vertices[i].edge_count].weight = weight;
    graph->vertices[i].edge_count++;
}

int dijkstra(Graph *graph, char start) {
    int distances[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};
    int i, j, min_distance, min_index;

    for (i = 0; i < graph->vertex_count; i++) {
        distances[i] = INT_MAX;
    }

    for (i = 0; i < graph->vertex_count; i++) {
        if (graph->vertices[i].name[0] == start) {
            distances[i] = 0;
            break;
        }
    }

    for (i = 0; i < graph->vertex_count - 1; i++) {
        min_distance = INT_MAX;
        min_index = -1;
        for (j = 0; j < graph->vertex_count; j++) {
            if (!visited[j] && distances[j] < min_distance) {
                min_distance = distances[j];
                min_index = j;
            }
        }
        if (min_index == -1) {
            break;
        }
        visited[min_index] = 1;

        for (j = 0; j < graph->vertices[min_index].edge_count; j++) {
            int k;
            for (k = 0; k < graph->vertex_count; k++) {
                if (graph->vertices[k].name[0] == graph->vertices[min_index].edges[j].name[0]) {
                    break;
                }
            }
            if (distances[min_index] + graph->vertices[min_index].edges[j].weight < distances[k]) {
                distances[k] = distances[min_index] + graph->vertices[min_index].edges[j].weight;
            }
        }
    }

    for (i = 0; i < graph->vertex_count; i++) {
        if (graph->vertices[i].name[0] == 'D') {
            return distances[i];
        }
    }

    return -1;
}

typedef struct {
    Graph graph;
} PathFinder;

int find_shortest_path(PathFinder *path_finder, char start, char end) {
    return dijkstra(&path_finder->graph, start);
}

void main() {
    Graph graph = {0};
    add_edge(&graph, 'A', 'B', 1);
    add_edge(&graph, 'B', 'C', 2);
    add_edge(&graph, 'A', 'C', 4);
    add_edge(&graph, 'C', 'D', 3);
    add_edge(&graph, 'B', 'D', 5);
    PathFinder path_finder = {graph};
    int result = find_shortest_path(&path_finder, 'A', 'D');
    printf("%d\n", result);
}