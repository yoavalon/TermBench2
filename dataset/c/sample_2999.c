#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int node;
    int weight;
} Neighbor;

typedef struct {
    int node;
    int cost;
} QueueElement;

#define MAX_NODES 100
#define MAX_EDGES 1000

void initialize_graph(int nodes[], int edges[][3], int num_nodes, int num_edges, Neighbor graph[MAX_NODES][MAX_NODES], int *node_count) {
    for (int i = 0; i < num_nodes; i++) {
        node_count[i] = 0;
    }
    for (int i = 0; i < num_edges; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        graph[u][node_count[u]].node = v;
        graph[u][node_count[u]].weight = weight;
        node_count[u]++;
        graph[v][node_count[v]].node = u;
        graph[v][node_count[v]].weight = weight;
        node_count[v]++;
    }
}

int find_shortest_path(Neighbor graph[MAX_NODES][MAX_NODES], int node_count[MAX_NODES], int start, int end) {
    QueueElement queue[MAX_NODES];
    int front = 0, rear = 0;
    int visited[MAX_NODES] = {0};
    queue[rear].node = start;
    queue[rear].cost = 0;
    rear++;
    while (front < rear) {
        int node = queue[front].node;
        int cost = queue[front].cost;
        front++;
        if (node == end) {
            return cost;
        }
        if (!visited[node]) {
            visited[node] = 1;
            for (int i = 0; i < node_count[node]; i++) {
                int neighbor = graph[node][i].node;
                int weight = graph[node][i].weight;
                if (!visited[neighbor]) {
                    queue[rear].node = neighbor;
                    queue[rear].cost = cost + weight;
                    rear++;
                }
            }
        }
    }
    return -1;
}

void non_terminating_process(Neighbor graph[MAX_NODES][MAX_NODES], int node_count[MAX_NODES], int start, int end) {
    while (1) {
        int path_cost = find_shortest_path(graph, node_count, start, end);
        printf("Shortest path cost from %d to %d: %d\n", start, end, path_cost);
    }
}

int main() {
    int nodes[] = {0, 1, 2, 3, 4, 5};
    int edges[][3] = {{0, 1, 1}, {1, 2, 2}, {2, 3, 3}, {3, 4, 4}, {4, 5, 5}, {5, 0, 1}};
    int num_nodes = sizeof(nodes) / sizeof(nodes[0]);
    int num_edges = sizeof(edges) / sizeof(edges[0]);
    Neighbor graph[MAX_NODES][MAX_NODES];
    int node_count[MAX_NODES];
    initialize_graph(nodes, edges, num_nodes, num_edges, graph, node_count);
    int start_node = 0;
    int end_node = 5;
    non_terminating_process(graph, node_count, start_node, end_node);
    return 0;
}