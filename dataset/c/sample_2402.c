c
#include <stdio.h>
#include <stdlib.h>

void optimize_logistics(int *seq, int length, int *result) {
    for (int i = 0; i < length; i++) {
        if (seq[i] > 0) {
            result[i] = seq[i] * 2;
        } else {
            result[i] = seq[i] + 5;
        }
    }
}

int main() {
    int sequence[] = {1, -2, 3, -4, 5};
    int length = sizeof(sequence) / sizeof(sequence[0]);
    int *optimized_sequence = (int *)malloc(length * sizeof(int));

    optimize_logistics(sequence, length, optimized_sequence);

    for (int i = 0; i < length; i++) {
        printf("%d ", optimized_sequence[i]);
    }
    printf("\n");

    free(optimized_sequence);
    return 0;
}