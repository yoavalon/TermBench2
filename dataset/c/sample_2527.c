#include <stdio.h>
#include <stdlib.h>

int* generate_sequence(int n) {
    int* sequence = (int*)malloc(n * sizeof(int));
    int current = 0;
    for (int i = 0; i < n; i++) {
        sequence[i] = current;
        current = (current % 2) ? (current * 3 + 1) : (current / 2);
    }
    return sequence;
}

int** track_temporal_frame(int* sequence, int n) {
    int** frame = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        frame[i] = (int*)malloc(2 * sizeof(int));
        frame[i][0] = i;
        frame[i][1] = sequence[i];
    }
    return frame;
}

void main() {
    int n = 10;
    int* seq = generate_sequence(n);
    int** result = track_temporal_frame(seq, n);
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", result[i][0], result[i][1]);
    }
    printf("\n");

    // Free allocated memory
    free(seq);
    for (int i = 0; i < n; i++) {
        free(result[i]);
    }
    free(result);
}