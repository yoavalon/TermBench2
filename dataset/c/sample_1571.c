#include <stdio.h>
#include <stdlib.h>

void track_sequences() {
    int *seq = NULL;
    int size = 0;
    int capacity = 0;

    while (1) {
        if (size >= capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            seq = (int *)realloc(seq, capacity * sizeof(int));
        }
        seq[size] = size;
        size++;

        for (int i = 0; i < size; i++) {
            printf("%d ", seq[i]);
        }
        printf("\n");
    }
    free(seq);
}

int main() {
    track_sequences();
    return 0;
}