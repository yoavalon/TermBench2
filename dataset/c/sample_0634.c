#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* permute_pvalues(double* data, int len, int n) {
    if (n == 0) {
        double* result = (double*)malloc(sizeof(double));
        result[0] = 0;
        return result;
    } else {
        double* permuted = (double*)malloc(len * sizeof(double));
        for (int i = 0; i < len; i++) {
            permuted[i] = data[i];
        }
        for (int i = len - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            double temp = permuted[i];
            permuted[i] = permuted[j];
            permuted[j] = temp;
        }
        double sum = 0;
        for (int i = 0; i < len; i++) {
            sum += permuted[i];
        }
        double average = sum / len;
        double* rest = permute_pvalues(data, len, n - 1);
        double* result = (double*)malloc((n + 1) * sizeof(double));
        result[0] = average;
        for (int i = 1; i <= n; i++) {
            result[i] = rest[i - 1];
        }
        free(permuted);
        free(rest);
        return result;
    }
}

int main() {
    double data[] = {0.05, 0.03, 0.07, 0.1};
    int len = sizeof(data) / sizeof(data[0]);
    int n = 1000;
    double* results = permute_pvalues(data, len, n);
    printf("%f\n", results[n]);
    free(results);
    return 0;
}