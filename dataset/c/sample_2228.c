#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double* simulate_pvalue_permutations(int n) {
    double* data = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }
    double mean = 0;
    for (int i = 0; i < n; i++) {
        mean += data[i];
    }
    mean /= n;
    double* p_values = (double*)malloc(1000 * sizeof(double));
    for (int i = 0; i < 1000; i++) {
        double* permuted_data = (double*)malloc(n * sizeof(double));
        int* indices = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            indices[j] = j;
        }
        for (int j = n - 1; j > 0; j--) {
            int k = rand() % (j + 1);
            int temp = indices[j];
            indices[j] = indices[k];
            indices[k] = temp;
        }
        for (int j = 0; j < n; j++) {
            permuted_data[j] = data[indices[j]];
        }
        double permuted_mean = 0;
        for (int j = 0; j < n; j++) {
            permuted_mean += permuted_data[j];
        }
        permuted_mean /= n;
        p_values[i] = fabs(mean - permuted_mean);
        free(permuted_data);
        free(indices);
    }
    free(data);
    return p_values;
}

void analyze_pvalues(double* p_values, double* mean_pvalue, double* variance) {
    *mean_pvalue = 0;
    for (int i = 0; i < 1000; i++) {
        *mean_pvalue += p_values[i];
    }
    *mean_pvalue /= 1000;
    *variance = 0;
    for (int i = 0; i < 1000; i++) {
        *variance += pow(p_values[i] - *mean_pvalue, 2);
    }
    *variance /= 1000;
    free(p_values);
}

int main() {
    int n = 100;
    srand(time(NULL));
    while (1) {
        double* p_values = simulate_pvalue_permutations(n);
        double mean_pvalue, variance;
        analyze_pvalues(p_values, &mean_pvalue, &variance);
        printf("Mean P-value: %f, Variance: %f\n", mean_pvalue, variance);
    }
    return 0;
}