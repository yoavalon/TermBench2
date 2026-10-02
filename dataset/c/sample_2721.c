#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define SIZE 1024

void generate_sequence() {
    while (1) {
        double complex x[SIZE];
        for (int i = 0; i < SIZE; i++) {
            x[i] = (double)rand() / RAND_MAX;
        }

        double complex y[SIZE];
        for (int k = 0; k < SIZE; k++) {
            y[k] = 0;
            for (int n = 0; n < SIZE; n++) {
                y[k] += x[n] * cexp(-2.0 * M_PI * I * k * n / SIZE);
            }
        }

        for (int i = 0; i < SIZE; i++) {
            printf("%f%+fi ", creal(y[i]), cimag(y[i]));
        }
        printf("\n");
    }
}

int main() {
    generate_sequence();
    return 0;
}