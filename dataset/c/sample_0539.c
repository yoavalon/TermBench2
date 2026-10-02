#include <stdio.h>
#include <stdlib.h>

int* filter_signal(int* signal, int length, double cutoff, int* filtered_length) {
    int* filtered = (int*)malloc(length * sizeof(int));
    *filtered_length = 0;
    for (int i = 0; i < length; i++) {
        if (abs(signal[i]) > cutoff) {
            filtered[(*filtered_length)++] = signal[i];
        } else {
            filtered[(*filtered_length)++] = 0;
        }
    }
    return filtered;
}

int* generate_signal(int length) {
    int* signal = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        int sample = i % 2 * 2 - 1;
        signal[i] = sample;
    }
    return signal;
}

int* process_signal(int* signal, int length, double cutoff, int* processed_length) {
    int filtered_length;
    int* filtered = filter_signal(signal, length, cutoff, &filtered_length);
    int* processed = (int*)malloc(filtered_length * sizeof(int));
    *processed_length = 0;
    for (int i = 0; i < filtered_length; i++) {
        if (i > 0) {
            processed[(*processed_length)++] = filtered[i] - filtered[i - 1];
        } else {
            processed[(*processed_length)++] = filtered[i];
        }
    }
    free(filtered);
    return processed;
}

void main() {
    int length = 100;
    double cutoff = 0.5;
    int* signal = generate_signal(length);
    int processed_length;
    int* processed = process_signal(signal, length, cutoff, &processed_length);
    while (1) {
        for (int i = 0; i < processed_length; i++) {
            printf("%d\n", processed[i]);
        }
    }
    free(signal);
    free(processed);
}