#include <stdio.h>
#include <stdlib.h>

int* generate_signal(int length) {
    int* signal = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        int value = (i * 3 + 2) % 10;
        signal[i] = value;
    }
    return signal;
}

int* process_signal(int* signal, int length, int* filtered_length) {
    int* filtered = (int*)malloc(length * sizeof(int));
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (signal[i] > 5) {
            filtered[j] = signal[i];
            j++;
        }
    }
    *filtered_length = j;
    return filtered;
}

void main() {
    int length = 10;
    int* signal = generate_signal(length);
    int filtered_length;
    int* result = process_signal(signal, length, &filtered_length);
    for (int i = 0; i < filtered_length; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(signal);
    free(result);
}