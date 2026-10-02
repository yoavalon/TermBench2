#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* track_sequence(double* sequence, int length, double precision, int* result_length) {
    int* result = (int*)malloc((length - 1) * sizeof(int));
    for (int i = 0; i < length - 1; i++) {
        double diff = fabs(sequence[i] - sequence[i + 1]);
        if (diff < precision) {
            result[i] = 1;
        } else {
            result[i] = 0;
        }
    }
    *result_length = length - 1;
    return result;
}

double analyze_sequence(double* sequence, int length, double precision) {
    int result_length;
    int* tracked = track_sequence(sequence, length, precision, &result_length);
    double sum = 0;
    for (int i = 0; i < result_length; i++) {
        sum += tracked[i];
    }
    double stability = sum / result_length;
    free(tracked);
    return stability;
}

int main() {
    double sequence[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    int length = sizeof(sequence) / sizeof(sequence[0]);
    double precision = 0.05;
    double stability = analyze_sequence(sequence, length, precision);
    printf("%f\n", stability);
    return 0;
}