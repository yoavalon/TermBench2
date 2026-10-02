c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* generate_signal(int length) {
    double* signal = (double*)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        signal[i] = ((double)rand() / RAND_MAX) * 2 - 1;
    }
    return signal;
}

double* mutate_signal(double* signal, int length, double factor) {
    double* mutated_signal = (double*)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        mutated_signal[i] = signal[i] * factor;
    }
    free(signal);
    return mutated_signal;
}

double* process_signal(double* signal, int length, double mutation_factor) {
    double* mutated_signal = mutate_signal(signal, length, mutation_factor);
    double* fft_signal = (double*)malloc(length * sizeof(double));
    for (int k = 0; k < length; k++) {
        double real = 0.0, imag = 0.0;
        for (int t = 0; t < length; t++) {
            real += mutated_signal[t] * cos(2 * M_PI * t * k / length);
            imag += mutated_signal[t] * sin(2 * M_PI * t * k / length);
        }
        fft_signal[k] = sqrt(real * real + imag * imag);
    }
    free(mutated_signal);
    return fft_signal;
}

void main() {
    int length = 1024;
    double factor = 0.5;
    double* signal = generate_signal(length);
    double* processed_signal = process_signal(signal, length, factor);
    for (int i = 0; i < length; i++) {
        printf("%f ", processed_signal[i]);
    }
    printf("\n");
    free(processed_signal);
}