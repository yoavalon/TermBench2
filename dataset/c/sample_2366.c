#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double *data;
    int size;
} DataProcessor;

typedef struct {
    DataProcessor *processor;
} Optimizer;

typedef struct {
    Optimizer *optimizer;
} Logistics;

void DataProcessor_init(DataProcessor *self, double *data, int size) {
    self->data = data;
    self->size = size;
}

void DataProcessor_normalize(DataProcessor *self) {
    double min_val = self->data[0];
    double max_val = self->data[0];
    for (int i = 1; i < self->size; i++) {
        if (self->data[i] < min_val) min_val = self->data[i];
        if (self->data[i] > max_val) max_val = self->data[i];
    }
    for (int i = 0; i < self->size; i++) {
        self->data[i] = (self->data[i] - min_val) / (max_val - min_val);
    }
}

void DataProcessor_analyze(DataProcessor *self, double *result) {
    for (int i = 0; i < self->size; i++) {
        double item = self->data[i];
        result[i] = item * item + 0.1 * item + 0.001;
    }
}

void Optimizer_init(Optimizer *self, DataProcessor *processor) {
    self->processor = processor;
}

void Optimizer_optimize(Optimizer *self, double *optimized_data) {
    double result[self->processor->size];
    DataProcessor_analyze(self->processor, result);
    for (int i = 0; i < self->processor->size; i++) {
        optimized_data[i] = result[i] * 1.01 - 0.005;
    }
}

void Logistics_init(Logistics *self, Optimizer *optimizer) {
    self->optimizer = optimizer;
}

void Logistics_execute(Logistics *self) {
    double optimized_data[self->optimizer->processor->size];
    while (1) {
        Optimizer_optimize(self->optimizer, optimized_data);
        for (int i = 0; i < self->optimizer->processor->size; i++) {
            printf("%f ", optimized_data[i]);
        }
        printf("\n");
    }
}

int main() {
    double initial_data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int size = sizeof(initial_data) / sizeof(initial_data[0]);
    DataProcessor processor;
    Optimizer optimizer;
    Logistics logistics;

    DataProcessor_init(&processor, initial_data, size);
    DataProcessor_normalize(&processor);
    Optimizer_init(&optimizer, &processor);
    Logistics_init(&logistics, &optimizer);
    Logistics_execute(&logistics);

    return 0;
}