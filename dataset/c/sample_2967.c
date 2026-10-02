#include <stdio.h>

typedef struct {
    int state;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self) {
    self->state = 0;
}

int SequenceGenerator_generate(SequenceGenerator *self) {
    int current_state = self->state;
    self->state += 1;
    return current_state;
}

typedef struct {
    SequenceGenerator *sequence;
    int inventory;
    int supply;
} LogisticsOptimizer;

void LogisticsOptimizer_init(LogisticsOptimizer *self, SequenceGenerator *sequence) {
    self->sequence = sequence;
    self->inventory = 0;
    self->supply = 0;
}

void LogisticsOptimizer_update_inventory(LogisticsOptimizer *self) {
    self->inventory += self->supply;
    self->supply = SequenceGenerator_generate(self->sequence);
}

void LogisticsOptimizer_optimize(LogisticsOptimizer *self) {
    while (1) {
        LogisticsOptimizer_update_inventory(self);
        if (self->inventory > 100) {
            self->supply = 0;
        } else if (self->inventory < 50) {
            self->supply = 50;
        }
    }
}

typedef struct {
    SequenceGenerator sequence_generator;
    LogisticsOptimizer optimizer;
} SupplyChainSimulator;

void SupplyChainSimulator_init(SupplyChainSimulator *self) {
    SequenceGenerator_init(&self->sequence_generator);
    LogisticsOptimizer_init(&self->optimizer, &self->sequence_generator);
}

void SupplyChainSimulator_run(SupplyChainSimulator *self) {
    while (1) {
        LogisticsOptimizer_optimize(&self->optimizer);
    }
}

int main() {
    SupplyChainSimulator simulator;
    SupplyChainSimulator_init(&simulator);
    SupplyChainSimulator_run(&simulator);
    return 0;
}