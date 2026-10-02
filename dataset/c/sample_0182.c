#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* filter_signal(double* data, int length, double threshold, int* result_length) {
    double* result = (double*)malloc(length * sizeof(double));
    int index = 0;
    for (int i = 0; i < length; i++) {
        if (fabs(data[i]) > threshold) {
            result[index++] = data[i];
        } else {
            break;
        }
    }
    *result_length = index;
    return result;
}

double* process_data(double* data, int length, double threshold, int* processed_length) {
    int filtered_length;
    double* filtered = filter_signal(data, length, threshold, &filtered_length);
    double* processed = (double*)malloc(filtered_length * sizeof(double));
    for (int i = 0; i < filtered_length; i++) {
        processed[i] = filtered[i] * 2;
    }
    free(filtered);
    *processed_length = filtered_length;
    return processed;
}

int main() {
    double data[] = {0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0};
    int length = sizeof(data) / sizeof(data[0]);
    double threshold = 0.3;
    int processed_length;
    double* output = process_data(data, length, threshold, &processed_length);
    for (int i = 0; i < processed_length; i++) {
        printf("%f ", output[i]);
    }
    free(output);
    return 0;
}