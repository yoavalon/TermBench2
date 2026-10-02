#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10
#define MAX_EDGES 10

void non_terminating_graph_traversal(int graph[MAX_NODES][MAX_EDGES], int degree[MAX_NODES]) {
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    queue[rear++] = 0;

    while (front != rear) {
        int current = queue[front++];
        for (int i = 0; i < degree[current]; i++) {
            int neighbor = graph[current][i];
            queue[rear++] = neighbor;
        }
    }
}

int main() {
    int graph[MAX_NODES][MAX_EDGES] = {
        {1, 2, -1},  // node 0
        {2, -1},     // node 1
        {0, -1}      // node 2
    };
    int degree[MAX_NODES] = {2, 1, 1};

    non_terminating_graph_traversal(graph, degree);
    return 0;
}