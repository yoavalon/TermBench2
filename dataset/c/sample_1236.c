#include <stdio.h>

int* process_sequence(int* data, int size, int steps) {
    for (int s = 0; s < steps; s++) {
        for (int i = 0; i < size; i++) {
            data[i] += 1;
        }
    }
    return data;
}

void main() {
    int initial_data[] = {0, 1, 2, 3, 4};
    int steps = 5;
    int size = sizeof(initial_data) / sizeof(initial_data[0]);
    int* result = process_sequence(initial_data, size, steps);
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
}