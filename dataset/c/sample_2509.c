#include <stdio.h>
#include <string.h>

double compute_similarity(const char *seq1, const char *seq2) {
    int length = strlen(seq1) < strlen(seq2) ? strlen(seq1) : strlen(seq2);
    int score = 0;
    for (int i = 0; i < length; i++) {
        if (seq1[i] == seq2[i]) {
            score += 1;
        }
    }
    return (double)score / length;
}

void align_sequences(const char *seq1, const char *seq2, char *best_alignment1, char *best_alignment2) {
    int max_score = 0;
    int len2 = strlen(seq2);
    for (int i = 0; i < len2; i++) {
        char shifted_seq[100];
        strcpy(shifted_seq, seq2 + i);
        strcat(shifted_seq, seq2);
        int score = compute_similarity(seq1, shifted_seq);
        if (score > max_score) {
            max_score = score;
            strcpy(best_alignment1, seq1);
            strcpy(best_alignment2, shifted_seq);
        }
    }
}

int main() {
    const char *sequence1 = "ACGTACGTAC";
    const char *sequence2 = "TACGTACGTA";
    char best_alignment1[100];
    char best_alignment2[100];
    align_sequences(sequence1, sequence2, best_alignment1, best_alignment2);
    printf("Aligned Sequences: (%s, %s)\n", best_alignment1, best_alignment2);
    return 0;
}