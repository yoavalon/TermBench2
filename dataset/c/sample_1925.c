#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* track_sequence(double* seq, int len, double precision, int* result_len) {
    double* result = (double*)malloc((len - 1) * sizeof(double));
    *result_len = 0;
    for (int i = 0; i < len - 1; i++) {
        double diff = fabs(seq[i] - seq[i + 1]);
        if (diff < precision) {
            result[*result_len] = diff;
            (*result_len)++;
        }
    }
    return result;
}

double* analyze_data(double* data, int len, int* result_len) {
    double precision = 1e-09;
    return track_sequence(data, len, precision, result_len);
}

int main() {
    double data[] = {0.1, 0.2, 0.300000001, 0.4, 0.5};
    int len = sizeof(data) / sizeof(data[0]);
    int result_len;
    double* output = analyze_data(data, len, &result_len);
    for (int i = 0; i < result_len; i++) {
        printf("%f\n", output[i]);
    }
    free(output);
    return 0;
}