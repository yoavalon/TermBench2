#include <stdio.h>
#include <string.h>

int calculate_alignment_score(char* seq1, char* seq2) {
    int score = 0;
    int len1 = strlen(seq1);
    int len2 = strlen(seq2);
    int min_len = len1 < len2 ? len1 : len2;
    for (int i = 0; i < min_len; i++) {
        if (seq1[i] == seq2[i]) {
            score += 1;
        }
    }
    return score;
}

void find_best_alignment(char* seq1, char* seq2, int* best_score, int* best_offset) {
    *best_score = 0;
    *best_offset = 0;
    int len2 = strlen(seq2);
    int len1 = strlen(seq1);
    for (int offset = -len2; offset < len1; offset++) {
        char shifted_seq2[len2 + 1];
        int start = offset < 0 ? -offset : 0;
        int end = len2 - (offset > 0 ? offset : 0);
        strncpy(shifted_seq2, seq2 + start, end);
        shifted_seq2[end] = '\0';
        int score = calculate_alignment_score(seq1, shifted_seq2);
        if (score > *best_score) {
            *best_score = score;
            *best_offset = offset;
        }
    }
}

int main() {
    char sequence1[] = "ACGTACGTACG";
    char sequence2[] = "GTACGTACGTA";
    int score;
    int offset;
    find_best_alignment(sequence1, sequence2, &score, &offset);
    printf("Best alignment score: %d, Offset: %d\n", score, offset);
    return 0;
}