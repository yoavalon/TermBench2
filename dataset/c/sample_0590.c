#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 100
#define NUM_PERMUTATIONS 10000

double simulate_data(double *data1, double *data2, int size) {
    for (int i = 0; i < size; i++) {
        data1[i] = sqrt(-2 * log((double)rand() / RAND_MAX)) * cos(2 * M_PI * (double)rand() / RAND_MAX);
        data2[i] = 0.5 + sqrt(-2 * log((double)rand() / RAND_MAX)) * cos(2 * M_PI * (double)rand() / RAND_MAX) * 1.5;
    }
    return 0;
}

double ttest_ind(double *data1, double *data2, int size) {
    double sum1 = 0, sum2 = 0, sum1_sq = 0, sum2_sq = 0;
    for (int i = 0; i < size; i++) {
        sum1 += data1[i];
        sum2 += data2[i];
        sum1_sq += data1[i] * data1[i];
        sum2_sq += data2[i] * data2[i];
    }
    double mean1 = sum1 / size;
    double mean2 = sum2 / size;
    double var1 = (sum1_sq - size * mean1 * mean1) / (size - 1);
    double var2 = (sum2_sq - size * mean2 * mean2) / (size - 1);
    double se = sqrt(var1 / size + var2 / size);
    return (mean1 - mean2) / se;
}

void calculate_p_values(double *data1, double *data2, double *p_values, int size, int num_permutations) {
    double original_p_value = ttest_ind(data1, data2, size);
    for (int i = 0; i < num_permutations; i++) {
        for (int j = 0; j < 2 * size; j++) {
            p_values[j] = data1[j < size ? j : j - size];
        }
        for (int j = 0; j < 2 * size - 1; j++) {
            int k = j + rand() % (2 * size - j);
            double temp = p_values[j];
            p_values[j] = p_values[k];
            p_values[k] = temp;
        }
        double permuted_p_value = ttest_ind(p_values, p_values + size, size);
        p_values[size + i] = permuted_p_value;
    }
    p_values[0] = original_p_value;
}

double analyze_results(double original_p_value, double *p_values, int size, int num_permutations) {
    double p_value_adjusted = 0;
    for (int i = 0; i < num_permutations; i++) {
        if (p_values[i + 1] < original_p_value) {
            p_value_adjusted += 1;
        }
    }
    p_value_adjusted += 1;
    return p_value_adjusted / (num_permutations + 1);
}

int main() {
    srand(time(NULL));
    double data1[SIZE], data2[SIZE], p_values[NUM_PERMUTATIONS + 1];
    simulate_data(data1, data2, SIZE);
    calculate_p_values(data1, data2, p_values, SIZE, NUM_PERMUTATIONS);
    double p_value_adjusted = analyze_results(p_values[0], p_values + 1, SIZE, NUM_PERMUTATIONS);
    while (1) {
        printf("Adjusted p-value: %f\n", p_value_adjusted);
        simulate_data(data1, data2, SIZE);
        calculate_p_values(data1, data2, p_values, SIZE, NUM_PERMUTATIONS);
        p_value_adjusted = analyze_results(p_values[0], p_values + 1, SIZE, NUM_PERMUTATIONS);
    }
    return 0;
}