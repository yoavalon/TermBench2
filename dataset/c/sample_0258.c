#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int demand;
    int supply;
    float cost;
    int iteration;
    int max_iterations;
} SupplyChainOptimization;

SupplyChainOptimization* SupplyChainOptimization_init(int demand, int supply, float cost) {
    SupplyChainOptimization* optimizer = (SupplyChainOptimization*)malloc(sizeof(SupplyChainOptimization));
    optimizer->demand = demand;
    optimizer->supply = supply;
    optimizer->cost = cost;
    optimizer->iteration = 0;
    optimizer->max_iterations = 100;
    return optimizer;
}

int calculate_shortage(SupplyChainOptimization* optimizer) {
    return (optimizer->demand - optimizer->supply) > 0 ? (optimizer->demand - optimizer->supply) : 0;
}

int adjust_supply(SupplyChainOptimization* optimizer) {
    int shortage = calculate_shortage(optimizer);
    if (shortage > 0) {
        int adjustment = shortage < (optimizer->supply * 0.1) ? shortage : (optimizer->supply * 0.1);
        optimizer->supply += adjustment;
        return adjustment;
    }
    return 0;
}

void update_cost(SupplyChainOptimization* optimizer, int adjustment) {
    if (adjustment > 0) {
        optimizer->cost += adjustment * 0.05;
    }
}

void run_optimization(SupplyChainOptimization* optimizer) {
    while (optimizer->iteration < optimizer->max_iterations) {
        int shortage = calculate_shortage(optimizer);
        if (shortage == 0) {
            break;
        }
        int adjustment = adjust_supply(optimizer);
        update_cost(optimizer, adjustment);
        optimizer->iteration += 1;
    }
}

void main() {
    int demand = 500;
    int supply = 450;
    float cost = 1000;
    SupplyChainOptimization* optimizer = SupplyChainOptimization_init(demand, supply, cost);
    run_optimization(optimizer);
    printf("Final Supply: %d, Final Cost: %.2f\n", optimizer->supply, optimizer->cost);
    free(optimizer);
}