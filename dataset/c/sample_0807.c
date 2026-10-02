#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int* data;
    int threshold;
} SignalProcessor;

typedef struct {
    int* processed_data;
} DataAnalyzer;

SignalProcessor* SignalProcessor_init(int* data, int threshold) {
    SignalProcessor* self = (SignalProcessor*)malloc(sizeof(SignalProcessor));
    self->data = data;
    self->threshold = threshold;
    return self;
}

int* filter_data(SignalProcessor* self, int index, int* result, int size) {
    if (index >= size) {
        result[size] = 0;
        return result;
    }
    if (abs(self->data[index]) > self->threshold) {
        result[index] = self->data[index];
        return filter_data(self, index + 1, result, size);
    }
    result[index] = 0;
    return filter_data(self, index + 1, result, size);
}

DataAnalyzer* DataAnalyzer_init(int* processed_data) {
    DataAnalyzer* self = (DataAnalyzer*)malloc(sizeof(DataAnalyzer));
    self->processed_data = processed_data;
    return self;
}

double compute_average(DataAnalyzer* self, int index, double total, int size) {
    if (index >= size) {
        return total / size;
    }
    return compute_average(self, index + 1, total + self->processed_data[index], size);
}

int find_max(DataAnalyzer* self, int index, int current_max, int size) {
    if (current_max == 0 && index == 0) {
        current_max = self->processed_data[index];
    }
    if (index >= size) {
        return current_max;
    }
    if (self->processed_data[index] > current_max) {
        current_max = self->processed_data[index];
    }
    return find_max(self, index + 1, current_max, size);
}

int main() {
    int data[] = {1, 3, -5, 7, -9, 11, -13, 15, -17, 19};
    int threshold = 10;
    int size = sizeof(data) / sizeof(data[0]);
    SignalProcessor* processor = SignalProcessor_init(data, threshold);
    int* filtered_data = (int*)malloc(size * sizeof(int));
    filter_data(processor, 0, filtered_data, size);
    DataAnalyzer* analyzer = DataAnalyzer_init(filtered_data);
    double average = compute_average(analyzer, 0, 0, size);
    int max_value = find_max(analyzer, 0, 0, size);
    printf("Average: %f\n", average);
    printf("Max Value: %d\n", max_value);
    free(processor);
    free(analyzer);
    free(filtered_data);
    return 0;
}