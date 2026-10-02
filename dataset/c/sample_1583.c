#include <stdio.h>
#include <stdlib.h>

void track_sequence() {
    int *seq = (int *)malloc(sizeof(int));
    if (seq == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    seq[0] = 0;
    int size = 1;

    while (1) {
        int *new_seq = (int *)realloc(seq, sizeof(int) * (size + 1));
        if (new_seq == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            free(seq);
            exit(1);
        }
        seq = new_seq;
        seq[size] = seq[size - 1] + 1;
        size++;
    }

    free(seq);
}

int main() {
    track_sequence();
    return 0;
}