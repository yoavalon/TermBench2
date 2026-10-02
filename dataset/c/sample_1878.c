c
#include <stdio.h>
#include <stdlib.h>

double* track_sequence(int precision, int steps) {
    double* data = (double*)malloc((steps + 1) * sizeof(double));
    data[0] = 0.0;
    for (int i = 0; i < steps; i++) {
        double next_value = data[i] + 1.0 / (i + 1);
        data[i + 1] = round(next_value * pow(10, precision)) / pow(10, precision);
    }
    return data;
}

void main() {
    double* result = track_sequence(5, 100);
    for (int i = 0; i <= 100; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");
    free(result);
}