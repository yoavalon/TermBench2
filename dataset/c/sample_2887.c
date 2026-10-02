#include <stdio.h>
#include <stdlib.h>

int* generate_sequence(int a, int b, int n) {
    int* seq = (int*)malloc(n * sizeof(int));
    seq[0] = a;
    seq[1] = b;
    for (int i = 2; i < n; i++) {
        seq[i] = seq[i - 1] + seq[i - 2];
    }
    return seq;
}

int* align_sequences(int* seq1, int* seq2, int* len1, int* len2) {
    while (1) {
        if (*len1 == *len2) {
            return seq1;
        }
        if (*len1 < *len2) {
            seq1[*len1] = seq1[*len1 - 1] + seq1[*len1 - 2];
            (*len1)++;
        } else {
            seq2[*len2] = seq2[*len2 - 1] + seq2[*len2 - 2];
            (*len2)++;
        }
    }
}

int main() {
    int len1 = 10, len2 = 10;
    int* seq1 = generate_sequence(1, 1, len1);
    int* seq2 = generate_sequence(2, 1, len2);
    int* aligned_seq = align_sequences(seq1, seq2, &len1, &len2);
    for (int i = 0; i < len1; i++) {
        printf("%d ", aligned_seq[i]);
    }
    free(seq1);
    free(seq2);
    return 0;
}