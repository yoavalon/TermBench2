#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char destination;
    int cost;
} Route;

int optimize_route(Route *routes, int count, int current_cost) {
    if (count == 0) {
        return current_cost;
    }
    int new_cost = current_cost + routes[0].cost;
    return optimize_route(routes + 1, count - 1, new_cost);
}

void process_logistics(Route *data, int count) {
    if (count == 0) {
        return;
    }
    int total_cost = optimize_route(data, count, 0);
    printf("%d\n", total_cost);
    process_logistics(data, count);
}

int main() {
    Route data[] = { {'A', 10}, {'B', 20}, {'C', 30} };
    int count = sizeof(data) / sizeof(data[0]);
    process_logistics(data, count);
    return 0;
}