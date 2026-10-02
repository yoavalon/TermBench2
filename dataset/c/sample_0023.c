#include <stdio.h>
#include <stdlib.h>

void process_signal(int *data, int length, int threshold, int **processed, int *processed_length) {
    *processed = (int *)malloc(length * sizeof(int));
    *processed_length = 0;

    for (int i = 0; i < length; i++) {
        if (data[i] > threshold) {
            (*processed)[(*processed_length)++] = data[i];
        }
    }
}

int main() {
    int signal[] = {10, 20, 30, 40, 50};
    int threshold = 25;
    int *result;
    int result_length;

    process_signal(signal, sizeof(signal) / sizeof(signal[0]), threshold, &result, &result_length);

    for (int i = 0; i < result_length; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}