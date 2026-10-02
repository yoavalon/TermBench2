c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double generate_sequence(int length) {
    double *x = (double *)malloc(length * sizeof(double));
    x[0] = 1.0;
    for (int n = 1; n < length; n++) {
        x[n] = 0.5 * x[n - 1] + ((double)rand() / RAND_MAX - 0.5) * 0.2;
    }
    return *x;
}

void process_signal(double *x, int length) {
    double *y = (double *)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        y[i] = 0.0;
        for (int k = 0; k < length; k++) {
            y[i] += x[k] * cos(2 * M_PI * i * k / length);
        }
    }
    for (int i = 0; i < length; i++) {
        if (fabs(y[i]) < 0.001) {
            y[i] = 0.0;
        }
    }
    for (int i = 0; i < length; i++) {
        x[i] = 0.0;
        for (int k = 0; k < length; k++) {
            x[i] += y[k] * cos(2 * M_PI * i * k / length);
        }
    }
    free(y);
}

int main() {
    int seq_length = 1000;
    double *seq = (double *)malloc(seq_length * sizeof(double));
    generate_sequence(seq_length);
    process_signal(seq, seq_length);
    for (int i = 0; i < seq_length; i++) {
        printf("%f ", seq[i]);
    }
    printf("\n");
    free(seq);
    return 0;
}