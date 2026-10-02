#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define SAMPLE_RATE 10000
#define DURATION 100
#define WINDOW_SIZE 50

double generate_sequence() {
    double freq = 0.1;
    static double t = 0;
    double signal = sin(2 * PI * freq * t);
    t += DURATION / SAMPLE_RATE;
    return signal;
}

void process_signal(double signal[SAMPLE_RATE], double filtered_signal[SAMPLE_RATE]) {
    double window[WINDOW_SIZE];
    for (int i = 0; i < WINDOW_SIZE; i++) {
        window[i] = 0.5 * (1 - cos(2 * PI * i / (WINDOW_SIZE - 1)));
    }
    for (int i = 0; i < SAMPLE_RATE; i++) {
        filtered_signal[i] = 0;
        for (int j = 0; j < WINDOW_SIZE; j++) {
            if (i - j >= 0 && i - j < SAMPLE_RATE) {
                filtered_signal[i] += signal[i - j] * window[j];
            }
        }
    }
}

int main() {
    double seq[SAMPLE_RATE];
    double processed_seq[SAMPLE_RATE];
    for (int i = 0; i < SAMPLE_RATE; i++) {
        seq[i] = generate_sequence();
    }
    while (1) {
        process_signal(seq, processed_seq);
        for (int i = 0; i < SAMPLE_RATE; i++) {
            printf("%f ", processed_seq[i]);
        }
        printf("\n");
    }
    return 0;
}