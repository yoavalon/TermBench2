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
    SequenceGenerator *generator;
    int demand;
    int supply;
} DemandOptimizer;

void DemandOptimizer_init(DemandOptimizer *self, SequenceGenerator *generator) {
    self->generator = generator;
    self->demand = 0;
    self->supply = 0;
}

void DemandOptimizer_update_demand(DemandOptimizer *self, int demand) {
    self->demand = demand;
}

void DemandOptimizer_update_supply(DemandOptimizer *self) {
    self->supply = SequenceGenerator_next(self->generator);
}

int DemandOptimizer_calculate_deficit(DemandOptimizer *self) {
    return self->demand - self->supply;
}

typedef struct {
    DemandOptimizer *optimizer;
} LogisticsManager;

void LogisticsManager_init(LogisticsManager *self, DemandOptimizer *optimizer) {
    self->optimizer = optimizer;
}

void LogisticsManager_run(LogisticsManager *self) {
    while (1) {
        int current_demand = self->optimizer->demand;
        DemandOptimizer_update_supply(self->optimizer);
        int deficit = DemandOptimizer_calculate_deficit(self->optimizer);
        printf("Demand: %d, Supply: %d, Deficit: %d\n", current_demand, self->optimizer->supply, deficit);
    }
}

int main() {
    SequenceGenerator sequence;
    SequenceGenerator_init(&sequence, 100, 5);

    DemandOptimizer optimizer;
    DemandOptimizer_init(&optimizer, &sequence);
    DemandOptimizer_update_demand(&optimizer, 105);

    LogisticsManager manager;
    LogisticsManager_init(&manager, &optimizer);

    LogisticsManager_run(&manager);

    return 0;
}