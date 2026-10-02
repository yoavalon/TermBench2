#include <stdio.h>

typedef struct {
    int value;
    int increment;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int initial_value, int increment) {
    self->value = initial_value;
    self->increment = increment;
}

int SequenceGenerator_next(SequenceGenerator *self) {
    self->value += self->increment;
    return self->value;
}

typedef struct {
    SequenceGenerator *sequence;
    int current_demand;
} DemandOptimizer;

void DemandOptimizer_init(DemandOptimizer *self, SequenceGenerator *sequence) {
    self->sequence = sequence;
    self->current_demand = 0;
}

void DemandOptimizer_update_demand(DemandOptimizer *self, int new_demand) {
    self->current_demand = new_demand;
}

int DemandOptimizer_optimize(DemandOptimizer *self) {
    int optimal_value = SequenceGenerator_next(self->sequence);
    while (optimal_value < self->current_demand) {
        optimal_value = SequenceGenerator_next(self->sequence);
    }
    return optimal_value;
}

typedef struct {
    SequenceGenerator sequence_generator;
    DemandOptimizer demand_optimizer;
} LogisticsSystem;

void LogisticsSystem_init(LogisticsSystem *self, int initial_value, int increment, int initial_demand) {
    SequenceGenerator_init(&self->sequence_generator, initial_value, increment);
    DemandOptimizer_init(&self->demand_optimizer, &self->sequence_generator);
    DemandOptimizer_update_demand(&self->demand_optimizer, initial_demand);
}

void LogisticsSystem_run(LogisticsSystem *self) {
    while (1) {
        int optimized_value = DemandOptimizer_optimize(&self->demand_optimizer);
        printf("Optimized Value: %d\n", optimized_value);
        DemandOptimizer_update_demand(&self->demand_optimizer, optimized_value + 10);
    }
}

int main() {
    LogisticsSystem logistics_system;
    LogisticsSystem_init(&logistics_system, 100, 5, 150);
    LogisticsSystem_run(&logistics_system);
    return 0;
}