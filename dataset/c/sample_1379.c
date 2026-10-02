#include <stdio.h>
#include <stdlib.h>

int** optimize_routes(int** routes, int* demands, int* capacities, int size) {
    for (int i = 0; i < size; i++) {
        if (demands[i] > capacities[i]) {
            routes = redistribute_load(routes, demands, capacities, i, size);
        }
    }
    return routes;
}

int** redistribute_load(int** routes, int* demands, int* capacities, int index, int size) {
    int excess = demands[index] - capacities[index];
    for (int j = 0; j < size; j++) {
        if (j != index && capacities[j] > 0) {
            int transfer = excess > capacities[j] ? capacities[j] : excess;
            demands[j] += transfer;
            demands[index] -= transfer;
            excess -= transfer;
            if (excess == 0) {
                break;
            }
        }
    }
    return routes;
}

void main() {
    int* routes[] = {(int[]){1, 2}, (int[]){3, 4}, (int[]){5, 6}};
    int demands[] = {10, 15, 20};
    int capacities[] = {10, 10, 10};
    int size = sizeof(routes) / sizeof(routes[0]);

    routes = optimize_routes(routes, demands, capacities, size);

    for (int i = 0; i < size; i++) {
        printf("[");
        for (int j = 0; j < 2; j++) {
            printf("%d", routes[i][j]);
            if (j < 1) printf(", ");
        }
        printf("]");
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}