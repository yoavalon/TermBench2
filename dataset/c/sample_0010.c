#include <stdio.h>
#include <stdlib.h>

void boundary_conditions(int *signal, int n, int window_size, int *result) {
    int padded_size = n + 2 * window_size;
    int *padded_signal = (int *)malloc(padded_size * sizeof(int));
    for (int i = 0; i < window_size; i++) {
        padded_signal[i] = 0;
        padded_signal[i + window_size + n] = 0;
    }
    for (int i = 0; i < n; i++) {
        padded_signal[i + window_size] = signal[i];
    }
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        for (int j = 0; j < 2 * window_size + 1; j++) {
            result[i] += padded_signal[i + j];
        }
    }
    free(padded_signal);
}

int main() {
    int signal[] = {1, 2, 3, 4, 5};
    int n = sizeof(signal) / sizeof(signal[0]);
    int window_size = 2;
    int *output = (int *)malloc(n * sizeof(int));
    boundary_conditions(signal, n, window_size, output);
    for (int i = 0; i < n; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");
    free(output);
    return 0;
}