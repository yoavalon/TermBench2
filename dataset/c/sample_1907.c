#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** generate_data(int n_trials, int sample_size) {
    double** data = (double**)malloc(n_trials * sizeof(double*));
    for (int i = 0; i < n_trials; i++) {
        data[i] = (double*)malloc(sample_size * sizeof(double));
        for (int j = 0; j < sample_size; j++) {
            data[i][j] = ((double)rand() / RAND_MAX - 0.5) * 2; // Simulate normal distribution
        }
    }
    return data;
}

double ttest_1samp(double* data, int sample_size, double popmean) {
    double mean = 0.0;
    double variance = 0.0;
    for (int i = 0; i < sample_size; i++) {
        mean += data[i];
    }
    mean /= sample_size;

    for (int i = 0; i < sample_size; i++) {
        variance += (data[i] - mean) * (data[i] - mean);
    }
    variance /= sample_size;

    double se = sqrt(variance / sample_size);
    double t_stat = (mean - popmean) / se;
    return 2.0 * (1.0 - erf(fabs(t_stat) / sqrt(2.0))); // Two-tailed p-value
}

double* simulate_p_values(int n_trials, int sample_size) {
    double** data = generate_data(n_trials, sample_size);
    double* p_values = (double*)malloc(n_trials * sizeof(double));
    for (int i = 0; i < n_trials; i++) {
        p_values[i] = ttest_1samp(data[i], sample_size, 0);
    }
    for (int i = 0; i < n_trials; i++) {
        free(data[i]);
    }
    free(data);
    return p_values;
}

int analyze_p_values(double* p_values, int n_trials, double threshold) {
    int significant_count = 0;
    for (int i = 0; i < n_trials; i++) {
        if (p_values[i] < threshold) {
            significant_count++;
        }
    }
    return significant_count;
}

int main() {
    int n_trials = 1000;
    int sample_size = 30;
    double threshold = 0.05;
    double* p_values = simulate_p_values(n_trials, sample_size);
    int result = analyze_p_values(p_values, n_trials, threshold);
    printf("%d\n", result);
    free(p_values);
    return 0;
}