#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 26
#define MAX_EDGES 100

typedef struct {
    char node;
    int weight;
} Edge;

typedef struct {
    int size;
    Edge edges[MAX_EDGES];
} NodeList;

typedef struct {
    char node;
    int cost;
} QueueElement;

typedef struct {
    int size;
    QueueElement elements[MAX_EDGES];
} PriorityQueue;

int dijkstra(char graph[MAX_NODES][MAX_EDGES][2], int node_count, char start, char end) {
    PriorityQueue queue;
    queue.size = 0;
    queue.elements[queue.size].node = start;
    queue.elements[queue.size].cost = 0;
    queue.size++;

    char visited[MAX_NODES] = {0};
    visited[start - 'A'] = 1;

    while (queue.size > 0) {
        int min_index = 0;
        for (int i = 1; i < queue.size; i++) {
            if (queue.elements[i].cost < queue.elements[min_index].cost) {
                min_index = i;
            }
        }
        QueueElement current = queue.elements[min_index];
        for (int i = min_index; i < queue.size - 1; i++) {
            queue.elements[i] = queue.elements[i + 1];
        }
        queue.size--;

        if (current.node == end) {
            return current.cost;
        }

        for (int i = 0; i < node_count; i++) {
            if (graph[i][0][0] == current.node) {
                for (int j = 0; graph[i][j][0] != '\0'; j++) {
                    if (!visited[graph[i][j][1] - 'A']) {
                        visited[graph[i][j][1] - 'A'] = 1;
                        queue.elements[queue.size].node = graph[i][j][1];
                        queue.elements[queue.size].cost = current.cost + graph[i][j][2];
                        queue.size++;
                    }
                }
            }
        }
    }
    return -1;
}

int shortest_path(char graph[MAX_NODES][MAX_EDGES][2], int node_count, char start, char end) {
    return dijkstra(graph, node_count, start, end);
}

void main() {
    char graph[MAX_NODES][MAX_EDGES][2] = {
        {'B', 1, 'C', 4, '\0'},
        {'A', 1, 'C', 2, 'D', 5, '\0'},
        {'A', 4, 'B', 2, 'D', 1, '\0'},
        {'B', 5, 'C', 1, '\0'}
    };
    int node_count = 4;
    char start = 'A';
    char end = 'D';
    int result = shortest_path(graph, node_count, start, end);
    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("No path found\n");
    }
}