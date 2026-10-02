#include <stdio.h>

#define SIZE 10

int* process_signal(double data[], double threshold, int* result_size) {
    static int result[SIZE];
    *result_size = 0;
    for (int i = 0; i < SIZE; i++) {
        if (data[i] > threshold) {
            result[(*result_size)++] = i;
        }
    }
    return result;
}

double analyze_data(double signal[], double boundary) {
    int result_size;
    int* processed = process_signal(signal, boundary, &result_size);
    double sum = 0.0;
    for (int i = 0; i < result_size; i++) {
        sum += signal[processed[i]];
    }
    return sum;
}

int main() {
    double data[SIZE] = {0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9};
    double threshold = 0.5;
    double result = analyze_data(data, threshold);
    printf("%f\n", result);
    return 0;
}