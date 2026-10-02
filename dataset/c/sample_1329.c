#include <stdio.h>
#include <stdlib.h>

#define MAX_ROUTES 3
#define MAX_ROUTE_LENGTH 3

int calculate_route_costs(int routes[MAX_ROUTES][MAX_ROUTE_LENGTH], int costs[MAX_ROUTES]) {
    for (int i = 0; i < MAX_ROUTES; i++) {
        int cost = 0;
        for (int j = 0; j < MAX_ROUTE_LENGTH; j++) {
            cost += routes[i][j];
        }
        costs[i] = cost;
    }
    return 0;
}

int optimize_routes(int routes[MAX_ROUTES][MAX_ROUTE_LENGTH], int budgets[MAX_ROUTES], int optimized_routes[MAX_ROUTES][MAX_ROUTE_LENGTH]) {
    int optimized_count = 0;
    for (int i = 0; i < MAX_ROUTES; i++) {
        int cost = 0;
        for (int j = 0; j < MAX_ROUTE_LENGTH; j++) {
            cost += routes[i][j];
        }
        if (cost <= budgets[i]) {
            for (int j = 0; j < MAX_ROUTE_LENGTH; j++) {
                optimized_routes[optimized_count][j] = routes[i][j];
            }
            optimized_count++;
        }
    }
    return optimized_count;
}

int main() {
    int routes[MAX_ROUTES][MAX_ROUTE_LENGTH] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    int budgets[MAX_ROUTES] = {150, 200, 250};
    int costs[MAX_ROUTES];
    int optimized_routes[MAX_ROUTES][MAX_ROUTE_LENGTH];
    int optimized_count;

    calculate_route_costs(routes, costs);
    optimized_count = optimize_routes(routes, budgets, optimized_routes);

    printf("[");
    for (int i = 0; i < optimized_count; i++) {
        printf("[");
        for (int j = 0; j < MAX_ROUTE_LENGTH; j++) {
            printf("%d", optimized_routes[i][j]);
            if (j < MAX_ROUTE_LENGTH - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < optimized_count - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}