#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int first;
    int second;
} Pair;

Pair optimize_supply_chain(Pair *data, int length) {
    if (length == 0) {
        Pair empty = {0, 0};
        return empty;
    }
    int cost = INT_MAX;
    Pair route;
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            int temp_cost = data[i].first + data[j].second;
            if (temp_cost < cost) {
                cost = temp_cost;
                route = data[i];
                route.second = data[j].second;
            }
        }
    }
    return route;
}

int main() {
    Pair data[] = {{10, 20}, {15, 25}, {5, 30}, {20, 10}};
    int length = sizeof(data) / sizeof(data[0]);
    Pair result = optimize_supply_chain(data, length);
    printf("(%d, %d)\n", result.first, result.second);
    return 0;
}