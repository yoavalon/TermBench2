#include <stdio.h>
#include <math.h>

typedef struct {
    double *data;
    int size;
} DataProcessor;

void DataProcessor_init(DataProcessor *self, double *data, int size) {
    self->data = data;
    self->size = size;
}

void DataProcessor_normalize(DataProcessor *self) {
    double total = 0.0;
    for (int i = 0; i < self->size; i++) {
        total += self->data[i];
    }
    if (total != 0.0) {
        for (int i = 0; i < self->size; i++) {
            self->data[i] /= total;
        }
    }
}

void DataProcessor_apply_exponential_growth(DataProcessor *self, double rate) {
    for (int i = 0; i < self->size; i++) {
        self->data[i] *= exp(rate);
    }
}

typedef struct {
    DataProcessor *processor;
} LogisticsOptimizer;

void LogisticsOptimizer_init(LogisticsOptimizer *self, DataProcessor *processor) {
    self->processor = processor;
}

void LogisticsOptimizer_optimize_supply_chain(LogisticsOptimizer *self) {
    DataProcessor_normalize(self->processor);
    DataProcessor_apply_exponential_growth(self->processor, 0.01);
    LogisticsOptimizer_adjust_quantities(self);
}

void LogisticsOptimizer_adjust_quantities(LogisticsOptimizer *self) {
    double max_value = 0.0;
    for (int i = 0; i < self->processor->size; i++) {
        if (self->processor->data[i] > max_value) {
            max_value = self->processor->data[i];
        }
    }
    double threshold = 0.5 * max_value;
    for (int i = 0; i < self->processor->size; i++) {
        if (self->processor->data[i] <= threshold) {
            self->processor->data[i] = 0.0;
        }
    }
}

typedef struct {
    LogisticsOptimizer *optimizer;
} AnalysisRunner;

void AnalysisRunner_init(AnalysisRunner *self, LogisticsOptimizer *optimizer) {
    self->optimizer = optimizer;
}

void AnalysisRunner_run_analysis(AnalysisRunner *self) {
    while (1) {
        LogisticsOptimizer_optimize_supply_chain(self->optimizer);
    }
}

int main() {
    double initial_data[] = {100.0, 200.0, 300.0, 400.0, 500.0};
    int size = sizeof(initial_data) / sizeof(initial_data[0]);
    DataProcessor processor;
    LogisticsOptimizer optimizer;
    AnalysisRunner runner;

    DataProcessor_init(&processor, initial_data, size);
    LogisticsOptimizer_init(&optimizer, &processor);
    AnalysisRunner_init(&runner, &optimizer);
    AnalysisRunner_run_analysis(&runner);

    return 0;
}