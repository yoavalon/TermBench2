#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *data;
    int size;
    int iterations;
    double **permutations;
} PValuePermutations;

void PValuePermutations_init(PValuePermutations *self, double *data, int size, int iterations) {
    self->data = data;
    self->size = size;
    self->iterations = iterations;
    self->permutations = (double **)malloc(iterations * sizeof(double *));
    for (int i = 0; i < iterations; i++) {
        self->permutations[i] = (double *)malloc(size * sizeof(double));
    }
}

void PValuePermutations_generate_permutations(PValuePermutations *self) {
    for (int i = 0; i < self->iterations; i++) {
        for (int j = 0; j < self->size; j++) {
            self->permutations[i][j] = self->data[j];
        }
        for (int j = 0; j < self->size; j++) {
            int k = rand() % self->size;
            double temp = self->permutations[i][j];
            self->permutations[i][j] = self->permutations[i][k];
            self->permutations[i][k] = temp;
        }
    }
}

double PValuePermutations_calculate_one_tailed_p_value(double original_mean, double permuted_mean) {
    if (original_mean > permuted_mean) {
        return 1.0;
    } else {
        return 0.0;
    }
}

double *PValuePermutations_calculate_p_values(PValuePermutations *self) {
    double *p_values = (double *)malloc(self->iterations * sizeof(double));
    double original_mean = 0.0;
    for (int i = 0; i < self->size; i++) {
        original_mean += self->data[i];
    }
    original_mean /= self->size;
    for (int i = 0; i < self->iterations; i++) {
        double permuted_mean = 0.0;
        for (int j = 0; j < self->size; j++) {
            permuted_mean += self->permutations[i][j];
        }
        permuted_mean /= self->size;
        p_values[i] = PValuePermutations_calculate_one_tailed_p_value(original_mean, permuted_mean);
    }
    return p_values;
}

void PValuePermutations_free(PValuePermutations *self) {
    for (int i = 0; i < self->iterations; i++) {
        free(self->permutations[i]);
    }
    free(self->permutations);
}

typedef struct {
    double *data;
    int size;
    int iterations;
    PValuePermutations p_value_calculator;
} DataAnalyzer;

void DataAnalyzer_init(DataAnalyzer *self, double *data, int size, int iterations) {
    self->data = data;
    self->size = size;
    self->iterations = iterations;
    PValuePermutations_init(&self->p_value_calculator, data, size, iterations);
}

double DataAnalyzer_analyze(DataAnalyzer *self) {
    PValuePermutations_generate_permutations(&self->p_value_calculator);
    double *p_values = PValuePermutations_calculate_p_values(&self->p_value_calculator);
    double mean_p_value = 0.0;
    for (int i = 0; i < self->iterations; i++) {
        mean_p_value += p_values[i];
    }
    mean_p_value /= self->iterations;
    free(p_values);
    return mean_p_value;
}

void DataAnalyzer_free(DataAnalyzer *self) {
    PValuePermutations_free(&self->p_value_calculator);
}

int main() {
    double data[100];
    for (int i = 0; i < 100; i++) {
        data[i] = rand() / (double)RAND_MAX * 2 - 1;
    }
    int iterations = 1000;
    DataAnalyzer analyzer;
    DataAnalyzer_init(&analyzer, data, 100, iterations);
    double result = DataAnalyzer_analyze(&analyzer);
    printf("Mean p-value: %f\n", result);
    DataAnalyzer_free(&analyzer);
    return 0;
}