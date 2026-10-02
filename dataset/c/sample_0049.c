#include <stdio.h>

typedef struct {
    int cost;
    int demand;
    int supply;
    int profit;
} Data;

Data supply_chain_optimization() {
    Data data = {100, 150, 120, 0};
    while (data.demand > data.supply) {
        data.cost += 5;
        data.supply += 10;
        data.profit -= 5;
    }
    return data;
}

int main() {
    Data result = supply_chain_optimization();
    printf("{cost: %d, demand: %d, supply: %d, profit: %d}\n", result.cost, result.demand, result.supply, result.profit);
    return 0;
}