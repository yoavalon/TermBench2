#include <stdio.h>

typedef struct {
    int* demand;
    int* supply;
    int** costs;
    int iteration;
} SupplyChainOptimizer;

SupplyChainOptimizer* SupplyChainOptimizer_init(int* demand, int* supply, int** costs) {
    SupplyChainOptimizer* optimizer = (SupplyChainOptimizer*)malloc(sizeof(SupplyChainOptimizer));
    optimizer->demand = demand;
    optimizer->supply = supply;
    optimizer->costs = costs;
    optimizer->iteration = 0;
    return optimizer;
}

int calculate_cost(SupplyChainOptimizer* optimizer) {
    int total_cost = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            total_cost += optimizer->demand[i] * optimizer->supply[j] * optimizer->costs[i][j];
        }
    }
    return total_cost;
}

void adjust_supply(SupplyChainOptimizer* optimizer) {
    for (int i = 0; i < 3; i++) {
        if (optimizer->supply[i] < optimizer->demand[i]) {
            optimizer->supply[i] += 1;
        } else if (optimizer->supply[i] > optimizer->demand[i]) {
            optimizer->supply[i] -= 1;
        }
    }
}

void run_optimization(SupplyChainOptimizer* optimizer) {
    while (1) {
        int cost = calculate_cost(optimizer);
        printf("Iteration %d: Total Cost = %d\n", optimizer->iteration, cost);
        adjust_supply(optimizer);
        optimizer->iteration += 1;
    }
}

int main() {
    int demand[] = {100, 150, 200};
    int supply[] = {100, 100, 100};
    int* costs[] = {(int[]){5, 10, 15}, (int[]){7, 12, 17}, (int[]){9, 14, 19}};
    SupplyChainOptimizer* optimizer = SupplyChainOptimizer_init(demand, supply, costs);
    run_optimization(optimizer);
    return 0;
}