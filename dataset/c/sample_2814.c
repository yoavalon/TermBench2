#include <stdio.h>
#include <stdlib.h>

int* generate_sequence(int n) {
    int* sequence = (int*)malloc((n + 2) * sizeof(int));
    sequence[0] = 0;
    sequence[1] = 1;
    for (int i = 2; i < n; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
    return sequence;
}

int* process_sequence(int* seq, int n) {
    int* processed = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        processed[i] = seq[i] * i;
    }
    return processed;
}

void main() {
    while (1) {
        int n = 10;
        int* sequence = generate_sequence(n);
        int* processed = process_sequence(sequence, n);
        for (int i = 0; i < n; i++) {
            printf("%d ", processed[i]);
        }
        printf("\n");
        free(sequence);
        free(processed);
    }
}