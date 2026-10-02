#include <stdio.h>

void optimize_supply_chain(int demand[], int supply[], int max_iterations) {
    int iteration = 0;
    while (iteration < max_iterations) {
        int total_demand = 0, total_supply = 0;
        for (int i = 0; i < 3; i++) {
            total_demand += demand[i];
            total_supply += supply[i];
        }
        if (total_demand > total_supply) {
            for (int i = 0; i < 3; i++) {
                supply[i] += 1;
            }
        } else if (total_demand < total_supply) {
            for (int i = 0; i < 3; i++) {
                supply[i] -= 1;
            }
        } else {
            break;
        }
        iteration += 1;
    }
}

int main() {
    int demand[] = {10, 20, 30};
    int supply[] = {15, 25, 20};
    int max_iterations = 10;
    optimize_supply_chain(demand, supply, max_iterations);
    return 0;
}