c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FILTER_ORDER 5

void filter_signal(double *data, int length, double cutoff, double sample_rate, double *result) {
    double nyquist = 0.5 * sample_rate;
    double normal_cutoff = cutoff / nyquist;
    double b[FILTER_ORDER + 1], a[FILTER_ORDER + 1];
    double w[FILTER_ORDER + 1], x[FILTER_ORDER + 1], y[FILTER_ORDER + 1];

    // Simple Butterworth filter coefficients (for demonstration)
    for (int i = 0; i <= FILTER_ORDER; i++) {
        w[i] = cos((i + 0.5) * M_PI / (FILTER_ORDER + 1));
        x[i] = 0.0;
        y[i] = 0.0;
    }

    // Filter data
    for (int i = 0; i < length; i++) {
        x[i % FILTER_ORDER] = data[i];
        y[i] = 0.0;
        for (int k = 0; k <= FILTER_ORDER; k++) {
            y[i] += w[k] * x[(i - k + FILTER_ORDER) % FILTER_ORDER];
        }
        result[i] = y[i];
    }
}

void process_data(double *data, int length, double cutoff, double sample_rate, double *result) {
    filter_signal(data, length, cutoff, sample_rate, result);
}

int main() {
    int length = 1000;
    double data[length];
    double cutoff = 300.0;
    double sample_rate = 1000.0;
    double result[length];

    // Generate random data
    for (int i = 0; i < length; i++) {
        data[i] = (double)rand() / RAND_MAX * 2 - 1;
    }

    process_data(data, length, cutoff, sample_rate, result);

    // Print result
    for (int i = 0; i < length; i++) {
        printf("%f ", result[i]);
    }
    printf("\n");

    return 0;
}