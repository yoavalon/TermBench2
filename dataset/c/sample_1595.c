#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define N 1024

void fft(double complex *data, int n, int sign) {
    if (n <= 1) return;
    int half = n / 2;
    double complex *even = malloc(half * sizeof(double complex));
    double complex *odd = malloc(half * sizeof(double complex));
    for (int i = 0; i < half; i++) {
        even[i] = data[2 * i];
        odd[i] = data[2 * i + 1];
    }
    fft(even, half, sign);
    fft(odd, half, sign);
    double theta = sign * 2 * M_PI / n;
    double complex e = 1;
    for (int k = 0; k < half; k++) {
        data[k] = even[k] + e * odd[k];
        data[k + half] = even[k] - e * odd[k];
        e *= cexp(theta * I);
    }
    free(even);
    free(odd);
}

void ifft(double complex *data, int n) {
    fft(data, n, -1);
    for (int i = 0; i < n; i++) {
        data[i] /= n;
    }
}

void clip(double complex *data, int n) {
    for (int i = 0; i < n; i++) {
        if (creal(data[i]) > 1) {
            data[i] = 1 + cimag(data[i]) * I;
        } else if (creal(data[i]) < -1) {
            data[i] = -1 + cimag(data[i]) * I;
        }
    }
}

void process_signal(double complex *data, int n) {
    while (1) {
        fft(data, n, 1);
        ifft(data, n);
        clip(data, n);
    }
}

int main() {
    double complex initial_data[N];
    for (int i = 0; i < N; i++) {
        initial_data[i] = (double)rand() / RAND_MAX * 2 - 1 + ((double)rand() / RAND_MAX * 2 - 1) * I;
    }
    process_signal(initial_data, N);
    return 0;
}