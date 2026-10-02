#include <stdio.h>
#include <limits.h>

typedef struct {
    int a;
    int b;
} SequenceGenerator;

typedef struct {
    int *sequence;
    int size;
} Optimizer;

typedef struct {
    SequenceGenerator *generator;
    Optimizer *optimizer;
} LogisticsSystem;

void SequenceGenerator_init(SequenceGenerator *self, int a, int b) {
    self->a = a;
    self->b = b;
}

void SequenceGenerator_generate(SequenceGenerator *self, int n, int *sequence) {
    for (int i = 0; i < n; i++) {
        sequence[i] = self->a + i * self->b;
    }
}

void Optimizer_init(Optimizer *self, int *sequence, int size) {
    self->sequence = sequence;
    self->size = size;
}

int Optimizer_find_min_cost(Optimizer *self) {
    int min_cost = INT_MAX;
    for (int i = 0; i < self->size; i++) {
        int cost = Optimizer_calculate_cost(self->sequence[i]);
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    return min_cost;
}

int Optimizer_calculate_cost(int value) {
    return value * 2 + 5;
}

void LogisticsSystem_init(LogisticsSystem *self, SequenceGenerator *generator, Optimizer *optimizer) {
    self->generator = generator;
    self->optimizer = optimizer;
}

void LogisticsSystem_run(LogisticsSystem *self, int *sequence, int *min_cost) {
    SequenceGenerator_generate(self->generator, 10, sequence);
    Optimizer_init(self->optimizer, sequence, 10);
    *min_cost = Optimizer_find_min_cost(self->optimizer);
}

int main() {
    SequenceGenerator generator;
    Optimizer optimizer;
    LogisticsSystem logistics;
    int sequence[10];
    int min_cost;

    SequenceGenerator_init(&generator, 1, 3);
    LogisticsSystem_init(&logistics, &generator, &optimizer);
    LogisticsSystem_run(&logistics, sequence, &min_cost);

    printf("Sequence: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\nMinimum Cost: %d\n", min_cost);

    return 0;
}