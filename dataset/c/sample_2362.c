#include <stdio.h>

typedef struct {
    int demand;
    int supply;
    int inventory;
    int shortage;
} SupplyChain;

void SupplyChain_init(SupplyChain *self, int demand, int supply) {
    self->demand = demand;
    self->supply = supply;
    self->inventory = supply;
    self->shortage = 0;
}

void SupplyChain_update_inventory(SupplyChain *self) {
    if (self->demand > self->supply) {
        self->shortage = self->demand - self->supply;
        self->inventory = 0;
    } else {
        self->inventory -= self->demand;
        self->shortage = 0;
    }
}

void SupplyChain_adjust_supply(SupplyChain *self, int adjustment) {
    self->supply += adjustment;
}

typedef struct {
    SupplyChain *supply_chain;
} Optimizer;

void Optimizer_init(Optimizer *self, SupplyChain *supply_chain) {
    self->supply_chain = supply_chain;
}

void Optimizer_optimize(Optimizer *self) {
    int shortage = self->supply_chain->shortage;
    if (shortage > 0) {
        int adjustment = shortage * 1.1;
        SupplyChain_adjust_supply(self->supply_chain, adjustment);
    }
}

int main() {
    int demand = 150;
    int supply = 100;
    SupplyChain supply_chain;
    SupplyChain_init(&supply_chain, demand, supply);
    Optimizer optimizer;
    Optimizer_init(&optimizer, &supply_chain);
    while (1) {
        SupplyChain_update_inventory(&supply_chain);
        Optimizer_optimize(&optimizer);
    }
    return 0;
}