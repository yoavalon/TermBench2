#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void process_signal(double *signal, int length, double *filtered_signal) {
    for (int i = 0; i < length; i++) {
        filtered_signal[i] = 0.25 * signal[i] + 0.5 * signal[(i + 1) % length] + 0.25 * signal[(i + 2) % length];
    }
}

void analyze_data(double *data, int length, int *anomalies) {
    double processed_data[length];
    process_signal(data, length, processed_data);
    double mean = 0.0, std = 0.0;
    for (int i = 0; i < length; i++) {
        mean += processed_data[i];
    }
    mean /= length;
    for (int i = 0; i < length; i++) {
        std += (processed_data[i] - mean) * (processed_data[i] - mean);
    }
    std = sqrt(std / length);
    double threshold = mean + 2 * std;
    for (int i = 0; i < length; i++) {
        anomalies[i] = (processed_data[i] > threshold);
    }
}

int main() {
    double data[100];
    int anomalies[100];
    for (int i = 0; i < 100; i++) {
        data[i] = (double)rand() / RAND_MAX;
    }
    analyze_data(data, 100, anomalies);
    for (int i = 0; i < 100; i++) {
        printf("%d ", anomalies[i]);
    }
    printf("\n");
    return 0;
}