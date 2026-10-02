#include <stdio.h>
#include <string.h>

double calculate_similarity(const char *seq1, const char *seq2) {
    int length = strlen(seq1) < strlen(seq2) ? strlen(seq1) : strlen(seq2);
    int matches = 0;
    for (int i = 0; i < length; i++) {
        if (seq1[i] == seq2[i]) {
            matches++;
        }
    }
    return (double)matches / length;
}

void align_sequences(const char *seq1, const char *seq2, int *best_alignment, double *max_score) {
    *max_score = 0;
    int seq1_len = strlen(seq1);
    int seq2_len = strlen(seq2);
    for (int i = 0; i <= seq1_len - seq2_len; i++) {
        for (int j = 0; j <= seq2_len - seq1_len; j++) {
            double score = calculate_similarity(seq1 + i, seq2 + j);
            if (score > *max_score) {
                *max_score = score;
                *best_alignment = i;
            }
        }
    }
}

int main() {
    const char *sequence1 = "ACGTACGT";
    const char *sequence2 = "TACGTACG";
    int best_alignment;
    double max_score;
    align_sequences(sequence1, sequence2, &best_alignment, &max_score);
    printf("Best alignment: %d, Similarity score: %f\n", best_alignment, max_score);
    return 0;
}