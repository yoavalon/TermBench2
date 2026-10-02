#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    double *data;
    int size;
    double *optimized_data;
} SupplyChainOptimizer;

typedef struct {
    double *data;
    int size;
} DataProcessor;

typedef struct {
    double *data;
    int size;
} DataAnalyzer;

void supply_chain_optimizer_init(SupplyChainOptimizer *optimizer, double *data, int size) {
    optimizer->data = data;
    optimizer->size = size;
    optimizer->optimized_data = (double *)malloc(size * sizeof(double));
}

void supply_chain_optimizer_process_data(SupplyChainOptimizer *optimizer) {
    for (int i = 0; i < optimizer->size; i++) {
        optimizer->optimized_data[i] = supply_chain_optimizer_mutate_item(optimizer->data[i]);
    }
}

double supply_chain_optimizer_mutate_item(double item) {
    double mutation_factor = 0.8 + ((double)rand() / RAND_MAX) * 0.4;
    return item * mutation_factor;
}

void supply_chain_optimizer_free(SupplyChainOptimizer *optimizer) {
    free(optimizer->optimized_data);
}

void data_processor_init(DataProcessor *processor, double *data, int size) {
    processor->data = data;
    processor->size = size;
}

double *data_processor_normalize_data(DataProcessor *processor) {
    double min_val = processor->data[0];
    double max_val = processor->data[0];
    for (int i = 1; i < processor->size; i++) {
        if (processor->data[i] < min_val) min_val = processor->data[i];
        if (processor->data[i] > max_val) max_val = processor->data[i];
    }
    double *normalized_data = (double *)malloc(processor->size * sizeof(double));
    for (int i = 0; i < processor->size; i++) {
        normalized_data[i] = (processor->data[i] - min_val) / (max_val - min_val);
    }
    return normalized_data;
}

void data_processor_free(DataProcessor *processor) {
    // No dynamic memory to free in this struct
}

void data_analyzer_init(DataAnalyzer *analyzer, double *data, int size) {
    analyzer->data = data;
    analyzer->size = size;
}

void data_analyzer_calculate_statistics(DataAnalyzer *analyzer, double *mean, double *variance) {
    double sum = 0.0;
    for (int i = 0; i < analyzer->size; i++) {
        sum += analyzer->data[i];
    }
    *mean = sum / analyzer->size;

    double sum_variance = 0.0;
    for (int i = 0; i < analyzer->size; i++) {
        sum_variance += pow(analyzer->data[i] - *mean, 2);
    }
    *variance = sum_variance / analyzer->size;
}

void data_analyzer_free(DataAnalyzer *analyzer) {
    // No dynamic memory to free in this struct
}

void main() {
    srand(time(NULL));
    int raw_data_size = 100;
    int *raw_data = (int *)malloc(raw_data_size * sizeof(int));
    for (int i = 0; i < raw_data_size; i++) {
        raw_data[i] = rand() % 91 + 10;
    }

    double *raw_data_double = (double *)malloc(raw_data_size * sizeof(double));
    for (int i = 0; i < raw_data_size; i++) {
        raw_data_double[i] = raw_data[i];
    }

    DataProcessor processor;
    data_processor_init(&processor, raw_data_double, raw_data_size);
    double *normalized_data = data_processor_normalize_data(&processor);

    SupplyChainOptimizer optimizer;
    supply_chain_optimizer_init(&optimizer, normalized_data, raw_data_size);
    supply_chain_optimizer_process_data(&optimizer);

    DataAnalyzer analyzer;
    data_analyzer_init(&analyzer, optimizer.optimized_data, raw_data_size);
    double mean, variance;
    data_analyzer_calculate_statistics(&analyzer, &mean, &variance);

    printf("Mean: %f, Variance: %f\n", mean, variance);

    data_analyzer_free(&analyzer);
    supply_chain_optimizer_free(&optimizer);
    data_processor_free(&processor);
    free(raw_data);
    free(raw_data_double);
    free(normalized_data);
}