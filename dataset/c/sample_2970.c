#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct {
    int V;
    int graph[MAX_VERTICES][MAX_VERTICES];
} Graph;

void Graph_init(Graph *self, int vertices) {
    self->V = vertices;
    for (int row = 0; row < vertices; row++) {
        for (int col = 0; col < vertices; col++) {
            self->graph[row][col] = 0;
        }
    }
}

void Graph_add_edge(Graph *self, int u, int v, int weight) {
    self->graph[u][v] = weight;
    self->graph[v][u] = weight;
}

int Graph_min_distance(Graph *self, int dist[], int spt_set[]) {
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < self->V; v++) {
        if (dist[v] < min && spt_set[v] == 0) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int* Graph_dijkstra(Graph *self, int src) {
    static int dist[MAX_VERTICES];
    static int spt_set[MAX_VERTICES];
    for (int v = 0; v < self->V; v++) {
        dist[v] = INT_MAX;
        spt_set[v] = 0;
    }
    dist[src] = 0;
    for (int cout = 0; cout < self->V; cout++) {
        int u = Graph_min_distance(self, dist, spt_set);
        spt_set[u] = 1;
        for (int v = 0; v < self->V; v++) {
            if (self->graph[u][v] > 0 && spt_set[v] == 0 && dist[v] > dist[u] + self->graph[u][v]) {
                dist[v] = dist[u] + self->graph[u][v];
            }
        }
    }
    return dist;
}

typedef struct {
    Graph *graph;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, Graph *graph) {
    self->graph = graph;
}

int* SequenceGenerator_generate_sequence(SequenceGenerator *self, int start_vertex) {
    static int sequence[MAX_VERTICES];
    int index = 0;
    while (1) {
        int *distances = Graph_dijkstra(self->graph, start_vertex);
        int next_vertex = 0;
        int min_distance = INT_MAX;
        for (int v = 0; v < self->graph->V; v++) {
            if (distances[v] < min_distance) {
                min_distance = distances[v];
                next_vertex = v;
            }
        }
        sequence[index++] = next_vertex;
        start_vertex = next_vertex;
    }
    return sequence;
}

int main() {
    int vertices = 5;
    Graph graph;
    Graph_init(&graph, vertices);
    Graph_add_edge(&graph, 0, 1, 4);
    Graph_add_edge(&graph, 0, 3, 7);
    Graph_add_edge(&graph, 1, 2, 1);
    Graph_add_edge(&graph, 1, 3, 2);
    Graph_add_edge(&graph, 1, 4, 10);
    Graph_add_edge(&graph, 2, 3, 5);
    Graph_add_edge(&graph, 3, 4, 3);
    Graph_add_edge(&graph, 2, 4, 8);
    SequenceGenerator sequence_generator;
    SequenceGenerator_init(&sequence_generator, &graph);
    int *sequence = SequenceGenerator_generate_sequence(&sequence_generator, 0);
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("%d\n", sequence[i]);
    }
    return 0;
}