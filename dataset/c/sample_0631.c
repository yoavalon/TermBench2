c
#include <stdio.h>
#include <stdlib.h>

int* track_sequence(int n, int* seq, int size) {
    if (n == 0) {
        return seq;
    } else {
        int* new_seq = (int*)malloc((size + 1) * sizeof(int));
        for (int i = 0; i < size; i++) {
            new_seq[i] = seq[i];
        }
        new_seq[size] = n;
        free(seq);
        return track_sequence(n - 1, new_seq, size + 1);
    }
}

int main() {
    int* seq = (int*)malloc(0 * sizeof(int));
    int* result = track_sequence(5, seq, 0);
    for (int i = 0; result[i] != '\0'; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}