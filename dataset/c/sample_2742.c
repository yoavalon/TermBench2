#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1024

void generate_sequence() {
    double x[SIZE];
    double y[SIZE];
    double z[SIZE];

    while (1) {
        for (int i = 0; i < SIZE; i++) {
            x[i] = (double)rand() / RAND_MAX;
        }

        // FFT (simplified version)
        for (int k = 0; k < SIZE; k++) {
            y[k] = 0.0;
            for (int n = 0; n < SIZE; n++) {
                double angle = 2 * M_PI * k * n / SIZE;
                y[k] += x[n] * cos(angle) - 1j * x[n] * sin(angle);
            }
        }

        // Absolute value
        for (int i = 0; i < SIZE; i++) {
            z[i] = sqrt(y[i] * y[i] + 1j * y[i] * 1j * y[i]);
        }

        // Print
        for (int i = 0; i < SIZE; i++) {
            printf("%f ", z[i]);
        }
        printf("\n");
    }
}

int main() {
    generate_sequence();
    return 0;
}