#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 50
#define ITERATIONS 1000

double generate_data(int size) {
    return ((double)rand() / RAND_MAX) * 2 - 1; // Random number between -1 and 1
}

double calculate_p_value(double *sample1, double *sample2, int size) {
    double mean1 = 0, mean2 = 0;
    for (int i = 0; i < size; i++) {
        mean1 += sample1[i];
        mean2 += sample2[i];
    }
    mean1 /= size;
    mean2 /= size;

    double var1 = 0, var2 = 0;
    for (int i = 0; i < size; i++) {
        var1 += pow(sample1[i] - mean1, 2);
        var2 += pow(sample2[i] - mean2, 2);
    }
    var1 /= size;
    var2 /= size;

    double pooled_var = ((size - 1) * var1 + (size - 1) * var2) / (2 * size - 2);
    double t_stat = (mean1 - mean2) / sqrt(pooled_var * (1.0 / size + 1.0 / size));

    // Using a simple approximation for p-value calculation
    double df = 2 * size - 2;
    double p_value = 1 - t_stat / sqrt(df);
    return p_value;
}

double permutation_test(double *sample1, double *sample2, int size, int iterations) {
    double original_p = calculate_p_value(sample1, sample2, size);
    int larger_count = 0;
    double permuted[2 * size];

    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < size; j++) {
            permuted[j] = sample1[j];
            permuted[size + j] = sample2[j];
        }
        for (int j = 0; j < 2 * size; j++) {
            int k = rand() % (2 * size);
            double temp = permuted[j];
            permuted[j] = permuted[k];
            permuted[k] = temp;
        }
        double new_p = calculate_p_value(permuted, permuted + size, size);
        if (new_p >= original_p) {
            larger_count++;
        }
    }
    return (double)larger_count / iterations;
}

int main() {
    double sample1[SIZE];
    double sample2[SIZE];
    for (int i = 0; i < SIZE; i++) {
        sample1[i] = generate_data(SIZE);
        sample2[i] = generate_data(SIZE);
    }
    double p_value = permutation_test(sample1, sample2, SIZE, ITERATIONS);
    printf("%f\n", p_value);
    return 0;
}