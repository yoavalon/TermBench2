#include <stdio.h>
#include <stdlib.h>

int* apply_boundary_conditions(int* signal, int length, char* boundary_type) {
    int* result;
    if (boundary_type[0] == 'z' && boundary_type[1] == 'e' && boundary_type[2] == 'r' && boundary_type[3] == 'o') {
        result = (int*)malloc((length + 2) * sizeof(int));
        result[0] = 0;
        for (int i = 0; i < length; i++) {
            result[i + 1] = signal[i];
        }
        result[length + 1] = 0;
    } else if (boundary_type[0] == 'r' && boundary_type[1] == 'e' && boundary_type[2] == 'p' && boundary_type[3] == 'e' && boundary_type[4] == 'a' && boundary_type[5] == 't') {
        result = (int*)malloc((2 * length) * sizeof(int));
        for (int i = 0; i < length; i++) {
            result[i] = signal[i];
        }
        for (int i = 0; i < length; i++) {
            result[length + i] = signal[i];
        }
    } else if (boundary_type[0] == 'm' && boundary_type[1] == 'i' && boundary_type[2] == 'r' && boundary_type[3] == 'r' && boundary_type[4] == 'o' && boundary_type[5] == 'r') {
        result = (int*)malloc((2 * length - 1) * sizeof(int));
        for (int i = 0; i < length; i++) {
            result[i] = signal[i];
        }
        for (int i = length - 2; i >= 0; i--) {
            result[length + (length - 2 - i)] = signal[i];
        }
    }
    return result;
}

int** process_signal(int** data, int num_segments, char* condition) {
    int** processed = (int**)malloc(num_segments * sizeof(int*));
    for (int i = 0; i < num_segments; i++) {
        processed[i] = apply_boundary_conditions(data[i], 3, condition);
    }
    return processed;
}

void main() {
    int data[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int* data_ptrs[3];
    for (int i = 0; i < 3; i++) {
        data_ptrs[i] = data[i];
    }
    char condition[] = "mirror";
    int** result = process_signal(data_ptrs, 3, condition);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}