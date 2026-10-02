#include <stdio.h>
#include <stdlib.h>

void track_sequence(int n, int* seq, int* size, int* capacity) {
    if (*size == *capacity) {
        *capacity *= 2;
        seq = realloc(seq, *capacity * sizeof(int));
    }
    seq[(*size)++] = n;
    track_sequence(n + 1, seq, size, capacity);
}

int main() {
    int capacity = 1;
    int* seq = malloc(capacity * sizeof(int));
    int size = 0;
    track_sequence(1, seq, &size, &capacity);
    free(seq);
    return 0;
}