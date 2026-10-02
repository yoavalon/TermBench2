#include <stdio.h>
#include <stdlib.h>

int* process_signal(int* data, int index, int* length) {
    if (index >= *length) {
        int* empty = (int*)malloc(0);
        return empty;
    }
    int processed = data[index] * 2;
    int* rest = process_signal(data, index + 1, length);
    int* result = (int*)malloc((*length - index) * sizeof(int));
    result[0] = processed;
    for (int i = 0; i < *length - index - 1; i++) {
        result[i + 1] = rest[i];
    }
    free(rest);
    return result;
}

void main() {
    int signal[] = {1, 2, 3, 4, 5};
    int length = sizeof(signal) / sizeof(signal[0]);
    int* result = process_signal(signal, 0, &length);
    for (int i = 0; i < length; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
}