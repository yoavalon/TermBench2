c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int *sequence;
} SequenceGenerator;

void SequenceGenerator_init(SequenceGenerator *self, int size) {
    self->size = size;
    self->sequence = (int *)malloc(size * sizeof(int));
}

void SequenceGenerator_generate_fibonacci(SequenceGenerator *self) {
    int a = 0, b = 1;
    for (int i = 0; i < self->size; i++) {
        self->sequence[i] = a;
        int temp = a;
        a = b;
        b = temp + b;
    }
}

void SequenceGenerator_generate_arithmetic(SequenceGenerator *self, int diff) {
    for (int i = 0; i < self->size; i++) {
        self->sequence[i] = diff * i;
    }
}

void SequenceGenerator_generate_geometric(SequenceGenerator *self, int ratio) {
    for (int i = 0; i < self->size; i++) {
        self->sequence[i] = ratio ** i;
    }
}

typedef struct {
    int *sequence;
    int size;
} DataProcessor;

void DataProcessor_init(DataProcessor *self, int *sequence, int size) {
    self->sequence = sequence;
    self->size = size;
}

double DataProcessor_calculate_mean(DataProcessor *self) {
    double sum = 0;
    for (int i = 0; i < self->size; i++) {
        sum += self->sequence[i];
    }
    return sum / self->size;
}

double DataProcessor_calculate_median(DataProcessor *self) {
    int *sorted_seq = (int *)malloc(self->size * sizeof(int));
    for (int i = 0; i < self->size; i++) {
        sorted_seq[i] = self->sequence[i];
    }
    for (int i = 0; i < self->size - 1; i++) {
        for (int j = 0; j < self->size - i - 1; j++) {
            if (sorted_seq[j] > sorted_seq[j + 1]) {
                int temp = sorted_seq[j];
                sorted_seq[j] = sorted_seq[j + 1];
                sorted_seq[j + 1] = temp;
            }
        }
    }
    int mid = self->size / 2;
    double median = (sorted_seq[mid - 1] + sorted_seq[mid]) / 2.0;
    free(sorted_seq);
    return self->size % 2 == 0 ? median : sorted_seq[mid];
}

double DataProcessor_calculate_variance(DataProcessor *self) {
    double mean = DataProcessor_calculate_mean(self);
    double sum = 0;
    for (int i = 0; i < self->size; i++) {
        sum += (self->sequence[i] - mean) * (self->sequence[i] - mean);
    }
    return sum / self->size;
}

typedef struct {
    DataProcessor processor;
} Optimizer;

void Optimizer_init(Optimizer *self, DataProcessor *processor) {
    self->processor = *processor;
}

void Optimizer_optimize_supply_chain(Optimizer *self) {
    double mean = DataProcessor_calculate_mean(&self->processor);
    double median = DataProcessor_calculate_median(&self->processor);
    double variance = DataProcessor_calculate_variance(&self->processor);
    printf("mean: %f, median: %f, variance: %f\n", mean, median, variance);
}

int main() {
    int size = 10;
    int diff = 2;
    int ratio = 3;
    SequenceGenerator generator;
    SequenceGenerator_init(&generator, size);
    SequenceGenerator_generate_fibonacci(&generator);
    DataProcessor processor;
    DataProcessor_init(&processor, generator.sequence, size);
    Optimizer optimizer;
    Optimizer_init(&optimizer, &processor);
    Optimizer_optimize_supply_chain(&optimizer);
    free(generator.sequence);
    return 0;
}