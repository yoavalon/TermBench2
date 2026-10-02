#include <stdio.h>
#include <stdlib.h>

int* optimize_shipments(int* data, int index, int length, int* size) {
    if (index >= length) {
        *size = 0;
        return NULL;
    }
    int current = data[index];
    int rest_size;
    int* rest = optimize_shipments(data, index + 1, length, &rest_size);
    if (current < 10) {
        *size = rest_size + 1;
        int* result = (int*)malloc((*size) * sizeof(int));
        result[0] = current;
        for (int i = 0; i < rest_size; i++) {
            result[i + 1] = rest[i];
        }
        free(rest);
        return result;
    } else {
        *size = rest_size;
        return rest;
    }
}

int* process_data(int* data, int length, int* size) {
    return optimize_shipments(data, 0, length, size);
}

void main() {
    int data[] = {5, 12, 7, 9, 15, 3};
    int length = sizeof(data) / sizeof(data[0]);
    int size;
    int* result = process_data(data, length, &size);
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", result[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    free(result);
}