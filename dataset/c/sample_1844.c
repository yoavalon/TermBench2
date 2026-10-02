#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

#define PI 3.14159265358979323846

void process_signal(double data[], complex double processed_data[], int n) {
    for (int k = 0; k < n; k++) {
        processed_data[k] = 0;
        for (int t = 0; t < n; t++) {
            processed_data[k] += data[t] * cexp(-2 * I * PI * k * t / n);
        }
    }
}

void main() {
    int n = 1024;
    double data[n];
    complex double result[n];

    for (int i = 0; i < n; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }

    process_signal(data, result, n);

    for (int i = 0; i < n; i++) {
        printf("%f + %fi\n", creal(result[i]), cimag(result[i]));
    }
}