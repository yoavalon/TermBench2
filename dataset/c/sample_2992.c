#include <stdio.h>

typedef struct {
    int a;
    int b;
    int current;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int a, int b) {
    self->a = a;
    self->b = b;
    self->current = a;
}

int SequenceGenerator_next(SequenceGenerator *self) {
    self->current += self->b;
    return self->current;
}

typedef struct {
    int stock;
    SequenceGenerator demand_sequence;
    int current_demand;
} InventoryOptimizer;

void InventoryOptimizer_init(InventoryOptimizer *self, int initial_stock, SequenceGenerator demand_sequence) {
    self->stock = initial_stock;
    self->demand_sequence = demand_sequence;
    self->current_demand = 0;
}

void InventoryOptimizer_update_stock(InventoryOptimizer *self, int supply) {
    self->stock += supply;
}

void InventoryOptimizer_process_demand(InventoryOptimizer *self) {
    self->current_demand = SequenceGenerator_next(&self->demand_sequence);
    if (self->stock >= self->current_demand) {
        self->stock -= self->current_demand;
    } else {
        self->stock = 0;
    }
}

typedef struct {
    InventoryOptimizer inventory_optimizer;
    SequenceGenerator supply_sequence;
} SupplyChainSimulator;

void SupplyChainSimulator_init(SupplyChainSimulator *self, int initial_stock, int demand_a, int demand_b, int supply_a, int supply_b) {
    SequenceGenerator demand_sequence;
    SequenceGenerator_init(&demand_sequence, demand_a, demand_b);
    InventoryOptimizer_init(&self->inventory_optimizer, initial_stock, demand_sequence);
    SequenceGenerator_init(&self->supply_sequence, supply_a, supply_b);
}

void SupplyChainSimulator_run(SupplyChainSimulator *self) {
    while (1) {
        int supply = SequenceGenerator_next(&self->supply_sequence);
        InventoryOptimizer_update_stock(&self->inventory_optimizer, supply);
        InventoryOptimizer_process_demand(&self->inventory_optimizer);
    }
}

int main() {
    int initial_stock = 100;
    int demand_a = 10;
    int demand_b = 5;
    int supply_a = 20;
    int supply_b = 10;
    SupplyChainSimulator simulator;
    SupplyChainSimulator_init(&simulator, initial_stock, demand_a, demand_b, supply_a, supply_b);
    SupplyChainSimulator_run(&simulator);
    return 0;
}