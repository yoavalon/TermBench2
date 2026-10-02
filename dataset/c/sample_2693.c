#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int current;
    int end;
    int step;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int start, int end, int step) {
    self->current = start;
    self->end = end;
    self->step = step;
}

int* SequenceGenerator_generate(SequenceGenerator *self, int *size) {
    int capacity = 10;
    int *sequence = (int*)malloc(capacity * sizeof(int));
    *size = 0;
    while (self->current <= self->end) {
        if (*size == capacity) {
            capacity *= 2;
            sequence = (int*)realloc(sequence, capacity * sizeof(int));
        }
        sequence[(*size)++] = self->current;
        self->current += self->step;
    }
    return sequence;
}

typedef struct {
    int demand;
    int supply;
} LogisticsOptimizer;

void LogisticsOptimizer_init(LogisticsOptimizer *self, int demand, int supply) {
    self->demand = demand;
    self->supply = supply;
}

int LogisticsOptimizer_calculate_deficit(LogisticsOptimizer *self) {
    return self->demand - self->supply > 0 ? self->demand - self->supply : 0;
}

int LogisticsOptimizer_optimize(LogisticsOptimizer *self) {
    int deficit = LogisticsOptimizer_calculate_deficit(self);
    if (deficit > 0) {
        return self->supply + deficit;
    }
    return self->supply;
}

int main() {
    SequenceGenerator demand_generator;
    SequenceGenerator_init(&demand_generator, 100, 200, 10);
    int demand_size;
    int *demand_sequence = SequenceGenerator_generate(&demand_generator, &demand_size);

    SequenceGenerator supply_generator;
    SequenceGenerator_init(&supply_generator, 120, 220, 15);
    int supply_size;
    int *supply_sequence = SequenceGenerator_generate(&supply_generator, &supply_size);

    int *optimized_supplies = (int*)malloc(demand_size * sizeof(int));
    for (int i = 0; i < demand_size; i++) {
        LogisticsOptimizer optimizer;
        LogisticsOptimizer_init(&optimizer, demand_sequence[i], supply_sequence[i]);
        optimized_supplies[i] = LogisticsOptimizer_optimize(&optimizer);
    }

    for (int i = 0; i < demand_size; i++) {
        printf("%d ", optimized_supplies[i]);
    }
    printf("\n");

    free(demand_sequence);
    free(supply_sequence);
    free(optimized_supplies);

    return 0;
}