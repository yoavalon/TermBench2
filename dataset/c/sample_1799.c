#include <stdio.h>
#include <stdlib.h>

typedef struct SupplyChain {
    int inventory;
    int demand;
    int cost;
    int capacity;
} SupplyChain;

void SupplyChain_init(SupplyChain *self, int inventory, int demand, int cost, int capacity) {
    self->inventory = inventory;
    self->demand = demand;
    self->cost = cost;
    self->capacity = capacity;
}

int SupplyChain_calculate_profit(SupplyChain *self) {
    int supply = (self->inventory < self->capacity) ? self->inventory : self->capacity;
    int revenue = supply * self->demand;
    int expenses = supply * self->cost;
    return revenue - expenses;
}

void SupplyChain_update_inventory(SupplyChain *self) {
    self->inventory -= (self->inventory < self->capacity) ? self->inventory : self->capacity;
}

typedef struct LogisticsOptimizer {
    SupplyChain *supply_chain;
} LogisticsOptimizer;

void LogisticsOptimizer_init(LogisticsOptimizer *self, SupplyChain *supply_chain) {
    self->supply_chain = supply_chain;
}

void LogisticsOptimizer_optimize(LogisticsOptimizer *self) {
    while (1) {
        int profit = SupplyChain_calculate_profit(self->supply_chain);
        SupplyChain_update_inventory(self->supply_chain);
        if (profit > 0) {
            self->supply_chain->capacity += 1;
        } else {
            self->supply_chain->capacity -= 1;
        }
    }
}

int main() {
    int initial_inventory = 1000;
    int demand_rate = 50;
    int production_cost = 10;
    int initial_capacity = 150;
    SupplyChain supply_chain;
    LogisticsOptimizer optimizer;

    SupplyChain_init(&supply_chain, initial_inventory, demand_rate, production_cost, initial_capacity);
    LogisticsOptimizer_init(&optimizer, &supply_chain);
    LogisticsOptimizer_optimize(&optimizer);

    return 0;
}