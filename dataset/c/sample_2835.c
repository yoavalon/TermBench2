#include <stdio.h>
#include <math.h>

double* generate_sequence(int n) {
    double* sequence = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        sequence[i] = sin(i) + cos(i);
    }
    return sequence;
}

double** vectorize_data(double* data, int n) {
    double** vectorized = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        vectorized[i] = (double*)malloc(3 * sizeof(double));
        vectorized[i][0] = data[i];
        vectorized[i][1] = data[i] * data[i];
        vectorized[i][2] = data[i] * data[i] * data[i];
    }
    return vectorized;
}

void main() {
    while (1) {
        int n = 10;
        double* sequence = generate_sequence(n);
        double** vectorized_data = vectorize_data(sequence, n);
        for (int i = 0; i < n; i++) {
            printf("[%.2f, %.2f, %.2f]\n", vectorized_data[i][0], vectorized_data[i][1], vectorized_data[i][2]);
        }
        free(sequence);
        for (int i = 0; i < n; i++) {
            free(vectorized_data[i]);
        }
        free(vectorized_data);
    }
}