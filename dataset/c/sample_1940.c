#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    char name[2];
    int weight;
} Edge;

typedef struct {
    char name[2];
    Edge edges[MAX_EDGES];
    int edge_count;
} Node;

typedef struct {
    int cost;
    char path[MAX_NODES * 2];
    int path_length;
} Result;

Node graph[MAX_NODES];
int node_count = 0;
int edge_count = 0;

void initialize_graph(char nodes[][2], int node_count, Edge edges[][3], int edge_count) {
    for (int i = 0; i < node_count; i++) {
        strcpy(graph[i].name, nodes[i]);
        graph[i].edge_count = 0;
    }
    for (int i = 0; i < edge_count; i++) {
        int u = 0, v = 0;
        for (int j = 0; j < node_count; j++) {
            if (strcmp(nodes[j], edges[i][0]) == 0) {
                u = j;
            }
            if (strcmp(nodes[j], edges[i][1]) == 0) {
                v = j;
            }
        }
        graph[u].edges[graph[u].edge_count].weight = edges[i][2];
        strcpy(graph[u].edges[graph[u].edge_count].name, edges[i][1]);
        graph[u].edge_count++;
        graph[v].edges[graph[v].edge_count].weight = edges[i][2];
        strcpy(graph[v].edges[graph[v].edge_count].name, edges[i][0]);
        graph[v].edge_count++;
    }
}

int compare(const void *a, const void *b) {
    return ((const Result *)a)->cost - ((const Result *)b)->cost;
}

Result dijkstra(char start[], char target[]) {
    Result queue[MAX_NODES];
    int queue_size = 0;
    int visited[MAX_NODES] = {0};
    queue[queue_size].cost = 0;
    strcpy(queue[queue_size].path, start);
    queue[queue_size].path_length = 1;
    queue_size++;

    while (queue_size > 0) {
        qsort(queue, queue_size, sizeof(Result), compare);
        Result current = queue[0];
        memmove(queue, queue + 1, (queue_size - 1) * sizeof(Result));
        queue_size--;

        int current_node = -1;
        for (int i = 0; i < node_count; i++) {
            if (strcmp(graph[i].name, current.path + current.path_length - 2) == 0) {
                current_node = i;
                break;
            }
        }

        if (visited[current_node]) {
            continue;
        }
        visited[current_node] = 1;

        if (strcmp(graph[current_node].name, target) == 0) {
            return current;
        }

        for (int i = 0; i < graph[current_node].edge_count; i++) {
            if (!visited[i]) {
                Result new_entry;
                new_entry.cost = current.cost + graph[current_node].edges[i].weight;
                strcpy(new_entry.path, current.path);
                strcat(new_entry.path, graph[current_node].edges[i].name);
                new_entry.path_length = current.path_length + 2;
                queue[queue_size++] = new_entry;
            }
        }
    }

    Result result;
    result.cost = INT_MAX;
    return result;
}

int main() {
    char nodes[][2] = {"A", "B", "C", "D", "E"};
    Edge edges[][3] = {
        {"A", "B", 1},
        {"B", "C", 2},
        {"C", "D", 1},
        {"D", "E", 1},
        {"A", "E", 4}
    };
    node_count = sizeof(nodes) / sizeof(nodes[0]);
    edge_count = sizeof(edges) / sizeof(edges[0]);
    initialize_graph(nodes, node_count, edges, edge_count);
    Result result = dijkstra("A", "E");
    printf("Shortest path cost: %d, Path: %s\n", result.cost, result.path);
    return 0;
}