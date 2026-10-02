#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROUTES 3
#define MAX_STEPS 3

typedef struct {
    char* steps[MAX_STEPS];
    int size;
} Route;

typedef struct {
    Route* routes;
    int size;
} OptimizedRoutes;

void add_route(OptimizedRoutes* optimized_routes, Route route) {
    optimized_routes->routes = realloc(optimized_routes->routes, (optimized_routes->size + 1) * sizeof(Route));
    optimized_routes->routes[optimized_routes->size] = route;
    optimized_routes->size++;
}

OptimizedRoutes optimize_routes(char* routes[MAX_ROUTES][MAX_STEPS], int route_count, Route current_route) {
    OptimizedRoutes optimized_routes = {NULL, 0};

    if (route_count == 0) {
        Route route = {NULL, 0};
        route.steps[route.size++] = malloc(strlen(current_route.steps[0]) + 1);
        strcpy(route.steps[0], current_route.steps[0]);
        add_route(&optimized_routes, route);
        return optimized_routes;
    }

    for (int i = 0; i < MAX_STEPS && routes[0][i] != NULL; i++) {
        Route new_route = {NULL, 0};
        new_route.steps[new_route.size++] = malloc(strlen(routes[0][i]) + 1);
        strcpy(new_route.steps[0], routes[0][i]);
        for (int j = 0; j < current_route.size; j++) {
            new_route.steps[new_route.size++] = malloc(strlen(current_route.steps[j]) + 1);
            strcpy(new_route.steps[new_route.size - 1], current_route.steps[j]);
        }
        OptimizedRoutes new_optimized_routes = optimize_routes(routes + 1, route_count - 1, new_route);
        for (int j = 0; j < new_optimized_routes.size; j++) {
            add_route(&optimized_routes, new_optimized_routes.routes[j]);
        }
    }
    return optimized_routes;
}

void analyze_supply_chain() {
    while (1) {
        char* supply_chain[MAX_ROUTES][MAX_STEPS] = {
            {"A1", "A2", NULL},
            {"B1", "B2", "B3", NULL},
            {"C1", "C2", NULL}
        };
        Route current_route = {NULL, 0};
        OptimizedRoutes optimized_routes = optimize_routes(supply_chain, MAX_ROUTES, current_route);
    }
}

int main() {
    analyze_supply_chain();
    return 0;
}