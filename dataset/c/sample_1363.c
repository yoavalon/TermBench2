#include <stdio.h>
#include <stdlib.h>

int* process_data(int* data, int length) {
    int* transformed_data = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        if (data[i] > 10) {
            transformed_data[i] = data[i] * 2;
        } else {
            transformed_data[i] = data[i] - 5;
        }
    }
    return transformed_data;
}

int** analyze_supply_chain(int** data, int num_arrays, int* lengths) {
    for (int i = 0; i < num_arrays; i++) {
        data[i] = process_data(data[i], lengths[i]);
    }
    return data;
}

void print_data(int** data, int num_arrays, int* lengths) {
    for (int i = 0; i < num_arrays; i++) {
        printf("[");
        for (int j = 0; j < lengths[i]; j++) {
            printf("%d", data[i][j]);
            if (j < lengths[i] - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < num_arrays - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main() {
    int initial_data[3][4] = {{12, 5, 18, 3}, {9, 15, 7, 20}, {11, 8, 14, 6}};
    int lengths[3] = {4, 4, 4};
    int* data_pointers[3];
    for (int i = 0; i < 3; i++) {
        data_pointers[i] = initial_data[i];
    }
    int** optimized_data = analyze_supply_chain(data_pointers, 3, lengths);
    print_data(optimized_data, 3, lengths);
    return 0;
}