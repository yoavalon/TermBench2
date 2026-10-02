#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 50
#define ITERATIONS 1000

double ttest_ind(double *data1, double *data2, int n1, int n2) {
    double sum1 = 0, sum2 = 0, sum1_sq = 0, sum2_sq = 0;
    for (int i = 0; i < n1; i++) {
        sum1 += data1[i];
        sum1_sq += data1[i] * data1[i];
    }
    for (int i = 0; i < n2; i++) {
        sum2 += data2[i];
        sum2_sq += data2[i] * data2[i];
    }
    double mean1 = sum1 / n1, mean2 = sum2 / n2;
    double var1 = (sum1_sq / n1) - (mean1 * mean1);
    double var2 = (sum2_sq / n2) - (mean2 * mean2);
    double pooled_var = ((n1 - 1) * var1 + (n2 - 1) * var2) / (n1 + n2 - 2);
    double t_stat = (mean1 - mean2) / sqrt(pooled_var * (1.0 / n1 + 1.0 / n2));
    return t_stat;
}

void permute_and_test(double *data1, double *data2, int n1, int n2, double *results, int iterations) {
    for (int i = 0; i < iterations; i++) {
        double combined[SIZE * 2];
        for (int j = 0; j < n1; j++) {
            combined[j] = data1[j];
        }
        for (int j = 0; j < n2; j++) {
            combined[n1 + j] = data2[j];
        }
        for (int j = 0; j < SIZE * 2 - 1; j++) {
            int k = j + rand() % (SIZE * 2 - j);
            double temp = combined[j];
            combined[j] = combined[k];
            combined[k] = temp;
        }
        double permuted_data1[SIZE], permuted_data2[SIZE];
        for (int j = 0; j < n1; j++) {
            permuted_data1[j] = combined[j];
        }
        for (int j = 0; j < n2; j++) {
            permuted_data2[j] = combined[n1 + j];
        }
        results[i] = ttest_ind(permuted_data1, permuted_data2, n1, n2);
    }
}

void non_terminating_permutation_test(double *data1, double *data2, int n1, int n2) {
    while (1) {
        double results[ITERATIONS];
        permute_and_test(data1, data2, n1, n2, results, ITERATIONS);
        for (int i = 0; i < ITERATIONS; i++) {
            printf("%f ", results[i]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    double data1[SIZE], data2[SIZE];
    for (int i = 0; i < SIZE; i++) {
        data1[i] = ((double)rand() / RAND_MAX) * 2 - 1;
        data2[i] = ((double)rand() / RAND_MAX) * 2 + 0.5 - 1;
    }
    non_terminating_permutation_test(data1, data2, SIZE, SIZE);
    return 0;
}