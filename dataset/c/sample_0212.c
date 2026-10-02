#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LENGTH 1000

double* apply_filter(double* data, double* filter_coefficients, int length) {
    double* filtered_data = (double*)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        filtered_data[i] = 0.0;
        for (int j = 0; j < 5; j++) {
            int index = i - j + 2;
            if (index >= 0 && index < length) {
                filtered_data[i] += data[index] * filter_coefficients[j];
            }
        }
    }
    return filtered_data;
}

typedef struct {
    double* data;
    int length;
} SignalProcessor;

void SignalProcessor_init(SignalProcessor* sp, double* data) {
    sp->data = data;
    sp->length = LENGTH;
}

double* SignalProcessor_apply_filter(SignalProcessor* sp, double* filter_coefficients) {
    return apply_filter(sp->data, filter_coefficients, sp->length);
}

typedef struct {
    SignalProcessor* signal_processor;
} BoundaryHandler;

void BoundaryHandler_init(BoundaryHandler* bh, SignalProcessor* signal_processor) {
    bh->signal_processor = signal_processor;
}

double* BoundaryHandler_process_data(BoundaryHandler* bh) {
    double filter_coefficients[] = {0.1, 0.2, 0.3, 0.2, 0.1};
    return SignalProcessor_apply_filter(bh->signal_processor, filter_coefficients);
}

typedef struct {
    BoundaryHandler* boundary_handler;
} DataAnalyzer;

void DataAnalyzer_init(DataAnalyzer* da, BoundaryHandler* boundary_handler) {
    da->boundary_handler = boundary_handler;
}

double* DataAnalyzer_analyze(DataAnalyzer* da) {
    double* data = BoundaryHandler_process_data(da->boundary_handler);
    double sum = 0.0;
    double max_value = -INFINITY;
    double min_value = INFINITY;
    for (int i = 0; i < LENGTH; i++) {
        sum += data[i];
        if (data[i] > max_value) max_value = data[i];
        if (data[i] < min_value) min_value = data[i];
    }
    double mean_value = sum / LENGTH;
    double* result = (double*)malloc(3 * sizeof(double));
    result[0] = mean_value;
    result[1] = max_value;
    result[2] = min_value;
    free(data);
    return result;
}

int main() {
    double* data = (double*)malloc(LENGTH * sizeof(double));
    for (int i = 0; i < LENGTH; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }
    SignalProcessor signal_processor;
    SignalProcessor_init(&signal_processor, data);
    BoundaryHandler boundary_handler;
    BoundaryHandler_init(&boundary_handler, &signal_processor);
    DataAnalyzer data_analyzer;
    DataAnalyzer_init(&data_analyzer, &boundary_handler);
    double* result = DataAnalyzer_analyze(&data_analyzer);
    printf("Mean: %f Max: %f Min: %f\n", result[0], result[1], result[2]);
    free(result);
    free(data);
    return 0;
}