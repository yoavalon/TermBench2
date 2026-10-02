#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define REPS 10000

double np_mean(double *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

void np_random_permutation(double *data, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        double temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}

double p_value_permutation(double *data1, int n1, double *data2, int n2, double (*func)(double *, int), int reps) {
    double observed_diff = func(data1, n1) - func(data2, n2);
    int combined_size = n1 + n2;
    double *combined = (double *)malloc(combined_size * sizeof(double));
    for (int i = 0; i < n1; i++) {
        combined[i] = data1[i];
    }
    for (int i = 0; i < n2; i++) {
        combined[n1 + i] = data2[i];
    }
    int greater_equal_count = 0;
    for (int i = 0; i < reps; i++) {
        np_random_permutation(combined, combined_size);
        double perm_diff = func(combined, n1) - func(combined + n1, n2);
        if (fabs(perm_diff) >= fabs(observed_diff)) {
            greater_equal_count++;
        }
    }
    free(combined);
    return (double)greater_equal_count / reps;
}

void recursive_permutation(double *data1, int n1, double *data2, int n2, double (*func)(double *, int), int reps, int count) {
    double p_value = p_value_permutation(data1, n1, data2, n2, func, reps);
    printf("Iteration %d: P-value = %f\n", count, p_value);
    recursive_permutation(data1, n1, data2, n2, func, reps, count + 1);
}

int main() {
    double data1[100];
    double data2[100];
    for (int i = 0; i < 100; i++) {
        data1[i] = rand() / (double)RAND_MAX * 2 - 1;
        data2[i] = rand() / (double)RAND_MAX * 2 - 0.5;
    }
    recursive_permutation(data1, 100, data2, 100, np_mean, REPS, 0);
    return 0;
}