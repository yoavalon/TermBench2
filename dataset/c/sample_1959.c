#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* track_sequence(double* seq, int seq_len, double precision, int* result_len) {
    double* result = (double*)malloc(seq_len * sizeof(double));
    int result_index = 0;
    result[result_index] = seq[0];
    for (int i = 1; i < seq_len; i++) {
        double diff = fabs(seq[i] - seq[i - 1]);
        if (diff < precision) {
            result[result_index] += seq[i];
        } else {
            result_index++;
            result[result_index] = seq[i];
        }
    }
    *result_len = result_index + 1;
    return result;
}

int main() {
    double sequence[] = {0.1, 0.2, 0.30001, 0.4, 0.400001, 0.5};
    int seq_len = sizeof(sequence) / sizeof(sequence[0]);
    double precision = 0.001;
    int result_len;
    double* processed_sequence = track_sequence(sequence, seq_len, precision, &result_len);
    for (int i = 0; i < result_len; i++) {
        printf("%f ", processed_sequence[i]);
    }
    printf("\n");
    free(processed_sequence);
    return 0;
}