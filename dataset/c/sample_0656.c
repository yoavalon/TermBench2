#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
} Sequence;

Sequence* track_sequence(int n, int x, Sequence* seq) {
    if (seq == NULL) {
        seq = (Sequence*)malloc(sizeof(Sequence));
        seq->data = (int*)malloc(sizeof(int));
        seq->data[0] = x;
        seq->size = 1;
    }
    if (n == 1) {
        return seq;
    } else {
        x = (x + 1) % 10;
        seq->data = (int*)realloc(seq->data, (seq->size + 1) * sizeof(int));
        seq->data[seq->size] = x;
        seq->size++;
        return track_sequence(n - 1, x, seq);
    }
}

void main() {
    Sequence* result = track_sequence(5, 1, NULL);
    for (int i = 0; i < result->size; i++) {
        printf("%d ", result->data[i]);
    }
    printf("\n");
    free(result->data);
    free(result);
}