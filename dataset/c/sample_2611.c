#include <stdio.h>

typedef struct {
    int current;
    int increment;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int start, int increment) {
    self->current = start;
    self->increment = increment;
}

void SequenceGenerator_generate(SequenceGenerator *self, int *sequence, int count) {
    for (int i = 0; i < count; i++) {
        sequence[i] = self->current;
        self->current += self->increment;
    }
}

typedef struct {
    int demand;
    int supply;
} SupplyChainOptimizer;

void SupplyChainOptimizer_init(SupplyChainOptimizer *self, int demand, int supply) {
    self->demand = demand;
    self->supply = supply;
}

int SupplyChainOptimizer_calculate_deficit(SupplyChainOptimizer *self) {
    int deficit = self->demand - self->supply;
    return (deficit > 0) ? deficit : 0;
}

void SupplyChainOptimizer_optimize_supply(SupplyChainOptimizer *self, int additional_supply) {
    self->supply += additional_supply;
}

typedef struct {
    int *demand_sequence;
    int *supply_sequence;
    SupplyChainOptimizer optimizer;
} SupplyChain;

void SupplyChain_init(SupplyChain *self, int *demand_sequence, int *supply_sequence) {
    self->demand_sequence = demand_sequence;
    self->supply_sequence = supply_sequence;
    SupplyChainOptimizer_init(&self->optimizer, 0, 0);
}

void SupplyChain_run_optimization(SupplyChain *self, int length) {
    for (int i = 0; i < length; i++) {
        self->optimizer.supply = self->supply_sequence[i];
        int deficit = SupplyChainOptimizer_calculate_deficit(&self->optimizer);
        if (deficit > 0) {
            SequenceGenerator deficit_gen;
            SequenceGenerator_init(&deficit_gen, deficit, 1);
            int additional_supply;
            SequenceGenerator_generate(&deficit_gen, &additional_supply, 1);
            SupplyChainOptimizer_optimize_supply(&self->optimizer, additional_supply);
        }
        printf("Demand: %d, Supply: %d, Deficit: %d, Adjusted Supply: %d\n",
               self->demand_sequence[i], self->supply_sequence[i], deficit, self->optimizer.supply);
    }
}

void main() {
    SequenceGenerator demand_gen;
    SequenceGenerator_init(&demand_gen, 100, 10);
    int demand_sequence[10];
    SequenceGenerator_generate(&demand_gen, demand_sequence, 10);

    SequenceGenerator supply_gen;
    SequenceGenerator_init(&supply_gen, 80, 5);
    int supply_sequence[10];
    SequenceGenerator_generate(&supply_gen, supply_sequence, 10);

    SupplyChain supply_chain;
    SupplyChain_init(&supply_chain, demand_sequence, supply_sequence);
    SupplyChain_run_optimization(&supply_chain, 10);
}