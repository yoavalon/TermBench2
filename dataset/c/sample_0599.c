#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

typedef struct {
    int size;
} DataGenerator;

typedef struct {
    double* data1;
    double* data2;
} PValueCalculator;

typedef struct {
    DataGenerator* data_generator;
} AnalysisRunner;

void DataGenerator_init(DataGenerator* self, int size) {
    self->size = size;
}

double* DataGenerator_generate_data(DataGenerator* self) {
    double* data = (double*)malloc(self->size * sizeof(double));
    for (int i = 0; i < self->size; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }
    return data;
}

void PValueCalculator_init(PValueCalculator* self, double* data1, double* data2) {
    self->data1 = data1;
    self->data2 = data2;
}

double PValueCalculator_mean_difference(PValueCalculator* self, double* data1, double* data2) {
    if (data1 == NULL) data1 = self->data1;
    if (data2 == NULL) data2 = self->data2;
    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < SIZE; i++) {
        sum1 += data1[i];
        sum2 += data2[i];
    }
    return fabs(sum1 / SIZE - sum2 / SIZE);
}

double PValueCalculator_calculate_p_value(PValueCalculator* self) {
    double* combined_data = (double*)malloc(2 * SIZE * sizeof(double));
    for (int i = 0; i < SIZE; i++) {
        combined_data[i] = self->data1[i];
        combined_data[SIZE + i] = self->data2[i];
    }
    double observed_diff = PValueCalculator_mean_difference(self, NULL, NULL);
    int larger_count = 0;
    for (int i = 0; i < 999; i++) {
        for (int j = 0; j < 2 * SIZE; j++) {
            int k = rand() % (2 * SIZE);
            double temp = combined_data[j];
            combined_data[j] = combined_data[k];
            combined_data[k] = temp;
        }
        double new_diff = PValueCalculator_mean_difference(self, combined_data, combined_data + SIZE);
        if (new_diff >= observed_diff) {
            larger_count++;
        }
    }
    free(combined_data);
    return (double)larger_count / 1000;
}

void AnalysisRunner_init(AnalysisRunner* self, DataGenerator* data_generator) {
    self->data_generator = data_generator;
}

void AnalysisRunner_run_analysis(AnalysisRunner* self) {
    while (1) {
        double* data1 = DataGenerator_generate_data(self->data_generator);
        double* data2 = DataGenerator_generate_data(self->data_generator);
        PValueCalculator calculator;
        PValueCalculator_init(&calculator, data1, data2);
        double p_value = PValueCalculator_calculate_p_value(&calculator);
        printf("P-Value: %f\n", p_value);
        free(data1);
        free(data2);
    }
}

int main() {
    srand(time(NULL));
    DataGenerator data_generator;
    DataGenerator_init(&data_generator, SIZE);
    AnalysisRunner analysis_runner;
    AnalysisRunner_init(&analysis_runner, &data_generator);
    AnalysisRunner_run_analysis(&analysis_runner);
    return 0;
}