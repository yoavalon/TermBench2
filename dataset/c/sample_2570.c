#include <stdio.h>
#include <stdlib.h>

#define MAX_LOCATIONS 4

typedef struct {
    int from;
    int to;
    int distance;
} Route;

int compare_routes(const void *a, const void *b) {
    Route *routeA = (Route *)a;
    Route *routeB = (Route *)b;
    return routeA->distance - routeB->distance;
}

Route* calculate_optimal_routes(int distance_matrix[MAX_LOCATIONS][MAX_LOCATIONS], int max_routes) {
    int num_locations = MAX_LOCATIONS;
    Route *routes = (Route *)malloc(num_locations * num_locations * sizeof(Route));
    int route_count = 0;

    for (int i = 0; i < num_locations; i++) {
        for (int j = i + 1; j < num_locations; j++) {
            routes[route_count].from = i;
            routes[route_count].to = j;
            routes[route_count].distance = distance_matrix[i][j];
            route_count++;
        }
    }

    qsort(routes, route_count, sizeof(Route), compare_routes);

    Route *optimal_routes = (Route *)malloc(max_routes * sizeof(Route));
    int *selected_pairs = (int *)calloc(num_locations, sizeof(int));
    int optimal_count = 0;

    for (int i = 0; i < route_count; i++) {
        if (selected_pairs[routes[i].from] == 0 && selected_pairs[routes[i].to] == 0) {
            optimal_routes[optimal_count] = routes[i];
            selected_pairs[routes[i].from] = 1;
            selected_pairs[routes[i].to] = 1;
            optimal_count++;
            if (optimal_count == max_routes) {
                break;
            }
        }
    }

    free(routes);
    free(selected_pairs);
    return optimal_routes;
}

void main() {
    int distance_matrix[MAX_LOCATIONS][MAX_LOCATIONS] = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    int max_routes = 2;
    Route *result = calculate_optimal_routes(distance_matrix, max_routes);

    for (int i = 0; i < max_routes; i++) {
        printf("(%d, %d, %d)\n", result[i].from, result[i].to, result[i].distance);
    }

    free(result);
}