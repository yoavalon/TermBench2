#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double* data;
    int length;
} SignalProcessor;

typedef struct {
    double* data;
    int length;
} DataTransformer;

SignalProcessor* SignalProcessor_init(double* data, int length) {
    SignalProcessor* self = malloc(sizeof(SignalProcessor));
    self->data = data;
    self->length = length;
    return self;
}

double* SignalProcessor_filter(SignalProcessor* self, double threshold, int index, int* result_length) {
    if (index >= self->length) {
        *result_length = 0;
        return NULL;
    }
    double* filtered = malloc(self->length * sizeof(double));
    int filtered_length = 0;
    if (fabs(self->data[index]) > threshold) {
        filtered[filtered_length++] = self->data[index];
        double* rest = SignalProcessor_filter(self, threshold, index + 1, &filtered_length);
        for (int i = 0; i < filtered_length - 1; i++) {
            filtered[i] = rest[i];
        }
        free(rest);
    } else {
        double* rest = SignalProcessor_filter(self, threshold, index + 1, &filtered_length);
        for (int i = 0; i < filtered_length; i++) {
            filtered[i] = rest[i];
        }
        free(rest);
    }
    *result_length = filtered_length;
    return filtered;
}

DataTransformer* DataTransformer_init(double* data, int length) {
    DataTransformer* self = malloc(sizeof(DataTransformer));
    self->data = data;
    self->length = length;
    return self;
}

double* DataTransformer_transform(DataTransformer* self, int index, int* result_length) {
    if (index >= self->length) {
        *result_length = 0;
        return NULL;
    }
    double* transformed = malloc(self->length * sizeof(double));
    int transformed_length = 0;
    transformed[transformed_length++] = self->data[index] * 2;
    double* rest = DataTransformer_transform(self, index + 1, &transformed_length);
    for (int i = 0; i < transformed_length - 1; i++) {
        transformed[i] = rest[i];
    }
    free(rest);
    *result_length = transformed_length;
    return transformed;
}

double* analyze_signal(double* data, int length, double threshold, int* result_length) {
    SignalProcessor* processor = SignalProcessor_init(data, length);
    int filtered_length;
    double* filtered_data = SignalProcessor_filter(processor, threshold, 0, &filtered_length);
    DataTransformer* transformer = DataTransformer_init(filtered_data, filtered_length);
    int transformed_length;
    double* transformed_data = DataTransformer_transform(transformer, 0, &transformed_length);
    free(processor);
    free(transformer);
    free(filtered_data);
    *result_length = transformed_length;
    return transformed_data;
}

int main() {
    double data[] = {0.1, -0.5, 0.8, -1.2, 0.3, -0.9, 1.1, -0.4};
    int length = sizeof(data) / sizeof(data[0]);
    double threshold = 0.5;
    int result_length;
    double* result = analyze_signal(data, length, threshold, &result_length);
    for (int i = 0; i < result_length; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}