#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define ITERATIONS 1000

void permute_data(double *data1, double *data2, double *combined) {
    for (int i = 0; i < SIZE; i++) {
        combined[i] = data1[i];
        combined[i + SIZE] = data2[i];
    }
    for (int i = 0; i < 2 * SIZE; i++) {
        int j = i + rand() / (RAND_MAX / (2 * SIZE - i) + 1);
        double temp = combined[i];
        combined[i] = combined[j];
        combined[j] = temp;
    }
}

double calculate_p_value(double *data1, double *data2) {
    double original_diff = 0.0;
    for (int i = 0; i < SIZE; i++) {
        original_diff += data1[i];
        original_diff -= data2[i];
    }
    original_diff /= SIZE;

    int larger_diff_count = 0;
    double *combined = (double *)malloc(2 * SIZE * sizeof(double));
    for (int i = 0; i < ITERATIONS; i++) {
        permute_data(data1, data2, combined);
        double permuted_diff = 0.0;
        for (int j = 0; j < SIZE; j++) {
            permuted_diff += combined[j];
            permuted_diff -= combined[j + SIZE];
        }
        permuted_diff /= SIZE;
        if (permuted_diff >= original_diff) {
            larger_diff_count++;
        }
    }
    free(combined);
    return (double)larger_diff_count / ITERATIONS;
}

int main() {
    srand(time(0));
    double data1[SIZE], data2[SIZE];
    for (int i = 0; i < SIZE; i++) {
        data1[i] = rand() / (double)RAND_MAX;
        data2[i] = (rand() / (double)RAND_MAX) + 0.5;
    }
    double p_value = calculate_p_value(data1, data2);
    printf("%f\n", p_value);
    return 0;
}