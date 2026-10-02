#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* apply_boundary_conditions(int* signal, int length, const char* boundary_type, int* new_length) {
    int padding = 10;
    *new_length = length + padding;
    int* padded_signal = (int*)malloc(*new_length * sizeof(int));

    if (strcmp(boundary_type, "zero") == 0) {
        memset(padded_signal, 0, *new_length * sizeof(int));
        memcpy(padded_signal + padding, signal, length * sizeof(int));
    } else if (strcmp(boundary_type, "reflect") == 0) {
        for (int i = 0; i < length; i++) {
            padded_signal[i] = signal[i];
        }
        for (int i = 1; i <= padding; i++) {
            padded_signal[length + i - 1] = signal[length - i];
        }
    } else if (strcmp(boundary_type, "wrap") == 0) {
        for (int i = 0; i < length; i++) {
            padded_signal[i] = signal[i];
        }
        for (int i = 1; i <= padding; i++) {
            padded_signal[length + i - 1] = signal[i % length];
        }
    } else {
        memcpy(padded_signal, signal, length * sizeof(int));
    }

    return padded_signal;
}

int* process_signal(int* signal, int length, int* new_length) {
    const char* boundary_type = "reflect";
    return apply_boundary_conditions(signal, length, boundary_type, new_length);
}

int main() {
    int signal[] = {1, 2, 3, 4, 5};
    int length = sizeof(signal) / sizeof(signal[0]);
    int new_length;
    int* result = process_signal(signal, length, &new_length);

    for (int i = 0; i < new_length; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}