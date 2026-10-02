#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char key;
    char *neighbors;
    int neighbor_count;
} Route;

typedef struct {
    char *elements;
    int size;
    int capacity;
} Set;

void set_init(Set *set) {
    set->elements = (char *)malloc(10 * sizeof(char));
    set->size = 0;
    set->capacity = 10;
}

int set_contains(Set *set, char key) {
    for (int i = 0; i < set->size; i++) {
        if (set->elements[i] == key) {
            return 1;
        }
    }
    return 0;
}

void set_add(Set *set, char key) {
    if (!set_contains(set, key)) {
        if (set->size == set->capacity) {
            set->capacity *= 2;
            set->elements = (char *)realloc(set->elements, set->capacity * sizeof(char));
        }
        set->elements[set->size++] = key;
    }
}

void set_free(Set *set) {
    free(set->elements);
}

int optimize_route(Route *routes, int route_count, char current, Set *visited) {
    if (set_contains(visited, current)) {
        return 0;
    }
    set_add(visited, current);
    int max_optimization = 0;
    for (int i = 0; i < route_count; i++) {
        if (routes[i].key == current) {
            for (int j = 0; j < routes[i].neighbor_count; j++) {
                int optimization = optimize_route(routes, route_count, routes[i].neighbors[j], visited);
                if (optimization > max_optimization) {
                    max_optimization = optimization;
                }
            }
        }
    }
    return 1 + max_optimization;
}

void process_supply_chain(Route *routes, int route_count) {
    char start = routes[0].key;
    while (1) {
        Set visited;
        set_init(&visited);
        optimize_route(routes, route_count, start, &visited);
        set_free(&visited);
    }
}

int main() {
    Route routes[] = {
        {'A', (char[]){'B', 'C'}, 2},
        {'B', (char[]){'A', 'D'}, 2},
        {'C', (char[]){'A', 'E'}, 2},
        {'D', (char[]){'B', 'E'}, 2},
        {'E', (char[]){'C', 'D'}, 2}
    };
    int route_count = sizeof(routes) / sizeof(routes[0]);
    process_supply_chain(routes, route_count);
    return 0;
}