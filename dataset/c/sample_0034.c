#include <stdio.h>
#include <stdlib.h>

double* process_signal(double* data, int n, int window_size, int* result_size) {
    *result_size = n - window_size + 1;
    double* processed = (double*)malloc(*result_size * sizeof(double));
    for (int i = 0; i < *result_size; i++) {
        double sum = 0.0;
        for (int j = 0; j < window_size; j++) {
            sum += data[i + j];
        }
        processed[i] = sum / window_size;
    }
    return processed;
}

int main() {
    int n = 100;
    int window_size = 5;
    int result_size;
    double* data = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }
    double* result = process_signal(data, n, window_size, &result_size);
    for (int i = 0; i < result_size; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    free(data);
    free(result);
    return 0;
}