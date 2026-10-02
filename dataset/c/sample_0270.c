#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

typedef struct {
    int v;
    int w;
} Edge;

typedef struct {
    Edge edges[MAX_NODES][MAX_NODES];
    int edge_count[MAX_NODES];
} Graph;

void init_graph(Graph *g) {
    for (int i = 0; i < MAX_NODES; i++) {
        g->edge_count[i] = 0;
    }
}

void add_edge(Graph *g, int u, int v, int w) {
    g->edges[u][g->edge_count[u]].v = v;
    g->edges[u][g->edge_count[u]].w = w;
    g->edge_count[u]++;
}

Edge* get_neighbors(Graph *g, int u, int *count) {
    *count = g->edge_count[u];
    return g->edges[u];
}

typedef struct {
    int cost;
    int node;
    int path[MAX_NODES];
    int path_count;
} DijkstraNode;

int compare_dijkstra_nodes(const void *a, const void *b) {
    return ((DijkstraNode*)a)->cost - ((DijkstraNode*)b)->cost;
}

int* find_shortest_path(Graph *graph, int start, int end, int *path_count) {
    DijkstraNode q[MAX_NODES];
    int q_size = 0;
    int dist[MAX_NODES];
    int visited[MAX_NODES];
    int path[MAX_NODES];

    for (int i = 0; i < MAX_NODES; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        path[i] = 0;
    }

    dist[start] = 0;
    q[q_size].cost = 0;
    q[q_size].node = start;
    q[q_size].path[0] = start;
    q[q_size].path_count = 1;
    q_size++;

    while (q_size > 0) {
        qsort(q, q_size, sizeof(DijkstraNode), compare_dijkstra_nodes);
        DijkstraNode current = q[0];
        for (int i = 1; i < q_size; i++) {
            q[i - 1] = q[i];
        }
        q_size--;

        if (visited[current.node]) {
            continue;
        }
        visited[current.node] = 1;

        if (current.node == end) {
            *path_count = current.path_count;
            for (int i = 0; i < current.path_count; i++) {
                path[i] = current.path[i];
            }
            return path;
        }

        int neighbor_count;
        Edge *neighbors = get_neighbors(graph, current.node, &neighbor_count);
        for (int i = 0; i < neighbor_count; i++) {
            int neighbor = neighbors[i].v;
            int weight = neighbors[i].w;
            if (!visited[neighbor] && dist[current.node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[current.node] + weight;
                DijkstraNode new_node;
                new_node.cost = dist[neighbor];
                new_node.node = neighbor;
                for (int j = 0; j < current.path_count; j++) {
                    new_node.path[j] = current.path[j];
                }
                new_node.path_count = current.path_count;
                new_node.path[new_node.path_count++] = neighbor;
                q[q_size++] = new_node;
            }
        }
    }

    *path_count = 0;
    return NULL;
}

void main() {
    Graph graph;
    init_graph(&graph);
    add_edge(&graph, 1, 2, 7);
    add_edge(&graph, 1, 3, 9);
    add_edge(&graph, 2, 3, 10);
    add_edge(&graph, 2, 4, 15);
    add_edge(&graph, 3, 4, 11);
    add_edge(&graph, 4, 5, 6);

    int path_count;
    int *result = find_shortest_path(&graph, 1, 5, &path_count);
    if (result) {
        for (int i = 0; i < path_count; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
}