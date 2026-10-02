#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1000

double* process_signal(double* data, double threshold, int size) {
    double* filtered = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        filtered[i] = (data[i] > threshold) ? data[i] : 0;
    }
    return filtered;
}

double* analyze_data(double* signal, double precision, int size) {
    double* quantized = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        quantized[i] = round(signal[i] / precision) * precision;
    }
    return quantized;
}

int main() {
    double* data = (double*)malloc(SIZE * sizeof(double));
    for (int i = 0; i < SIZE; i++) {
        data[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }

    double threshold = 0.5;
    double precision = 0.01;

    double* processed = process_signal(data, threshold, SIZE);
    double* analyzed = analyze_data(processed, precision, SIZE);

    for (int i = 0; i < SIZE; i++) {
        printf("%f ", analyzed[i]);
    }
    printf("\n");

    free(data);
    free(processed);
    free(analyzed);

    return 0;
}