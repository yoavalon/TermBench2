#include <stdio.h>
#include <stdlib.h>

double* process_signal(int* data, int data_length, int window_size, int* result_length) {
    double* result = (double*)malloc((data_length - window_size + 1) * sizeof(double));
    for (int i = 0; i <= data_length - window_size; i++) {
        int sum = 0;
        for (int j = 0; j < window_size; j++) {
            sum += data[i + j];
        }
        result[i] = (double)sum / window_size;
    }
    *result_length = data_length - window_size + 1;
    return result;
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int window_size = 3;
    int result_length;
    double* output = process_signal(data, sizeof(data) / sizeof(data[0]), window_size, &result_length);

    for (int i = 0; i < result_length; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");

    free(output);
    return 0;
}