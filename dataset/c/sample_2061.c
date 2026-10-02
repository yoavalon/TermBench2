#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double a;
    double b;
    double c;
} Simulation;

double calculate(Simulation *self, double x) {
    return self->a * x * x + self->b * x + self->c;
}

typedef struct {
    Simulation *simulation;
} PrecisionAnalyzer;

double* analyze(PrecisionAnalyzer *self, double *x_values, int size) {
    double *results = (double *)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        results[i] = calculate(self->simulation, x_values[i]);
    }
    return results;
}

typedef struct {
    PrecisionAnalyzer *analyzer;
} DataProcessor;

double* format_data(double *data, int size) {
    double *formatted = (double *)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        formatted[i] = round(data[i] * 100000) / 100000;
    }
    return formatted;
}

double* process(DataProcessor *self, double *x_values, int size) {
    double *raw_data = analyze(self->analyzer, x_values, size);
    double *processed_data = format_data(raw_data, size);
    free(raw_data);
    return processed_data;
}

void main() {
    Simulation sim = {2.0, 3.0, 1.0};
    PrecisionAnalyzer analyzer = {&sim};
    DataProcessor processor = {&analyzer};
    double x_values[] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    int size = sizeof(x_values) / sizeof(x_values[0]);
    double *processed_results = process(&processor, x_values, size);
    for (int i = 0; i < size; i++) {
        printf("X: %.1f, Result: %.5f\n", x_values[i], processed_results[i]);
    }
    free(processed_results);
}