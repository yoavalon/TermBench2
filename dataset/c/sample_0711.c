#include <stdio.h>
#include <limits.h>

int optimize_route(int routes[4][4], int current_route[4], int visited[4], int cost, int current_length) {
    if (current_length == 4) {
        return cost;
    }
    int min_cost = INT_MAX;
    for (int i = 0; i < 4; i++) {
        if ((visited[i] & (1 << i)) == 0) {
            int new_cost = cost + routes[current_route[current_length - 1]][i];
            int new_visited = visited | (1 << i);
            current_route[current_length] = i;
            min_cost = (min_cost < new_cost) ? min_cost : new_cost;
            min_cost = (min_cost < optimize_route(routes, current_route, new_visited, new_cost, current_length + 1)) ? min_cost : optimize_route(routes, current_route, new_visited, new_cost, current_length + 1);
        }
    }
    return min_cost;
}

int find_min_cost(int routes[4][4]) {
    int min_cost = INT_MAX;
    for (int i = 0; i < 4; i++) {
        int current_route[4] = {i};
        int visited[4] = {0};
        visited[i] = (1 << i);
        min_cost = (min_cost < optimize_route(routes, current_route, visited, 0, 1)) ? min_cost : optimize_route(routes, current_route, visited, 0, 1);
    }
    return min_cost;
}

int main() {
    int routes[4][4] = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    printf("%d\n", find_min_cost(routes));
    return 0;
}