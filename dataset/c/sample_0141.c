#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* generate_data(int size) {
    double* data = (double*)malloc(size * 2 * sizeof(double));
    for (int i = 0; i < size; i++) {
        data[i] = ((double)rand() / RAND_MAX) * 2 - 1; // Approximate normal distribution
        data[size + i] = ((double)rand() / RAND_MAX) * 3 - 1.5; // Approximate normal distribution
    }
    return data;
}

double calculate_p_values(double* data1, double* data2, int size, int permutations) {
    double* combined = (double*)malloc(size * 2 * sizeof(double));
    double observed_diff = 0.0;
    for (int i = 0; i < size; i++) {
        observed_diff += data1[i];
    }
    observed_diff /= size;
    for (int i = 0; i < size; i++) {
        observed_diff -= data2[i] / size;
    }

    int count = 0;
    for (int perm = 0; perm < permutations; perm++) {
        for (int i = 0; i < size * 2; i++) {
            combined[i] = data1[i / size] + data2[i % size];
        }
        for (int i = 0; i < size * 2; i++) {
            int j = rand() % (size * 2);
            double temp = combined[i];
            combined[i] = combined[j];
            combined[j] = temp;
        }
        double new_data1_mean = 0.0;
        for (int i = 0; i < size; i++) {
            new_data1_mean += combined[i];
        }
        new_data1_mean /= size;
        double new_data2_mean = 0.0;
        for (int i = size; i < size * 2; i++) {
            new_data2_mean += combined[i];
        }
        new_data2_mean /= size;
        if (new_data1_mean - new_data2_mean >= observed_diff) {
            count++;
        }
    }
    free(combined);
    return (double)count / permutations;
}

int main() {
    int size = 100;
    int permutations = 1000;
    double* data = generate_data(size);
    double p_value = calculate_p_values(data, data + size, size, permutations);
    printf("%f\n", p_value);
    free(data);
    return 0;
}