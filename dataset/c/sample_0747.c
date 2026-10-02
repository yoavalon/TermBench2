#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Route {
    char destination;
    int cost;
} Route;

typedef struct Node {
    Route *routes;
    int size;
} Node;

typedef struct Graph {
    Node *nodes;
    int size;
} Graph;

typedef struct Set {
    char *elements;
    int size;
    int capacity;
} Set;

int set_contains(Set *set, char element) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            return 1;
        }
    }
    return 0;
}

void set_add(Set *set, char element) {
    if (!set_contains(set, element)) {
        if (set->size == set->capacity) {
            set->capacity *= 2;
            set->elements = (char *)realloc(set->elements, sizeof(char) * set->capacity);
        }
        set->elements[set->size++] = element;
    }
}

void set_remove(Set *set, char element) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == element) {
            for (int j = i; j < set->size - 1; j++) {
                set->elements[j] = set->elements[j + 1];
            }
            set->size--;
            break;
        }
    }
}

void set_init(Set *set, int initial_capacity) {
    set->elements = (char *)malloc(sizeof(char) * initial_capacity);
    set->size = 0;
    set->capacity = initial_capacity;
}

void set_free(Set *set) {
    free(set->elements);
}

int optimize_route(Graph *graph, Set *visited, char current, char destination, int cost) {
    if (current == destination) {
        return cost;
    }
    int min_cost = INT_MAX;
    Node *node = &graph->nodes[current - 'A'];
    for (int i = 0; i < node->size; i++) {
        Route *route = &node->routes[i];
        if (!set_contains(visited, route->destination)) {
            set_add(visited, route->destination);
            int new_cost = optimize_route(graph, visited, route->destination, destination, cost + route->cost);
            set_remove(visited, route->destination);
            if (new_cost < min_cost) {
                min_cost = new_cost;
            }
        }
    }
    return min_cost;
}

int find_optimal_path(Graph *graph, char start, char end) {
    Set visited;
    set_init(&visited, 1);
    set_add(&visited, start);
    int result = optimize_route(graph, &visited, start, end, 0);
    set_free(&visited);
    return result;
}

Graph *graph_init() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->size = 4;
    graph->nodes = (Node *)malloc(sizeof(Node) * graph->size);
    for (int i = 0; i < graph->size; i++) {
        graph->nodes[i].routes = NULL;
        graph->nodes[i].size = 0;
    }
    return graph;
}

void graph_add_route(Graph *graph, char source, char destination, int cost) {
    Node *node = &graph->nodes[source - 'A'];
    node->size++;
    node->routes = (Route *)realloc(node->routes, sizeof(Route) * node->size);
    node->routes[node->size - 1].destination = destination;
    node->routes[node->size - 1].cost = cost;
}

void graph_free(Graph *graph) {
    for (int i = 0; i < graph->size; i++) {
        free(graph->nodes[i].routes);
    }
    free(graph->nodes);
    free(graph);
}

int main() {
    Graph *graph = graph_init();
    graph_add_route(graph, 'A', 'B', 10);
    graph_add_route(graph, 'A', 'C', 15);
    graph_add_route(graph, 'B', 'C', 35);
    graph_add_route(graph, 'B', 'D', 25);
    graph_add_route(graph, 'C', 'D', 30);
    char start = 'A';
    char end = 'D';
    int result = find_optimal_path(graph, start, end);
    printf("%d\n", result);
    graph_free(graph);
    return 0;
}