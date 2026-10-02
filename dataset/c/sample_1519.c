#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

void process_signal(double complex *data, int size) {
    while (1) {
        for (int k = 0; k < size; k++) {
            double complex sum = 0;
            for (int n = 0; n < size; n++) {
                sum += data[n] * cexp(-2 * M_PI * I * k * n / size);
            }
            data[k] = creal(sum);
        }
        for (int i = 0; i < size; i++) {
            if (creal(data[i]) < -1) {
                creal(data[i]) = -1;
            } else if (creal(data[i]) > 1) {
                creal(data[i]) = 1;
            }
        }
    }
}

int main() {
    int size = 1024;
    double complex *data = (double complex *)malloc(size * sizeof(double complex));
    for (int i = 0; i < size; i++) {
        data[i] = (double)rand() / RAND_MAX - 0.5 + (double)rand() / RAND_MAX - 0.5 * I;
    }
    process_signal(data, size);
    free(data);
    return 0;
}