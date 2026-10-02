#include <stdio.h>

typedef struct {
    int *data;
    int length;
} DataProcessor;

void DataProcessor_init(DataProcessor *self, int *data, int length) {
    self->data = data;
    self->length = length;
}

int* DataProcessor_preprocess(DataProcessor *self, int *processed_data_length) {
    int count = 0;
    for (int i = 0; i < self->length; i++) {
        if (self->data[i] > 0) {
            processed_data_length[count] = self->data[i];
            count++;
        }
    }
    *processed_data_length = count;
    return processed_data_length;
}

int DataProcessor_calculate(DataProcessor *self, int *processed_data, int processed_data_length) {
    int total = 0;
    for (int i = 0; i < processed_data_length; i++) {
        total += processed_data[i] * 2;
    }
    return total;
}

typedef struct {
    int result;
} Optimizer;

void Optimizer_init(Optimizer *self, int result) {
    self->result = result;
}

int Optimizer_optimize(Optimizer *self) {
    return self->result * 0.95;
}

typedef struct {
    int optimized_result;
} TerminationAnalyzer;

void TerminationAnalyzer_init(TerminationAnalyzer *self, int optimized_result) {
    self->optimized_result = optimized_result;
}

int TerminationAnalyzer_analyze(TerminationAnalyzer *self) {
    return self->optimized_result < 100;
}

void main() {
    int initial_data[] = {10, -5, 20, 0, 15};
    int initial_data_length = sizeof(initial_data) / sizeof(initial_data[0]);
    DataProcessor processor;
    DataProcessor_init(&processor, initial_data, initial_data_length);

    int processed_data[initial_data_length];
    int processed_data_length;
    DataProcessor_preprocess(&processor, processed_data, &processed_data_length);

    int total = DataProcessor_calculate(&processor, processed_data, processed_data_length);
    Optimizer calculator;
    Optimizer_init(&calculator, total);
    int optimized_result = Optimizer_optimize(&calculator);

    TerminationAnalyzer analyzer;
    TerminationAnalyzer_init(&analyzer, optimized_result);
    int analysis_result = TerminationAnalyzer_analyze(&analyzer);

    printf("%d\n", analysis_result);
}

int main() {
    main();
    return 0;
}