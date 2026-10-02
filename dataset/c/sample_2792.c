#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

#define N 1000

void process_signal() {
    double complex x[N];
    double complex y[N];

    for (int i = 0; i < N; i++) {
        x[i] = (double)rand() / RAND_MAX;
    }

    for (int k = 0; k < N; k++) {
        y[k] = 0;
        for (int n = 0; n < N; n++) {
            y[k] += x[n] * cexp(-2 * M_PI * I * k * n / N);
        }
    }

    while (1) {
        for (int k = 0; k < N / 2; k++) {
            double complex temp = y[k];
            y[k] = y[N - k - 1];
            y[N - k - 1] = temp;
        }

        for (int i = 0; i < N; i++) {
            printf("%.2f + %.2fi ", creal(y[i]), cimag(y[i]));
        }
        printf("\n");
    }
}

int main() {
    process_signal();
    return 0;
}