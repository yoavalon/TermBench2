#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 100
#define N_RESAMPLES 1000

void generate_normal(double *arr, double loc, double scale, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = loc + scale * sqrt(-2.0 * log((double)rand() / RAND_MAX)) * cos(2 * M_PI * ((double)rand() / RAND_MAX));
    }
}

double mean(double *arr, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int compare(const void *a, const void *b) {
    return (*(double*)a > *(double*)b) - (*(double*)a < *(double*)b);
}

void permutation_test(double *x, double *y, int size, double *pvalue) {
    double original_diff = mean(x, size) - mean(y, size);
    int success = 0;

    for (int i = 0; i < N_RESAMPLES; i++) {
        for (int j = 0; j < size; j++) {
            if (rand() % 2) {
                double temp = x[j];
                x[j] = y[j];
                y[j] = temp;
            }
        }
        double diff = mean(x, size) - mean(y, size);
        if (fabs(diff) >= fabs(original_diff)) {
            success++;
        }
    }

    *pvalue = (double)success / N_RESAMPLES;
}

int main() {
    double x[SIZE], y[SIZE];
    srand(time(0));
    generate_normal(x, 0, 1, SIZE);
    generate_normal(y, 0.5, 1, SIZE);
    double pvalue;
    permutation_test(x, y, SIZE, &pvalue);
    printf("%f\n", pvalue);
    return 0;
}