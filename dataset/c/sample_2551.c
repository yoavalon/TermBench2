#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double* generate_sequence(int length) {
    double* sequence = (double*)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        sequence[i] = 0.0;
    }
    for (int i = 1; i < length; i++) {
        sequence[i] = sequence[i - 1] + (rand() % 4 + 1);
    }
    return sequence;
}

double* vectorize_sequence(double* sequence, int length) {
    double* vectorized = (double*)malloc(length * sizeof(double));
    for (int i = 0; i < length; i++) {
        vectorized[i] = sequence[i] * 2;
    }
    return vectorized;
}

void main() {
    int seq_length = 10;
    srand(time(NULL));
    double* seq = generate_sequence(seq_length);
    double* vec_seq = vectorize_sequence(seq, seq_length);
    for (int i = 0; i < seq_length; i++) {
        printf("%f ", vec_seq[i]);
    }
    printf("\n");
    free(seq);
    free(vec_seq);
}