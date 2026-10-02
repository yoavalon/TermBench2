#include <stdio.h>

int optimize_route(int routes[][3], int demands[], int num_routes, int num_demands) {
    int costs[num_routes];
    for (int r = 0; r < num_routes; r++) {
        int cost = 0;
        for (int i = 0; i < num_demands; i++) {
            cost += demands[i] * routes[r][i];
        }
        costs[r] = cost;
    }
    int min_cost = costs[0];
    for (int i = 1; i < num_routes; i++) {
        if (costs[i] < min_cost) {
            min_cost = costs[i];
        }
    }
    return min_cost;
}

void update_demands(int demands[], int adjustments[], int num_demands) {
    for (int i = 0; i < num_demands; i++) {
        demands[i] += adjustments[i];
    }
}

int main() {
    int routes[3][3] = {{2, 3, 1}, {4, 1, 2}, {3, 2, 3}};
    int demands[3] = {5, 10, 15};
    int adjustments[3] = {-1, 2, -3};
    update_demands(demands, adjustments, 3);
    int best_cost = optimize_route(routes, demands, 3, 3);
    printf("%d\n", best_cost);
    return 0;
}