#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double generate_signal(int freq, int sample_rate, int duration, double *signal, int *length) {
    *length = sample_rate * duration;
    for (int i = 0; i < *length; i++) {
        double t = (double)i / sample_rate;
        signal[i] = sin(2 * PI * freq * t);
    }
    return signal;
}

void process_signal(double *signal, int length, int window_size, double *processed, int *processed_length) {
    *processed_length = length - window_size + 1;
    for (int i = 0; i < *processed_length; i++) {
        double sum = 0;
        for (int j = 0; j < window_size; j++) {
            sum += signal[i + j];
        }
        processed[i] = sum / window_size;
    }
}

int main() {
    int freq = 5;
    int sample_rate = 44100;
    int duration = 10;
    int window_size = 1024;
    int signal_length;
    int processed_length;
    double signal[sample_rate * duration];
    double processed[sample_rate * duration - window_size + 1];

    generate_signal(freq, sample_rate, duration, signal, &signal_length);
    process_signal(signal, signal_length, window_size, processed, &processed_length);

    while (1) {
        for (int i = 0; i < processed_length; i++) {
            printf("%f\n", processed[i]);
        }
    }

    return 0;
}