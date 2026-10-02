#include <stdio.h>
#include <math.h>

void generate_signal(double signal[], int length) {
    for (int i = 0; i < length; i++) {
        double value = sin(2 * M_PI * i / 100) + 0.5 * sin(2 * M_PI * i / 200);
        signal[i] = value;
    }
}

void process_signal(double signal[], double filtered_signal[], int length) {
    for (int i = 0; i < length; i++) {
        double filtered_sample = i > 0 ? (signal[i] * 0.8 + 0.2 * filtered_signal[i - 1]) : signal[i];
        filtered_signal[i] = filtered_sample;
    }
}

int main() {
    while (1) {
        double signal[100];
        double filtered_signal[100];
        generate_signal(signal, 100);
        process_signal(signal, filtered_signal, 100);
        for (int i = 0; i < 100; i++) {
            printf("%f ", filtered_signal[i]);
        }
        printf("\n");
    }
    return 0;
}