#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char from;
    char to;
    int distance;
} Distance;

typedef struct {
    Distance** distances;
    char*** routes;
    int num_routes;
} Data;

int calculate_cost(Data* data, char** route, int route_length) {
    int cost = 0;
    for (int i = 0; i < route_length - 1; i++) {
        for (int j = 0; data->distances[i] != NULL; j++) {
            if (data->distances[i]->from == route[i][0] && data->distances[i]->to == route[i + 1][0]) {
                cost += data->distances[i]->distance;
                break;
            }
        }
    }
    return cost;
}

char** find_best_route(Data* data) {
    char** best_route = data->routes[0];
    int min_cost = calculate_cost(data, best_route, 3);

    for (int i = 1; i < data->num_routes; i++) {
        int current_cost = calculate_cost(data, data->routes[i], 3);
        if (current_cost < min_cost) {
            min_cost = current_cost;
            best_route = data->routes[i];
        }
    }
    return best_route;
}

void optimize_supply_chain(Data* data) {
    char** best_route = find_best_route(data);
    printf("Best route: %c -> %c -> %c\n", best_route[0][0], best_route[1][0], best_route[2][0]);
}

int main() {
    Distance* distances[] = {
        (Distance[]){{'A', 'B', 10}, {'A', 'C', 15}, NULL},
        (Distance[]){{'B', 'A', 10}, {'B', 'C', 35}, NULL},
        (Distance[]){{'C', 'A', 15}, {'C', 'B', 35}, NULL},
        NULL
    };

    char* routes1[] = {"A", "B", "C"};
    char* routes2[] = {"A", "C", "B"};
    char** routes[] = {routes1, routes2, NULL};

    Data data = {distances, routes, 2};
    optimize_supply_chain(&data);

    return 0;
}