#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* filter_signal(double* signal, int length, double threshold, int* result_length) {
    if (length == 0) {
        *result_length = 0;
        return NULL;
    } else {
        double* result;
        int tail_length = length - 1;
        double* tail_result = filter_signal(signal + 1, tail_length, threshold, result_length);
        if (fabs(signal[0]) > threshold) {
            *result_length = tail_length + 1;
            result = (double*)malloc((*result_length) * sizeof(double));
            result[0] = signal[0];
            for (int i = 0; i < tail_length; i++) {
                result[i + 1] = tail_result[i];
            }
        } else {
            *result_length = tail_length;
            result = tail_result;
        }
        return result;
    }
}

int main() {
    double signal[] = {0.1, -0.3, 0.5, -0.2, 0.8, 0.4, -0.6, 0.7};
    double threshold = 0.5;
    int result_length;
    double* result = filter_signal(signal, 8, threshold, &result_length);
    for (int i = 0; i < result_length; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    if (result != NULL) {
        free(result);
    }
    return 0;
}