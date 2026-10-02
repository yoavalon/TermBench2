#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N_PERMUTATIONS 1000

double mean(double *data, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

double permutation_test(double *a, double *b, int size_a, int size_b, int n_permutations) {
    double original_mean_diff = mean(a, size_a) - mean(b, size_b);
    int larger_than_original = 0;

    for (int i = 0; i < n_permutations; i++) {
        for (int j = 0; j < size_a; j++) {
            swap(&a[j], &b[j % size_b]);
        }
        double permuted_mean_diff = mean(a, size_a) - mean(b, size_b);
        if (permuted_mean_diff >= original_mean_diff) {
            larger_than_original++;
        }
        for (int j = 0; j < size_a; j++) {
            swap(&a[j], &b[j % size_b]);
        }
    }

    return (double)larger_than_original / n_permutations;
}

int main() {
    int size = 100;
    double data1[size];
    double data2[size];

    for (int i = 0; i < size; i++) {
        data1[i] = rand() / (double)RAND_MAX * 2 - 1;
        data2[i] = rand() / (double)RAND_MAX * 2 - 0.5;
    }

    double p_value = permutation_test(data1, data2, size, size, N_PERMUTATIONS);
    printf("%f\n", p_value);

    return 0;
}