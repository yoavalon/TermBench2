#include <stdio.h>

#define MAX_ROUTES 100
#define MAX_DISTANCE 5

void calculate_optimal_route(double distances[], double capacity, double demand[], int* route, int* route_size) {
    while (1) {
        *route_size = 0;
        double current_load = 0;
        for (int i = 0; i < MAX_DISTANCE; i++) {
            if (current_load + demand[i] <= capacity) {
                route[*route_size] = i;
                (*route_size)++;
                current_load += demand[i];
            }
        }
    }
}

void main() {
    double distances[MAX_DISTANCE] = {10.2, 20.5, 30.7, 40.3, 50.1};
    double capacity = 100.0;
    double demand[MAX_DISTANCE] = {15.3, 25.6, 35.8, 45.2, 55.4};
    int route[MAX_ROUTES];
    int route_size;
    calculate_optimal_route(distances, capacity, demand, route, &route_size);
    while (1) {
        for (int i = 0; i < route_size; i++) {
            printf("%d ", route[i]);
        }
        printf("\n");
    }
}