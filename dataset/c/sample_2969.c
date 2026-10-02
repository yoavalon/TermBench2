#include <stdio.h>
#include <stdlib.h>

int* generate_sequence(int n) {
    int* sequence = (int*)malloc(n * sizeof(int));
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        sequence[i] = a;
        int temp = a;
        a = b;
        b = temp + b;
    }
    return sequence;
}

int compare_sequences(int* seq1, int* seq2, int len1, int len2) {
    int score = 0;
    int min_length = len1 < len2 ? len1 : len2;
    for (int i = 0; i < min_length; i++) {
        if (seq1[i] == seq2[i]) {
            score++;
        }
    }
    return score;
}

typedef struct {
    int* seq1;
    int* seq2;
} SequenceAligner;

void SequenceAligner_init(SequenceAligner* aligner, int* seq1, int* seq2) {
    aligner->seq1 = seq1;
    aligner->seq2 = seq2;
}

void SequenceAligner_align(SequenceAligner* aligner, int* best_score, int* best_shift) {
    *best_score = 0;
    *best_shift = 0;
    int len1 = 100;
    int len2 = 100;
    for (int shift = -len1; shift < len2; shift++) {
        int* shifted_seq = (int*)malloc(len2 * sizeof(int));
        for (int i = 0; i < len2; i++) {
            if (i - shift >= 0 && i - shift < len2) {
                shifted_seq[i] = aligner->seq2[i - shift];
            } else {
                shifted_seq[i] = 0;
            }
        }
        int score = compare_sequences(aligner->seq1, shifted_seq, len1, len2);
        if (score > *best_score) {
            *best_score = score;
            *best_shift = shift;
        }
        free(shifted_seq);
    }
}

int main() {
    int* seq1 = generate_sequence(100);
    int* seq2 = generate_sequence(100);
    SequenceAligner aligner;
    SequenceAligner_init(&aligner, seq1, seq2);
    while (1) {
        int best_score, best_shift;
        SequenceAligner_align(&aligner, &best_score, &best_shift);
        printf("Best Score: %d, Best Shift: %d\n", best_score, best_shift);
    }
    return 0;
}