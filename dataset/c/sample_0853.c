#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    char* vertex;
    int weight;
} Edge;

typedef struct {
    char* vertex;
    Edge* edges;
    int edge_count;
} Vertex;

typedef struct {
    Vertex* vertices;
    int vertex_count;
} Graph;

Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = NULL;
    graph->vertex_count = 0;
    return graph;
}

int find_vertex_index(Graph* graph, const char* vertex) {
    for (int i = 0; i < graph->vertex_count; i++) {
        if (strcmp(graph->vertices[i].vertex, vertex) == 0) {
            return i;
        }
    }
    return -1;
}

void add_vertex(Graph* graph, const char* vertex) {
    int index = find_vertex_index(graph, vertex);
    if (index == -1) {
        graph->vertices = (Vertex*)realloc(graph->vertices, (graph->vertex_count + 1) * sizeof(Vertex));
        graph->vertices[graph->vertex_count].vertex = strdup(vertex);
        graph->vertices[graph->vertex_count].edges = NULL;
        graph->vertices[graph->vertex_count].edge_count = 0;
        graph->vertex_count++;
    }
}

void add_edge(Graph* graph, const char* vertex1, const char* vertex2, int weight) {
    int index1 = find_vertex_index(graph, vertex1);
    int index2 = find_vertex_index(graph, vertex2);
    if (index1 != -1 && index2 != -1) {
        graph->vertices[index1].edges = (Edge*)realloc(graph->vertices[index1].edges, (graph->vertices[index1].edge_count + 1) * sizeof(Edge));
        graph->vertices[index1].edges[graph->vertices[index1].edge_count].vertex = strdup(vertex2);
        graph->vertices[index1].edges[graph->vertices[index1].edge_count].weight = weight;
        graph->vertices[index1].edge_count++;

        graph->vertices[index2].edges = (Edge*)realloc(graph->vertices[index2].edges, (graph->vertices[index2].edge_count + 1) * sizeof(Edge));
        graph->vertices[index2].edges[graph->vertices[index2].edge_count].vertex = strdup(vertex1);
        graph->vertices[index2].edges[graph->vertices[index2].edge_count].weight = weight;
        graph->vertices[index2].edge_count++;
    }
}

int find_shortest_path(Graph* graph, const char* start, const char* end) {
    int* distances = (int*)malloc(graph->vertex_count * sizeof(int));
    int* visited = (int*)malloc(graph->vertex_count * sizeof(int));
    for (int i = 0; i < graph->vertex_count; i++) {
        distances[i] = INT_MAX;
        visited[i] = 0;
    }

    int start_index = find_vertex_index(graph, start);
    distances[start_index] = 0;

    for (int count = 0; count < graph->vertex_count - 1; count++) {
        int min_distance = INT_MAX;
        int min_index = -1;

        for (int v = 0; v < graph->vertex_count; v++) {
            if (!visited[v] && distances[v] < min_distance) {
                min_distance = distances[v];
                min_index = v;
            }
        }

        visited[min_index] = 1;

        for (int v = 0; v < graph->vertex_count; v++) {
            if (!visited[v]) {
                int index = find_vertex_index(graph, graph->vertices[min_index].edges[v].vertex);
                if (index != -1 && distances[min_index] + graph->vertices[min_index].edges[v].weight < distances[index]) {
                    distances[index] = distances[min_index] + graph->vertices[min_index].edges[v].weight;
                }
            }
        }
    }

    int end_index = find_vertex_index(graph, end);
    int result = (end_index != -1) ? distances[end_index] : -1;

    free(distances);
    free(visited);
    return result;
}

void free_graph(Graph* graph) {
    for (int i = 0; i < graph->vertex_count; i++) {
        free(graph->vertices[i].vertex);
        for (int j = 0; j < graph->vertices[i].edge_count; j++) {
            free(graph->vertices[i].edges[j].vertex);
        }
        free(graph->vertices[i].edges);
    }
    free(graph->vertices);
    free(graph);
}

int main() {
    Graph* g = create_graph();
    add_vertex(g, "A");
    add_vertex(g, "B");
    add_vertex(g, "C");
    add_vertex(g, "D");
    add_vertex(g, "E");
    add_edge(g, "A", "B", 1);
    add_edge(g, "B", "C", 2);
    add_edge(g, "C", "D", 3);
    add_edge(g, "D", "E", 4);
    add_edge(g, "A", "E", 10);

    int result = find_shortest_path(g, "A", "E");
    printf("%d\n", result);

    free_graph(g);
    return 0;
}