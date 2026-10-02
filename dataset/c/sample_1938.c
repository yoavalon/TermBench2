c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double normal_distribution(double mu, double sigma) {
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return mu + sigma * z0;
}

void generate_data(double *sample1, double *sample2, int size) {
    srand(0);
    for (int i = 0; i < size; i++) {
        sample1[i] = normal_distribution(0, 1);
        sample2[i] = normal_distribution(0.5, 1);
    }
}

double mean(double *data, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

double permutation_test(double *sample1, double *sample2, int size, int n_permutations) {
    double pvalue = 0;
    double observed_diff = mean(sample1, size) - mean(sample2, size);
    double combined[size * 2];
    for (int i = 0; i < size; i++) {
        combined[i] = sample1[i];
        combined[i + size] = sample2[i];
    }
    for (int perm = 0; perm < n_permutations; perm++) {
        for (int i = 0; i < size * 2; i++) {
            int j = rand() % (size * 2);
            double temp = combined[i];
            combined[i] = combined[j];
            combined[j] = temp;
        }
        double perm_diff = mean(combined, size) - mean(combined + size, size);
        if (perm_diff >= observed_diff) {
            pvalue += 1;
        }
    }
    return pvalue / n_permutations;
}

void main() {
    int size = 100;
    double sample1[size], sample2[size];
    generate_data(sample1, sample2, size);
    double pvalue = permutation_test(sample1, sample2, size, 10000);
    printf("%f\n", pvalue);
}