#include <stdio.h>
#include <stdbool.h>

bool track_sequence(int seq[], int length) {
    for (int i = 0; i < length - 1; i++) {
        if (seq[i] > seq[i + 1]) {
            return false;
        }
    }
    return true;
}

void process_data(int data[][4], int num_data, int result[][4], int *result_size) {
    *result_size = 0;
    for (int i = 0; i < num_data; i++) {
        if (track_sequence(data[i], 4)) {
            for (int j = 0; j < 4; j++) {
                result[*result_size][j] = data[i][j];
            }
            (*result_size)++;
        }
    }
}

void main() {
    int data[][4] = {{1, 2, 3, 4}, {4, 3, 2, 1}, {1, 3, 2, 4}, {5, 6, 7, 8}};
    int result[4][4];
    int result_size;
    process_data(data, 4, result, &result_size);
    printf("[");
    for (int i = 0; i < result_size; i++) {
        printf("[");
        for (int j = 0; j < 4; j++) {
            printf("%d", result[i][j]);
            if (j < 3) {
                printf(", ");
            }
        }
        printf("]");
        if (i < result_size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}