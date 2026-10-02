#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int stock;
    int replenish_rate;
} Inventory;

void Inventory_init(Inventory *self, int initial_stock, int replenish_rate) {
    self->stock = initial_stock;
    self->replenish_rate = replenish_rate;
}

void Inventory_update_stock(Inventory *self, double demand) {
    self->stock -= demand;
    if (self->stock < 0) {
        self->stock = 0;
    }
}

void Inventory_replenish(Inventory *self) {
    self->stock += self->replenish_rate;
}

typedef struct {
    // No state needed for now
} DemandGenerator;

double DemandGenerator_generate(DemandGenerator *self) {
    return (double)(rand() % 1000) / 100 + 1;
}

typedef struct {
    Inventory *inventory;
    DemandGenerator *demand_generator;
} SupplyChainOptimizer;

void SupplyChainOptimizer_init(SupplyChainOptimizer *self, Inventory *inventory, DemandGenerator *demand_generator) {
    self->inventory = inventory;
    self->demand_generator = demand_generator;
}

void SupplyChainOptimizer_run_optimization(SupplyChainOptimizer *self) {
    while (1) {
        double demand = DemandGenerator_generate(self->demand_generator);
        Inventory_update_stock(self->inventory, demand);
        Inventory_replenish(self->inventory);
    }
}

int main() {
    srand(time(NULL));
    int initial_stock = 100;
    int replenish_rate = 10;
    Inventory inventory;
    DemandGenerator demand_generator;
    SupplyChainOptimizer optimizer;

    Inventory_init(&inventory, initial_stock, replenish_rate);
    SupplyChainOptimizer_init(&optimizer, &inventory, &demand_generator);
    SupplyChainOptimizer_run_optimization(&optimizer);

    return 0;
}