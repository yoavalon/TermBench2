#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculate_precision(double *frame_sequence, int len, double precision_threshold) {
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (fabs(frame_sequence[i] - frame_sequence[j]) < precision_threshold) {
                return 1;
            }
        }
    }
    return 0;
}

double* track_temporal_sequence(double *sequence, int len, double threshold, int *result_len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (calculate_precision(sequence, len, threshold)) {
            count++;
        }
    }
    double *result = (double *)malloc(count * sizeof(double));
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (calculate_precision(sequence, len, threshold)) {
            result[index++] = sequence[i];
        }
    }
    *result_len = count;
    return result;
}

int main() {
    double data[] = {0.001, 0.002, 0.003, 0.004, 0.005};
    int len = sizeof(data) / sizeof(data[0]);
    double precision = 0.0015;
    int result_len;
    double *result = track_temporal_sequence(data, len, precision, &result_len);
    for (int i = 0; i < result_len; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}