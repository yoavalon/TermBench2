#include <stdio.h>
#include <stdlib.h>

double* generate_signal(int length) {
    double* signal = (double*)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        double value = (i % 10) * 0.1;
        signal[i] = value;
    }
    return signal;
}

double* process_signal(double* signal, int length) {
    double* processed = (double*)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        double value = signal[i];
        double processed_value = value * value;
        processed[i] = processed_value;
    }
    return processed;
}

void main() {
    while (1) {
        double* signal = generate_signal(100);
        double* processed_signal = process_signal(signal, 100);
        for (int i = 0; i < 100; i++) {
            printf("%f ", processed_signal[i]);
        }
        printf("\n");
        free(signal);
        free(processed_signal);
    }
}