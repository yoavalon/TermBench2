#include <stdio.h>
#include <stdlib.h>

int* filter_signal(int* signal, int length, int threshold, int* filtered_length) {
    if (length == 0) {
        *filtered_length = 0;
        return NULL;
    } else {
        int* filtered = (int*)malloc(length * sizeof(int));
        int index = 0;
        if (signal[0] > threshold) {
            filtered[index++] = signal[0];
        }
        int* rest = filter_signal(signal + 1, length - 1, threshold, filtered_length);
        if (rest != NULL) {
            for (int i = 0; i < *filtered_length; i++) {
                filtered[index++] = rest[i];
            }
            free(rest);
        }
        *filtered_length = index;
        return filtered;
    }
}

int* process_signal(int* data, int length, int* result_length) {
    int threshold = 0;
    for (int i = 0; i < length; i++) {
        threshold += data[i];
    }
    threshold /= length;
    return filter_signal(data, length, threshold, result_length);
}

void main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = sizeof(data) / sizeof(data[0]);
    int result_length;
    int* result = process_signal(data, length, &result_length);
    for (int i = 0; i < result_length; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    main();
}