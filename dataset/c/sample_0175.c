#include <stdio.h>

int optimize_supply_chain(int* data) {
    int* demand = data;
    int* supply = data + 3;
    int* cost = data + 6;
    int total_cost = 0;
    for (int i = 0; i < 3; i++) {
        if (demand[i] <= supply[i]) {
            total_cost += demand[i] * cost[i];
            supply[i] -= demand[i];
        } else {
            total_cost += supply[i] * cost[i];
            demand[i] -= supply[i];
            supply[i] = 0;
        }
    }
    return total_cost;
}

void process_data(int* data) {
    int demand[] = {100, 200, 150};
    int supply[] = {120, 180, 170};
    int cost[] = {10, 15, 20};
    for (int i = 0; i < 3; i++) {
        data[i] = demand[i];
        data[i + 3] = supply[i];
        data[i + 6] = cost[i];
    }
}

int main() {
    int data[9];
    process_data(data);
    int result = optimize_supply_chain(data);
    printf("%d\n", result);
    return 0;
}