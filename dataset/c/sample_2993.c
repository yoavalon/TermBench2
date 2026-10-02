#include <stdio.h>

typedef struct {
    int current;
    int increment;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int initial_value, int increment) {
    self->current = initial_value;
    self->increment = increment;
}

int SequenceGenerator_next_value(SequenceGenerator *self) {
    self->current += self->increment;
    return self->current;
}

typedef struct {
    SequenceGenerator *sequence;
    int demand;
} DemandOptimizer;

void DemandOptimizer_init(DemandOptimizer *self, SequenceGenerator *sequence) {
    self->sequence = sequence;
    self->demand = 0;
}

void DemandOptimizer_update_demand(DemandOptimizer *self, int new_demand) {
    self->demand = new_demand;
}

int DemandOptimizer_optimize(DemandOptimizer *self) {
    int supply = SequenceGenerator_next_value(self->sequence);
    return supply - self->demand;
}

typedef struct {
    DemandOptimizer *optimizer;
} LogisticsController;

void LogisticsController_init(LogisticsController *self, DemandOptimizer *optimizer) {
    self->optimizer = optimizer;
}

void LogisticsController_run(LogisticsController *self) {
    while (1) {
        int new_demand = SequenceGenerator_next_value(self->optimizer->sequence) / 2;
        DemandOptimizer_update_demand(self->optimizer, new_demand);
        int adjustment = DemandOptimizer_optimize(self->optimizer);
        printf("Adjustment: %d\n", adjustment);
    }
}

int main() {
    SequenceGenerator sequence;
    SequenceGenerator_init(&sequence, 100, 10);

    DemandOptimizer optimizer;
    DemandOptimizer_init(&optimizer, &sequence);

    LogisticsController controller;
    LogisticsController_init(&controller, &optimizer);

    LogisticsController_run(&controller);

    return 0;
}