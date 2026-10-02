#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double* data;
    int length;
} DataProcessor;

typedef struct {
    double* processed_data;
    int length;
} SupplyChainOptimizer;

typedef struct {
    double* optimized_data;
    int length;
} ResultCompiler;

DataProcessor* DataProcessor_init(double* data, int length) {
    DataProcessor* self = malloc(sizeof(DataProcessor));
    self->data = data;
    self->length = length;
    return self;
}

double* DataProcessor_process_data(DataProcessor* self) {
    double* processed = malloc(self->length * sizeof(double));
    for (int i = 0; i < self->length; i++) {
        processed[i] = DataProcessor_adjust_precision(self, self->data[i]);
    }
    return processed;
}

double DataProcessor_adjust_precision(DataProcessor* self, double value) {
    return round(value * 100000) / 100000;
}

SupplyChainOptimizer* SupplyChainOptimizer_init(double* processed_data, int length) {
    SupplyChainOptimizer* self = malloc(sizeof(SupplyChainOptimizer));
    self->processed_data = processed_data;
    self->length = length;
    return self;
}

double* SupplyChainOptimizer_optimize(SupplyChainOptimizer* self) {
    double* optimized_data = malloc(self->length * sizeof(double));
    for (int i = 0; i < self->length; i++) {
        optimized_data[i] = SupplyChainOptimizer_calculate_cost(self, self->processed_data[i]);
    }
    return optimized_data;
}

double SupplyChainOptimizer_calculate_cost(SupplyChainOptimizer* self, double item) {
    return item * 1.05;
}

ResultCompiler* ResultCompiler_init(double* optimized_data, int length) {
    ResultCompiler* self = malloc(sizeof(ResultCompiler));
    self->optimized_data = optimized_data;
    self->length = length;
    return self;
}

double* ResultCompiler_compile_results(ResultCompiler* self) {
    double* result = malloc(self->length * sizeof(double));
    for (int i = 0; i < self->length; i++) {
        result[i] = self->optimized_data[i];
    }
    return result;
}

void main() {
    double raw_data[] = {100.123456, 200.654321, 300.987654, 400.135792, 500.24681};
    int length = sizeof(raw_data) / sizeof(raw_data[0]);
    DataProcessor* processor = DataProcessor_init(raw_data, length);
    double* processed_data = DataProcessor_process_data(processor);
    SupplyChainOptimizer* optimizer = SupplyChainOptimizer_init(processed_data, length);
    double* optimized_data = SupplyChainOptimizer_optimize(optimizer);
    ResultCompiler* compiler = ResultCompiler_init(optimized_data, length);
    double* results = ResultCompiler_compile_results(compiler);
    for (int i = 0; i < length; i++) {
        printf("%d: %f\n", i, results[i]);
    }
    free(processor);
    free(processed_data);
    free(optimizer);
    free(optimized_data);
    free(compiler);
    free(results);
}