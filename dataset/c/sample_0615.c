#include <stdio.h>

int optimize_supply_chain(int costs[][3], int index, int result) {
    if (index == 3) {
        return result;
    }
    int min_cost = costs[index][0];
    for (int i = 1; i < 3; i++) {
        if (costs[index][i] < min_cost) {
            min_cost = costs[index][i];
        }
    }
    return optimize_supply_chain(costs, index + 1, result + min_cost);
}

int main() {
    int costs[3][3] = {{10, 20, 30}, {15, 25, 35}, {5, 15, 25}};
    printf("%d\n", optimize_supply_chain(costs, 0, 0));
    return 0;
}