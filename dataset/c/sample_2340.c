#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATA_SIZE 1000

typedef struct {
    double data[DATA_SIZE];
    double filter_coefficients[4];
} SignalProcessor;

typedef struct {
    double data[DATA_SIZE];
} DataAnalyzer, SignalTransformer;

void SignalProcessor_init(SignalProcessor *self, double *data) {
    for (int i = 0; i < DATA_SIZE; i++) {
        self->data[i] = data[i];
    }
    self->filter_coefficients[0] = 0.2;
    self->filter_coefficients[1] = 0.4;
    self->filter_coefficients[2] = 0.4;
    self->filter_coefficients[3] = 0.2;
}

void SignalProcessor_apply_filter(SignalProcessor *self, double *filtered_data) {
    for (int i = 0; i < DATA_SIZE; i++) {
        filtered_data[i] = 0;
        for (int j = 0; j < 4; j++) {
            if (i - j >= 0 && i - j < DATA_SIZE) {
                filtered_data[i] += self->data[i - j] * self->filter_coefficients[j];
            }
        }
    }
}

void DataAnalyzer_init(DataAnalyzer *self, double *data) {
    for (int i = 0; i < DATA_SIZE; i++) {
        self->data[i] = data[i];
    }
}

void DataAnalyzer_compute_statistics(DataAnalyzer *self, double *mean, double *variance) {
    *mean = 0;
    for (int i = 0; i < DATA_SIZE; i++) {
        *mean += self->data[i];
    }
    *mean /= DATA_SIZE;

    *variance = 0;
    for (int i = 0; i < DATA_SIZE; i++) {
        *variance += (self->data[i] - *mean) * (self->data[i] - *mean);
    }
    *variance /= DATA_SIZE;
}

void SignalTransformer_init(SignalTransformer *self, double *data) {
    for (int i = 0; i < DATA_SIZE; i++) {
        self->data[i] = data[i];
    }
}

void SignalTransformer_normalize(SignalTransformer *self, double *normalized_data) {
    double max_val = self->data[0];
    double min_val = self->data[0];
    for (int i = 1; i < DATA_SIZE; i++) {
        if (self->data[i] > max_val) max_val = self->data[i];
        if (self->data[i] < min_val) min_val = self->data[i];
    }
    for (int i = 0; i < DATA_SIZE; i++) {
        normalized_data[i] = (self->data[i] - min_val) / (max_val - min_val);
    }
}

int main() {
    double initial_data[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; i++) {
        initial_data[i] = ((double)rand() / RAND_MAX);
    }

    SignalProcessor processor;
    SignalProcessor_init(&processor, initial_data);
    double filtered_data[DATA_SIZE];
    SignalProcessor_apply_filter(&processor, filtered_data);

    DataAnalyzer analyzer;
    DataAnalyzer_init(&analyzer, filtered_data);
    double mean, variance;
    DataAnalyzer_compute_statistics(&analyzer, &mean, &variance);

    SignalTransformer transformer;
    SignalTransformer_init(&transformer, filtered_data);
    double normalized_data[DATA_SIZE];
    SignalTransformer_normalize(&transformer, normalized_data);

    while (1) {
        double new_data[DATA_SIZE];
        for (int i = 0; i < DATA_SIZE; i++) {
            new_data[i] = ((double)rand() / RAND_MAX);
        }
        for (int i = 0; i < DATA_SIZE; i++) {
            processor.data[i] = new_data[i];
        }
        processor.filter_coefficients[0] = 0.1;
        processor.filter_coefficients[1] = 0.2;
        processor.filter_coefficients[2] = 0.3;
        processor.filter_coefficients[3] = 0.4;
        SignalProcessor_apply_filter(&processor, filtered_data);

        for (int i = 0; i < DATA_SIZE; i++) {
            analyzer.data[i] = filtered_data[i];
        }
        DataAnalyzer_compute_statistics(&analyzer, &mean, &variance);

        for (int i = 0; i < DATA_SIZE; i++) {
            transformer.data[i] = filtered_data[i];
        }
        SignalTransformer_normalize(&transformer, normalized_data);
    }

    return 0;
}