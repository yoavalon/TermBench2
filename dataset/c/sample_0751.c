#include <stdio.h>
#include <limits.h>

#define N 4

int optimize_route(int cost_matrix[N][N], int current_route[N], int visited[N], int route_length, int total_cost) {
    if (route_length == N) {
        return total_cost;
    }
    int min_cost = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            int cost = optimize_route(cost_matrix, current_route, visited, route_length + 1, total_cost + cost_matrix[current_route[route_length - 1]][i]);
            visited[i] = 0;
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
    }
    return min_cost;
}

void main() {
    int cost_matrix[N][N] = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    int initial_route[N] = {0};
    int visited[N] = {0};
    visited[0] = 1;
    int result = optimize_route(cost_matrix, initial_route, visited, 1, 0);
    printf("%d\n", result);
}