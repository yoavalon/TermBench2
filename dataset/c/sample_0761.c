#include <stdio.h>
#include <string.h>

void align(const char *seq1, const char *seq2, int *match, char *aligned_seq1, char *aligned_seq2, int *index1, int *index2) {
    if (!seq1[0] || !seq2[0]) {
        *match = 0;
        aligned_seq1[*index1] = '\0';
        aligned_seq2[*index2] = '\0';
        return;
    }
    if (seq1[0] == seq2[0]) {
        align(seq1 + 1, seq2 + 1, match, aligned_seq1, aligned_seq2, index1 + 1, index2 + 1);
        *match += 1;
        aligned_seq1[*index1] = seq1[0];
        aligned_seq2[*index2] = seq2[0];
    } else {
        int match1, match2;
        char aligned_seq1_1[100], aligned_seq1_2[100], aligned_seq2_1[100], aligned_seq2_2[100];
        align(seq1 + 1, seq2, &match1, aligned_seq1_1, aligned_seq2_1, index1 + 1, index2);
        align(seq1, seq2 + 1, &match2, aligned_seq1_2, aligned_seq2_2, index1, index2 + 1);
        if (match1 > match2) {
            *match = match1;
            aligned_seq1[*index1] = seq1[0];
            aligned_seq1[*index1 + 1] = '\0';
            aligned_seq2[*index2] = '-';
            aligned_seq2[*index2 + 1] = '\0';
            strcat(aligned_seq1, aligned_seq1_1);
            strcat(aligned_seq2, aligned_seq2_1);
        } else {
            *match = match2;
            aligned_seq1[*index1] = '-';
            aligned_seq1[*index1 + 1] = '\0';
            aligned_seq2[*index2] = seq2[0];
            aligned_seq2[*index2 + 1] = '\0';
            strcat(aligned_seq1, aligned_seq1_2);
            strcat(aligned_seq2, aligned_seq2_2);
        }
    }
}

int main() {
    const char *sequence1 = "ACGT";
    const char *sequence2 = "ACGA";
    int match = 0;
    char aligned_seq1[100], aligned_seq2[100];
    int index1 = 0, index2 = 0;
    align(sequence1, sequence2, &match, aligned_seq1, aligned_seq2, &index1, &index2);
    printf("Matched: %d, Aligned Seq1: %s, Aligned Seq2: %s\n", match, aligned_seq1, aligned_seq2);
    return 0;
}