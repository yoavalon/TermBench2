#include <stdio.h>

int optimize_supply_chain(int data[][2], int size) {
    int total_cost = 0;
    for (int i = 0; i < size; i++) {
        int cost = data[i][0] * data[i][1];
        total_cost += cost;
    }
    return total_cost;
}

int main() {
    int data[][2] = {{10, 5}, {20, 10}, {15, 3}};
    int result = optimize_supply_chain(data, 3);
    printf("%d\n", result);
    return 0;
}