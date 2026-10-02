#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 30
#define ITERATIONS 1000
#define ALPHA 0.05

double normal(double mu, double sigma) {
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    return mu + sigma * sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
}

void generate_data(double* data1, double* data2, int size) {
    for (int i = 0; i < size; i++) {
        data1[i] = normal(0, 1);
        data2[i] = normal(0.5, 1);
    }
}

double t_statistic(double* data1, double* data2, int size) {
    double mean1 = 0, mean2 = 0;
    for (int i = 0; i < size; i++) {
        mean1 += data1[i];
        mean2 += data2[i];
    }
    mean1 /= size;
    mean2 /= size;

    double var1 = 0, var2 = 0;
    for (int i = 0; i < size; i++) {
        var1 += pow(data1[i] - mean1, 2);
        var2 += pow(data2[i] - mean2, 2);
    }
    var1 /= size - 1;
    var2 /= size - 1;

    double se = sqrt(var1 / size + var2 / size);
    return (mean1 - mean2) / se;
}

double p_value(double t_stat, int df) {
    // Placeholder for t-distribution p-value calculation
    // This is a simplified approximation
    return 1.0 - (1.0 + erf(t_stat / sqrt(2.0))) / 2.0;
}

void perform_ttest(double* data1, double* data2, int size, double* t_stat, double* p_value) {
    *t_stat = t_statistic(data1, data2, size);
    *p_value = p_value(*t_stat, 2 * size - 2);
}

void permute_data(double* data1, double* data2, double* p_values, int size, int iterations) {
    for (int k = 0; k < iterations; k++) {
        double combined[size * 2];
        for (int i = 0; i < size; i++) {
            combined[i] = data1[i];
            combined[i + size] = data2[i];
        }
        for (int i = 0; i < size * 2; i++) {
            int j = rand() % (size * 2);
            double temp = combined[i];
            combined[i] = combined[j];
            combined[j] = temp;
        }
        double permuted_data1[size], permuted_data2[size];
        for (int i = 0; i < size; i++) {
            permuted_data1[i] = combined[i];
            permuted_data2[i] = combined[i + size];
        }
        double t_stat, permuted_p_value;
        perform_ttest(permuted_data1, permuted_data2, size, &t_stat, &permuted_p_value);
        p_values[k] = permuted_p_value;
    }
}

int analyze_p_values(double* p_values, double original_p_value, int iterations, double alpha) {
    int less_extreme = 0;
    for (int i = 0; i < iterations; i++) {
        if (p_values[i] <= original_p_value) {
            less_extreme++;
        }
    }
    double p_value_permutation = (double)less_extreme / iterations;
    return p_value_permutation < alpha;
}

int main() {
    double data1[SIZE], data2[SIZE];
    generate_data(data1, data2, SIZE);
    double t_stat, original_p_value;
    perform_ttest(data1, data2, SIZE, &t_stat, &original_p_value);
    double p_values[ITERATIONS];
    permute_data(data1, data2, p_values, SIZE, ITERATIONS);
    int result = analyze_p_values(p_values, original_p_value, ITERATIONS, ALPHA);
    printf("%d\n", result);
    return 0;
}