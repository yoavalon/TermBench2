#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char start[2];
    char end[2];
    int cost;
} Cost;

int calculate_cost(char** route, int route_len, Cost* costs, int num_costs) {
    int total_cost = 0;
    for (int i = 0; i < route_len - 1; i++) {
        for (int j = 0; j < num_costs; j++) {
            if (strcmp(route[i], costs[j].start) == 0 && strcmp(route[i + 1], costs[j].end) == 0) {
                total_cost += costs[j].cost;
                break;
            }
        }
    }
    return total_cost;
}

char** find_optimal_route(char*** routes, int num_routes, int* route_lengths, Cost* costs, int num_costs) {
    int min_cost = INT_MAX;
    char** best_route = NULL;
    for (int i = 0; i < num_routes; i++) {
        int cost = calculate_cost(routes[i], route_lengths[i], costs, num_costs);
        if (cost < min_cost) {
            min_cost = cost;
            best_route = routes[i];
        }
    }
    return best_route;
}

int main() {
    char* routes1[] = {"A", "B", "C"};
    char* routes2[] = {"A", "C", "B"};
    char* routes3[] = {"B", "A", "C"};
    char** routes[] = {routes1, routes2, routes3};
    int route_lengths[] = {3, 3, 3};
    int num_routes = 3;

    Cost costs[] = {{"A", "B", 10}, {"B", "C", 15}, {"C", "A", 20}};
    int num_costs = 3;

    char** optimal_route = find_optimal_route(routes, num_routes, route_lengths, costs, num_costs);

    printf("Optimal Route: ");
    for (int i = 0; i < route_lengths[0]; i++) {
        printf("%s ", optimal_route[i]);
    }
    printf("\n");

    return 0;
}