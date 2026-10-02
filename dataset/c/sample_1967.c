#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_VERTICES 26
#define MAX_EDGES 100

typedef struct {
    char name;
    int cost;
} Edge;

typedef struct {
    char name;
    Edge edges[MAX_EDGES];
    int edge_count;
} Vertex;

typedef struct {
    int cost;
    char path[MAX_EDGES];
    int path_length;
} Path;

typedef struct {
    Vertex vertices[MAX_VERTICES];
    int vertex_count;
} Graph;

int vertex_index(Graph *graph, char name) {
    for (int i = 0; i < graph->vertex_count; i++) {
        if (graph->vertices[i].name == name) {
            return i;
        }
    }
    return -1;
}

void add_edge(Graph *graph, char from, char to, int cost) {
    int from_index = vertex_index(graph, from);
    int to_index = vertex_index(graph, to);
    if (from_index == -1) {
        from_index = graph->vertex_count++;
        graph->vertices[from_index].name = from;
    }
    if (to_index == -1) {
        to_index = graph->vertex_count++;
        graph->vertices[to_index].name = to;
    }
    graph->vertices[from_index].edges[graph->vertices[from_index].edge_count].name = to;
    graph->vertices[from_index].edges[graph->vertices[from_index].edge_count].cost = cost;
    graph->vertices[from_index].edge_count++;
}

Path dijkstra(Graph *graph, char start, char end) {
    int visited[MAX_VERTICES] = {0};
    Path q[MAX_EDGES];
    int q_size = 0;
    q[q_size].cost = 0;
    q[q_size].path[0] = start;
    q[q_size].path_length = 1;
    q_size++;

    while (q_size > 0) {
        int min_index = 0;
        for (int i = 1; i < q_size; i++) {
            if (q[i].cost < q[min_index].cost) {
                min_index = i;
            }
        }

        Path current = q[min_index];
        for (int i = min_index; i < q_size - 1; i++) {
            q[i] = q[i + 1];
        }
        q_size--;

        if (visited[vertex_index(graph, current.path[current.path_length - 1])]) {
            continue;
        }
        visited[vertex_index(graph, current.path[current.path_length - 1])] = 1;

        if (current.path[current.path_length - 1] == end) {
            return current;
        }

        for (int i = 0; i < graph->vertices[vertex_index(graph, current.path[current.path_length - 1])].edge_count; i++) {
            if (!visited[vertex_index(graph, graph->vertices[vertex_index(graph, current.path[current.path_length - 1])].edges[i].name)]) {
                Path new_path = current;
                new_path.cost += graph->vertices[vertex_index(graph, current.path[current.path_length - 1])].edges[i].cost;
                new_path.path[new_path.path_length] = graph->vertices[vertex_index(graph, current.path[current.path_length - 1])].edges[i].name;
                new_path.path_length++;
                q[q_size] = new_path;
                q_size++;
            }
        }
    }

    Path result;
    result.cost = INT_MAX;
    result.path_length = 0;
    return result;
}

Path find_shortest_path(Graph *graph, char start, char end) {
    return dijkstra(graph, start, end);
}

void main() {
    Graph graph;
    graph.vertex_count = 0;
    add_edge(&graph, 'A', 'B', 1);
    add_edge(&graph, 'A', 'C', 4);
    add_edge(&graph, 'B', 'C', 2);
    add_edge(&graph, 'B', 'D', 5);
    add_edge(&graph, 'C', 'D', 1);

    char start = 'A';
    char end = 'D';
    Path result = find_shortest_path(&graph, start, end);

    printf("Shortest path cost: %d\n", result.cost);
    printf("Shortest path: ");
    for (int i = 0; i < result.path_length; i++) {
        printf("%c ", result.path[i]);
    }
    printf("\n");
}