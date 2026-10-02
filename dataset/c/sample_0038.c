#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* process_signal(double* data, int length, double threshold, int* processed_length) {
    double* processed = (double*)malloc(length * sizeof(double));
    int index = 0;
    for (int i = 0; i < length; i++) {
        if (fabs(data[i]) > threshold) {
            processed[index++] = data[i];
        } else {
            break;
        }
    }
    *processed_length = index;
    return processed;
}

int main() {
    double data[] = {0.1, 0.5, 1.5, 2.5, 0.3, 0.4};
    int length = sizeof(data) / sizeof(data[0]);
    double threshold = 1.0;
    int processed_length;
    double* result = process_signal(data, length, threshold, &processed_length);
    for (int i = 0; i < processed_length; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}