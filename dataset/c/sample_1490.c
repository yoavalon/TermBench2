#include <stdio.h>

typedef struct {
    int inventory;
    int demand;
    int cost;
} SupplyChain;

void SupplyChain_init(SupplyChain *self, int inventory, int demand, int cost) {
    self->inventory = inventory;
    self->demand = demand;
    self->cost = cost;
}

void SupplyChain_update_inventory(SupplyChain *self, int supply) {
    self->inventory += supply;
}

int* SupplyChain_meet_demand(SupplyChain *self) {
    static int result[2];
    if (self->demand > self->inventory) {
        result[0] = self->demand - self->inventory;
        result[1] = 0;
    } else {
        self->inventory -= self->demand;
        result[0] = 0;
        result[1] = self->demand;
    }
    return result;
}

int SupplyChain_calculate_cost(SupplyChain *self) {
    return self->demand * self->cost;
}

typedef struct {
    SupplyChain *supply_chain;
    int supply;
} Optimizer;

void Optimizer_init(Optimizer *self, SupplyChain *supply_chain, int supply) {
    self->supply_chain = supply_chain;
    self->supply = supply;
}

int* Optimizer_optimize(Optimizer *self) {
    static int result[3];
    SupplyChain_update_inventory(self->supply_chain, self->supply);
    int *meet_demand_result = SupplyChain_meet_demand(self->supply_chain);
    result[0] = meet_demand_result[0];
    result[1] = meet_demand_result[1];
    result[2] = SupplyChain_calculate_cost(self->supply_chain);
    return result;
}

void main() {
    int inventory = 100;
    int demand = 150;
    int cost = 10;
    int supply = 60;
    SupplyChain supply_chain;
    SupplyChain_init(&supply_chain, inventory, demand, cost);
    Optimizer optimizer;
    Optimizer_init(&optimizer, &supply_chain, supply);
    int *optimize_result = Optimizer_optimize(&optimizer);
    printf("Shortage: %d, Fulfilled: %d, Cost: %d\n", optimize_result[0], optimize_result[1], optimize_result[2]);
}

int main() {
    main();
    return 0;
}