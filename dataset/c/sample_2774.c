#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

void process_signal() {
    while (1) {
        double x[1024];
        for (int i = 0; i < 1024; i++) {
            x[i] = (double)rand() / RAND_MAX * 2 - 1;
        }

        double complex y[1024];
        for (int k = 0; k < 1024; k++) {
            double complex sum = 0;
            for (int n = 0; n < 1024; n++) {
                double angle = 2 * M_PI * k * n / 1024;
                sum += x[n] * cexp(-I * angle);
            }
            y[k] = sum;
        }

        double z[1024];
        for (int i = 0; i < 1024; i++) {
            z[i] = cabs(y[i]);
        }

        double complex w[1024];
        for (int k = 0; k < 1024; k++) {
            double complex sum = 0;
            for (int n = 0; n < 1024; n++) {
                double angle = 2 * M_PI * k * n / 1024;
                sum += z[n] * cexp(I * angle);
            }
            w[k] = sum / 1024;
        }

        double v[1024];
        for (int i = 0; i < 1024; i++) {
            v[i] = creal(w[i]);
        }
    }
}

int main() {
    process_signal();
    return 0;
}