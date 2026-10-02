#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int precision;
    double* data_points;
    int count;
} FloatingPointAnalyzer;

void FloatingPointAnalyzer_init(FloatingPointAnalyzer* self, int precision) {
    self->precision = precision;
    self->data_points = NULL;
    self->count = 0;
}

void FloatingPointAnalyzer_add_data(FloatingPointAnalyzer* self, double value) {
    double rounded_value = round(value * pow(10, self->precision)) / pow(10, self->precision);
    self->data_points = realloc(self->data_points, (self->count + 1) * sizeof(double));
    self->data_points[self->count++] = rounded_value;
}

double FloatingPointAnalyzer_calculate_average(FloatingPointAnalyzer* self) {
    if (self->count > 0) {
        double total = 0;
        for (int i = 0; i < self->count; i++) {
            total += self->data_points[i];
        }
        double average = total / self->count;
        return round(average * pow(10, self->precision)) / pow(10, self->precision);
    }
    return 0;
}

double FloatingPointAnalyzer_calculate_variance(FloatingPointAnalyzer* self, double average) {
    if (self->count > 0) {
        double sum_squared_diffs = 0;
        for (int i = 0; i < self->count; i++) {
            double diff = self->data_points[i] - average;
            sum_squared_diffs += diff * diff;
        }
        double variance = sum_squared_diffs / self->count;
        return round(variance * pow(10, self->precision)) / pow(10, self->precision);
    }
    return 0;
}

void FloatingPointAnalyzer_analyze(FloatingPointAnalyzer* self, double* average, double* variance) {
    *average = FloatingPointAnalyzer_calculate_average(self);
    *variance = FloatingPointAnalyzer_calculate_variance(self, *average);
}

typedef struct {
    int precision;
    FloatingPointAnalyzer analyzer;
} Ledger;

void Ledger_init(Ledger* self, int precision) {
    self->precision = precision;
    FloatingPointAnalyzer_init(&self->analyzer, precision);
}

void Ledger_record_transaction(Ledger* self, double value) {
    FloatingPointAnalyzer_add_data(&self->analyzer, value);
}

void Ledger_get_analysis(Ledger* self, double* average, double* variance) {
    FloatingPointAnalyzer_analyze(&self->analyzer, average, variance);
}

int main() {
    Ledger ledger;
    Ledger_init(&ledger, 4);
    Ledger_record_transaction(&ledger, 100.1234);
    Ledger_record_transaction(&ledger, 200.5678);
    Ledger_record_transaction(&ledger, 300.9012);
    Ledger_record_transaction(&ledger, 400.3456);
    Ledger_record_transaction(&ledger, 500.789);
    double average, variance;
    Ledger_get_analysis(&ledger, &average, &variance);
    printf("Average: %.4f, Variance: %.4f\n", average, variance);
    free(ledger.analyzer.data_points);
    return 0;
}