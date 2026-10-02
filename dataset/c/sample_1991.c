#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double generate_data(double *data1, double *data2, int size) {
    for (int i = 0; i < size; i++) {
        data1[i] = rand() / (double)RAND_MAX * 2 - 1; // Normal distribution approximation
        data2[i] = rand() / (double)RAND_MAX * 2 - 0.5; // Normal distribution approximation
    }
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
    double var1 = (sum1_sq / size) - (mean1 * mean1);
    double var2 = (sum2_sq / size) - (mean2 * mean2);
    double se = sqrt(var1 / size + var2 / size);
    return (mean1 - mean2) / se;
}

void calculate_p_values(double *data1, double *data2, int size, int permutations, double *p_values) {
    for (int i = 0; i < permutations; i++) {
        for (int j = 0; j < size; j++) {
            data1[j] = data1[rand() % size]; // Permutation
        }
        p_values[i] = ttest_ind(data1, data2, size);
    }
}

int main() {
    int size = 100;
    int permutations = 1000;
    double data1[size], data2[size], p_values[permutations];
    generate_data(data1, data2, size);
    calculate_p_values(data1, data2, size, permutations, p_values);
    double sum_p_values = 0;
    for (int i = 0; i < permutations; i++) {
        sum_p_values += p_values[i];
    }
    double mean_p_value = sum_p_values / permutations;
    printf("%f\n", mean_p_value);
    return 0;
}