#include <stdio.h>
#include <stdlib.h>

int* filter_signal(int* data, int* kernel, int data_len, int kernel_len, int* result_len) {
    *result_len = data_len - kernel_len + 1;
    int* result = (int*)malloc(*result_len * sizeof(int));
    for (int i = 0; i < *result_len; i++) {
        int segment[kernel_len];
        for (int j = 0; j < kernel_len; j++) {
            segment[j] = data[i + j];
        }
        int convolution = 0;
        for (int j = 0; j < kernel_len; j++) {
            convolution += segment[j] * kernel[j];
        }
        result[i] = convolution;
    }
    return result;
}

int* apply_boundary_conditions(int* data, int data_len, const char* boundary_type, int* new_len) {
    if (boundary_type == "reflect") {
        *new_len = data_len * 2 - 2;
        int* new_data = (int*)malloc(*new_len * sizeof(int));
        for (int i = 0; i < data_len; i++) {
            new_data[i] = data[i];
        }
        for (int i = 0; i < data_len - 1; i++) {
            new_data[data_len - 1 + i] = data[data_len - 2 - i];
        }
        return new_data;
    } else if (boundary_type == "zero") {
        *new_len = data_len * 2;
        int* new_data = (int*)malloc(*new_len * sizeof(int));
        for (int i = 0; i < data_len; i++) {
            new_data[i] = data[i];
        }
        for (int i = 0; i < data_len; i++) {
            new_data[data_len + i] = 0;
        }
        return new_data;
    } else if (boundary_type == "constant") {
        *new_len = data_len * 2;
        int* new_data = (int*)malloc(*new_len * sizeof(int));
        for (int i = 0; i < data_len; i++) {
            new_data[i] = data[i];
        }
        for (int i = 0; i < data_len; i++) {
            new_data[data_len + i] = data[data_len - 1];
        }
        return new_data;
    } else {
        *new_len = data_len;
        int* new_data = (int*)malloc(*new_len * sizeof(int));
        for (int i = 0; i < data_len; i++) {
            new_data[i] = data[i];
        }
        return new_data;
    }
}

void main() {
    int data[] = {1, 2, 3, 4, 5};
    int kernel[] = {1, 0, -1};
    int data_len = sizeof(data) / sizeof(data[0]);
    int kernel_len = sizeof(kernel) / sizeof(kernel[0]);
    int new_len;
    int* extended_data = apply_boundary_conditions(data, data_len, "reflect", &new_len);
    int result_len;
    int* filtered_data = filter_signal(extended_data, kernel, new_len, kernel_len, &result_len);
    for (int i = 0; i < data_len; i++) {
        printf("%d ", filtered_data[i]);
    }
    printf("\n");
    free(extended_data);
    free(filtered_data);
}