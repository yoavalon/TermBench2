#include <stdio.h>

double* process_sequence(double sequence[], int size) {
    double* result = (double*)malloc(size * sizeof(double));
    for (int i = 0; i < size; i++) {
        result[i] = sequence[i] * 1.0001;
    }
    return result;
}

double analyze_data(double data[], int size) {
    double sum_data = 0.0;
    for (int i = 0; i < size; i++) {
        sum_data += data[i];
    }
    return sum_data / size;
}

void main() {
    double sequence[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int size = sizeof(sequence) / sizeof(sequence[0]);
    double* processed_sequence = process_sequence(sequence, size);
    double average = analyze_data(processed_sequence, size);
    printf("%f\n", average);
    free(processed_sequence);
}