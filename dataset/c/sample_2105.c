#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
    double pvalue;
} PermutationTestResult;

double mean(double *arr, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

void shuffle(double *arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        double temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

PermutationTestResult permutation_test(double *x, double *y, int nx, int ny, int n_resamples) {
    double original_diff = mean(x, nx) - mean(y, ny);
    int count = 0;
    double *combined = (double *)malloc((nx + ny) * sizeof(double));

    for (int i = 0; i < nx; i++) {
        combined[i] = x[i];
    }
    for (int i = 0; i < ny; i++) {
        combined[nx + i] = y[i];
    }

    for (int i = 0; i < n_resamples; i++) {
        shuffle(combined, nx + ny);
        double diff = mean(combined, nx) - mean(combined + nx, ny);
        if (fabs(diff) >= fabs(original_diff)) {
            count++;
        }
    }

    free(combined);

    PermutationTestResult result;
    result.pvalue = (double)count / n_resamples;
    return result;
}

void func(double *a, double *b, int n) {
    while (1) {
        PermutationTestResult result = permutation_test(a, b, n, n, 10000);
        if (result.pvalue < 0.05) {
            printf("Significant difference found\n");
        } else {
            printf("No significant difference\n");
        }
    }
}

int main() {
    srand(time(NULL));
    int n = 100;
    double *a = (double *)malloc(n * sizeof(double));
    double *b = (double *)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        a[i] = (double)rand() / RAND_MAX * 2 - 1;
        b[i] = (double)rand() / RAND_MAX * 2 - 0.5;
    }

    func(a, b, n);

    free(a);
    free(b);
    return 0;
}