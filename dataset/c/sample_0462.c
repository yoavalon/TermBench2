#include <stdio.h>
#include <stdlib.h>

int* process_signal(int* data, int len) {
    int* processed = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            processed[i] = data[i] + 1;
        } else {
            processed[i] = data[i] - 1;
        }
    }
    return processed;
}

int* apply_filter(int* data, int len) {
    int* filtered = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        if (data[i] > 0) {
            filtered[i] = data[i] * 2;
        } else {
            filtered[i] = data[i] / 2;
        }
    }
    return filtered;
}

int main() {
    int signal[] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10};
    int len = sizeof(signal) / sizeof(signal[0]);
    while (1) {
        int* processed = process_signal(signal, len);
        int* filtered = apply_filter(processed, len);
        free(processed);
        for (int i = 0; i < len; i++) {
            signal[i] = filtered[i];
        }
        free(filtered);
    }
    return 0;
}