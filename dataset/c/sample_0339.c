#include <stdio.h>
#include <stdlib.h>

void track_sequences() {
    int seq[10];
    int seq_size = 0;
    seq[seq_size++] = 0;

    while (1) {
        seq[seq_size % 10] = seq[(seq_size - 1) % 10] + 1;
        seq_size++;
        if (seq_size > 10) {
            seq_size = 10;
        }

        for (int i = 0; i < seq_size; i++) {
            printf("%d ", seq[i]);
        }
        printf("\n");
    }
}

int main() {
    track_sequences();
    return 0;
}