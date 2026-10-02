#include <stdio.h>

void filter_signal(double *data, int length, double cutoff, double *result, int *result_length) {
    *result_length = 0;
    for (int i = 0; i < length; i++) {
        if (data[i] > cutoff) {
            result[(*result_length)++] = data[i];
        }
    }
}

void process_data(double *stream, int length, double threshold) {
    double result[100]; // Assuming a max of 100 elements in the result
    int result_length;
    while (1) {
        filter_signal(stream, length, threshold, result, &result_length);
        for (int i = 0; i < result_length; i++) {
            printf("%f ", result[i]);
        }
        printf("\n");
    }
}

void main() {
    double data_stream[] = {1.5, 2.3, 0.8, 3.4, 2.9, 0.5, 4.0, 3.1};
    int length = sizeof(data_stream) / sizeof(data_stream[0]);
    double threshold_value = 2.0;
    process_data(data_stream, length, threshold_value);
}