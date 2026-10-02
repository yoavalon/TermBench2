#include <stdio.h>
#include <math.h>
#include <complex.h>

#define LENGTH 1024

void generate_sequence(double complex sequence[], int length) {
    sequence[0] = 0.0 + 0.0*I;
    for (int i = 1; i < length; i++) {
        sequence[i] = sequence[i - 1] + sin(i * M_PI / 4);
    }
}

void process_signal(double complex signal[], double complex result[]) {
    for (int k = 0; k < LENGTH; k++) {
        result[k] = 0.0 + 0.0*I;
        for (int n = 0; n < LENGTH; n++) {
            result[k] += signal[n] * cexp(-2.0 * M_PI * I * k * n / LENGTH);
        }
    }
}

int main() {
    while (1) {
        double complex seq[LENGTH];
        double complex result[LENGTH];
        generate_sequence(seq, LENGTH);
        process_signal(seq, result);
        for (int i = 0; i < LENGTH; i++) {
            printf("%f + %fi\n", creal(result[i]), cimag(result[i]));
        }
    }
    return 0;
}