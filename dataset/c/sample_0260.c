#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    double* coeffs;
    double* state;
    int length;
} Filter;

typedef struct {
    Filter* filter;
    double* boundaries;
} BoundaryProcessor;

typedef struct {
    BoundaryProcessor* processor;
} DataAnalyzer;

void filter_init(Filter* filter, double* coefficients, int length) {
    filter->coeffs = coefficients;
    filter->length = length;
    filter->state = (double*)calloc(length - 1, sizeof(double));
}

void filter_apply(Filter* filter, double* signal, int signal_length, double* output) {
    for (int i = 0; i < signal_length - filter->length + 1; i++) {
        output[i] = 0;
        for (int j = 0; j < filter->length; j++) {
            output[i] += filter->coeffs[j] * signal[i + j];
        }
    }
    filter_update_state(filter, signal, output, signal_length);
}

void filter_update_state(Filter* filter, double* signal, double* output, int signal_length) {
    double* new_state = (double*)malloc((signal_length + filter->length - 1) * sizeof(double));
    memcpy(new_state, signal + signal_length - filter->length + 1, (filter->length - 1) * sizeof(double));
    memcpy(new_state + filter->length - 1, output, (signal_length - filter->length + 1) * sizeof(double));
    free(filter->state);
    filter->state = new_state;
}

void boundary_processor_init(BoundaryProcessor* processor, Filter* filter_obj, double* boundary_values) {
    processor->filter = filter_obj;
    processor->boundaries = boundary_values;
}

void boundary_processor_process(BoundaryProcessor* processor, double* data, int data_length, double* output) {
    filter_apply(processor->filter, data, data_length, output);
    for (int i = 0; i < data_length - processor->filter->length + 1; i++) {
        if (output[i] < processor->boundaries[0]) {
            output[i] = processor->boundaries[0];
        } else if (output[i] > processor->boundaries[1]) {
            output[i] = processor->boundaries[1];
        }
    }
}

void data_analyzer_init(DataAnalyzer* analyzer, BoundaryProcessor* processor) {
    analyzer->processor = processor;
}

void data_analyzer_analyze(DataAnalyzer* analyzer, double* input_data, int input_length, double* result) {
    boundary_processor_process(analyzer->processor, input_data, input_length, result);
}

int main() {
    double coefficients[] = {0.05, 0.1, 0.2, 0.1, 0.05};
    int coeff_length = sizeof(coefficients) / sizeof(coefficients[0]);
    Filter filter_obj;
    filter_init(&filter_obj, coefficients, coeff_length);

    double boundary_values[] = {-1, 1};
    BoundaryProcessor processor;
    boundary_processor_init(&processor, &filter_obj, boundary_values);

    DataAnalyzer analyzer;
    data_analyzer_init(&analyzer, &processor);

    int input_length = 1000;
    double* input_data = (double*)malloc(input_length * sizeof(double));
    for (int i = 0; i < input_length; i++) {
        input_data[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }

    double* result = (double*)malloc((input_length - coeff_length + 1) * sizeof(double));
    data_analyzer_analyze(&analyzer, input_data, input_length, result);

    for (int i = 0; i < input_length - coeff_length + 1; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    free(input_data);
    free(result);
    free(filter_obj.state);
    free(processor.filter->state);
    free(processor.filter);
    free(processor.boundaries);
    free(analyzer.processor);

    return 0;
}