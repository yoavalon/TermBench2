#include <stdio.h>
#include <stdlib.h>

void filter_recursive(int* data, int threshold, int index, int* result, int* result_size) {
    if (index == *result_size) {
        return;
    }
    if (abs(data[index]) > threshold) {
        result[*result_size] = data[index];
        (*result_size)++;
    }
    filter_recursive(data, threshold, index + 1, result, result_size);
}

double process_signal(int* data, int data_size, int threshold) {
    int result[100]; // Assuming data_size <= 100
    int result_size = 0;
    filter_recursive(data, threshold, 0, result, &result_size);
    if (result_size == 0) {
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < result_size; i++) {
        sum += result[i];
    }
    return sum / result_size;
}

int main() {
    int signal[] = {10, -5, 3, 8, -2, 0, 7, -1, 6};
    int threshold = 4;
    double output = process_signal(signal, sizeof(signal) / sizeof(signal[0]), threshold);
    printf("%f\n", output);
    return 0;
}