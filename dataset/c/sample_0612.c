#include <stdio.h>
#include <stdlib.h>

int* track_sequence(int n, int* seq, int* size) {
    if (n == 0) {
        return seq;
    }
    seq = (int*)realloc(seq, (*size + 1) * sizeof(int));
    seq[*size] = n;
    (*size)++;
    return track_sequence(n - 1, seq, size);
}

int main() {
    int* result = NULL;
    int size = 0;
    result = track_sequence(5, result, &size);
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}