#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double perm_test(double *data, int size, int n_permutations) {
    double orig_mean = 0.0;
    for (int i = 0; i < size; i++) {
        orig_mean += data[i];
    }
    orig_mean /= size;

    double *perm_means = (double *)malloc(n_permutations * sizeof(double));
    for (int i = 0; i < n_permutations; i++) {
        double *perm_data = (double *)malloc(size * sizeof(double));
        for (int j = 0; j < size; j++) {
            perm_data[j] = data[j];
        }
        for (int j = 0; j < size; j++) {
            int k = rand() % size;
            double temp = perm_data[j];
            perm_data[j] = perm_data[k];
            perm_data[k] = temp;
        }
        double perm_mean = 0.0;
        for (int j = 0; j < size; j++) {
            perm_mean += perm_data[j];
        }
        perm_mean /= size;
        perm_means[i] = perm_mean;
        free(perm_data);
    }

    int count = 0;
    for (int i = 0; i < n_permutations; i++) {
        if (perm_means[i] >= orig_mean) {
            count++;
        }
    }
    double p_value = (count + 1.0) / (n_permutations + 1.0);
    free(perm_means);
    return p_value;
}

int main() {
    srand(time(NULL));
    double data[100];
    for (int i = 0; i < 100; i++) {
        data[i] = rand() / (double)RAND_MAX * 2 - 1;
    }
    double result = perm_test(data, 100, 10000);
    printf("%f\n", result);
    return 0;
}