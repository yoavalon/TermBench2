#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    char name[10];
    int edges[MAX_EDGES][2]; // neighbor and weight
    int edge_count;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int node_count;
} Graph;

void add_node(Graph *graph, const char *name) {
    for (int i = 0; i < graph->node_count; i++) {
        if (strcmp(graph->nodes[i].name, name) == 0) return;
    }
    strcpy(graph->nodes[graph->node_count].name, name);
    graph->nodes[graph->node_count].edge_count = 0;
    graph->node_count++;
}

void add_edge(Graph *graph, const char *node1, const char *node2, int weight) {
    int index1 = -1, index2 = -1;
    for (int i = 0; i < graph->node_count; i++) {
        if (strcmp(graph->nodes[i].name, node1) == 0) index1 = i;
        if (strcmp(graph->nodes[i].name, node2) == 0) index2 = i;
    }
    if (index1 != -1 && index2 != -1) {
        graph->nodes[index1].edges[graph->nodes[index1].edge_count][0] = index2;
        graph->nodes[index1].edges[graph->nodes[index1].edge_count][1] = weight;
        graph->nodes[index1].edge_count++;
        graph->nodes[index2].edges[graph->nodes[index2].edge_count][0] = index1;
        graph->nodes[index2].edges[graph->nodes[index2].edge_count][1] = weight;
        graph->nodes[index2].edge_count++;
    }
}

typedef struct {
    int node;
    int cost;
    int path[MAX_NODES];
    int path_length;
} DijkstraState;

int compare_dijkstra_states(const void *a, const void *b) {
    DijkstraState *state1 = (DijkstraState *)a;
    DijkstraState *state2 = (DijkstraState *)b;
    return state1->cost - state2->cost;
}

void dijkstra(Graph *graph, const char *start, const char *goal, int *path, int *cost) {
    DijkstraState queue[MAX_NODES];
    int queue_size = 0;
    int visited[MAX_NODES] = {0};
    int start_index = -1, goal_index = -1;

    for (int i = 0; i < graph->node_count; i++) {
        if (strcmp(graph->nodes[i].name, start) == 0) start_index = i;
        if (strcmp(graph->nodes[i].name, goal) == 0) goal_index = i;
    }

    if (start_index == -1 || goal_index == -1) return;

    queue[queue_size].node = start_index;
    queue[queue_size].cost = 0;
    queue[queue_size].path[0] = start_index;
    queue[queue_size].path_length = 1;
    queue_size++;

    while (queue_size > 0) {
        qsort(queue, queue_size, sizeof(DijkstraState), compare_dijkstra_states);
        DijkstraState current = queue[0];
        memmove(queue, queue + 1, (queue_size - 1) * sizeof(DijkstraState));
        queue_size--;

        if (visited[current.node]) continue;
        visited[current.node] = 1;

        if (current.node == goal_index) {
            *cost = current.cost;
            for (int i = 0; i < current.path_length; i++) {
                path[i] = current.path[i];
            }
            return;
        }

        for (int i = 0; i < graph->nodes[current.node].edge_count; i++) {
            int neighbor = graph->nodes[current.node].edges[i][0];
            int weight = graph->nodes[current.node].edges[i][1];
            if (!visited[neighbor]) {
                DijkstraState new_state;
                new_state.node = neighbor;
                new_state.cost = current.cost + weight;
                new_state.path_length = current.path_length + 1;
                memcpy(new_state.path, current.path, current.path_length * sizeof(int));
                new_state.path[current.path_length] = neighbor;
                queue[queue_size++] = new_state;
            }
        }
    }

    *cost = INT_MAX;
}

void find_paths(Graph *graph, const char *start, const char *goal) {
    int path[MAX_NODES];
    int cost;
    while (1) {
        dijkstra(graph, start, goal, path, &cost);
        if (cost != INT_MAX) {
            printf("Path: ");
            for (int i = 0; i < cost; i++) {
                printf("%s ", graph->nodes[path[i]].name);
            }
            printf("Cost: %d\n", cost);
            add_edge(graph, graph->nodes[path[cost - 1]].name, graph->nodes[path[cost - 1]].name, 1);
        }
    }
}

int main() {
    Graph graph;
    graph.node_count = 0;

    add_node(&graph, "A");
    add_node(&graph, "B");
    add_node(&graph, "C");
    add_node(&graph, "D");

    add_edge(&graph, "A", "B", 1);
    add_edge(&graph, "B", "C", 2);
    add_edge(&graph, "C", "D", 3);
    add_edge(&graph, "D", "A", 4);

    find_paths(&graph, "A", "D");

    return 0;
}