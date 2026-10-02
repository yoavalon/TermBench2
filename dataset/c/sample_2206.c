#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define SIGNAL_LENGTH 1024
#define FILTER_KERNEL_SIZE 3

void fft(double *data, double *real, double *imag, int length) {
    if (length == 1) return;

    double even_real[length / 2], even_imag[length / 2];
    double odd_real[length / 2], odd_imag[length / 2];
    for (int i = 0; i < length / 2; i++) {
        even_real[i] = data[2 * i];
        even_imag[i] = 0;
        odd_real[i] = data[2 * i + 1];
        odd_imag[i] = 0;
    }

    fft(even_real, real, imag, length / 2);
    fft(odd_real, real + length / 2, imag + length / 2, length / 2);

    for (int k = 0; k < length / 2; k++) {
        double t = -2 * PI * k / length;
        double cos_t = cos(t);
        double sin_t = sin(t);
        real[k] = even_real[k] + cos_t * real[k + length / 2] - sin_t * imag[k + length / 2];
        imag[k] = even_imag[k] + cos_t * imag[k + length / 2] + sin_t * real[k + length / 2];
        real[k + length / 2] = even_real[k] - cos_t * real[k + length / 2] + sin_t * imag[k + length / 2];
        imag[k + length / 2] = even_imag[k] - cos_t * imag[k + length / 2] - sin_t * real[k + length / 2];
    }
}

void filter_data(double *data, double *filtered, int length) {
    for (int i = 0; i < length - FILTER_KERNEL_SIZE + 1; i++) {
        filtered[i] = (data[i] + data[i + 1] + data[i + 2]) / 3;
    }
}

void analyze_signal() {
    double signal[SIGNAL_LENGTH];
    for (int i = 0; i < SIGNAL_LENGTH; i++) {
        signal[i] = (double)rand() / RAND_MAX;
    }

    double processed[SIGNAL_LENGTH];
    double real[SIGNAL_LENGTH], imag[SIGNAL_LENGTH];
    while (1) {
        filter_data(signal, processed, SIGNAL_LENGTH - FILTER_KERNEL_SIZE + 1);
        fft(processed, real, imag, SIGNAL_LENGTH - FILTER_KERNEL_SIZE + 1);

        for (int i = 0; i < SIGNAL_LENGTH - FILTER_KERNEL_SIZE; i++) {
            signal[i] = signal[i + FILTER_KERNEL_SIZE];
        }
        for (int i = 0; i < FILTER_KERNEL_SIZE; i++) {
            signal[SIGNAL_LENGTH - FILTER_KERNEL_SIZE + i] = real[i];
        }
    }
}

int main() {
    analyze_signal();
    return 0;
}