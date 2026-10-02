#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NEIGHBORS 10

typedef struct {
    char name;
    int neighbors[MAX_NEIGHBORS];
    int costs[MAX_NEIGHBORS];
    int neighbor_count;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int node_count;
} Graph;

typedef struct {
    Graph data;
} LogisticsOptimizer;

typedef struct {
    int visited[MAX_NODES];
    int path[MAX_NODES];
    int path_length;
} State;

void add_edge(Graph* graph, char from, char to, int cost) {
    Node* from_node = NULL;
    Node* to_node = NULL;

    for (int i = 0; i < graph->node_count; i++) {
        if (graph->nodes[i].name == from) {
            from_node = &graph->nodes[i];
        }
        if (graph->nodes[i].name == to) {
            to_node = &graph->nodes[i];
        }
    }

    if (!from_node) {
        from_node = &graph->nodes[graph->node_count++];
        from_node->name = from;
        from_node->neighbor_count = 0;
    }
    if (!to_node) {
        to_node = &graph->nodes[graph->node_count++];
        to_node->name = to;
        to_node->neighbor_count = 0;
    }

    from_node->neighbors[from_node->neighbor_count] = to_node->name;
    from_node->costs[from_node->neighbor_count] = cost;
    from_node->neighbor_count++;
}

int find_optimal_route(LogisticsOptimizer* optimizer, char current, char destination, State* state) {
    if (current == destination) {
        state->path[state->path_length++] = destination;
        return 1;
    }
    state->visited[current - 'A'] = 1;
    Node* current_node = NULL;
    for (int i = 0; i < optimizer->data.node_count; i++) {
        if (optimizer->data.nodes[i].name == current) {
            current_node = &optimizer->data.nodes[i];
            break;
        }
    }
    if (!current_node) return 0;
    for (int i = 0; i < current_node->neighbor_count; i++) {
        char neighbor = current_node->neighbors[i];
        if (!state->visited[neighbor - 'A']) {
            if (find_optimal_route(optimizer, neighbor, destination, state)) {
                state->path[state->path_length++] = current;
                return 1;
            }
        }
    }
    return 0;
}

int calculate_cost(LogisticsOptimizer* optimizer, State* state) {
    int cost = 0;
    for (int i = 0; i < state->path_length - 1; i++) {
        char current = state->path[i];
        char next = state->path[i + 1];
        Node* current_node = NULL;
        for (int j = 0; j < optimizer->data.node_count; j++) {
            if (optimizer->data.nodes[j].name == current) {
                current_node = &optimizer->data.nodes[j];
                break;
            }
        }
        if (!current_node) return 0;
        for (int k = 0; k < current_node->neighbor_count; k++) {
            if (current_node->neighbors[k] == next) {
                cost += current_node->costs[k];
                break;
            }
        }
    }
    return cost;
}

void optimize(LogisticsOptimizer* optimizer, char start, char end, int* cost, char* path) {
    State state = {0};
    find_optimal_route(optimizer, start, end, &state);
    *cost = calculate_cost(optimizer, &state);
    for (int i = 0; i < state.path_length; i++) {
        path[i] = state.path[state.path_length - 1 - i];
    }
}

int main() {
    LogisticsOptimizer optimizer = {0};
    add_edge(&optimizer.data, 'A', 'B', 10);
    add_edge(&optimizer.data, 'A', 'C', 15);
    add_edge(&optimizer.data, 'B', 'A', 10);
    add_edge(&optimizer.data, 'B', 'D', 20);
    add_edge(&optimizer.data, 'C', 'A', 15);
    add_edge(&optimizer.data, 'C', 'D', 30);
    add_edge(&optimizer.data, 'D', 'B', 20);
    add_edge(&optimizer.data, 'D', 'C', 30);

    int cost;
    char path[MAX_NODES];
    optimize(&optimizer, 'A', 'D', &cost, path);

    printf("Optimal Cost: %d\n", cost);
    printf("Optimal Path: ");
    for (int i = 0; path[i] != '\0'; i++) {
        printf("%c ", path[i]);
    }
    printf("\n");

    return 0;
}