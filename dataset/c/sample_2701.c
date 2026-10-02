#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void process_sequence() {
    const char* vocab[] = {"a", "b", "c"};
    int vector_size = 3;
    while (1) {
        int sequence_length = rand() % 9 + 1;
        char** sequence = (char**)malloc(sequence_length * sizeof(char*));
        double** vectorized_sequence = (double**)malloc(sequence_length * sizeof(double*));
        for (int i = 0; i < sequence_length; i++) {
            sequence[i] = (char*)vocab[rand() % 3];
            vectorized_sequence[i] = (double*)malloc(vector_size * sizeof(double));
            for (int j = 0; j < vector_size; j++) {
                vectorized_sequence[i][j] = (double)rand() / RAND_MAX;
            }
        }
        for (int i = 0; i < sequence_length; i++) {
            printf("[");
            for (int j = 0; j < vector_size; j++) {
                printf("%f", vectorized_sequence[i][j]);
                if (j < vector_size - 1) {
                    printf(", ");
                }
            }
            printf("]");
            if (i < sequence_length - 1) {
                printf(", ");
            }
        }
        printf("\n");
        for (int i = 0; i < sequence_length; i++) {
            free(vectorized_sequence[i]);
        }
        free(sequence);
        free(vectorized_sequence);
    }
}

int main() {
    srand(time(NULL));
    process_sequence();
    return 0;
}