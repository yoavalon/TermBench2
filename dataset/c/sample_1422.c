#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int V;
    int **graph;
} Graph;

Graph* create_graph(int vertices) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = vertices;
    g->graph = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        g->graph[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++) {
            g->graph[i][j] = 0;
        }
    }
    return g;
}

void add_edge(Graph* g, int u, int v, int w) {
    g->graph[u][v] = w;
    g->graph[v][u] = w;
}

typedef struct {
    Graph* graph;
    int* dist;
    int* parent;
} ShortestPath;

ShortestPath* create_shortest_path(Graph* graph) {
    ShortestPath* sp = (ShortestPath*)malloc(sizeof(ShortestPath));
    sp->graph = graph;
    sp->dist = (int*)malloc(graph->V * sizeof(int));
    sp->parent = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        sp->dist[i] = INT_MAX;
        sp->parent[i] = -1;
    }
    return sp;
}

void bellman_ford(ShortestPath* sp, int src) {
    sp->dist[src] = 0;
    for (int i = 0; i < sp->graph->V - 1; i++) {
        for (int u = 0; u < sp->graph->V; u++) {
            for (int v = 0; v < sp->graph->V; v++) {
                int weight = sp->graph->graph[u][v];
                if (weight != 0 && sp->dist[u] != INT_MAX && sp->dist[u] + weight < sp->dist[v]) {
                    sp->dist[v] = sp->dist[u] + weight;
                    sp->parent[v] = u;
                }
            }
        }
    }
}

int* get_shortest_path(ShortestPath* sp, int dst, int* path_size) {
    if (sp->dist[dst] == INT_MAX) {
        *path_size = 0;
        return NULL;
    }
    int* path = (int*)malloc(sp->graph->V * sizeof(int));
    int index = 0;
    while (dst != -1) {
        path[index++] = dst;
        dst = sp->parent[dst];
    }
    *path_size = index;
    for (int i = 0; i < index / 2; i++) {
        int temp = path[i];
        path[i] = path[index - i - 1];
        path[index - i - 1] = temp;
    }
    return path;
}

void main() {
    int V = 5;
    Graph* graph = create_graph(V);
    add_edge(graph, 0, 1, 4);
    add_edge(graph, 0, 2, 8);
    add_edge(graph, 1, 2, 8);
    add_edge(graph, 1, 3, 7);
    add_edge(graph, 1, 4, 9);
    add_edge(graph, 2, 3, 4);
    add_edge(graph, 2, 4, 2);
    add_edge(graph, 3, 4, 11);
    add_edge(graph, 3, 0, 2);
    add_edge(graph, 4, 0, 7);
    ShortestPath* shortest_path_finder = create_shortest_path(graph);
    bellman_ford(shortest_path_finder, 0);
    int path_size;
    int* path = get_shortest_path(shortest_path_finder, 4, &path_size);
    for (int i = 0; i < path_size; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
    free(path);
    free(shortest_path_finder->dist);
    free(shortest_path_finder->parent);
    free(shortest_path_finder);
    for (int i = 0; i < graph->V; i++) {
        free(graph->graph[i]);
    }
    free(graph->graph);
    free(graph);
}