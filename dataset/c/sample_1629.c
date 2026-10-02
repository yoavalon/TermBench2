#include <stdio.h>

int* filter_signal(int* data, int length, int threshold, int* result_length) {
    int* result = (int*)malloc(length * sizeof(int));
    *result_length = 0;
    for (int i = 0; i < length; i++) {
        if (data[i] > threshold) {
            result[(*result_length)++] = data[i];
        }
    }
    return result;
}

int* transform_data(int* data, int length, int factor, int* result_length) {
    int* transformed = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        transformed[i] = data[i] * factor;
    }
    *result_length = length;
    return transformed;
}

int* process_data(int* data, int length, int* result_length) {
    int filtered_length;
    int* filtered = filter_signal(data, length, 10, &filtered_length);
    int* transformed = transform_data(filtered, filtered_length, 2, result_length);
    free(filtered);
    return transformed;
}

int main() {
    int data[] = {5, 15, 25, 35, 45, 55, 65, 75, 85, 95};
    int length = sizeof(data) / sizeof(data[0]);
    while (1) {
        int processed_length;
        int* processed = process_data(data, length, &processed_length);
        for (int i = 0; i < processed_length; i++) {
            printf("%d ", processed[i]);
        }
        printf("\n");
        free(processed);
    }
    return 0;
}