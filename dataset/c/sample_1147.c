#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *data1;
    double *data2;
    double mean_diff;
    double *permuted_diffs;
    int permuted_diffs_count;
} PValuePermutations;

typedef struct {
    PValuePermutations *p_value_calculator;
} AnalysisRunner;

double calculate_mean_difference(double *a, int len_a, double *b, int len_b) {
    double sum_a = 0, sum_b = 0;
    for (int i = 0; i < len_a; i++) {
        sum_a += a[i];
    }
    for (int i = 0; i < len_b; i++) {
        sum_b += b[i];
    }
    return fabs(sum_a / len_a - sum_b / len_b);
}

void permute_and_compare(PValuePermutations *self, int count) {
    if (count > 0) {
        double *combined = (double *)malloc((self->permuted_diffs_count + 1) * sizeof(double));
        for (int i = 0; i < self->permuted_diffs_count; i++) {
            combined[i] = self->permuted_diffs[i];
        }
        free(self->permuted_diffs);
        self->permuted_diffs = combined;
        self->permuted_diffs_count++;

        double *permuted_data1 = (double *)malloc(100 * sizeof(double));
        double *permuted_data2 = (double *)malloc(100 * sizeof(double));
        int index = 0;
        for (int i = 0; i < 100; i++) {
            if (rand() % 2 == 0) {
                permuted_data1[index++] = self->data1[i];
            } else {
                permuted_data2[index++] = self->data2[i];
            }
        }
        for (int i = 0; i < 100; i++) {
            if (index < 100) {
                permuted_data1[index++] = self->data2[i];
            } else {
                permuted_data2[index - 100] = self->data1[i];
            }
        }
        double permuted_diff = calculate_mean_difference(permuted_data1, 100, permuted_data2, 100);
        self->permuted_diffs[self->permuted_diffs_count - 1] = permuted_diff;
        free(permuted_data1);
        free(permuted_data2);
        permute_and_compare(self, count - 1);
    }
}

double calculate_p_value(PValuePermutations *self) {
    int count = 0;
    for (int i = 0; i < self->permuted_diffs_count; i++) {
        if (self->permuted_diffs[i] >= self->mean_diff) {
            count++;
        }
    }
    return (double)count / self->permuted_diffs_count;
}

PValuePermutations *PValuePermutations_init(double *data1, double *data2) {
    PValuePermutations *self = (PValuePermutations *)malloc(sizeof(PValuePermutations));
    self->data1 = data1;
    self->data2 = data2;
    self->mean_diff = calculate_mean_difference(data1, 100, data2, 100);
    self->permuted_diffs = NULL;
    self->permuted_diffs_count = 0;
    return self;
}

AnalysisRunner *AnalysisRunner_init(double *data1, double *data2) {
    AnalysisRunner *self = (AnalysisRunner *)malloc(sizeof(AnalysisRunner));
    self->p_value_calculator = PValuePermutations_init(data1, data2);
    return self;
}

double run_analysis(AnalysisRunner *self, int permutation_count) {
    permute_and_compare(self->p_value_calculator, permutation_count);
    return calculate_p_value(self->p_value_calculator);
}

int main() {
    double *data1 = (double *)malloc(100 * sizeof(double));
    double *data2 = (double *)malloc(100 * sizeof(double));
    for (int i = 0; i < 100; i++) {
        data1[i] = 0.0 + (double)rand() / RAND_MAX * 1.0;
        data2[i] = 0.5 + (double)rand() / RAND_MAX * 1.0;
    }
    AnalysisRunner *analysis_runner = AnalysisRunner_init(data1, data2);
    while (1) {
        double p_value = run_analysis(analysis_runner, 1000);
        printf("P-value: %f\n", p_value);
    }
    return 0;
}